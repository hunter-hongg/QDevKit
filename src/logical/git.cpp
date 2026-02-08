#include <filesystem>
#include <logical/git.h>

namespace logical {
GitHelper::GitHelper(std::string path) : libpath(path) {}
bool GitHelper::git_exists() {
  return std::filesystem::exists(libpath + ".git");
}
void GitHelper::set_path(std::string path) {
  libpath = path;
}
} // namespace logical