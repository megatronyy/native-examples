/*
   C有一个鲜为人知的运算符叫”趋向于”，
   写作“-->”。比如说如果要实现一个倒数的程序，
   我们可以定义一个变量x，然后让它趋向于0...
*/

#include <stdio.h>

int main(void) {
  int x = 10;
  while (0 <---- x) {
    printf("%d", x);
  }

  return 0;
}