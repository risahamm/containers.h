#ifndef S21_CONTAINERS_CONTAINERS_S21_TREE_H_
#define S21_CONTAINERS_CONTAINERS_S21_TREE_H_

#include <utility>
namespace s21 {

template <typename Key, typename T>
class Tree {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type,mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
//  using iterator;
//  using const_iterator;
  using size_type = std::size_t;


  template <typename value_type>
  struct Node {
    key_type key;
    mapped_type data;
    unsigned int height = 1;
    size_type size = 0; // number of elements in the tree
    struct Node *parent = nullptr;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
  };


 private:

  Node<value_type> *root_;

}; // class Tree


}  // namespace s21

#endif  // S21_CONTAINERS_CONTAINERS_S21_TREE_H_

