#include <stdio.h>
#include <stdlib.h>

typedef struct _Parent
{
    int a;
    int b;
    void (*print)(struct _Parent *this);
} Parent;

/*封装继承*/
typedef struct _Child
{
    Parent parent;
    int c;
} Child;

/*多态*/
void print_parent(Parent *this)
{  
    printf("a = %d. b = %d.\n",   this->a, this->b);  
}
/*多态*/
void print_child(Parent *this)
{  
    Child *p = (Child *)this;  
	printf("a = %d. b = %d. c = %d.\n", p->parent.a, p->parent.b, p->c);  
}

Parent *create_parent(int a, int b)  
{  
    Parent *this;  
  
    this = NULL;  
    this = (Parent *)malloc(sizeof(Parent));  
    if (this != NULL)
	{  
        this->a = a;  
        this->b = b;  
        this->print = print_parent;  
        printf("Create parent successfully!\n");  
    }  
      
    return this;  
}

void destroy_parent(Parent **p)  
{  
    if (*p != NULL)
	{  
        free(*p);  
        *p = NULL;  
        printf("Delete parent successfully!\n");  
    }  
}

Child *create_child(int a, int b, int c)  
{  
    Child *this;  
  
    this = NULL;  
    this = (Child *)malloc(sizeof(Child));  
    if (this != NULL)
	{  
        this->parent.a = a;  
        this->parent.b = b;  
        this->c = c;  
        this->parent.print = print_child;  
        printf("Create child successfully!\n");  
    }  
      
    return this;  
}  
  
void destroy_child(Child **p)  
{  
    if (*p != NULL)
	{  
        free(*p);  
        *p = NULL;  
        printf("Delete child successfully!\n");  
    }  
}  

int main()  
{  
    Child *p = create_child(1, 2, 3);  
    Parent *q;  
  

    q = (Parent *)p;  
    
    q->print(q);  
  
    destroy_child(&p); 
	system("pause");
    return 0;  
}  