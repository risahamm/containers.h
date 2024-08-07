#ifndef S21_CONTAINERS_CONTAINERS_S21_MAP_H_
#define S21_CONTAINERS_CONTAINERS_S21_MAP_H_

#include "s21_tree.h"

namespace s21 {

template <typename KeyType, typename ValueType>
class Map {
 public:
  /* MAP MEMBER TYPE */

  using key_type = KeyType;
  using mapped_type = ValueType;
  using value_type = std::pair<const KeyType, ValueType>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = TreeIterator<KeyType, ValueType>;
  using const_iterator = ConstIterator<key_type, value_type>;
  using size_type = std::size_t;

 private:
  Tree<KeyType, ValueType> tree_;
  /*--------------------------------------------------------------------------*/

 public:
  /* MAP MEMBER FUNCTIONS */

  /* default constructor */
  Map() noexcept : tree_() {}

  /* copy constructor */
  Map(const Map &other) noexcept : tree_(other.tree_) {}

  /* move constructor */
  Map(Map &&other) noexcept : tree_(std::move(other.tree_)) {}

  Map(std::initializer_list<value_type> const &items) {
    for (auto &item : items) {
      tree_.insert(item);
    }
  }

  /* destructor */
  ~Map() noexcept { clear(); }

  /* = overload, copy assignment */
  Map &operator=(const Map &other) noexcept {
    if (this == &other) {
      return *this;
    }
    tree_ = other.tree_;
    return *this;
  }

  /* = overload, move assignment */
  Map &operator=(Map &&other) noexcept {
    if (this == &other) {
      return *this;
    }
    tree_ = std::move(other.tree_);
    return *this;
  }
  /*--------------------------------------------------------------------------*/

  /* MAP ELEMENT ACCESS */

  /* access or insert specified element */
  mapped_type &at(const key_type key) { return tree_.at(key); }

  mapped_type &operator[](const key_type &key) { return tree_[key]; }
  /*--------------------------------------------------------------------------*/

  /* MAP ITERATORS */

  iterator begin() { return tree_.begin(); }

  /* returns an iterator to the element following the last element of the map */
  iterator end() { return tree_.end(); }
  /*--------------------------------------------------------------------------*/

  /* MAP CAPACITY */

  /* checks whether the container is empty */
  bool empty() noexcept { return tree_.empty(); }

  /* returns the number of elements */
  size_t size() noexcept { return tree_.size(); }

  /* returns the maximum possible number of elements */
  size_type max_size() noexcept { return tree_.max_size(); }
  /*--------------------------------------------------------------------------*/

  /* MAP MODIFIERS */

  /* clears the contents */
  void clear() { tree_.clear(); }

  /* inserts node and returns iterator to where the element is in the container
   * and bool denoting whether the insertion took place */
  std::pair<iterator, bool> insert(const value_type &new_node) {
    return tree_.insert(new_node);
  }

  std::pair<iterator, bool> insert(const key_type &new_key,
                                   const mapped_type &value) {
    return tree_.insert(new_key, value);
  }

  /* if no equivalent key exists, inserts an element. if the key already exists,
   * assigns new value to the element with such key */
  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const mapped_type &value) {
    return tree_.insert_or_assign(key, value);
  }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    (result.push_back(insert(std::forward<Args>(args).first,
                             std::forward<Args>(args).second)),
     ...);
    return result;
  }

  /* if not found, returns exception */
  void erase(iterator pos) { tree_.erase(pos); }

  /* swaps the contents */
  void swap(Map &other) { tree_.swap(other.tree_); }

  /* splices nodes from another container */
  void merge(Map &other) { tree_.merge(other.tree_); }
  /*--------------------------------------------------------------------------*/

  /* MAP LOOKUP */

  /* checks if there is an element with key equivalent to key in the container
   */
  bool contains(const key_type &key) noexcept { return tree_.contains(key); }
  /*--------------------------------------------------------------------------*/

};  // class Map

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_MAP_H_