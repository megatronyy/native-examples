#include "some_struct.h"
#include <stdlib.h>

struct some_struct
{
    int num;
    char* str;
};

SOME_STRUCT_PTR new_some_struct(void){
    SOME_STRUCT_PTR new_ss = (SOME_STRUCT_PTR)malloc(sizeof(*new_ss));
    new_ss->num = 2014;
    new_ss->str = "Welcome to 2014, and get ready for 2015";
    return new_ss;
}

int get_num(SOME_STRUCT_PTR s){
    return s->num;
}

char* get_str(SOME_STRUCT_PTR s){
    return s->str;
}