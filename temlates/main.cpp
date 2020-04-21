#include "nontype_class_template_v1.h"
#include <iostream>
#include <string>

int main(){
    Stack<int, 20> int20Stack;
    Stack<int, 40> int40Stack;
    Stack<std::string, 40> stringStack;

    int20Stack.push(7);

    std::cout << int20Stack.top() << '\n';
    int20Stack.pop();

    //manipulate stack of up to 40 strings
    stringStack.push("hello");
    std::cout << stringStack.top() << '\n';
    stringStack.pop();
}