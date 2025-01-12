#include <regex>
#include <list>
#include <vector>
#include <atomic>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <system_error>
#include <string>
#include <format>
#include <sstream>

namespace tools {
namespace fs = std::filesystem;
using iss = std::istringstream;
using oss = std::ostringstream;

[[nodiscard]] inline auto get_mds(const fs::path& root) noexcept
{
  std::list<fs::directory_entry> dirs;
  std::copy_if(fs::recursive_directory_iterator(root),
               {}, 
               std::back_inserter(dirs),
               [](const auto& e){ return e.path().extension() == ".md"; });
  return dirs;
}

[[nodiscard]] inline auto make_link(const std::ssub_match& match)
{
  std::string encode_url;
  iss _iss(match.str());
  for(std::string sub; std::getline(_iss, sub, ' ');) encode_url += sub + "%20";
  return std::format("![]({}{})",
                    "https://github.com/Stehfyn/vault/blob/main/vault/",
                    (encode_url.erase(encode_url.size() - 3), encode_url));
}

struct task{
  fs::path     _fp;
  std::fstream _fd;
  oss          _buf;
  explicit task(const fs::path& fp) : _fp{fp}, _fd { _fp, std::ios::in | std::ios::out } {}
};
}

int main(void)
{
    auto mds = tools::get_mds(".");
    std::vector<tools::task> tasks;
    tasks.reserve(mds.size());

    std::transform(mds.cbegin(), mds.cend(), std::back_inserter(tasks),
      [](const auto& e) { return tools::task(e.path()); });

#pragma omp parallel
    {
      static const std::regex pattern(R"(!\[\[(.*?)\]\])");

#pragma omp for nowait
      for (__int64 i = 0; i < static_cast<__int64>(tasks.size()); ++i)
      {
        auto& task = tasks[i];

        for (std::string line; std::getline(task._fd, line);) {
          std::smatch matches;
          std::string::const_iterator search_start(line.cbegin());
          if (!std::regex_search(search_start, line.cend(), matches, pattern))
            task._buf << "\n";
          else do {
            task._buf << matches[0] << tools::make_link(matches[1]) << "\n";
            search_start = matches.suffix().first;
          } while (std::regex_search(search_start, line.cend(), matches, pattern));
        }
        task._fd.clear();
        task._fd.seekp(0, std::ios::beg);
        task._fd << task._buf.str();
      }
    }
    return 0;
}
