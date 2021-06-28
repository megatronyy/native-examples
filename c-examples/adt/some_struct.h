#pragma one

/*透明指针*/
typedef struct some_struct* SOME_STRUCT_PTR;

extern SOME_STRUCT_PTR new_some_struct(void);

extern int get_num(SOME_STRUCT_PTR s);

extern char* get_str(SOME_STRUCT_PTR s);