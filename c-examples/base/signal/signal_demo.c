/*
    解读：void (*signal(int sig, void (*func)(int)))(int)

    解读变量或函数的声明首先遵守下面的原则：

    A. 声明从它的名字开始读取，然后按照优先级顺序依次读取。名字是什么呢，从左到右碰到的第一个标识符就是名字.

    B.优先级从高到低依次是：

        B1 声明中被括号括起来的那部分

        B2 后缀操作符：括号（）表示这是一个函数，而[ ]表示这是一个数组.

        B3 前缀操作符：星号*表示“指向…的指针”

    C 如果const和volatile关键字的后面紧跟类型说明符（如 int，long等），那么它作用于类型说明符.在其他情况下，const和volatile关键字作用于它左边紧邻的星号.
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sighandler(int);

int main(void) {
  signal(SIGINT, sighandler);

  while (1) {
    printf("开始休眠一秒钟...\n");
    sleep(1);
  }

  return 0;
}

void sighandler(int signum) {
  printf("捕获信号 %d, 跳出....\n", signum);
  exit(1);
}