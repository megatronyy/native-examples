#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <random>
#include <thread>

int doSomething(char c) {
  std::default_random_engine dre(c);
  std::uniform_int_distribution<int> id(10, 1000);

  for (int i = 0; i < 1; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
    std::cout.put(c).flush();
  }

  return c;
}

int func1() { return doSomething('.'); }

int func2() { return doSomething('+'); }

int main() {
  std::cout << "starting func1() in background"
            << " and func2() in foreground:" << std::endl;

  // start func1() asynchronously(now or later or never)
  std::future<int> result1(std::async(func1));

  // call func2() synchronously(here and now)
  int result2 = func2();

  // print result(wait for func1() to finish and add its result to result2)
  int result = result1.get() + result2;

  std::cout << "\nresult of func1()+func2(): " << result << std::endl;
}