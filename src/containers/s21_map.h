#ifndef S21_CONTAINERS_CONTAINERS_S21_MAP_H_
#define S21_CONTAINERS_CONTAINERS_S21_MAP_H_

#include "s21_tree.h"

namespace s21 {

template <typename KeyType, typename ValueType>
class Map : public Tree<KeyType, ValueType> {
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

  /*--------------------------------------------------------------------------*/

 public:
  /* MAP MEMBER FUNCTIONS */

  /**
   * default constructor
   */
  Map() noexcept : Tree<KeyType, ValueType>() {}

  /**
   * copy constructor
   */
  Map(const Map &other) noexcept : Tree<KeyType, ValueType>(other) {}

  /**
   * move constructor
   */
  Map(Map &&other) noexcept : Tree<KeyType, ValueType>(std::move(other)) {}

  Map(std::initializer_list<value_type> const &items) {
    for (auto &item : items) {
      Tree<KeyType, ValueType>::insert(item);
    }
  }

  /**
   * destructor
   */
  ~Map() = default;

  /**
   * = overload, copy assignment
   */
  Map &operator=(const Map &other) noexcept {
    if (this != &other) {
      Tree<KeyType, ValueType>::operator=(other);
    }
    return *this;
  }

  /**
   * = overload, move assignment
   */
  Map &operator=(Map &&other) noexcept {
    if (this != &other) {
      Tree<KeyType, ValueType>::operator=(std::move(other));
    }
    return *this;
  }

  mapped_type &operator[](const key_type &key) { return Tree<KeyType, ValueType>::operator[](key); }

  /*--------------------------------------------------------------------------*/

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    (result.push_back(Tree<KeyType, ValueType>::insert(std::forward<Args>(args).first,
                             std::forward<Args>(args).second)),
     ...);
    return result;
  }

};  // class Map

}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_MAP_H_