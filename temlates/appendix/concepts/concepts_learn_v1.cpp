template <typename T>
concept LessThanComparable = requires(T x, T y) {
  { x < y } -> bool;
};