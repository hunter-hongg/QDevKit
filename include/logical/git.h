#pragma once
#include <string>

namespace logical {
class GitHelper {
public:
  GitHelper() = delete;
  GitHelper(std::string path);
  bool git_exists();
  void set_path(std::string path);

protected:
  std::string libpath;
};
} // namespace logical