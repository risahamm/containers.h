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

  Node() = default;
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
    fake_node_ = new FakeNode[sizeof(FakeNode)];
  }

  size_type size() noexcept {return size_;}

  bool insert(const key_type new_key, const mapped_type value) {
    if (size_ == 0) {
      root_ = InitNode();
      root_->parent = fake_node_;
      root_->key = new_key;
      root_->data = value;
    } else {
      FindInsert(root_, new_key, value);
    }
    ++size_;
    return 1;
  }

  void printTree() {
    std::cout << "root value: " << root_->data << std::endl;
    if(root_->right != nullptr) {
      std::cout << root_->right->data << std::endl;
    }
  }

  void FindInsert(Node<KeyType, ValueType> *root, const key_type new_key, const mapped_type value) {
    Node<KeyType, ValueType> *child;
    child = new_key > root->key ? root->right : root->left;
     if (child != nullptr) {
      FindInsert(child, new_key, value);
     } else {

      child = InitNode();
      child->key = new_key;
      child->data = value;
      ++root->height;
     }
  }

 private:
  FakeNode *fake_node_;
  Node<KeyType, ValueType> *root_;
  size_t size_; // number of elements in the tree

  Node<key_type, mapped_type> *InitNode() {
    auto *new_node = new Node<key_type, mapped_type>[sizeof(Node<key_type, mapped_type>)];
    return new_node;
  }

}; // class Tree

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_TREE_H_

