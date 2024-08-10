#ifndef S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_
#define S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_

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
  Vector() noexcept;             // default constructor
  Vector(size_type n) noexcept;  // parametrized constructor
  Vector(std::initializer_list<value_type> const
             &items) noexcept;            // initializer list constructor
  Vector(const Vector &v) noexcept;       // copy constructor
  Vector(Vector &&v) noexcept;            // move constructor
  ~Vector() noexcept;                     // destructor
  Vector operator=(Vector &&v) noexcept;  // assignment operator overload

  // Vector Element access
  reference at(size_type pos);          // access a specified element
  reference operator[](size_type pos);  // [] overload
  const_reference front();              // access the first element
  const_reference back();               // access the last element
  T *data() noexcept;                   // direct access the underlying array

  // Vector Iterators
  iterator begin() noexcept;  // returns an iterator to the beginning
  iterator end() noexcept;    // returns an iterator to the end

  // Vector Capacity
  bool empty() noexcept;
  size_type size() noexcept;
  size_type max_size() noexcept;
  void reserve(size_type new_cap);
  size_type capacity() noexcept;
  void shrink_to_fit();

  // Vector Modifiers
  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);

  template <class... Args>
  void insert_many_back(Args &&...args);

  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(Vector &other);

 private:
  T *data_;             // pointer to the first element
  size_type size_;      // size of a nonempty container
  size_type capacity_;  // size of memory allocated for a container

};  // class s21::Vector

/* CONSTRUCTORS */

/**
 * default constructor, creates an empty vector */
template <typename value_type>
Vector<value_type>::Vector() noexcept
    : data_(nullptr), size_(0U), capacity_(0U) {}

/**
 * parametrized constructor, creates the vector of size n */
template <typename value_type>
Vector<value_type>::Vector(size_type n) noexcept {
  size_ = n;
  capacity_ = n;
  data_ = new value_type[n]();
}

/**
 * initializer list constructor, creates a vector initialized using
 * std::initializer_list */
template <typename value_type>
Vector<value_type>::Vector(
    std::initializer_list<value_type> const &items) noexcept {
  size_ = items.size();
  capacity_ = items.size();
  data_ = new value_type[size_];
  int i = 0;  // iterator
  for (const auto &one_item : items) {
    data_[i++] = one_item;
  }
}

/**
 * copy constructor */
template <typename value_type>
Vector<value_type>::Vector(const Vector &v) noexcept {
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = new value_type[size_]();
  for (size_type i = 0; i < size_; ++i) {
    data_[i] = v.data_[i];
  }
}

/**
 * move constructor */
template <typename value_type>
Vector<value_type>::Vector(Vector &&v) noexcept {
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = v.data_;
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
}

/**
 * assignment operator overload for moving an object */
template <typename value_type>
Vector<value_type> Vector<value_type>::operator=(
    Vector<value_type> &&v) noexcept {
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = v.data_;
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
  return *this;
}

/**
 * destructor */
template <typename value_type>
Vector<value_type>::~Vector() noexcept {
  delete[] data_;
  size_ = 0;
  capacity_ = 0;
}

/* VECTOR ELEMENT ACCESS */

/**
 * access a specified element with bounds checking */
template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Error. Invalid index.");
  }
  return data_[pos];
}

/**
 * access a specified element, no bounds checking. never inserts a new
 * element into the container. accessing a nonexistent element through this
 * operator is undefined behavior */
template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](
    size_type pos) {
  return data_[pos];
}

/**
 * returns a reference to the first element in the container. calling front on
 * an empty container causes undefined behavior */
template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::front() {
  const_reference first_element = *data_;
  return first_element;
}

/**
 * returns a reference to the last element in the container. calling back on an
 * empty container causes undefined behavior */
template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::back() {
  const_reference last_element = data_[size_ - 1];
  return last_element;
}

/**
 * direct access the underlying array */
template <typename value_type>
value_type *Vector<value_type>::data() noexcept {
  return data_;
}

/* VECTOR ITERATORS */

/**
 * returns an iterator to the first element of the vector. if the vector is
 * empty, the returned iterator will be equal to end() */
template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin() noexcept {
  if (size_ != 0) {
    return data_;
  } else {
    return end();
  }
}

/**
 * returns an iterator to the element following the last element of the vector.
 * this element acts as a placeholder; attempting to access it results in
 * undefined behavior */
template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::end() noexcept {
  iterator result = data_ + size_;
  return result;
}

/* VECTOR CAPACITY */

/**
 * checks whether the container is empty */
template <typename value_type>
bool Vector<value_type>::empty() noexcept {
  return !size_;
}

/**
 * returns the number of elements */
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::size() noexcept {
  return size_;
}

/**
 * returns the maximum possible number of elements */
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::max_size() noexcept {
  return SIZE_MAX / sizeof(value_type);
}

/**
 * allocate storage of size elements and copies current array elements to a
 * newely allocated array */
template <typename value_type>
void Vector<value_type>::reserve(size_type new_cap) {
  if (new_cap > capacity_) {
    s21::Vector<value_type> new_vector(new_cap);
    new_vector.size_ = size_;
    for (size_type i = 0; i < size_; ++i) {
      new_vector.data_[i] = data_[i];
    }
    delete[] data_;
    data_ = new_vector.data_;
    size_ = new_vector.size_;
    capacity_ = new_vector.capacity_;
    new_vector.data_ = nullptr;
  }
}

/**
 * returns the number of elements that can be held in currently allocated
 * storage */
template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::capacity() noexcept {
  return capacity_;
}

/**
 * reduces memory usage by freeing unused memory */
template <typename value_type>
void Vector<value_type>::shrink_to_fit() {
  if (capacity_ > size_) {
    s21::Vector<value_type> new_vector(size_);
    for (size_type i = 0; i < size_; ++i) {
      new_vector.data_[i] = data_[i];
    }
    delete[] data_;
    data_ = new_vector.data_;
    size_ = new_vector.size_;
    capacity_ = new_vector.capacity_;
    new_vector.data_ = nullptr;
  }
}

/* VECTOR MODIFIERS */

/**
 * clears the contents */
template <typename value_type>
void Vector<value_type>::clear() noexcept {
  size_ = 0;
}

/**
 * erases an element at pos */
template <typename value_type>
void Vector<value_type>::erase(iterator pos) {
  Vector<value_type> result(size_ - 1);
  int j = 0;  // iterator
  for (iterator ptr = data_; ptr != end(); ++ptr) {
    if (ptr == pos) continue;
    result.data_[j] = *ptr;
    ++j;
  }
  delete[] data_;
  data_ = result.data_;
  size_ = result.size_;
  capacity_ = result.capacity_;
  result.data_ = nullptr;
}

/**
 * inserts elements into particular pos and returns the iterator that points to
 * the new element */
template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::insert(
    iterator pos, const_reference value) {
  Vector<value_type> result(size_ + 1);
  int j = 0;  // iterator
  iterator return_val;
  for (iterator ptr = data_; ptr <= end(); ++ptr) {
    if (ptr == pos) {
      result.data_[j] = value;
      return_val = &result.data_[j];
      result.data_[++j] = *ptr;
    } else {
      result.data_[j] = *ptr;
    }
    ++j;
  }
  delete[] data_;
  data_ = result.data_;
  size_ = result.size_;
  capacity_ = result.capacity_;
  result.data_ = nullptr;
  return return_val;
}

template <class value_type>
template <class... Args>
void Vector<value_type>::insert_many_back(Args &&...args) {
  Vector<value_type> tmp{args...};
  for (size_type i = 0; i < tmp.size(); ++i) {
    push_back(tmp[i]);
  }
}

/**
 * adds an element to the end */
template <typename value_type>
void Vector<value_type>::push_back(const_reference value) {
  size_type result_size = 0;
  if ((size_ == capacity_) && (size_ != 0 && capacity_ != 0)) {
    result_size = size_ * 2;  // if size == capacity, double capacity
  } else if (size_ == 0 && capacity_ == 0) {
    result_size = 1;  // if vector is empty, allocate memory for 1 element
  } else {
    result_size = capacity_;  // otherwise, no new memory allocated
  }
  Vector<value_type> result(result_size);
  result.size_ = size_ + 1;
  for (size_type i = 0; i < size_; ++i) {
    result.data_[i] = data_[i];
  }
  result.data_[size_] = value;
  delete[] data_;
  data_ = result.data_;
  size_ = result.size_;
  capacity_ = result.capacity_;
  result.data_ = nullptr;
}

/**
 * removes the last element, capacity remains unchanged. calling pop_back on an
 * empty container results in undefined behavior */
template <typename value_type>
void Vector<value_type>::pop_back() {
  if (size_ != 0) {
    data_[size_ - 1] = 0;
    --size_;
  }
}

/**
 * swaps the contents */
template <typename value_type>
void Vector<value_type>::swap(Vector<value_type> &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_