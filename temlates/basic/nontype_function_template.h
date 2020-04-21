/**
 * non-type function template
 * 
 * Note that nontype template parameters carry some restrictions. In general, they
 * can be only constant integral values (including enumerations), pointers to
 * objects/functions/members, lvalue references to objects or functions, or
 * std::nullptr_t (the type of nullptr).
 * Floating-point numbers and class-type objects are not allowed as nontype
 * template parameters
 */

template <int Val, typename T>
T addValue(T x) {
  return x + Val;
}

// template parameter with auto in c++ 17
template <auto Val, typename T = decltype(Val)>
T foo();

template<typename T, T val= T{}>
T bar();