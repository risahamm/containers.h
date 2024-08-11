# s21_containers

Реализация контейнеров Vector, Map, Set библиотеки s21_containers.h.

- Программа разработана на языке C++ стандарта C++17 с использованием компилятора gcc;
- Код программы находится в папке src;
- Код написан в соответствии с Google Style;
- Классы являются шаблонными;
- Классы реализованы внутри пространства имен `s21`;
- Подготовлено полное покрытие unit-тестами методов контейнерных классов c помощью библиотеки GTest;
- Соблюдена логика работы стандартной библиотеки шаблонов (STL) (в части проверок, работы с памятью и поведения в нештатных ситуациях);
- Предусмотрен Makefile для сборки библиотеки с целями clean, check_style, test, gcov_report.

Каждый вид контейнеров предоставляет пользователю следующие методы:

- стандартные конструкторы (конструктор по умолчанию, конструктор копирования, конструктор перемещения, конструктор со списком инициализации, см. материалы);

- методы доступа к элементам контейнера (например, осуществление доступа к элементу с индексом i);

- методы проверки наполненности контейнера (например, количество элементов в контейнере, проверка на пустоту контейнера);

- методы изменения контейнера (удаление и добавление новых элементов, очистка контейнера);

- методы для работы с итератором контейнера.

Итераторы обеспечивают доступ к элементам контейнера. Через методы `begin()` и `end()` контейнеры предоставляют итераторы, которые указывают на первый и следующий после последнего элементы контейнера соответственно.

Над итератором `iter` определены следующие операции:

- `*iter`: получение элемента, на который указывает итератор;

- `++iter`: перемещение итератора вперед для обращения к следующему элементу;

- `--iter`: перемещение итератора назад для обращения к предыдущему элементу;

- `iter1 == iter2`: два итератора равны, если они указывают на один и тот же элемент;

- `iter1 != iter2`: два итератора не равны, если они указывают на разные элементы.

### Map

<details>
  <summary>Общая информация</summary>
<br />

Map (словарь) - это ассоциативный контейнер, содержащий отсортированные по возрастанию ключа пары ключ-значение. То есть каждый элемент ассоциирован с некоторым уникальным ключом, и его положение в словаре определяется его ключом. Словари удобно применять, когда необходимо ассоциировать элементы с некоторым другим значением (не индексом).
```
В данном проекте контейнер Map реализован на основе AVL-дерева. 
AVL-дерево - сбалансированное бинарное дерево поиска, в котором поддерживается следующее свойство: для каждой его вершины высота её двух поддеревьев различается не более чем на 1.
```
</details>

<details>
  <summary>Спецификация</summary>
  <br />

*Map Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

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

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Member functions                                      | Definition                                      |
|-------------------------------------------------------|-------------------------------------------------|
| `Map()`                                               | default constructor, creates empty map                                 |
| `Map(std::initializer_list<value_type> const &items)` | initializer list constructor, creates the map initizialized using std::initializer_list<T>    |
| `Map(const Map &other)`                                   | copy constructor  |
| `Map(Map &&other)`                                        | move constructor  |
| `~Map()`                                              | destructor  |
| `operator=(Map &&other)`                              | assignment operator overload for moving object                                |

*Map Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access                              | Definition                                                                             |
|---------------------------------------------|----------------------------------------------------------------------------------------|
| `ValueType &at(const KeyType &key)`         | access specified element with bounds checking                                          |
| `ValueType &operator[](const KeyType &key)` | access or insert specified element                                                     |

*Map Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |

*Map Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`                  | checks whether the container is empty                                                  |
| `size_type size()`                   | returns the number of elements                                                         |
| `size_type max_size()`               | returns the maximum possible number of elements                                        |

*Map Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

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

В этой таблице перечислены публичные методы, осуществляющие просмотр контейнера:

| Lookup                              | Definition                                                                             |
|-------------------------------------|----------------------------------------------------------------------------------------|
| `bool contains(const KeyType &key)` | checks if there is an element with key equivalent to key in the container                                   |

</details>

### Set

<details>
  <summary>Общая информация</summary>
<br />

Set (множество) - ассоциативный контейнер уникальных элементов. Это означает, что в множество нельзя добавить один и тот же элемент дважды. Контейнер множество является ассоциативным, так как внутри он также представлен в виде дерева, как и контейнер map (словарь), и, соответственно, также хранит элементы в отсортированном порядке. Разница между словарем и множеством заключается в том, что уникальным в множестве является, не ключ а само значение, ровно как и поиск значения в дереве проверяется не по ключу, а по самому значению.
```
В данном проекте контейнер Set реализован на основе AVL-дерева. 
AVL-дерево - сбалансированное бинарное дерево поиска, в котором поддерживается следующее свойство: для каждой его вершины высота её двух поддеревьев различается не более чем на 1.
```
</details>

<details>
  <summary>Спецификация</summary>
<br />

*Set Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

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

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Member functions                                      | Definition                                      |
|-------------------------------------------------------|-------------------------------------------------|
| `Set()`                                               | default constructor, creates empty set                                 |
| `Set(std::initializer_list<value_type> const &items)` | initializer list constructor, creates the set initizialized using std::initializer_list<T>    |
| `Set(const Set &other)`                               | copy constructor  |
| `Set(Set &&other)`                                    | move constructor  |
| `~Set()`                                              | destructor  |
| `operator=(Set &&other)`                              | assignment operator overload for moving object                                |

*Set Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators              | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `iterator begin()`            | returns an iterator to the beginning                                                   |
| `iterator end()`                | returns an iterator to the end                                                         |

*Set Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Set Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers                                                | Definition                                                                                                                   |
|----------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------|
| `void clear()`                                           | clears the contents                                                                                                          |
| `std::pair<iterator, bool> insert(const KeyType &value)` | inserts node and returns iterator to where the element is in the container and bool denoting whether the insertion took place |
| `vector<std::pair<iterator,bool>> insert_many(Args&&... args)`          | inserts new elements into the container                                                                                      |
| `void erase(iterator pos)`                               | erases element at pos                                                                                                        |
| `void swap(Set &other)`                                  | swaps the contents                                                                                                           |
| `void merge(Set &other);`                                | splices nodes from another container                                                                                         |

*Set Lookup*

В этой таблице перечислены публичные методы, осуществляющие просмотр контейнера:

| Lookup                              | Definition                                                                             |
|-------------------------------------|----------------------------------------------------------------------------------------|
| `iterator find(const KeyType &key)` | finds element with specific key                                                        |
| `bool contains(const KeyType &key)` | checks if the container contains element with specific key                             |

</details>

### Vector

<details>
  <summary>Общая информация</summary>
<br />

Vector (вектор) - это последовательный контейнер, инкапсулируюший в себе динамический массив для более интуитивной работы. Данный контейнер не требует ручного контроля памяти, как стандартные динамические массивы, вместо этого он позволяет добавлять через методы `push_back()` и `insert()` произвольное количество элементов, и, в отличие от списка, позволяет обратиться к любому элементу контейнера напрямую, по индексу. Элементы в векторе хранятся последовательно, что позволяет итерировать по вектору не только через предоставляемый итератор, но также и вручную смещая указатель на элемент вектора. Таким образом, указатель на первый элемент вектора может быть передан в качестве аргумента в любую функцию, ожидающую в качестве аргумента обыкновенный массив. Динамическое изменение размера массива происходит не при каждом добавлении или удалении элемента, а только в случае превышения размера заданного буфера. Таким образом, вектор хранит два значения, отвечающих за размер: размер хранимого массива (метод `size()`) и размер буффера (метод `capacity()`). 

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Vector Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                                                           |
|------------------------|----------------------------------------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                                         |
| `reference`              | `T &` defines the type of the reference to an element                                                                |
| `const_reference`        | `const T &` defines the type of the constant reference                                                               |
| `iterator`               | `T *` defines the type for iterating through the container                                                           |
| `const_iterator`         | `const T *` defines the constant type for iterating through the container |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t)                                            |

*Vector Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

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

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference at(size_type pos)`                     | access specified element with bounds checking                                          |
| `reference operator[](size_type pos);`             | access specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |
| `T* data()`                   | direct access to the underlying array                                                  |

*Vector Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*Vector Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:


| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |
| `void reserve(size_type size)`                | allocate storage of size elements and copies current array elements to a newely allocated array                                     |
| `size_type capacity()`               | returns the number of elements that can be held in currently allocated storage         |
| `void shrink_to_fit()`          | reduces memory usage by freeing unused memory                                          |

*Vector Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

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