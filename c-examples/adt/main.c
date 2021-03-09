#include <stdio.h>

#include "some_struct.h"

#define RAII_VARIABLE(vartype, varname, initval, dtor) \
    void _dtor_ ## varname (vartype* v) { dtor(*v); } \
    vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)

int main()
{
    SOME_STRUCT_PTR ss = new_some_struct();
    printf("%d\n", get_num(ss));
    printf("%s\n", get_str(ss));
    return 0;
}
