#include <functional>
#include <iostream>

class View {
 public:
  void onClick(int x, int y) {
      std::cout << "X : " << x << ", Y : " << y << std::endl;
  }
};

std::function<void(View, int, int)> clickCallback;

int main(int argc, char const *argv[])
{
    View button;
    clickCallback = &View::onClick;

    //进行调用
    clickCallback(button, 10, 123);

    return 0;
}
