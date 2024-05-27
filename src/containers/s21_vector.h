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
             &items);                     // initializer list constructor
  Vector(const Vector &v);                // copy constructor
  Vector(Vector &&v);                     // move constructor
  ~Vector();                              // destructor
  Vector operator=(Vector &&v) noexcept;  // assignment operator overload

  // Vector Element access
  reference at(size_type pos);          // access a specified element
  reference operator[](size_type pos);  // [] overload
  const_reference front();              // access the first element
  const_reference back();               // access the last element
  T *data();                            // direct access the underlying array

  // Vector Iterators
  iterator begin() noexcept; // returns an iterator to the beginning
  iterator end() noexcept; // returns an iterator to the end

  // Vector Capacity
  bool empty() noexcept;
  size_type size() noexcept;
  size_type max_size();
  void reserve(size_type size);
  size_type capacity() noexcept;
  void shrink_to_fit();

  // Vector Modifiers
  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(Vector &other);

 private:
  T *data_;             // pointer to the first element
  size_type size_;      // size of a nonempty container
  size_type capacity_;  // size of memory allocated for a container

};  // class Vector

/* CONSTRUCTORS */

/* default constructor, creates an empty vector */
template <typename value_type>
Vector<value_type>::Vector() : data_(nullptr), size_(0U), capacity_(0U) {}

/* parametrized constructor, creates the vector of size n */
template <typename value_type>
Vector<value_type>::Vector(size_type n) {
  size_ = n;
  capacity_ = n;
  data_ = new value_type[n]();
}

/* copy constructor */
template <typename value_type>
Vector<value_type>::Vector(const Vector &v) {
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = new value_type[size_]();
  for (int i = 0; i < size_; i++) {
    data_[i] = v.data_[i];
  }
}

/* move constructor */
template <typename value_type>
Vector<value_type>::Vector(Vector &&v) {
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = v.data_;
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
}

/* assignment operator overload for moving an object */
template <typename value_type>
Vector<value_type> Vector<value_type>::operator=(
    Vector<value_type> &&v) noexcept {
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = v.data_;
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
}

/* destructor */
template <typename value_type>
Vector<value_type>::~Vector() {
  delete[] data_;
  size_ = 0;
  capacity_ = 0;
  std::cout << "destroy " << this << std::endl;  // TODO remove
}

/* VECTOR ELEMENT ACCESS */

/* access a specified element with bounds checking */
template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::at(size_type pos) {
  if (pos >= size_ || pos < 0) {
    throw std::out_of_range("Error. Invalid index.");
  }
  return data_[pos];
}

/* access a specified element, no bounds checking. never inserts a new
 * element into the container. accessing a nonexistent element through this
 * operator is undefined behavior */
template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](
    size_type pos) {
  if (size_ != 0 && (pos < size_ && pos >= 0)) {
    return data_[pos];
  }
}

/* returns a reference to the first element in the container. calling front on
 * an empty container causes undefined behavior */
template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::front() {
  if (size_ != 0) {
    const_reference first_element = *data_;
    return first_element;
  }
}

/* returns a reference to the last element in the container. calling back on an
 * empty container causes undefined behavior */
template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::back() {
  if (size_ != 0) {
    const_reference last_element = data_[size_ - 1];
    return last_element;
  }
}

/* direct access the underlying array */
template <typename value_type>
value_type *Vector<value_type>::data() {
  return data_;
}

/* VECTOR ITERATORS */

/* returns an iterator to the first element of the vector. if the vector is
 * empty, the returned iterator will be equal to end() */
template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin() noexcept {
  if (size_ != 0) {
    return data_;
  }
  else {
    return end();
  }
}

/* returns an iterator to the element following the last element of the vector.
 * this element acts as a placeholder; attempting to access it results in
 * undefined behavior */
template <typename value_type> // TODO проверить где освоб-ся указатель
typename Vector<value_type>::iterator Vector<value_type>::end() noexcept {
  return data_+=size_;
}

/* VECTOR CAPACITY */

/* checks whether the container is empty */
template <typename value_type>
bool Vector<value_type>::empty() noexcept {
  return !size_;
}

/* returns the number of elements */
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::size() noexcept {
  return size_;
}

/* returns the number of elements that can be held in currently allocated
 * storage */
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::capacity() noexcept {
  return capacity_;
}

/* VECTOR MODIFIERS */

/* clears the contents */
template <typename value_type>
void Vector<value_type>::clear() noexcept {
  size_ = 0;
}

/* erases an element at pos */
template <typename value_type>
void Vector<value_type>::erase(iterator pos) () {

}

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_Vector_H_