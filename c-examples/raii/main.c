#include <stdlib.h>
#include <stdio.h>

/*RAII的宏封装，离开变量的作用域后，自动调用方法的析构函数*/
#define RAII_VARIABLE(vartype, varname, initval, dtor) \
    void _dtor_##varname(vartype *v) { dtor(*v); printf("dtor invoke...\n"); }     \
    vartype varname __attribute__((cleanup(_dtor_##varname))) = (initval)

int main()
{
    /* code */
    RAII_VARIABLE(FILE*, logfile, fopen("logfile.txt", "w+"), fclose);
    fputs("hello logfile", logfile);
    printf("main method invoke end...\n");
    return 0;
}
