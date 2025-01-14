#include <filesystem>
#include <format>
#include <list>
#include <string>
#include <vector>

namespace fs = std::filesystem;
namespace tools {

template <typename T>
[[nodiscard]] inline auto get_media(const fs::path&& root) noexcept
{
  std::list<fs::directory_entry> media;
  std::copy_if(T(root), {}, std::back_inserter(media),
    [](const auto& e){ return e.is_regular_file() && e.path().extension() != ".md"; });
  return media;
}
[[nodiscard]] inline auto move_to(const fs::path& file, const fs::path&& to) noexcept
{
  fs::path to_file = to / file.filename();
  fs::copy(file, to_file);
  fs::remove(file);
  std::system(std::format("git add \"{}\"", to_file.generic_string()).c_str());
}

struct task{
  fs::path     _fp;
  explicit task(const fs::path& fp) : _fp{fp} {}
};
}

int main(void)
{
    auto mds = tools::get_media<fs::directory_iterator>(".\\vault");
    std::vector<tools::task> tasks;
    tasks.reserve(mds.size());

    std::transform(mds.cbegin(), mds.cend(), std::back_inserter(tasks),
      [](const auto& e) { return tools::task(e.path()); });

#pragma omp parallel
    {
#pragma omp for nowait
      for (__int64 i = 0; i < static_cast<__int64>(tasks.size()); ++i)
      {
        auto& task = tasks[i];
        tools::move_to(task._fp, ".\\vault\\media");
      }
    }
    return 0;
}

