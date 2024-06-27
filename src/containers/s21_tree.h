#ifndef S21_CONTAINERS_CONTAINERS_S21_TREE_H_
#define S21_CONTAINERS_CONTAINERS_S21_TREE_H_

#include <utility>

namespace s21 {


//struct FakeNode {
//  FakeNode *parent;// = nullptr;
//
//  FakeNode() {
//      parent = nullptr;
//  }
//};

template <typename KeyType, typename ValueType>
struct Node {

  KeyType key;
  ValueType data;
  size_t height = 1;
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;

  Node() = default;
//  Node(KeyType NewKey, ValueType NewValue) :
//    key(NewKey),
//    data(NewValue) {}

}; // Node

template <typename KeyType, typename ValueType>
class Tree {
 public:

/* Tree Member type */
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


/* Tree Member functions */

  /* default constructor */
  Tree() noexcept : size_(0), root_(nullptr) {}

/* Tree Capacity */

  /* returns the number of elements */
  size_type size() noexcept {return size_;}

/* Tree Modifiers */

  /* checks whether the tree is empty or not */
  bool insert(const key_type new_key, const mapped_type value) { // TODO not bool
    bool ret_val = true;
    if (size_ == 0) {
      root_ = new Node<KeyType, ValueType>;  // InitNode();
      root_->parent = nullptr;
      root_->key = new_key;
      root_->data = value;
    } else {
      ret_val = FindInsert(root_, new_key, value);
    }
    if (ret_val) {
      ++size_;
    }
    return ret_val;
  }

/* Tree lookup */

  bool contains(const key_type& key) {

  }

  void printTree() {
    std::cout << "root value: " << root_->data << std::endl;
    if(root_->right != nullptr) {
      std::cout << root_->right->data << std::endl;
    }
  }


 private:
  //FakeNode *fake_node_;
  Node<KeyType, ValueType> *root_;
  size_t size_; // number of elements in the tree

  /* searches for the right place to insert a new node and inserts */
  bool FindInsert(Node<KeyType, ValueType>* root, const key_type new_key, const mapped_type value) {
    if (new_key == root->key) {
      return false;
    }
    auto* child = new Node<KeyType, ValueType>;
    if (new_key > root->key) {
      if (root->right != nullptr) {
        FindInsert(root->right, new_key, value);
      } else {
        root->right = child;
      }
    } else {
      if (root->left != nullptr) {
        FindInsert(root->left, new_key, value);
      } else {
        root->left = child;
      }
    }
    child->key = new_key;
    child->data = value;
    child->parent = root;
    if (root->left == nullptr || root->right == nullptr) {
      UpdateHeight(child->parent);
    }
    return true;
  }

  /* recursively updates the height of the branch */
  void UpdateHeight(Node<KeyType, ValueType>* node) {
    if (node!= nullptr) {
      ++node->height;
      UpdateHeight(node->parent);
    }
  }


}; // class Tree

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_TREE_H_

