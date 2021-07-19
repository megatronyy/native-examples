#include <functional>
#include <iostream>

using FunPtr = std::function<void()>;
/**
 * @quwb
 * 栈对象，在pop时，调用析构函数，实现golang defer关键字的功能
 */
class ScopeGuard {
 public:
  ScopeGuard(FunPtr f) { mFunc = f; }

  ~ScopeGuard() { mFunc(); }

 private:
  FunPtr mFunc;
};

void f() {
  int *p = new int{3};

  ScopeGuard s([&p]() {
    if (p) {
      delete p;
    }
    std::cout << "delete pointer \n";
  });
}

int main() {
  std::cout << "starting...... \n";

  f();

  return 0;
}
