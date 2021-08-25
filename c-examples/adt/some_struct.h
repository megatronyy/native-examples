#pragma one

/*不透明指针*/
typedef struct some_struct* SOME_STRUCT_PTR;

SOME_STRUCT_PTR new_some_struct(void);

int get_num(SOME_STRUCT_PTR s);

char* get_str(SOME_STRUCT_PTR s);