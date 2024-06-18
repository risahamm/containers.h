#ifndef S21_CONTAINERS_CONTAINERS_S21_TREE_H_
#define S21_CONTAINERS_CONTAINERS_S21_TREE_H_

#include <utility>

namespace s21 {


struct FakeNode {
  FakeNode *parent = nullptr;

  FakeNode() = default;
};

template <typename KeyType, typename ValueType>
struct Node : FakeNode {

  KeyType key;
  ValueType data;
  size_t height = 1;
//  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;

  Node(KeyType NewKey, ValueType NewValue) :
    key(NewKey),
    data(NewValue) {}

}; // Node

template <typename KeyType, typename ValueType>
class Tree {
 public:

// Tree Member type
  using key_type = KeyType;
  using mapped_type = ValueType;
  using value_type = std::pair<const KeyType, ValueType>;

  class TreeIterator {
   public:
    TreeIterator() = default;
    TreeIterator(Node<key_type, mapped_type> data) : node_(data){}

   private:
    Node< key_type, mapped_type> *node_ = nullptr;

  }; // class TreeIterator

  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = TreeIterator;
//  using const_iterator;
  using size_type = std::size_t;


// Tree Member functions

  /* default constructor */
  Tree() noexcept : size_(0)
  {
    FakeNode fake_node;
    root_->parent = &fake_node;
  }

  size_type size() noexcept {return size_;}

  bool insert(const key_type key, const mapped_type value) {
    if(size_ == 0) {
      root_->data = value;
    }
    return 1;
  }

  void printTree() {
    std::cout << "root value: " << root_->data << std::endl;
    if(root_->right != nullptr) {
      std::cout << root_->right->data << std::endl;
    }
  }

 private:
  Node<KeyType, ValueType> *root_;
  size_t size_; // number of elements in the tree

}; // class Tree

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_TREE_H_

