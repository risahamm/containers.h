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
  // using const_iterator = typename Tree<key_type, value_type>::TreeItrator;
  using size_type = std::size_t;

  /* MAP MEMBER FUNCTIONS */

  /* default constructor */
  Map() noexcept : tree_() {}

  /* copy constructor */
  Map(const Map &other) noexcept { tree_(other.tree_); }

  /* move constructor */
  Map(Map &&other) noexcept { tree_(std::move(other.tree_)); }

  /* destructor */
  ~Map() noexcept {}

  /* = overload, move assignment */
  Map &operator=(Map &&other) noexcept {
    if (this == &other) {
      return *this;
    }
    tree_(std::move(other.tree_));
    return *this;
  }

  /* MAP ELEMENT ACCESS */

  /* access or insert specified element */
  mapped_type &at(const key_type key) { return tree_.at(key); }

  mapped_type &operator[](const key_type &key) { return at(key); }

  /* MAP ITERATORS */

  iterator begin() { return tree_.begin(); }

  iterator end() { return tree_.end(); }

  /* MAP CAPACITY */

  /* checks whether the container is empty */
  bool empty() noexcept { return tree_.empty(); }

  /* MAP MODIFIERS */

  /* inserts value by key and returns iterator to where the element is in the
   * container and bool denoting whether the insertion took place */
  std::pair<iterator, bool> insert(const key_type &new_key,
                                   const mapped_type &value) {
    return tree_.insert(new_key, value);
  }

 private:
  Tree<KeyType, ValueType> tree_;
};  // class Map

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_MAP_H_