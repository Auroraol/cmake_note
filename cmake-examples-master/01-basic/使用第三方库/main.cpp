#include <boost/filesystem.hpp>
#include <boost/shared_ptr.hpp> // 第三方库
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Hello Third Party Include!" << std::endl;

  // use a shared ptr
  boost::shared_ptr<int> isp(new int(4));

  // trivial use of boost filesystem
  boost::filesystem::path path = "/usr/share/cmake/modules";
  if (path.is_relative()) {
    std::cout << "Path is relative" << std::endl;
  } else {
    std::cout << "Path is not relative" << std::endl;
  }

  return 0;
}
