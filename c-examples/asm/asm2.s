Reading symbols from ./asm2.o...done.
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000000000000625 <+0>:	push   %rbp
   0x0000000000000626 <+1>:	mov    %rsp,%rbp
   0x0000000000000629 <+4>:	sub    $0x10,%rsp
   0x000000000000062d <+8>:	movl   $0x7b,-0x10(%rbp)
   0x0000000000000634 <+15>:	movl   $0x1c8,-0xc(%rbp)
   0x000000000000063b <+22>:	mov    -0x10(%rbp),%edx
   0x000000000000063e <+25>:	mov    -0xc(%rbp),%eax
   0x0000000000000641 <+28>:	add    %eax,%edx
   0x0000000000000643 <+30>:	mov    -0x10(%rbp),%eax
   0x0000000000000646 <+33>:	mov    %edx,%esi
   0x0000000000000648 <+35>:	mov    %eax,%edi
   0x000000000000064a <+37>:	callq  0x688 <add>
   0x000000000000064f <+42>:	mov    %eax,-0x8(%rbp)
   0x0000000000000652 <+45>:	movl   $0xea,-0x4(%rbp)
   0x0000000000000659 <+52>:	mov    -0x4(%rbp),%edx
   0x000000000000065c <+55>:	mov    -0x8(%rbp),%eax
   0x000000000000065f <+58>:	mov    %edx,%esi
   0x0000000000000661 <+60>:	mov    %eax,%edi
   0x0000000000000663 <+62>:	callq  0x6c9 <mult>
   0x0000000000000668 <+67>:	mov    %eax,-0x8(%rbp)
   0x000000000000066b <+70>:	mov    -0x8(%rbp),%eax
   0x000000000000066e <+73>:	mov    %eax,%esi
   0x0000000000000670 <+75>:	lea    0xed(%rip),%rdi        # 0x764
   0x0000000000000677 <+82>:	mov    $0x0,%eax
   0x000000000000067c <+87>:	callq  0x520 <printf@plt>
   0x0000000000000681 <+92>:	mov    $0x0,%eax
   0x0000000000000686 <+97>:	leaveq 
   0x0000000000000687 <+98>:	retq   
End of assembler dump.
(gdb) [K(gdb) [K(gdb) [K(gdb) [K(gdb) disassemble main[C main/ mainm main[C main
Dump of assembler code for function main:
18	int main(){
   0x0000000000000625 <+0>:	push   %rbp
   0x0000000000000626 <+1>:	mov    %rsp,%rbp
   0x0000000000000629 <+4>:	sub    $0x10,%rsp

19	   int a=123;
   0x000000000000062d <+8>:	movl   $0x7b,-0x10(%rbp)

20	   int b=456;
   0x0000000000000634 <+15>:	movl   $0x1c8,-0xc(%rbp)

21	   int c=add(a,a+b);
   0x000000000000063b <+22>:	mov    -0x10(%rbp),%edx
   0x000000000000063e <+25>:	mov    -0xc(%rbp),%eax
   0x0000000000000641 <+28>:	add    %eax,%edx
   0x0000000000000643 <+30>:	mov    -0x10(%rbp),%eax
--Type <RET> for more, q to quit, c to continue without paging--[K--Type <RET> for more, q to quit, c to continue without paging--
   0x0000000000000646 <+33>:	mov    %edx,%esi
   0x0000000000000648 <+35>:	mov    %eax,%edi
   0x000000000000064a <+37>:	callq  0x688 <add>
   0x000000000000064f <+42>:	mov    %eax,-0x8(%rbp)

22	   int d=234;
   0x0000000000000652 <+45>:	movl   $0xea,-0x4(%rbp)

23	   c=mult(c,d);
   0x0000000000000659 <+52>:	mov    -0x4(%rbp),%edx
   0x000000000000065c <+55>:	mov    -0x8(%rbp),%eax
   0x000000000000065f <+58>:	mov    %edx,%esi
   0x0000000000000661 <+60>:	mov    %eax,%edi
   0x0000000000000663 <+62>:	callq  0x6c9 <mult>
   0x0000000000000668 <+67>:	mov    %eax,-0x8(%rbp)

24	   printf("c=%d\n",c);
   0x000000000000066b <+70>:	mov    -0x8(%rbp),%eax
   0x000000000000066e <+73>:	mov    %eax,%esi
   0x0000000000000670 <+75>:	lea    0xed(%rip),%rdi        # 0x764
   0x0000000000000677 <+82>:	mov    $0x0,%eax
   0x000000000000067c <+87>:	callq  0x520 <printf@plt>
   0x0000000000000681 <+92>:	mov    $0x0,%eax

25	}
   0x0000000000000686 <+97>:	leaveq 
   0x0000000000000687 <+98>:	retq   

End of assembler dump.
(gdb) [K(gdb) [K(gdb) [K(gdb) exit
(gdb) 
(gdb) 
(gdb) 
(gdb) 
(gdb) help
List of classes of commands:

aliases -- Aliases of other commands
breakpoints -- Making program stop at certain points
data -- Examining data
files -- Specifying and examining files
internals -- Maintenance commands
obscure -- Obscure features
running -- Running the program
stack -- Examining the stack
status -- Status inquiries
support -- Support facilities
tracepoints -- Tracing of program execution without stopping the program
user-defined -- User-defined commands

--Type <RET> for more, q to quit, c to continue without paging--