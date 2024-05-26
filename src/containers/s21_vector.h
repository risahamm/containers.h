#ifndef S21_CONTAINERS_CONTAINERS_S21_Vector_H_
#define S21_CONTAINERS_CONTAINERS_S21_Vector_H_

#include "../s21_containers.h"
namespace s21 {

template <typename T>
class Vector {
 public:

  // Vector Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // Vector Member functions
  Vector();             // default constructor
  Vector(size_type n);  // parametrized constructor
  Vector(std::initializer_list<value_type> const
             &items);       // initializer list constructor
  Vector(const Vector &v);  // copy constructor
  Vector(Vector &&v);       // move constructor
  //  ~Vector(); // destructor
  Vector operator=(Vector &&v);  // assignment operator overload

  // Vector Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T *data();

  // Vector Iterators
  iterator begin();
  iterator end();

  // Vector Capacity
  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  // Vector Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(Vector &other);

 private:
  T *data_;         // pointer to the first element
  size_type size_;  //
  size_type capacity_;
};

/* CONSTRUCTORS */

// default constructor, creates an empty vector
template <typename value_type>
Vector<value_type>::Vector() : data_(nullptr), size_(0U), capacity_(0U) {}

template <typename value_type>
Vector<value_type>::Vector(size_type n) {
  *data_ = new T
}

/* VECTOR CAPACITY */

// checks whether the container is empty
template <typename value_type>
bool Vector<value_type>::empty() {
  return !size_;
}

// returns the number of elements
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::size() {
  return size_;
}

// returns the number of elements that can be held in currently allocated
// storage
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::capacity() {
  return capacity_;
}

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_Vector_H_