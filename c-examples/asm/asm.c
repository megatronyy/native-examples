#include <stdio.h>

int main()
{
    /* code */
    int result = 0;
    int input = 1;

    int a = 1;
    int b = 2;

    asm volatile(
        "movl %1, %0\n"
        : "=r"(result)
        : "r"(input));

    printf("result = %d\n", result);
    printf("input = %d\n", input);

    asm volatile (
        "movl %%eax, %%ecx;"
        "movl %%ebx, %%eax\n"
        "movl %%ecx, %%ebx;"
        : "=a"(a), "=b"(b)
        : "a"(4), "b"(5)
    );

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}

/*

C标准中并未规定如何嵌入汇编代码，所以嵌入汇编代码的语法只适用于特定的编译器，下面主要介绍GCC中的内联汇编，其格式为：__asm__　__volatile__("Instruction List" : Output : Input : Clobber/Modify)。

1、__asm__和__volatile__宏

    __asm__可简写为asm，用于标识一段汇编指令，__volatile__可简写为volatile，用于告诉编译器不需要对asm中的汇编指令做优化，原封不动的保留即可。

2、Instruction List

   Instruction List是指汇编指令列表，可以为空，多条指令时，通常一条指令一行，以分号";"或者换行符"\n"表示结束，并用双引号包住，注意指令中使用寄存器时前面必须加两个%。

3、Output

  Output指定汇编语句的输出，即将寄存器中的值存入到哪个变量中，如"=a"(a)，表示将a对应寄存器的值赋值给变量a，a是寄存器eax/ax /al的简写，编译器根据汇编指令自动推测是eax还是ax。

4、Input

  Input指定汇编语句的执行参数，可以是一个常量，也可以是一个复杂的表达式，执行参数可以通过占位符或者寄存器的方式传入，占位符按照Input/Output表达式出现的顺序从0开始编号，最多十个表达式，编号最大9。

5、操作数约束

  Output表达式"=a"(a) 中a就是操作数约束中的寄存器约束，其他约束如下，其中I O表示Input和Output适用：

r I,O 表示使用一个通用寄存器，由GCC在%eax/%ax/%al, %ebx/%bx/%bl, %ecx/%cx/%cl, %edx/%dx/%dl中选取一个GCC认为合适的。 
q I,O 表示使用一个通用寄存器，和r的意义相同。 
a I,O 表示使用%eax / %ax / %al 
b I,O 表示使用%ebx / %bx / %bl 
c I,O 表示使用%ecx / %cx / %cl 
d I,O 表示使用%edx / %dx / %dl 
D I,O 表示使用%edi / %di 
S I,O 表示使用%esi / %si 
f I,O 表示使用浮点寄存器 
t I,O 表示使用第一个浮点寄存器 
u I,O 表示使用第二个浮点寄存器
m I,O 表示使用系统所支持的任何一种内存方式，不需要借助寄存器
i I 表示输入表达式是一个立即数(整数)，不需要借助任何寄存器 
F I 表示输入表达式是一个立即数(浮点数)，不需要借助任何寄存器
g I,O 表示可以使用通用寄存器，内存，立即数等任何一种处理方式。

通过 gcc -S test.c -o test.s 或者objdump -S test.o > test.s查看生成的汇编代码

*/