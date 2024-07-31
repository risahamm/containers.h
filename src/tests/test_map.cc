#include <gtest/gtest.h>

#include <map>

#include "../containers/s21_map.h"

/* MAP MEMBER FUNCTIONS */
/*----------------------------------------------------------------------------*/

TEST(Map, DefaultConstructor) {
  s21::Map<int, int> my;
  std::map<int, int> orig;

  EXPECT_TRUE(my.empty());
  EXPECT_TRUE(orig.empty());
}

TEST(Map, InitListConstructor1) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  EXPECT_EQ(my.begin()->key, orig.begin()->first);
}

TEST(Map, InitListConstructor2) {
  s21::Map<float, int> my = {
      {6.83656, 0}, {3.256, 1}, {9.873, 2}, {1.756, 3}, {4.323, 4}};
  std::map<float, int> orig = {
      {6.83656, 0}, {3.256, 1}, {9.873, 2}, {1.756, 3}, {4.323, 4}};
  EXPECT_EQ(my.begin()->key, orig.begin()->first);
}

TEST(Map, InitListConstructor3) {
  s21::Map<std::string, int> my = {{"abc", 0}, {"defg", 1}, {"higk", 2}};
  std::map<std::string, int> orig = {{"abc", 0}, {"defg", 1}, {"higk", 2}};
  EXPECT_EQ(my.begin()->key, orig.begin()->first);
}

TEST(Map, CopyConstructor) {
  s21::Map<int, int> a = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  s21::Map<int, int> b(a);
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.begin()->key, b.begin()->key);
}

TEST(Map, MoveConstructor) {
  s21::Map<int, int> a = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  size_t a_size_before = a.size();
  s21::Map<int, int> b(std::move(a));
  EXPECT_TRUE(a.empty());
  EXPECT_EQ(b.size(), a_size_before);
}

TEST(Map, EqualOverload1) {
  s21::Map<int, int> a = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  s21::Map<int, int> b = a;
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.begin()->key, b.begin()->key);
}

TEST(Map, EqualOverload2) {
  s21::Map<int, int> a = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  size_t a_size_before = a.size();
  s21::Map<int, int> b = std::move(a);
  EXPECT_TRUE(a.empty());
  EXPECT_EQ(b.size(), a_size_before);
}

TEST(Map, EqualOverload3) {
  s21::Map<int, int> a = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  a = a;
  size_t a_size_before = a.size();
  EXPECT_EQ(a.size(), a_size_before);
}

TEST(Map, EqualOverload4) {
  s21::Map<int, int> a = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  size_t a_size_before = a.size();
  s21::Map<int, int> b = {{7, 0}, {12, 1}, {5, 2}};
  a = b;
  size_t b_size = b.size();
  size_t a_size_after = a.size();
  EXPECT_TRUE((a_size_after != a_size_before));
  EXPECT_TRUE((a_size_after == b_size));
}

TEST(Map, EqualOverload5) {
  s21::Map<int, int> a = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  size_t a_size_before = a.size();
  s21::Map<int, int> b = {{7, 0}, {12, 1}, {5, 2}};
  size_t b_size = b.size();
  a = std::move(b);
  size_t a_size_after = a.size();
  EXPECT_TRUE((a_size_after != a_size_before));
  EXPECT_TRUE((a_size_after == b_size));
  EXPECT_TRUE(b.size() == 0);
}

/* MAP ELEMENT ACCESS */
/*----------------------------------------------------------------------------*/

TEST(Map, At) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  EXPECT_EQ(my.at(4), orig.at(4));
}

TEST(Map, AtOutOfRange) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  EXPECT_ANY_THROW(my.at(25));
}

TEST(Map, AtEmpty) {
  s21::Map<int, int> my;
  EXPECT_ANY_THROW(my.at(25));
}

TEST(Map, BracketsOverload) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  EXPECT_EQ(my[4], orig[4]);
}

TEST(Map, BracketsOverloadAssignment) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  s21::Map<std::string, std::string> my_2 = {{"abc", "abc"},
                                             {"def", "def"},
                                             {"ghi", "ghi"},
                                             {"jkl", "jkl"},
                                             {"mno", "mno"}};
  my[4] = 25;
  EXPECT_EQ(my[4], 25);
}

/* MAP ITERATORS */
/*----------------------------------------------------------------------------*/

TEST(Map, Begin) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  auto my_it = my.begin();
  auto orig_it = orig.begin();
  EXPECT_EQ(my_it->data, orig_it->second);
}

TEST(Map, BeginEmpty) {
  s21::Map<int, int> my;
  EXPECT_ANY_THROW(my.begin());
}

TEST(Map, EndEmpty) {
    s21::Map<int, int> my;
    EXPECT_ANY_THROW(my.end());
}

TEST(Map, IteratorEqual) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  s21::Map<int, int>::iterator it = my.begin();
  it = it;
  s21::Map<int, int>::iterator it2 = it;
  EXPECT_EQ(it->key, it2->key);
}

TEST(Map, IteratorDereference) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  s21::Map<int, int>::iterator it = my.end();
  EXPECT_ANY_THROW(*it);
}

TEST(Map, IteratorDereference2) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  s21::Map<int, int>::iterator it = my.end();
  EXPECT_ANY_THROW(it->key);
}

TEST(Map, IteratorIncrementDecrement) {
  s21::Map<int, int> my;
  my.insert(40, 0);
  my.insert(20, 1);
  my.insert(80, 2);
  my.insert(10, 3);
  my.insert(90, 4);
  my.insert(5, 5);
  my.insert(60, 6);
  my.insert(70, 7);
  my.insert(50, 8);
  my.insert(45, 9);

  auto it = my.begin();

  for (size_t i = 1; i < my.size(); ++i) {
    ++it;
  }
  EXPECT_EQ(it->key, 90);
  EXPECT_EQ(it->data, 4);
  for (size_t i = my.size(); i > 1; --i) {
    --it;
    std::cout << "it " << it->key << std::endl;
  }
  EXPECT_EQ(it->key, 5);
  EXPECT_EQ(it->data, 5);
}

TEST(Map, IteratorDecrement) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}};
  s21::Map<int, int>::iterator it = my.begin();
    ++it;
    ++it;
    --it;
    it--;
  EXPECT_EQ(it->key, 3);
}

/* MAP CAPACITY */
/*----------------------------------------------------------------------------*/

TEST(Map, Empty1) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  EXPECT_FALSE(my.empty());
}
TEST(Map, Empty2) {
  s21::Map<int, int> my;
  EXPECT_TRUE(my.empty());
}

TEST(Map, Size) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  EXPECT_EQ(my.size(), orig.size());
}

TEST(Map, SizeEmpty) {
  s21::Map<int, int> my;
  std::map<int, int> orig;
  EXPECT_EQ(my.size(), orig.size());
}

/* MAP MODIFIERS */
/*----------------------------------------------------------------------------*/

TEST(Map, Clear) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  my.clear();
  orig.clear();
  EXPECT_EQ(my.size(), 0);
  EXPECT_EQ(my.size(), orig.size());
}

TEST(Map, ClearEmpty) {
  s21::Map<int, int> my;
  std::map<int, int> orig;
  my.clear();
  orig.clear();
  EXPECT_EQ(my.size(), 0);
  EXPECT_EQ(my.size(), orig.size());
}

TEST(Map, InsertSimple) {
  s21::Map<int, int> my;
  my.insert(6, 0);
  my.insert(3, 1);
  my.insert(9, 2);
  my.insert(1, 3);
  my.insert(4, 2);
  std::map<int, int> orig;
  orig.insert({6, 0});
  orig.insert({3, 1});
  orig.insert({9, 2});
  orig.insert({1, 3});
  orig.insert({4, 2});
  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.begin()->key, orig.begin()->first);
  EXPECT_EQ(my.begin()->data, orig.begin()->second);
}

TEST(Map, InsertSimple2) {
  s21::Map<int, int> my = {{10, 0}, {20, 1}, {15, 2}};
  std::map<int, int> orig = {{10, 0}, {20, 1}, {15, 2}};
  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.begin()->key, orig.begin()->first);
  EXPECT_EQ(my.begin()->data, orig.begin()->second);
}

TEST(Map, InsertNotUnique) {
  s21::Map<int, int> my;
  my.insert(6, 0);
  my.insert(3, 1);
  my.insert(9, 2);

  my.insert(6, 25);

  std::map<int, int> orig;
  orig.insert({6, 0});
  orig.insert({3, 1});
  orig.insert({9, 2});

  orig.insert({6, 25});

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my[6], 0);
  EXPECT_EQ(my[6], orig[6]);
}

TEST(Map, InsertPair) {
  s21::Map<int, int> my;
  my.insert(std::pair<int, int>(6, 0));
  my.insert(std::pair<int, int>(3, 1));
  my.insert(std::pair<int, int>(9, 2));

  std::map<int, int> orig;
  orig.insert({6, 0});
  orig.insert({3, 1});
  orig.insert({9, 2});

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.begin()->key, orig.begin()->first);
  EXPECT_EQ(my.begin()->data, orig.begin()->second);
}

TEST(Map, InsertOrAssign) {
  s21::Map<int, int> my;
  my.insert(std::pair<int, int>(6, 0));
  my.insert(std::pair<int, int>(3, 1));
  my.insert(std::pair<int, int>(9, 2));

  my.insert_or_assign(9, 35);
  my.insert_or_assign(4, 28);

  EXPECT_EQ(my[9], 35);
  EXPECT_EQ(my[4], 28);
  EXPECT_EQ(my.size(), 4);
}

TEST(Map, InsertOrAssignEmpty) {
  s21::Map<int, int> my;

  my.insert_or_assign(9, 35);

  EXPECT_EQ(my[9], 35);
  EXPECT_EQ(my.size(), 1);
}

TEST(Map, InsertMany) {
  s21::Map<int, std::string> my;
  my.insert_many(std::pair(1, "one"), std::pair(2, "two"), std::pair(3, "three"));
  auto it = my.begin();
  EXPECT_EQ(my.size(), 3);
  EXPECT_EQ(my.begin()->data, "one");
  EXPECT_EQ(my.begin()->key, 1);
}

TEST(Map, Erase) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};

  auto my_it = my.begin();
  my_it++;
  my.erase(my_it);

  auto orig_it = orig.begin();
  orig_it++;
  orig.erase(orig_it);

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.size(), 4);
}

TEST(Map, Erase2) {
  s21::Map<int, int> my;
  auto it = my.insert(6, 0);
  my.insert(3, 1);
  my.erase(it.first);
  EXPECT_EQ(my.size(), 1);
}

TEST(Map, Erase3) {
  s21::Map<int, int> my;
  auto it = my.insert(40, 0);
  my.insert(20, 1);
  my.insert(80, 2);
  my.insert(10, 3);
  my.insert(90, 4);
  my.insert(5, 5);
  my.insert(60, 6);
  auto it2 = my.insert(70, 7);
  my.insert(50, 8);
  my.insert(45, 9);

  size_t size = my.size();

  my.erase(it2.first);
  my.erase(it.first);
  EXPECT_EQ(my.size(), (size - 2));
}

TEST(Map, Erase4) {
  s21::Map<int, int> my;
  my.insert(40, 0);
  my.insert(20, 1);
  my.insert(80, 2);
  my.insert(10, 3);
  my.insert(90, 4);
  my.insert(5, 5);
  my.insert(60, 6);
  my.insert(70, 7);
  auto it = my.insert(50, 8);
  my.insert(45, 9);

  size_t size = my.size();

  my.erase(it.first);
  EXPECT_EQ(my.size(), (size - 1));
}

TEST(Map, Erase5) {
  s21::Map<int, int> my;
  my.insert(40, 0);
  my.insert(20, 1);
  my.insert(80, 2);
  my.insert(10, 3);
  my.insert(90, 4);
  my.insert(5, 5);
  auto it = my.insert(60, 6);
  my.insert(70, 7);
  my.insert(50, 8);
  my.insert(45, 9);

  size_t size = my.size();

  my.erase(it.first);
  EXPECT_EQ(my.size(), (size - 1));
}

TEST(Map, EraseBegin) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};

  auto my_it = my.begin();
  my.erase(my_it);

  auto orig_it = orig.begin();
  orig.erase(orig_it);

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.size(), 4);
  EXPECT_EQ(my.begin()->key, orig.begin()->first);
}

TEST(Map, EraseNonExistent) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {1, 3}, {4, 4}};
  auto it = my.begin();
  my.erase(my.begin());
  EXPECT_ANY_THROW(my.erase(it));
}

TEST(Map, EraseEmpty) {
    s21::Map<int, int> my;
    my.insert(1, 1);
    auto it = my.begin();
    my.erase(it);
    EXPECT_ANY_THROW(my.erase(it));
}

TEST(Map, Swap) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {5, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {5, 3}, {4, 4}};
  int my_begin_before = my.begin()->key;
  size_t my_size_before = my.size();

  s21::Map<int, int> my2 = {{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> orig2 = {{1, 10}, {2, 20}, {3, 30}};
  int my2_begin_before = my2.begin()->key;
  size_t my2_size_before = my2.size();

  my.swap(my2);
  orig.swap(orig2);

  int my_begin_after = my.begin()->key;
  int my2_begin_after = my2.begin()->key;
  size_t my_size_after = my.size();
  size_t my2_size_after = my2.size();

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my2.size(), orig2.size());
  EXPECT_EQ(my_begin_after, my2_begin_before);
  EXPECT_EQ(my2_begin_after, my_begin_before);
  EXPECT_EQ(my_size_after, my2_size_before);
  EXPECT_EQ(my2_size_after, my_size_before);
}

TEST(Map, SwapEmptyAndNonEmpty) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {5, 3}, {4, 4}};
  size_t my_size_before = my.size();
  s21::Map<int, int> my2;
  size_t my2_size_before = my2.size();

  my.swap(my2);;

  size_t my_size_after = my.size();
  size_t my2_size_after = my2.size();

  EXPECT_EQ(my_size_after, my2_size_before);
  EXPECT_EQ(my2_size_after, my_size_before);
}

TEST(Map, Merge) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {5, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {5, 3}, {4, 4}};
  int my_begin_before = my.begin()->key;
  size_t my_size_before = my.size();

  s21::Map<int, int> my2 = {{1, 10}, {2, 20}, {3, 30}};
  std::map<int, int> orig2 = {{1, 10}, {2, 20}, {3, 30}};

  my.merge(my2);
  orig.merge(orig2);

  int my_begin_after = my.begin()->key;
  size_t my_size_after = my.size();

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_TRUE((my_size_before != my_size_after));
  EXPECT_TRUE((my_begin_before != my_begin_after));
}

TEST(Map, MergeEmpty) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {5, 3}, {4, 4}};
  std::map<int, int> orig = {{6, 0}, {3, 1}, {9, 2}, {5, 3}, {4, 4}};
  size_t my_size_before = my.size();

  s21::Map<int, int> my2;
  std::map<int, int> orig2;

  my.merge(my2);
  orig.merge(orig2);

  size_t my_size_after = my.size();

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_TRUE((my_size_before == my_size_after));
}

TEST(Map, ContainsExistent) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {5, 3}, {4, 4}};
  bool res = my.contains(3);
  EXPECT_TRUE(res);
}

TEST(Map, ContainsNonExistent) {
  s21::Map<int, int> my = {{6, 0}, {3, 1}, {9, 2}, {5, 3}, {4, 4}};
  bool res = my.contains(33);
  EXPECT_FALSE(res);
}

TEST(Map, ContainsEmpty) {
  s21::Map<int, int> my;
  bool res = my.contains(33);
  EXPECT_FALSE(res);
}

