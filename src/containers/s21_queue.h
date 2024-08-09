#ifndef S21_CONTAINERS_CONTAINERS_S21_QUEUE_H_
#define S21_CONTAINERS_CONTAINERS_S21_QUEUE_H_

#include "s21_list.h"

namespace s21 {
template <typename T, class Container = List<T> >
class Queue {
 public:
  // Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

 private:
  Container list_;

 public:
  // Queue Element access:
  const_reference front() { return list_.front(); }
  const_reference back() { return list_.back(); }

  // Queue Capacity:
  bool empty() { return list_.empty(); }
  size_type size() { return list_.size(); }

  // Constructors:
  Queue() : list_() {}
  Queue(std::initializer_list<value_type> const &items) : list_(items) {}
  Queue(const Queue &q) : list_(q.list_) {}
  Queue(Queue &&q) : list_(std::move(q.list_)) {}
  ~Queue() = default;
  Queue operator=(Queue &&q) {
    if (this != &q) {
      list_ = std::move(q.list_);
    }
    return *this;
  }

  // Functions:
  void push(const_reference value) { list_.push_back(value); }
  void pop() { return list_.pop_front(); }
  void swap(Queue &other) { std::swap(list_, other.list_); }
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    for (const auto &i : {args...}) {
      push(i);
    }
  }

};  // Queue
}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_QUEUE_H_