#ifndef S21_CONTAINERS_CONTAINERS_S21_TREE_H_
#define S21_CONTAINERS_CONTAINERS_S21_TREE_H_

#include <utility>

namespace s21 {

// struct FakeNode {
//   FakeNode *parent;// = nullptr;
//
//   FakeNode() {
//       parent = nullptr;
//   }
// };

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

};  // Node

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
    TreeIterator(Node<key_type, mapped_type> data) : node_(data) {}

   private:
    Node<key_type, mapped_type> *node_ = nullptr;

  };  // class TreeIterator

  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = TreeIterator;
  //  using const_iterator;
  using size_type = std::size_t;

  /* Tree Member functions */

  /* default constructor */
  Tree() noexcept : size_(0), root_(nullptr) {}

  /* Tree Capacity */

  /* returns the number of elements */
  size_type size() noexcept { return size_; }

  /* Tree Modifiers */

  /* inserts value by key and returns iterator to where the element is in the
   * container and bool denoting whether the insertion took place */
  bool insert(const key_type new_key,
              const mapped_type value) {  // TODO not bool
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

  //  bool contains(const key_type& key) {
  //
  //  }

  /* finds element with specific key */
  bool find(const key_type key_to_find) {  // TODO not bool
    return Find(root_, key_to_find);
  }


 private:
  // FakeNode *fake_node_;
  Node<KeyType, ValueType> *root_;
  size_t size_;  // number of elements in the tree

  /* searches for the right place to insert a new node and inserts */
  bool FindInsert(Node<KeyType, ValueType> *root, const key_type new_key,
                  const mapped_type value) {
    if (new_key == root->key) {
      return false;
    }
    bool ret_val = true;
    auto *child = new Node<KeyType, ValueType>;
    if (new_key > root->key) {
      if (root->right != nullptr) {
        ret_val = FindInsert(root->right, new_key, value);
      } else {
        root->right = child;
      }
    } else {
      if (root->left != nullptr) {
        ret_val = FindInsert(root->left, new_key, value);
      } else {
        root->left = child;
      }
    }
    if (ret_val) {
      child->key = new_key;
      child->data = value;
      child->parent = root;
      if (root->left == nullptr || root->right == nullptr) {
        UpdateHeight(child->parent);
      }
    }
    //    else {
    //      child.destroy(); // TODO потом добавить деструктор
    //    }
    return ret_val;
  }

  /* recursively updates the height of the branch */
  void UpdateHeight(Node<KeyType, ValueType> *node) {
    if (node != nullptr) {
      ++node->height;
      UpdateHeight(node->parent);
    }
  }

  bool Find(Node<KeyType, ValueType> *root, const key_type key_to_find) {
    if(root->key == key_to_find) {
      return true;
    }
    bool ret_val = false;
    if(key_to_find < root->key && root->left != nullptr) {
      ret_val = Find(root->left, key_to_find);
    } else if (key_to_find > root->key && root->right != nullptr){
      ret_val = Find(root->right, key_to_find);
    }
    return ret_val;
  }

};  // class Tree

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_TREE_H_
