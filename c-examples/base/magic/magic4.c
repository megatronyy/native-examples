/*
    下面这个打印是否让你惊奇？
        输出：4 and 5
    sizeof 是编译时行为，运行时不会执行
*/

#include <stdio.h>

int main(void)
{
    int x = 5;
    
    printf("%d and ", sizeof(x++));
    printf("%d\n", x);
    /* code */
    return 0;
}
