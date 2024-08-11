# s21_containers

Implementation of Vector, Map, Set containers of the s21_containers.h library. Study project.

The russian version of the task can be found in the repository.

- The program is developed in C++ language of C++17 standard using gcc compiler;
- The program code is located in the src folder;
- The code of the program is written in accordance with Google style;
- Classes are template;
- Classes are implemented within the `s21` namespace;
- Full coverage of container classes methods is provided with unit-tests using the GTest library;
- Makefile with targets clean, check_style, test, gcov_report is provided.

Each of the containers provides a user with the following methods:

- standard constructors (default constructor, copy constructor, move constructor, constructor with initialization list, see materials);

- methods for accessing container elements (e.g. accessing an element with the index i);

- methods for checking if a container is full (e.g. the number of elements in the container, check if the container is empty);

- methods for changing the container (removing and adding new elements, cleaning the container);

- methods for dealing with the container iterator.

Iterators provide access to container elements. Containers provide iterators via the `begin()` and `end()` methods, which point to the first and next after last elements of the container respectively.

Iterator `iter` has the following operations:

- `*iter`: gets the element pointed to by the iterator;

- `++iter`: moves the iterator forward to the next element;

- `--iter`: moves the iterator backwards to the previous element;

- `iter1 == iter2`: two iterators are equal if they point to the same element;

- `iter1 != iter2`: two iterators are not equal if they point to different elements.

### Map

<details>
  <summary>General information</summary>
<br />

A map (dictionary) is an associative container that stores key-value pairs sorted in ascending order. It means that each element is associated with some unique key, and its position in the map is determined by its key. Maps come in handy when you want to associate elements with some other value (not an index).
```
In this project container Map is implemented based on AVL-tree algorithm.
AVL-tree is a balanced binary search tree with the following property: for each of its vertices, the heights of its two subtrees differ by at most 1.
```
</details>

<details>
  <summary>Specification</summary>
<br />

*Map Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | Definition                                                                                                                                                   |
|------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `key_type`               | `KeyType` the first template parameter (Key)                                                                                                                 |
| `mapped_type`           | `ValueType` the second template parameter (T)                                                                                                                |
| `value_type`             | `std::pair<const KeyType, ValueType>` Key-value pair                                                                                                         |
| `reference`              | `value_type &` defines the type of the reference to an element                                                                                               |
| `const_reference`        | `const value_type &` defines the type of the constant reference                                                                                              |
| `iterator`               | internal class `TreeIterator<KeyType, ValueType>` as internal iterator of tree subclass; defines the type for iterating through the container                |
| `const_iterator`         | internal class `TreeIterator<KeyType, ValueType>` as internal const iterator of tree subclass; defines the constant type for iterating through the container |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t)                                                                                    |

*Map Member functions*

This table contains the main public methods for interacting with the class:

| Member functions                                      | Definition                                      |
|-------------------------------------------------------|-------------------------------------------------|
| `Map()`                                               | default constructor, creates empty map                                 |
| `Map(std::initializer_list<value_type> const &items)` | initializer list constructor, creates the map initizialized using std::initializer_list<T>    |
| `Map(const Map &other)`                                   | copy constructor  |
| `Map(Map &&other)`                                        | move constructor  |
| `~Map()`                                              | destructor  |
| `operator=(Map &&other)`                              | assignment operator overload for moving object                                |

*Map Element access*

This table contains the public methods for accessing the elements of the class:

| Element access                              | Definition                                                                             |
|---------------------------------------------|----------------------------------------------------------------------------------------|
| `ValueType &at(const KeyType &key)`         | access specified element with bounds checking                                          |
| `ValueType &operator[](const KeyType &key)` | access or insert specified element                                                     |

*Map Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |

*Map Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`                  | checks whether the container is empty                                                  |
| `size_type size()`                   | returns the number of elements                                                         |
| `size_type max_size()`               | returns the maximum possible number of elements                                        |

*Map Modifiers*

This table contains the public methods for modifying a container:

| Modifiers                                                                   | Definition                                                                                                                           |
|-----------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------|
| `void clear()`                                                              | clears the contents                                                                                                                  |
| `std::pair<iterator, bool> insert(const ValueType &value)`                 | inserts node and returns iterator to where the element is in the container and bool denoting whether the insertion took place        |
| `std::pair<iterator, bool> insert(const KeyType &key, const ValueType &obj)`            | inserts value by key and returns iterator to where the element is in the container and bool denoting whether the insertion took place |
| `vector<std::pair<iterator,bool>> insert_many(Args&&... args)`          | inserts new elements into the container                                                                                              |
| `std::pair<iterator, bool> insert_or_assign(const KeyType &key, const ValueType &obj);` | inserts an element or assigns to the current element if the key already exists                                                       |
| `void erase(iterator pos)`                                                  | erases element at pos                                                                                                                |
| `void swap(Map &other)`                                                     | swaps the contents                                                                                                                   |
| `void merge(Map &other);`                                                   | splices nodes from another container                                                                                                 |

*Map Lookup*

This table contains the public methods for viewing the container:

| Lookup                              | Definition                                                                             |
|-------------------------------------|----------------------------------------------------------------------------------------|
| `bool contains(const KeyType &key)` | checks if there is an element with key equivalent to key in the container                                   |

</details>

### Set

<details>
  <summary>General information</summary>
<br />

Set is an associative container of unique elements. This means that the same element can’t be added to a set twice. The set container is associative, because it is also represented as a tree like the map container, and therefore also stores elements in a sorted order.
The difference between a map and a set is that in the set the value itself is unique and not the key as well as the value in the tree is not checked by the key, but by the value itself. There is an appropriate exception when you add an already existing element to a set.
```
In this project container Set is implemented based on AVL-tree algorithm.
AVL-tree is a balanced binary search tree with the following property: for each of its vertices, the heights of its two subtrees differ by at most 1.
```
</details>

<details>
  <summary>Specification</summary>
<br />

*Set Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | Definition                                                                                                                                                                         |
|------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `key_type`               | `KeyType` the first template parameter (Key)                                                                                                                                       |
| `value_type`             | `KeyType` value type (the value itself is a key)                                                                                                                                   |
| `reference`              | `value_type &` defines the type of the reference to an element                                                                                                                     |
| `const_reference`        | `const value_type &` defines the type of the constant reference                                                                                                                    |
| `iterator`               | internal class `TreeIterator<T>` as the internal iterator of tree subclass; defines the type for iterating through the container                          |
| `const_iterator`         | internal class `TreeConstIterator<T>` as the internal const iterator of tree subclass; defines the constant type for iterating through the container |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t)                                                                                                          |

*Set Member functions*

This table contains the main public methods for interacting with the class:

| Member functions                                      | Definition                                      |
|-------------------------------------------------------|-------------------------------------------------|
| `Set()`                                               | default constructor, creates empty set                                 |
| `Set(std::initializer_list<value_type> const &items)` | initializer list constructor, creates the set initizialized using std::initializer_list<T>    |
| `Set(const Set &other)`                               | copy constructor  |
| `Set(Set &&other)`                                    | move constructor  |
| `~Set()`                                              | destructor  |
| `operator=(Set &&other)`                              | assignment operator overload for moving object                                |

*Set Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |

*Set Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Set Modifiers*

This table contains the public methods for modifying a container:

| Modifiers                                                | Definition                                                                                                                   |
|----------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------|
| `void clear()`                                           | clears the contents                                                                                                          |
| `std::pair<iterator, bool> insert(const KeyType &value)` | inserts node and returns iterator to where the element is in the container and bool denoting whether the insertion took place |
| `vector<std::pair<iterator,bool>> insert_many(Args&&... args)`          | inserts new elements into the container                                                                                      |
| `void erase(iterator pos)`                               | erases element at pos                                                                                                        |
| `void swap(Set &other)`                                  | swaps the contents                                                                                                           |
| `void merge(Set &other);`                                | splices nodes from another container                                                                                         |

*Set Lookup*

This table contains the public methods for viewing the container:

| Lookup                              | Definition                                                                             |
|-------------------------------------|----------------------------------------------------------------------------------------|
| `iterator find(const KeyType &key)` | finds element with specific key                                                        |
| `bool contains(const KeyType &key)` | checks if the container contains element with specific key                             |

</details>

### Vector

<details>
  <summary>General information</summary>
<br />

Vector is a sequence container that encapsulates a dynamic array for more user-friendly usage. This container does not require manual memory control like standard dynamic arrays, but instead allows any number of elements to be added via `push_back()` and `insert()` methods and, unlike a list, allows any container element to be accessed directly by an index. Elements in a vector are stored sequentially, allowing iterating over the vector not only through the provided iterator, but also by manually shifting the pointer to the vector element. So, a pointer to the first element of a vector can be passed as an argument to any function that expects an ordinary array as an argument. The dynamic resizing of the array does not occur every time an element is added or removed, only when the specified buffer size is exceeded. So, the vector stores two values for a size: the size of the stored array (`size()` method) and the size of the buffer (`capacity()` method).

</details>

<details>
  <summary>Specification</summary>
<br />

*Vector Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | definition                                                                                                           |
|------------------------|----------------------------------------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                                         |
| `reference`              | `T &` defines the type of the reference to an element                                                                |
| `const_reference`        | `const T &` defines the type of the constant reference                                                               |
| `iterator`               | `T *` defines the type for iterating through the container                                                           |
| `const_iterator`         | `const T *` defines the constant type for iterating through the container |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t)                                            |

*Vector Member functions*

This table contains the main public methods for interacting with the class:

| Functions                                                | Definition                                      |
|----------------------------------------------------------|-------------------------------------------------|
| `Vector()`                                               | default constructor, creates empty vector                                 |
| `Vector(size_type n)`                                    | parameterized constructor, creates the vector of size n                                 |
| `Vector(std::initializer_list<value_type> const &items)` | initializer list constructor, creates vector initizialized using std::initializer_list<T>    |
| `Vector(const Vector &other)`                            | copy constructor  |
| `Vector(Vector &&other)`                                 | move constructor  |
| `~Vector()`                                              | destructor  |
| `operator=(Vector &&other)`                              | assignment operator overload for moving object                                |

*Vector Element access*

This table contains the public methods for accessing the elements of the class:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference at(size_type pos)`                     | access specified element with bounds checking                                          |
| `reference operator[](size_type pos);`             | access specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |
| `T* data()`                   | direct access to the underlying array                                                  |

*Vector Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*Vector Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |
| `void reserve(size_type size)`                | allocate storage of size elements and copies current array elements to a newely allocated array                                     |
| `size_type capacity()`               | returns the number of elements that can be held in currently allocated storage         |
| `void shrink_to_fit()`          | reduces memory usage by freeing unused memory                                          |

*Vector Modifiers*

This table contains the public methods for modifying a container:

| Modifiers                                              | Definition                                                                                |
|--------------------------------------------------------|-------------------------------------------------------------------------------------------|
| `void clear()`                                         | clears the contents                                                                       |
| `iterator insert(iterator pos, const_reference value)` | inserts elements into concrete pos and returns the iterator that points to the new element |
| `void insert_many_back(Args&&... args)`          | appends new elements to the end of the container                                          |
| `void erase(iterator pos)`                             | erases element at pos                                                                     |
| `void push_back(const_reference value)`                | adds an element to the end                                                                |
| `void pop_back()`                                      | removes the last element                                                                  |
| `void swap(Vector &other)`                             | swaps the contents                                                                        |

</details>