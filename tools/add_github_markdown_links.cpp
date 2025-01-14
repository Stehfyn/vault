#include <filesystem>
#include <format>
#include <fstream>
#include <list>
#include <regex>
#include <sstream>
#include <set>
#include <string>
#include <system_error>
#include <vector>

namespace fs = std::filesystem;

namespace tools {
using iss = std::istringstream;
using oss = std::ostringstream;

template <typename T>
[[nodiscard]] inline auto get(const fs::path&& root, const std::set<std::string>&& exts) noexcept
{
  std::list<fs::directory_entry> dirs;
  std::copy_if(T(root), {}, std::back_inserter(dirs),
    [&](const auto& e){ return exts.end() != exts.find(e.path().extension().generic_string()); });
  return dirs;
}

[[nodiscard]] inline auto make_link(iss&& match) noexcept
{
  std::string encode_url;
  for(std::string sub; std::getline(match, sub, ' ');) encode_url += sub + "%20";
  return std::format("![](https://github.com/Stehfyn/vault/blob/main/vault/media/{})",
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
    auto mds = tools::get<fs::recursive_directory_iterator>(".", {".md"});
    std::vector<tools::task> tasks;
    tasks.reserve(mds.size());

    std::transform(mds.cbegin(), mds.cend(), std::back_inserter(tasks),
      [](const auto& e) { return tools::task(e.path()); });

#pragma omp parallel
    {
      static const std::regex wikilink(R"(!\[\[(.*?)\]\])");

#pragma omp for nowait
      for (__int64 i = 0; i < static_cast<__int64>(tasks.size()); ++i)
      {
        auto& task = tasks[i];
        for (std::string line; std::getline(task._fd, line);) {
          std::smatch matches;
          std::string::const_iterator search_start(line.cbegin());
          if (!std::regex_search(search_start, line.cend(), matches, wikilink))
            task._buf << line << "\n";
          else do {
            task._buf << matches[0] << tools::make_link(tools::iss(matches[1])) << "\n";
            search_start = matches.suffix().first;
          } while (std::regex_search(search_start, line.cend(), matches, wikilink));
        }
        task._fd.clear();
        task._fd.seekp(0, std::ios::beg);
        task._fd << task._buf.str();
      }
    }
    return 0;
}

