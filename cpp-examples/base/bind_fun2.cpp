#include <functional>
#include <iostream>

int TestFunc(int a, char c, float f) {
  std::cout << a << std::endl;
  std::cout << c << std::endl;
  std::cout << f << std::endl;

  return a;
}

int main(int argc, char const *argv[]) {
  auto bindFun1 = std::bind(TestFunc, std::placeholders::_1, 'A', 100.1);
  bindFun1(10);
  std::cout << "==================================\n";

  auto bindFun2 =
      std::bind(TestFunc, std::placeholders::_2, std::placeholders::_1, 100.1);
  bindFun2('A', 10);
  std::cout << "==================================\n";

  auto bindFunc3 = std::bind(TestFunc, std::placeholders::_2, std::placeholders::_3,
                        std::placeholders::_1);
  bindFunc3(100.1, 30, 'C');

  return 0;
}
