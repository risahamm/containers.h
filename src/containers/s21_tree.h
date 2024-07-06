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
  using ptr = KeyType *;
  using ref = KeyType &;

  class TreeIterator {
   public:
    TreeIterator() = default;
    explicit TreeIterator(Node<key_type, mapped_type> *data) : node_(data) {}

    TreeIterator(const TreeIterator &other) { node_ = other.node_; }

    TreeIterator &operator=(const TreeIterator &other) {
      if (this == &other) {
        return *this;
      }
      node_ = other.node_;
      return *this;
    }

    ref operator*() {  // TODO add exception
      Node<key_type, mapped_type> *result = node_;
      if (result != nullptr) {
        result->key = node_->key;
      } else {
        throw std::out_of_range("Bad access.");
      }
      return result->key;
    }

    Node<key_type, mapped_type> *operator->() { return node_; }

    TreeIterator &operator++() {  // prefix
      if (node_ != nullptr) {
        if (node_->right != nullptr) {
          node_ = node_->right;
          while (node_->left != nullptr) {
            node_ = node_->left;
          }
        } else {
          Node<key_type, mapped_type> *temp = node_->parent;
          while (temp != nullptr && node_ == temp->right) {
            node_->temp;
            temp = temp->parent;
          }
          node_ = temp;
        }
      }
      return *this;
    }

    TreeIterator &operator--() {  // prefix
      if (node_ != nullptr) {
        if (node_->left != nullptr) {
          node_ = node_->left;
          while (node_->right != nullptr) {
            node_ = node_->right;
          }
        } else {
          Node<key_type, mapped_type> *temp = node_->parent;
          while (temp != nullptr && node_ == temp->left) {
            node_->temp;
            temp = temp->parent;
          }
          node_ = temp;
        }
      }
      return *this;
    }

    TreeIterator operator++(int) {  // postfix
      TreeIterator res(*this);
      ++(*this);
      return res;
    }

    TreeIterator operator--(int) {  // postfix
      TreeIterator res(*this);
      --(*this);
      return res;
    }

    bool operator==(const TreeIterator &other) { return (node_ = other.node_); }

    bool operator!=(const TreeIterator &other) {
      return !(node_ = other.node_);
    }

   private:  // TODO protected потому что наследование
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
    std::cout << BalanceFactor(root_) << '\n';  // TODO remove
    return ret_val;
  }

  /* Tree lookup */

  /* finds element with specific key */
  TreeIterator find(const key_type key_to_find) {  // TODO not bool
    Node<KeyType, ValueType> *found = Find(root_, key_to_find);
    TreeIterator result(found);

    return result;
  }

  /* checks if there is an element with key equivalent to key in the container
   */
  bool contains(const key_type &key) {
    bool ret_val = false;
    Node<KeyType, ValueType> *result = Find(root_, key);
    if (result != nullptr) {
      ret_val = true;
    }
    return ret_val;
  }

 private:
  // FakeNode *fake_node_;
  size_t size_;  // number of elements in the tree
  Node<KeyType, ValueType> *root_;

  /* recursively searches for the right place to insert a new node and inserts
   */
  bool FindInsert(Node<KeyType, ValueType> *root, const key_type new_key,
                  const mapped_type value) {
    bool ret_val = true;
    Node<KeyType, ValueType> **direction = Comparator(&root, new_key);
    if (*direction == root) {
      return false;
    }
    if (*direction != nullptr) {
      ret_val = FindInsert(*direction, new_key, value);
    } else {
      auto *child = new Node<KeyType, ValueType>;
      *direction = child;
      child->key = new_key;
      child->data = value;
      child->parent = root;
      //      if (root->left == nullptr || root->right == nullptr) {
      UpdateHeight(child->parent);
      //      }
    }
    return ret_val;
  }

  /* compares the keys and returns a pointer to a left or right child. if the
   * key is equal to the current node key, returns a pointer to the current
   * node */
  Node<KeyType, ValueType> **Comparator(Node<KeyType, ValueType> **root,
                                        const key_type new_key) {
    Node<KeyType, ValueType> **result = nullptr;
    if (new_key == (*root)->key) {
      result = root;
    } else if (new_key > (*root)->key) {
      result = &(*root)->right;
    } else if (new_key < (*root)->key) {
      result = &(*root)->left;
    }
    return result;
  }

  /* recursively updates the height of the branch */
  void UpdateHeight(Node<KeyType, ValueType> *node) {
    if (node != nullptr) {
      size_t l_height = getHeight(node->left);
      size_t r_height = getHeight(node->right);
      ;
      node->height = (l_height > r_height ? l_height : r_height) + 1;
      UpdateHeight(node->parent);
    }
  }

  /* recursively searches for the key in the tree, returns a pointer  */
  Node<KeyType, ValueType> *Find(Node<KeyType, ValueType> *root,
                                 const key_type key_to_find) {
    Node<KeyType, ValueType> *result = nullptr;
    Node<KeyType, ValueType> **direction = Comparator(&root, key_to_find);
    if (*direction == root) {
      result = root;
    } else if (*direction != nullptr) {
      result = Find(*direction, key_to_find);
    }
    return result;
  }

  /* returns the difference between the heights of the left and right subtrees
   */
  int BalanceFactor(Node<KeyType, ValueType> *node) {
    int ret_val = 0;
    if (node != nullptr) {
      ret_val = (getHeight(node->left) - getHeight(node->right));
    }
    return ret_val;
  }

  size_t getHeight(Node<KeyType, ValueType> *node) {
    size_t ret_val = 0;
    if (node != nullptr) {
      ret_val = node->height;
    }
    return ret_val;
  }

};  // class Tree

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_TREE_H_
