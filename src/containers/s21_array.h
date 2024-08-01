#ifndef S21_CONTAINERS_CONTAINERS_S21_ARRAY_H_
#define S21_CONTAINERS_CONTAINERS_S21_ARRAY_H_

namespace s21 {
template <typename T, std::size_t N>
class Array {
 public:
  // Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

 private:
  value_type head_[N];

 public:
  // Constructors
  Array() = default;
  //        Array(std::initializer_list<value_type> const &items) {}
  Array(const Array &a) = default;
  Array(Array &&a) = default;
  ~Array() = default;
  Array operator=(Array &&a) = default;

  // Array Element access:
  //        reference at(size_type pos) {}
  //        reference operator[](size_type pos) {}
  const_reference front() { return head_[0]; }
  const_reference back() { return head_[N - 1]; }
  iterator data() { return head_; }

  // Array Iterators:
  iterator begin() { return head_; }
  iterator end() { return head_ + N; }

  // Array Capacity:
  bool empty() { return begin() == end(); }
  size_type size() { return N; }
  size_type max_size() { return N; }

  // Array functions:
  void swap(Array &other) { std::swap(head_, other.head_); }
  void fill(const_reference value) {
    for (size_type i = 0; i < N; ++i) {
      head_[i] = value;
    }
  }

};  // Array
}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_ARRAY_H_