#include <stdio.h>

#include "some_struct.h"

int main()
{
    SOME_STRUCT_PTR ss = new_some_struct();
    printf("%d\n", get_num(ss));
    printf("%s\n", get_str(ss));
    return 0;
}
