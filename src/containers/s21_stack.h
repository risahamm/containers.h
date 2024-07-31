#ifndef S21_CONTAINERS_CONTAINERS_S21_STACK_H_
#define S21_CONTAINERS_CONTAINERS_S21_STACK_H_

#include "s21_list.h"

namespace s21 {
template <typename T, class Container = List<T> >
class Stack {
 public:

  // Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

 private:
  Container list_;

 public:
  // Stack Element access:
  const_reference top() { return list_.front(); }

  // Stack Capacity:
  bool empty() { return list_.empty(); }
  size_type size() { return list_.size(); }

  // Constructors:
  Stack() : list_() {}
  Stack(std::initializer_list<value_type> const &items) {
    for (auto i = items.begin(); i != items.end(); ++i) {
      push(*i);
    }
  }
  Stack(const Stack &s) : list_(s.list_) {}
  Stack(Stack &&s) : list_(std::move(s.list_)) {}
  ~Stack() = default;
  Stack operator=(Stack &&s) {
    if (this != &s) {
      list_ = std::move(s.list_);
    }
    return *this;
  }

  // Functions:
  void push(const_reference value) { list_.push_front(value); }
  void pop() { return list_.pop_front(); }
  void swap(Stack &other) { std::swap(list_, other.list_); }
  template <typename... Args>
  void insert_many_front(Args &&...args) {
    for (const auto &i : {args...}) {
      push(i);
    }
  }

};  // Stack
}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_STACK_H_
