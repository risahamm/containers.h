#ifndef S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_
#define S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_

namespace s21 {
template <typename T>
class List {
 public:
  List();
  ~List();

  void push_back(T data);
  int GetSize() { return Size; }
  T &operator[](const int index);
  void pop_front();
  void clear();
  void push_front(T data);
  //  void pop_back();
  void insert(T value, int index);
  void removeAt(int index);

 private:
  template <typename T1>
  class Node {
   public:
    Node *pNext;
    T data;

    Node(T data = T(), Node *pNext = nullptr) {
      this->data = data;
      this->pNext = pNext;
    }
  };
  Node<T> *head;
  int Size;
};

template <typename T>
List<T>::List() {
  Size = 0;
  head = nullptr;
}

template <typename T>
List<T>::~List() {
  clear();
}

template <typename T>
void List<T>::push_back(T data) {
  if (head == nullptr) {
    head = new Node<T>(data);
  } else {
    Node<T> *current = this->head;
    while (current->pNext != nullptr) {
      current = current->pNext;
    }
    current->pNext = new Node<T>(data);
  }
  Size++;
}

template <typename T>
T &List<T>::operator[](const int index) {
  Node<T> *current = this->head;
  int counter = 0;
  while (current != nullptr) {
    if (counter == index) {
      return current->data;
    }
    current = current->pNext;
    counter++;
  }
}

template <typename T>
void List<T>::pop_front() {
  Node<T> *temp = head;
  head = head->pNext;
  delete temp;
  Size--;
}

template <typename T>
void List<T>::clear() {
  while (Size) {
    pop_front();
  }
}

template <typename T>
void List<T>::push_front(T data) {
  head = new Node<T>(data, head);
  Size++;
}

// template <typename T>
// void List<T>::pop_back() {
//
// }

template <typename T>
void List<T>::insert(T value, int index) {
  if (index == 0) {
    push_front(value);
  } else {
    Node<T> *previous = this->head;
    for (int i = 0; i < index - 1; i++) {
      previous = previous->pNext;
    }
    Node<T> *newNode = new Node<T>(value, previous->pNext);
    previous->pNext = newNode;
    Size++;
  }
}

template <typename T>
void List<T>::removeAt(int index) {
  if (index == 0) {
    pop_front();
  } else {
    Node<T> *previous = this->head;
    for (int i = 0; i < index - 1; i++) {
      previous = previous->pNext;
    }
    Node<T> *toDelete = previous->pNext;
    previous->pNext = toDelete->pNext;
    delete toDelete;
    Size--;
  }
}

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_VECTOR_H_