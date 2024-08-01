#ifndef S21_CONTAINERS_CONTAINERS_S21_SET_H_
#define S21_CONTAINERS_CONTAINERS_S21_SET_H_

#include "s21_tree.h"

namespace s21 {

template <typename KeyType>
class Set {
 public:
  /* SET MEMBER TYPE */

  using key_type = KeyType;
  using reference = key_type &;
  using const_reference = const key_type &;
  using iterator = TreeIterator<KeyType, unsigned int>;
  using const_iterator = ConstIterator<key_type, unsigned int>;
  using size_type = std::size_t;
  /*--------------------------------------------------------------------------*/

  /* SET MEMBER FUNCTIONS */

  /* default constructor */
  Set() noexcept : tree_() {}

  /* copy constructor */
  Set(const Set &other) noexcept : tree_(other.tree_) {}

  /* move constructor */
  Set(Set &&other) noexcept : tree_(std::move(other.tree_)) {}

  Set(std::initializer_list<key_type> const &items) {
    for (auto &item : items) {
      insert(item);
    }
  }

  /* destructor */
  ~Set() noexcept {}

  /* = overload, copy assignment */
  Set &operator=(const Set &other) noexcept {
    if (this == &other) {
      return *this;
    }
    tree_ = other.tree_;
    return *this;
  }

  /* = overload, move assignment */
  Set &operator=(Set &&other) noexcept {
    if (this == &other) {
      return *this;
    }
    tree_ = std::move(other.tree_);
    return *this;
  }
  /*--------------------------------------------------------------------------*/

  /* SET ITERATORS */

  iterator begin() { return tree_.begin(); }

  /* returns an iterator to the element following the last element of the map */
  iterator end() { return tree_.end(); }
  /*--------------------------------------------------------------------------*/

  /* SET CAPACITY */

  /* checks whether the container is empty */
  bool empty() noexcept { return tree_.empty(); }

  /* returns the number of elements */
  size_t size() noexcept { return tree_.size(); }

  /* returns the maximum possible number of elements */
  size_type max_size() noexcept { return tree_.max_size(); }
  /*--------------------------------------------------------------------------*/

  /* SET MODIFIERS */

  /* clears the contents */
  void clear() { tree_.clear(); }

  /* inserts node and returns iterator to where the element is in the container
   * and bool denoting whether the insertion took place */
  std::pair<iterator, bool> insert(const key_type &key) {
    return tree_.insert(key, 0);
  }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    return (tree_.insert_many_set(std::forward<Args>(args)...));
  }

  /* if not found, returns exception */
  void erase(iterator pos) { tree_.erase(pos); }

  /* swaps the contents */
  void swap(Set &other) { tree_.swap(other.tree_); }

  /* splices nodes from another container */
  void merge(Set &other) { tree_.merge(other.tree_); }
  /*--------------------------------------------------------------------------*/

  /* SET LOOKUP */

  /* finds element with specific key. if no such element is found, end()
   * iterator is returned */
  iterator find(const key_type &key) { return tree_.find(key); }

  /* checks if there is an element with key equivalent to key in the container
   */
  bool contains(const key_type &key) noexcept { return tree_.contains(key); }
  /*--------------------------------------------------------------------------*/

 private:
  Tree<KeyType, unsigned int> tree_;

};  // class Set

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_SET_H_