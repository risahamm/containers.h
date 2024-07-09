#ifndef S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_
#define S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_

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
    reference operator*() const { return node_->data_; }
    ListIterator *operator->() const { return &(operator*()); }
    ListIterator &
    operator++() {  // ++x    (int y = ( ++x)); 'y' changed his value.
      node_ = node_->pNext;
      return *this;
    }
    // ListIterator operator++(int) {} // x++     ((int y = x)++); 'y' didn't
    // change his value.
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
    bool operator==(const ListIterator &other) {
        return node_ == other.node_;
    }
    bool operator!=(const ListIterator &other) {
        return node_ != other.node_;
    }
    // functions:
    Node<value_type> *get_node()const { return node_; }

   private:
    Node<value_type> *node_ = nullptr;
  };  // ListIterator

  using iterator = ListIterator<value_type>;
  using const_iterator = const ListIterator<value_type>;

  // Iterators
  iterator begin() { return iterator(head_->pNext); }
  iterator end() { return iterator(head_); }

    size_type size() { return size_; }

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

    ~List() {
        clear();
        delete head_;
    }

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

  void push_back( reference value) { insert(end(), value); }

  void push_front( reference value) { insert(begin(), value); }

  void erase(iterator pos) {
    Node<value_type> *toErase = pos.get_node();
    toErase->pPrev->pNext = toErase->pNext;
    toErase->pNext->pPrev = toErase->pPrev;
    delete toErase;
    --size_;
  }

  void pop_back() {  // переделать?
    erase(end() - 1);
  }

  void pop_front() { erase(begin()); }

  void clear() {
    while (size_) {
      pop_front();
    }
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
  }

  void removeAt(int index) {
    if (index == 0) {
      pop_front();
    } else {
      Node<value_type> *previous = this->head_;
      for (int i = 0; i < index - 1; i++) {
        previous = previous->pNext;
      }
      Node<value_type> *toDelete = previous->pNext;
      previous->pNext = toDelete->pNext;
      delete toDelete;
      --size_;
    }
  }

};  // List
}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_