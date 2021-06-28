#include <stdio.h>
 
int outer=12;
 
int add(int a,int b);
 
int mult(int a,int b);
 
int main(){
   int a=123;
   int b=456;
   int c=add(a,a+b);
   int d=234;
   c=mult(c,d);
   printf("c=%d\n",c);
}
 
int add(int a,int b){
	int c=mult(a,b);
	for(int i=0;i<3;i++){
	  c+=outer;
	}
	return c;
}
 
int mult(int a,int b){
	return (a+b)*2;

}

/*
C与汇编语言<====>https://blog.csdn.net/qq_31865983/article/details/91453963#2%E3%80%81%20%E8%B0%83%E7%94%A8%E6%A0%88

1、执行sudo gcc -g -std=c99 asm2.c -o asm2.o，生成可执行文件asm2.o，因为for循环中初始化变量i是从C99开始支持的，如果gcc版本较低需要指定C标准版本。

 2、执行gdb -q ./asm2.o |tee asm2.s 启动gdb，-q表示不输出gdb的版本信息等，tee命令用于将gdb的输出保存到指定文件asm2.s。

3、执行disassemble main 输出main方法的汇编代码，如下图

4、执行disassemble /m main 输出main方法的汇编代码和对应的源码，disassemble 还有一个/r选项，这个是默认值，和不带的效果一样

5、反汇编调试详解

- 执行 sudo gcc -g asm2.c -o asm2 -std=c99 生成可执行文件，
- 执行gdb -q -tui ./asm2 启动gdb，-tui表示启动用于显示源码和汇编代码等的文本窗口，也可用gdbtui -q ./asm2替代。
- 执行layout split：显示源代码和汇编窗口，主要是为了查看执行main方法前的汇编指令，因为断点调试只能从int a=123; 这行代码开始，之前的汇编指令在开始断点调试后看不到。
- 执行layout regs，显示寄存器窗口，可直接查看所有寄存器的值，layout src显示源码窗口，查看当前执行的源码，如果寄存器窗口没了，再执行layout regs
- 执行show disassembly-flavor 查看显示的汇编语法类型，默认是att，即AT&T 汇编语法，也可通过set disassembly-flavor intel设置成Intel汇编语法。
- 执行set disassemble-next-line on，当程序暂停时反汇编下一行代码，默认是off
- 执行start， gdb自动停在main方法的第一行代码上，如下图：
- 执行ni可查看下一步的汇编代码
- 执行到int c=add(a,a+b)；时，汇编代码会显示有多行：因为多行代码未显示完所以出现最下面的一行---Type <return> to continue, or q <return> to quit---，
  点击回车往下查看未显示的部分，全部显示完自动退出，也可输入q手动退出，然后执行ni继续下一步调试，当执行到callq的时候可以，
  执行si可以进入到这个方法的汇编代码执行调试
- 此时可通过info registers查看当前所有寄存器的值，也可通过寄存器窗口查看

*/