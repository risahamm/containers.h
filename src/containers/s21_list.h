#ifndef S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_
#define S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_

//#include <cmath>
//#include <initializer_list>
//#include <iostream>
//#include <limits>
//#include <memory>
//#include <type_traits>

namespace s21 {
template <typename T>
class List {
 public:
  // Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  template <typename value_type>
  class Node {
   public:
    Node *pNext;
    Node *pPrev;
    value_type data;
    Node(value_type data = value_type(), Node *pNext = nullptr,
         Node *pPrev = nullptr) {
      this->data = data;
      this->pNext = pNext;
      this->pPrev = pPrev;
    }
  };  // Node

  template <typename value_type>
  class ListIterator {
   public:
    // Constructors:
    ListIterator() = default;
    ListIterator(Node<value_type> *node) : node_(node) {}
    ListIterator(const ListIterator<value_type> &other) {  // copy
      node_ = other.get_node();
    }
    ~ListIterator() = default;
    // overloads:
    reference operator*() const { return node_->data; }
    ListIterator *operator->() const { return &(operator*()); }
    ListIterator &
    operator++() {  // ++x    (int y = ( ++x)); 'y' changed his value.
      node_ = node_->pNext;
      return *this;
    }
    // ListIterator operator++(int) {} // x++     ((int y = x)++); 'y' didn't
    // change his value.
    ListIterator &operator=(ListIterator &other) {
      if (*this != other) {
        node_ = other.node_;
      }
      return *this;
    }
    ListIterator operator++(int) {
      ListIterator temp(*this);
      operator++();
      return temp;
    }
    ListIterator &operator--() {
      node_ = node_->pPrev;
      return *this;
    }
    ListIterator operator--(int) {
      ListIterator temp(*this);
      operator--();
      return temp;
    }
    bool operator==(const ListIterator &other) { return node_ == other.node_; }
    bool operator!=(const ListIterator &other) { return node_ != other.node_; }
    // functions:
    Node<value_type> *get_node() const { return node_; }

   private:
    Node<value_type> *node_ = nullptr;
  };  // ListIterator

  using iterator = ListIterator<value_type>;
  using const_iterator = const ListIterator<value_type>;

  // Iterators
  iterator begin() { return iterator(head_->pNext); }
  iterator end() { return iterator(head_); }

  // List Element access
  const_reference front() { return *begin(); }
  const_reference back() {
    iterator temp = end();
    --temp;
    return *temp;
  }

  // List Capacity
  bool empty() { return (begin() == end()); }
  size_type size() { return size_; }
  size_type max_size() { return SIZE_MAX / sizeof(value_type); }

 private:
  Node<value_type> *head_;
  size_type size_;

 public:
  // Constructors:
  List() : size_(0U) {
    auto *base = new Node<value_type>();
    head_ = base;
    head_->pNext = base;
    head_->pPrev = base;
  }
  List(size_type n) : size_(0U) {
    auto *base = new Node<value_type>();
    head_ = base;
    head_->pNext = base;
    head_->pPrev = base;
    for (size_type i = 0; i < n; i++) {
      push_back(value_type());
    }
  }
  // e.g. List <int> A = {1, 2, 3} (List initializing with the help of { } )
  List(std::initializer_list<value_type> const &items) : size_(0U) {
    auto *base = new Node<value_type>();
    head_ = base;
    for (const auto &i : items) {
      push_back(i);
    }
  }
  List(const List &l) {
    auto *prev_node = new Node<value_type>(value_type());
    head_ = prev_node;
    Node<value_type> *current = l.head_->pNext;
    while (current != l.head_) {
      auto *new_node = new Node<value_type>(current->data);
      prev_node->pNext = new_node;
      new_node->pPrev = prev_node;
      prev_node = new_node;
      current = current->pNext;
      ++size_;
    }
    prev_node->pNext = head_;
    head_->pPrev = prev_node;
  }
  List(List &&l) {
    head_ = l.head_;
    size_ = l.size_;
    l.head_ = nullptr;
    l.size_ = 0;
  }
  ~List() {
    clear();
    delete head_;
  }

  // overload:
  auto operator=(List &&l) {
    clear();
    head_ = l.head_;
    size_ = l.size_;
    l.head_ = nullptr;
    l.size_ = 0;
    return *this;
  }

  // functions:
  iterator insert(iterator pos, const_reference value) {
    auto *new_node = new Node<value_type>(value);
    if (size_ == 0) {
      new_node->pPrev = head_;
      new_node->pNext = head_;
      head_->pNext = new_node;
      head_->pPrev = new_node;
    } else {
      Node<value_type> *next_node = pos.get_node();
      new_node->pPrev = next_node->pPrev;
      new_node->pNext = next_node;
      next_node->pPrev->pNext = new_node;
      next_node->pPrev = new_node;
    }
    ++size_;
    return iterator(new_node);
  }
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    iterator index = pos;
    for (const auto &i : {args...}) {
      index = insert(index, i);
      index++;
    }
    return index;
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    for (const auto &i : {args...}) {
      push_back(i);
    }
  }

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    List temp{args...};
    temp.reverse();
    for (const auto &i : temp) {
      push_front(i);
    }
  }

  void push_back(const_reference value) { insert(end(), value); }
  void push_front(const_reference value) { insert(begin(), value); }
  void erase(iterator pos) {
    Node<value_type> *toErase = pos.get_node();
    toErase->pPrev->pNext = toErase->pNext;
    toErase->pNext->pPrev = toErase->pPrev;
    delete toErase;
    --size_;
  }
  void pop_back() {
    iterator temp = end();
    --temp;
    erase(temp);
  }
  void pop_front() { erase(begin()); }
  void clear() {
    while (size_) {
      pop_front();
    }
  }
  void swap(List &other) {
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
  }

  void reverse() {
    for (size_type i = 0; i <= size(); ++i) {
      std::swap(head_->pPrev, head_->pNext);
      head_ = head_->pPrev;
    }
  }

  void unique() {  // удаляет дубликаты, которые идут друг за другом
    if (size_ > 1) {
      iterator current = begin();
      iterator next = current;
      ++next;
      while (next != end()) {
        if (*current == *next) {
          erase(next);
          next = current;
          ++next;
        } else {
          current = next;
          ++next;
        }
      }
    }
  }

  void splice(const_iterator pos, List &other) {
    Node<value_type> *previous = pos.get_node()->pPrev;
    Node<value_type> *current = const_cast<Node<value_type> *>(pos.get_node());
    Node<value_type> *other_first = other.begin().get_node();
    //        Node<value_type> *other_last = std::prev(other.end()).get_node();
    Node<value_type> *other_last = (other.end().get_node())->pPrev;

    current->pPrev = other_last;
    other_last->pNext = current;
    previous->pNext = other_first;
    other_first->pPrev = previous;

    other.head_->pPrev = other.head_->pNext = other.head_;
    size_ = size_ + other.size_;
    other.size_ = 0;
  }

  void merge(List &other) {
    if (this != &other) {
      iterator this_iterator = begin();
      iterator other_iterator = other.begin();
      while (!other.empty()) {
        if (this->empty() || this_iterator == end() ||
            *this_iterator > *other_iterator) {
          insert(this_iterator, *other_iterator);
          other.erase(other_iterator++);
          //          other_iterator++;
        } else {
          ++this_iterator;
        }
      }
    }
  }

  void sort() {
    if (size_ > 1) {
      Node<value_type> *first_node = head_->pNext;
      Node<value_type> *last_node = head_->pPrev;
      Node<value_type> *head = head_;

      first_node->pPrev = nullptr;
      last_node->pNext = nullptr;

      first_node = merge_sort(first_node);
      first_node->pPrev = head;
      head_->pNext = first_node;
      Node<value_type> *temp = head_;
      while (temp->pNext != nullptr) {
        temp = temp->pNext;
      }
      temp->pNext = head_;
      head_->pPrev = temp;
    }
  }

  Node<value_type> *merge_sort(Node<value_type> *head) {
    if (head == nullptr || head->pNext == nullptr) {
      return head;
    }
    Node<value_type> *slow = head;
    Node<value_type> *fast = head->pNext;
    while (fast != nullptr && fast->pNext != nullptr) {
      slow = slow->pNext;
      fast = fast->pNext->pNext;
    }
    Node<value_type> *second_half = slow->pNext;
    slow->pNext = nullptr;
    Node<value_type> *left = merge_sort(head);
    Node<value_type> *right = merge_sort(second_half);
    return merge_sorted(left, right);
  }

  Node<value_type> *merge_sorted(Node<value_type> *left,
                                 Node<value_type> *right) {
    if (left == nullptr) {
      return right;
    }
    if (right == nullptr) {
      return left;
    }
    Node<value_type> *result = nullptr;
    if (left->data <= right->data) {
      result = left;
      result->pPrev = nullptr;
      result->pNext = merge_sorted(left->pNext, right);
      result->pNext->pPrev = result;
    } else {
      result = right;
      result->pPrev = nullptr;
      result->pNext = merge_sorted(left, right->pNext);
      result->pNext->pPrev = result;
    }
    return result;
  }

  // old

  reference operator[](const int index) {
    Node<value_type> *current = this->head_;
    int counter = 0;
    while (current != nullptr) {
      if (counter == index) {
        return current->data;
      }
      current = current->pNext;
      counter++;
    }
    return current->data;
  }

};  // List
}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_