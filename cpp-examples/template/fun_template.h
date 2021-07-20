#include <iostream>
#include <type_traits>

template<typename C>
void print2nd(const C& container){
    if (container.size() >= 2)
    {
        //C::const_iterator嵌套从属类型名，必须加typename告诉编译器，它是个类型
        typename C::const_iterator iter(container.begin());
        ++iter;
        int value = *iter;
        std::cout << value;
    }
    
}

template<typename IterT>
void workWithIterator(IterT iter){
    typedef typename std::iterator_traits<IterT>::value_type value_type;
    value_type temp(*iter);
}