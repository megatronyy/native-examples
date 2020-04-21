/**
 * non-type function template
 */

template <int Val, typename T>
T addValue(T x) {
  return x + Val;
}

// template parameter with auto in c++ 17
template <auto Val, typename T = decltype(Val)>
T foo();