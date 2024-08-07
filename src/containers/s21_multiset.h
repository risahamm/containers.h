#ifndef S21_CONTAINERS_CONTAINERS_S21_MULTISET_H_
#define S21_CONTAINERS_CONTAINERS_S21_MULTISET_H_

#include "s21_tree.h"

namespace s21 {

template <typename KeyType>
class Multiset {
 public:
  /* MULTISET MEMBER TYPE */

  using key_type = KeyType;
  using reference = key_type &;
  using const_reference = const key_type &;
  using iterator = TreeIterator<KeyType, unsigned int>;
  using const_iterator = ConstIterator<key_type, unsigned int>;
  using size_type = std::size_t;

 private:
  Tree<KeyType, unsigned int> tree_;
  /*--------------------------------------------------------------------------*/

 public:
  /* MULTISET MEMBER FUNCTIONS */

  /* default constructor */
  Multiset() noexcept : tree_() {}

  /* copy constructor */
  Multiset(const Multiset &other) noexcept : tree_(other.tree_) {}

  /* move constructor */
  Multiset(Multiset &&other) noexcept : tree_(std::move(other.tree_)) {}

  Multiset(std::initializer_list<key_type> const &items) {
    for (auto &item : items) {
      insert(item);
    }
  }

  /* destructor */
  ~Multiset() noexcept { clear(); }

  /* = overload, copy assignment */
  Multiset &operator=(const Multiset &other) noexcept {
    if (this == &other) {
      return *this;
    }
    tree_ = other.tree_;
    return *this;
  }

  /* = overload, move assignment */
  Multiset &operator=(Multiset &&other) noexcept {
    if (this == &other) {
      return *this;
    }
    tree_ = std::move(other.tree_);
    return *this;
  }
  /*--------------------------------------------------------------------------*/

  /* MULTISET ITERATORS */

  iterator begin() { return tree_.begin(); }

  /* returns an iterator to the element following the last element of the map */
  iterator end() { return tree_.end(); }
  /*--------------------------------------------------------------------------*/

  /* MULTISET CAPACITY */

  /* checks whether the container is empty */
  bool empty() noexcept { return tree_.empty(); }

  /* returns the number of elements */
  size_t size() noexcept { return tree_.size(); }

  /* returns the maximum possible number of elements */
  size_type max_size() noexcept { return tree_.max_size(); }
  /*--------------------------------------------------------------------------*/

  /* MULTISET MODIFIERS */

  /* clears the contents */
  void clear() { tree_.clear(); }

  iterator insert(const key_type &key) { return tree_.InsertMultiset(key); }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    (result.push_back(std::pair<iterator, bool>(
        (insert(std::forward<Args>(args)), ...), true)));
    return result;
  }

  /* if not found, returns exception */
  void erase(iterator pos) { tree_.erase(pos); }

  /* swaps the contents */
  void swap(Multiset &other) { tree_.swap(other.tree_); }

  /* splices nodes from another container */
  void merge(Multiset &other) { tree_.merge(other.tree_); }
  /*--------------------------------------------------------------------------*/

  /* MULTISET LOOKUP */

  /* returns the number of elements matching a specific key */
  size_type count(const key_type &key) { return tree_.count(key); }

  /* finds element with specific key. if no such element is found, end()
   * iterator is returned */
  iterator find(const key_type &key) { return tree_.find(key); }

  /* checks if there is an element with key equivalent to key in the container
   */
  bool contains(const key_type &key) noexcept { return tree_.contains(key); }

  /* returns a range of elements from lower_bound to upper_bound */
  std::pair<iterator, iterator> equal_range(const key_type &key) {
    std::pair<iterator, iterator> result;
    result.first = lower_bound(key);
    result.second = upper_bound(key);
    return result;
  }

  /* returns an iterator to the first element greater than the given key. if no
   * such element is found, end() iterator is returned */
  iterator upper_bound(const key_type &key) { return tree_.upper_bound(key); }

  /* returns an iterator to the first element not less than the given key. if no
   * such element is found, end() iterator is returned */
  iterator lower_bound(const key_type &key) { return tree_.lower_bound(key); }
  /*--------------------------------------------------------------------------*/

};  // class Multiset

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_MULTISET_H_