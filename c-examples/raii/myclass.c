// myclass.h

struct _MyObject;

typedef struct _MyClass{
    struct _MyObject *(*_new)();
    void (*_delete)(struct _MyObject*);
    void (*init)(struct _MyObject*);
    void (*destruct)(struct _MyObject*);
    void (*set_data)(struct _MyObject*, int size, void *data);
    void *(*get_data)(struct _MyObject*);
    int (*work)(struct _MyObject*);
    void (*release)(struct _MyObject*);
} MyClass;

typedef struct _MyObject{
    MyClass *classptr;
} MyObject;

extern MyClass SubClass;

typedef struct _SubClass_Object{
    MyObject _myobject;
    void *data;
}SubClassObject;

// myclass.c

static MyObject *subclass_new(){
    return (MyObject*)malloc(sizeof(SubClassObject));
}

static void subclass_delete(MyObject *obj){
    free(obj);
}

static void subclass_init(MyObject *ptr){
    SubClassObject *_this = (SubClassObject*)ptr;
    _this->_myobject.classptr = &SubClass;
    _this->data = NULL;
}

static void subclass_destruct(MyObject *ptr){
    SubClassObject *_this = (SubClassObject*)ptr;
    if(_this->data != NULL){
        _this->_myobject.classptr->release(ptr);
    }
}

static void subclass_set_data(MyObject *ptr, int size, void *data){
    SubClassObject *_this = (SubClassObject*)ptr;
    if(_this->data != NULL){
        // Why not subclass_release(ptr)? Think about it.
        _this->_myobject.classptr->release(ptr);
    }
    if(size > 0){
        _this->data = malloc(size);
        memcpy(_this->data, data, size);
    }
}

static void subclass_get_data(MyObject *ptr){
    SubClassObject *_this = (SubClassObject*)ptr;
    return _this->data;
}

static void subclass_release(MyObject *ptr){
    SubClassObject *_this = (SubClassObject*)ptr;
    if(_this->data){
        free(_this->data);
        _this->data = NULL;
    }
}

MyClass SubClass = {subclass_new, subclass_delete, subclass_init, subclass_destruct,
                    subclass_set_data, subclass_get_data, NULL, subclass_release};

MyObject *create_object(MyClass *_class){
    MyObject *newobj = _class->_new();
    _class->init(newobj);
    return newobj;
}

void delete_object(MyObject *obj){
    MyClass *class = obj->classptr;
    class->destruct(obj);
    class->_delete(obj);
}

int main(){
    MyObject *newobj;
    char data[] = "Test data";
    newobj = create_object(&SubClass);
    newobj->classptr->set_data(newobj, data, sizeof(data));
    printf("%s\n", (char*)(newobj->classptr->get_data(newobj)));
    delete_object(newobj);
    return 0;
}