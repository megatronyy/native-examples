#include <iostream>

void getNum(int &);
int doubleNum(int number);

int main() {
  int value;
  getNum(value);

  return 0;
}

void getNum(int &userNum) {
  std::cout << "Enter a number: ";
  std::cin >> userNum;
}
int doubleNum(int number) { return number * 2; }
