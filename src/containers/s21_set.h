#ifndef S21_CONTAINERS_CONTAINERS_S21_SET_H_
#define S21_CONTAINERS_CONTAINERS_S21_SET_H_

#include "s21_tree.h"

namespace s21 {

template <typename KeyType>
class Set : public Tree<KeyType, KeyType> {
 public:
  /* SET MEMBER TYPE */
  using key_type = KeyType;
  using reference = key_type &;
  using const_reference = const key_type &;
  using iterator = TreeIterator<key_type, key_type>;
  using const_iterator = ConstIterator<key_type, key_type>;
  using size_type = std::size_t;

  /*--------------------------------------------------------------------------*/

  /* SET MEMBER FUNCTIONS */

  /**
   * default constructor
   */
  Set() noexcept : Tree<KeyType, KeyType>() {}

  /**
   * copy constructor
   */
  Set(const Set &other) noexcept : Tree<KeyType, KeyType>(other) {}

  /**
   * move constructor
   */
  Set(Set &&other) noexcept : Tree<KeyType, KeyType>(std::move(other)) {}

  Set(std::initializer_list<key_type> const &items) {
    for (auto &item : items) {
      Tree<KeyType, KeyType>::insert(item, item);
    }
  }

  /**
   * destructor
   */
  ~Set() = default;

  /**
   * = overload, copy assignment
   */
  Set &operator=(const Set &other) noexcept {
    if (this != &other) {
      Tree<KeyType, KeyType>::operator=(other);
    }
    return *this;
  }

  /**
   * = overload, move assignment
   */
  Set &operator=(Set &&other) noexcept {
    if (this != &other) {
      Tree<KeyType, KeyType>::operator=(other);
    }
    return *this;
  }
  /*--------------------------------------------------------------------------*/

  std::pair<iterator, bool> insert(const key_type &key) {
    return Tree<KeyType, KeyType>::insert(key, key);
  }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    (result.push_back(insert(std::forward<Args>(args))), ...);
    return result;
  }

};  // class Set

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_SET_H_