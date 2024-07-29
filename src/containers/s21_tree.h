#ifndef S21_CONTAINERS_CONTAINERS_S21_TREE_H_
#define S21_CONTAINERS_CONTAINERS_S21_TREE_H_

#include <utility>

namespace s21 {

template <typename KeyType, typename ValueType>
struct Node {
  KeyType key;
  ValueType data;
  size_t height = 1;
  Node *parent = nullptr;
  Node *left = nullptr;
  Node *right = nullptr;

  Node() = default;
};  // struct Node
/*----------------------------------------------------------------------------*/

template <typename KeyType, typename ValueType>
class TreeIterator {
 public:
  using key_type = KeyType;
  using mapped_type = ValueType;
  using ptr = KeyType *;
  using ref = KeyType &;

  TreeIterator() = default;

  explicit TreeIterator(Node<key_type, mapped_type> *data) : node_(data) {}

  TreeIterator(const TreeIterator &other) { node_ = other.node_; }

  ~TreeIterator() = default;

  TreeIterator &operator=(const TreeIterator &other) {
    if (this == &other) {
      return *this;
    }
    node_ = other.node_;
    return *this;
  }

  /* access node key */
  ref operator*() {
    Node<key_type, mapped_type> *result = node_;
    if (result != nullptr) {
      result->key = node_->key;
    } else {
      throw std::out_of_range("Bad access.");
    }
    return result->key;
  }

  /* access node elements */
  Node<key_type, mapped_type> *operator->() {
    if (node_ != nullptr) {
      return node_;
    } else {
      throw std::out_of_range("Bad access.");
    }
  }

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
          node_ = temp;
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
          node_ = temp;
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

  bool operator==(const TreeIterator &other) { return (node_ == other.node_); }

  bool operator!=(const TreeIterator &other) { return !(node_ == other.node_); }

  bool operator<=(const TreeIterator &other) {
    return (this->node_->key <= other.node_->key);
  }

  bool IsNull() { return (node_ == nullptr) ? true : false; }

 private:  // TODO protected потому что наследование
  Node<key_type, mapped_type> *node_ = nullptr;

};  // class TreeIterator
/*----------------------------------------------------------------------------*/

template <typename KeyType, typename ValueType>
class Tree {
 public:
  /* TREE MEMBER TYPE */

  using key_type = KeyType;
  using mapped_type = ValueType;
  using value_type = std::pair<const KeyType, ValueType>;
  using reference = value_type &;
  using const_reference = const value_type &;
  //  using const_iterator;
  using size_type = std::size_t;

  /* TREE MEMBER FUNCTIONS */

  /* default constructor */
  Tree() noexcept : size_(0), root_(nullptr) {}

  /* copy constructor */
  Tree(const Tree &other) noexcept : size_(0) { *this = other; }

  /* move constructor */
  Tree(Tree &&other) noexcept : size_(0) { *this = std::move(other); }

  ~Tree() noexcept { clear(); }

  /* = overload, copy assignment */
  Tree &operator=(const Tree &other) noexcept {
    if (this != &other) {
      if (size_ != 0) {
        clear();
      }
      size_ = 0;
      CopyTree(other.root_);
    }
    return *this;
  }

  /* = overload, move assignment */
  Tree &operator=(Tree &&other) noexcept {
    if (this != &other) {
      if (size_ != 0) {
        clear();
      }
      size_ = other.size_;
      root_ = other.root_;
      other.root_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }
  /*--------------------------------------------------------------------------*/

  /* TREE ITERATORS */

  TreeIterator<KeyType, ValueType> begin() {
    if (size_ == 0) {
      throw std::out_of_range("Container is empty.");
    }
    return FindMinLeft(root_);
  }

  TreeIterator<KeyType, ValueType> end() {
    if (size_ == 0) {
      throw std::out_of_range("Container is empty.");
    }
    return ++FindMaxRight(root_);
  }
  /*--------------------------------------------------------------------------*/

  /* TREE ELEMENT ACCESS */

  /* access or insert specified element */
  mapped_type &operator[](const key_type &key) { return at(key); }

  mapped_type &at(const key_type key) {
    auto iterator = find(key);
    if (iterator.IsNull() == true) {
      throw std::out_of_range("Bad access. Index out of range.");
    }
    return iterator->data;
  }
  /*--------------------------------------------------------------------------*/

  /* TREE CAPACITY */

  /* returns the number of elements */
  size_type size() noexcept { return size_; }

  /* checks whether the container is empty */
  bool empty() noexcept { return !size_; }

  /* returns the maximum possible number of elements */
  size_type max_size() noexcept {
    return SIZE_MAX / sizeof(Node<KeyType, ValueType> *);
  }
  /*--------------------------------------------------------------------------*/

  /* TREE MODIFIERS */

  void clear() {
    if (size_ == 0) {
      return;
    }
    Destroy(root_);
    root_ = nullptr;
  }

  /* inserts node and returns iterator to where the element is in the container
   * and bool denoting whether the insertion took place */
  std::pair<TreeIterator<KeyType, ValueType>, bool> insert(
      const value_type &new_node) {
    std::pair<TreeIterator<KeyType, ValueType>, bool> result;
    key_type new_key = new_node.first;
    mapped_type value = new_node.second;
    return insert(new_key, value);
  }

  /* inserts value by key and returns iterator to where the element is in the
   * container and bool denoting whether the insertion took place */
  std::pair<TreeIterator<KeyType, ValueType>, bool> insert(
      const key_type &new_key, const mapped_type &value) {
    std::pair<TreeIterator<KeyType, ValueType>, bool> result;
    bool ret_val = true;

    if (size_ == 0) {
      root_ = new Node<KeyType, ValueType>;
      root_->parent = nullptr;
      root_->key = new_key;
      root_->data = value;
    } else {
      ret_val = FindInsert(root_, new_key, value);
    }
    if (ret_val) {
      ++size_;
    }

    result.first = find(new_key);
    result.second = ret_val;

    return result;
  }

  /* if no equivalent key exists, inserts an element. if the key already exists,
   * assigns new value to the element with such key */
  std::pair<TreeIterator<KeyType, ValueType>, bool> insert_or_assign(
      const key_type &key, const mapped_type &value) {
    /* if the key is unique, insert a node */
    if (contains(key) == false) {
      return insert(key, value);
    }

    /* if the key already exists, overwrite the value */
    at(key) = value;
    std::pair<TreeIterator<KeyType, ValueType>, bool> result;
    result.first = find(key);
    result.second = false;
    return result;
  }

  template <typename... Args>
  std::vector<std::pair<TreeIterator<KeyType, ValueType>, bool>> insert_many(
      Args &&...args) {
    std::vector<std::pair<TreeIterator<KeyType, ValueType>, bool>> result;
    (result.push_back(insert(std::forward<Args>(args))), ...);
//    insert_pack(result, std::forward<Args>(args)...);
    return result;
  }

  template <typename... Args>
  void insert_pack(
      std::vector<std::pair<TreeIterator<KeyType, ValueType>, bool>> &result,
      KeyType key, ValueType value, Args &&...args) {
    auto res = insert({key, value});
    result.push_back(res);
    if (sizeof...(args) > 0) {
      insert_many_helper(result, std::forward<Args>(args)...);
    }
  }

  /* if not found, returns exception */
  void erase(TreeIterator<KeyType, ValueType> pos) {
    if (size_ == 0) {
      throw std::out_of_range("No elements in the container.");
    }
    key_type key_to_remove = *pos;
    Node<KeyType, ValueType> *delete_node = Find(root_, key_to_remove);

    /* if the needed node is found */
    if (delete_node != nullptr) {
      /* if right subtree is not empty */
      if (delete_node->right != nullptr) {
        RedirectRight(delete_node);
        return;

        /* if left subtree is not empty */
      } else if (delete_node->left != nullptr) {
        RedirectLeft(delete_node);
        return;

        /* if delete_node is a leaf */
      } else {
        DeleteLeaf(delete_node);
      }

      /* if no elements left */
      if (size_ == 0) {
        root_ = nullptr;
      }

    } else {
      throw std::out_of_range("Key not found.");
    }
  }

  /* swaps the contents */
  void swap(Tree<key_type, mapped_type> &other) {
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
  }

  /* splices nodes from another container */
  void merge(Tree<key_type, mapped_type> &other) {
    if (this == &other || other.size_ == 0) {
      return;
    }
    TreeIterator<KeyType, ValueType> iter = other.begin();
    while (iter.IsNull() == false) {
      key_type key = iter->key;
      mapped_type value = iter->data;
      std::pair<TreeIterator<KeyType, ValueType>, bool> res;
      res = insert(key, value);
      ++iter;

      /* if insertion took place, remove the node */
      if (res.second == true) {
        other.erase(res.first);
      }
    }
  }
  /*--------------------------------------------------------------------------*/

  /* TREE LOOKUP */

  /* finds element with specific key */
  // TODO If no such element is found, end() iterator is returned.
  TreeIterator<KeyType, ValueType> find(const key_type &key_to_find) {
    if (size_ == 0) {
      throw std::out_of_range("No elements in the container.");
    }
    Node<KeyType, ValueType> *found = Find(root_, key_to_find);
    TreeIterator<KeyType, ValueType> result(found);

    return result;
  }

  /* checks if there is an element with key equivalent to key in the container
   */
  bool contains(const key_type &key) noexcept {
    if (size_ == 0) {
      return false;
    }
    bool ret_val = false;
    Node<KeyType, ValueType> *result = Find(root_, key);
    if (result != nullptr) {
      ret_val = true;
    }
    return ret_val;
  }
  /*--------------------------------------------------------------------------*/

 private:
  size_t size_; /* number of elements in the tree */
  Node<KeyType, ValueType> *root_;
  /*--------------------------------------------------------------------------*/

  /* recursively searches for the right place to insert a new node and inserts
   */
  bool FindInsert(Node<KeyType, ValueType> *root, const key_type new_key,
                  const mapped_type value) {
    bool ret_val = true;
    Node<KeyType, ValueType> **direction = Compare(&root, new_key);

    /* if the key already exists */
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
      UpdateHeight(child->parent);
      Balance(child->parent);
    }
    return ret_val;
  }

  /* compares the keys and returns a pointer to a left or right child. if the
   * key is equal to the current node key, returns a pointer to the current
   * node */
  Node<KeyType, ValueType> **Compare(Node<KeyType, ValueType> **root,
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

  /* recursively updates the height of the branch bottom-up */
  void UpdateHeight(Node<KeyType, ValueType> *node) {
    if (node != nullptr) {
      size_t l_height = getHeight(node->left);
      size_t r_height = getHeight(node->right);
      node->height = (l_height > r_height ? l_height : r_height) + 1;
      UpdateHeight(node->parent);
    }
  }

  /* recursively searches for the key in the tree, returns a pointer, if not
   * found, returns nullptr */
  Node<KeyType, ValueType> *Find(Node<KeyType, ValueType> *root,
                                 const key_type key_to_find) {
    Node<KeyType, ValueType> *result = nullptr;
    Node<KeyType, ValueType> **direction = Compare(&root, key_to_find);
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

  /* returns the height of a node */
  size_t getHeight(Node<KeyType, ValueType> *node) {
    size_t ret_val = 0;
    if (node != nullptr) {
      ret_val = node->height;
    }
    return ret_val;
  }

  /* if disbalanced, recursively rebalances the tree relative to the parent node
   * of a newly added node */
  void Balance(Node<KeyType, ValueType> *node) {
    if (node != nullptr) {
      if (BalanceFactor(node) == 2) {
        if (BalanceFactor(node->left) == -1) {
          RotateLeft(node->left);
        }
        RotateRight(node);
      } else if (BalanceFactor(node) == -2) {
        if (BalanceFactor(node->right) == 1) {
          RotateRight(node->right);
        }
        RotateLeft(node);
      }

      UpdateHeight(node);
      Balance(node->parent);
    }
  }

  /* rotates relative to the disbalanced node */
  void RotateRight(Node<KeyType, ValueType> *node) {
    Node<KeyType, ValueType> *new_root = node->left;
    node->left = new_root->right;
    if (new_root->right != nullptr) {
      new_root->right->parent = node;
    }
    if (node->parent != nullptr) {
      (new_root->key > node->parent->key) ? node->parent->right = new_root
                                          : node->parent->left = new_root;
    }
    new_root->parent = node->parent;
    new_root->right = node;
    node->parent = new_root;
    UpdateHeight(node);
    UpdateHeight(new_root);
    if (new_root->parent == nullptr) {
      root_ = new_root;
    }
  }

  /* rotates relative to the disbalanced node */
  void RotateLeft(Node<KeyType, ValueType> *node) {
    Node<KeyType, ValueType> *new_root = node->right;
    node->right = new_root->left;
    if (new_root->left != nullptr) {
      new_root->left->parent = node;
    }
    if (node->parent != nullptr) {
      (new_root->key > node->parent->key) ? node->parent->right = new_root
                                          : node->parent->left = new_root;
    }
    new_root->parent = node->parent;
    new_root->left = node;
    node->parent = new_root;
    UpdateHeight(node);
    UpdateHeight(new_root);
    if (new_root->parent == nullptr) {
      root_ = new_root;
    }
  }

  /* returns a pointer to a node with min value of the right subtree */
  Node<KeyType, ValueType> *FindMinRight(Node<KeyType, ValueType> *node) {
    Node<KeyType, ValueType> *result = nullptr;
    if (node->left != nullptr) {
      result = FindMinRight(node->left);
    } else {
      result = node;
    }
    return result;
  }

  /* removes the node and reappoints min node in the right subtree to where
   * erase_node had been */
  void RedirectRight(Node<KeyType, ValueType> *erase_node) {
    Node<KeyType, ValueType> *min_node = FindMinRight(erase_node->right);

    /* if distance between erase_node and min_node > 1 */
    if (min_node->parent != erase_node) {
      min_node->parent->left = min_node->right;
      min_node->left = erase_node->left;
      min_node->right = erase_node->right;
      min_node->parent = erase_node->parent;
      if (erase_node->parent != nullptr) {
        erase_node->parent->right = min_node;
      }
      erase_node->right->parent = min_node;
      erase_node->left->parent = min_node;

    } else {
      /* if distance between erase_node and min_node == 1 */
      if (erase_node->parent != nullptr) {
        (min_node->key > erase_node->parent->key)
            ? erase_node->parent->right = min_node
            : erase_node->parent->left = min_node;
      }
      min_node->left = erase_node->left;
      if (erase_node->left != nullptr) {
        erase_node->left->parent = min_node;
      }
      min_node->parent = erase_node->parent;
    }

    if (min_node->parent == nullptr) {
      root_ = min_node;
    }
    UpdateHeight(min_node);
    Balance(min_node);
    delete erase_node;
    --size_;
  }

  /* if right subtree is empty, returns a pointer to left subtree of erase_node
   */
  void RedirectLeft(Node<KeyType, ValueType> *erase_node) {
    Node<KeyType, ValueType> *replace_node = erase_node->left;
    replace_node->parent = erase_node->parent;
    if (erase_node->parent != nullptr) {
      (erase_node->key > erase_node->parent->key)
          ? erase_node->parent->right = replace_node
          : erase_node->parent->left = replace_node;
    }
    if (replace_node->parent == nullptr) {
      root_ = replace_node;
    }
    UpdateHeight(replace_node);
    Balance(replace_node);
    delete erase_node;
    --size_;
  }

  void DeleteLeaf(Node<KeyType, ValueType> *erase_node) {
    if (erase_node->parent != nullptr) {
      (erase_node->key > erase_node->parent->key)
          ? erase_node->parent->right = nullptr
          : erase_node->parent->left = nullptr;
    }
    --size_;
    if (size_ == 0) {
      root_ = nullptr;
    }
    delete erase_node;
  }

  /* returns iterator to min element in the left subtree */
  TreeIterator<KeyType, ValueType> FindMinLeft(Node<KeyType, ValueType> *node) {
    TreeIterator<KeyType, ValueType> result(node);
    if (node->left != nullptr) {
      result = FindMinLeft(node->left);
    }
    return result;
  }

  /* returns iterator to max element in the right subtree */
  TreeIterator<KeyType, ValueType> FindMaxRight(
      Node<KeyType, ValueType> *node) {
    TreeIterator<KeyType, ValueType> result(node);
    if (node->right != nullptr) {
      result = FindMaxRight(node->right);
    }
    return result;
  }

  /* recursively deletes nodes on the right and on the left */
  void Destroy(Node<KeyType, ValueType> *node) {
    if (node == nullptr) {
      return;
    }

    Destroy(node->left);
    Destroy(node->right);
    if (node->left == nullptr && node->right == nullptr) {
      if (node->parent != nullptr) {
        (node->key > node->parent->key) ? node->parent->right = nullptr
                                        : node->parent->left = nullptr;
      }

      delete node;
      node = nullptr;
      --size_;
    }
  }

  /* recursively inserts nodes from other tree */
  void CopyTree(Node<KeyType, ValueType> *other_node) {
    if (other_node == nullptr) {
      return;
    }
    insert(other_node->key, other_node->data);
    CopyTree(other_node->left);
    CopyTree(other_node->right);
  }

};  // class Tree

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_TREE_H_
