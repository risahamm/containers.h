#include <gtest/gtest.h>

#include <set>

#include "../containers/s21_set.h"

/* SET MEMBER FUNCTIONS */
/*----------------------------------------------------------------------------*/

TEST(Set, DefaultConstructor) {
  s21::Set<int> my;
  std::set<int> orig;

  EXPECT_TRUE(my.empty());
  EXPECT_TRUE(orig.empty());
}

TEST(Set, InitListConstructor1) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  std::set<int> orig = {6, 3, 9, 1, 4};
  EXPECT_EQ(*my.begin(), *orig.begin());
}

TEST(Set, InitListConstructor2) {
  s21::Set<double> my = {6.83656, 3.256, 9.873, 1.756, 4.323};
  std::set<double> orig = {6.83656, 3.256, 9.873, 1.756, 4.323};
  EXPECT_EQ(*my.begin(), *orig.begin());
}

TEST(Set, InitListConstructor3) {
  s21::Set<std::string> my = {"abc",  "defg", "higk", "lmno",
                              "pqst", "uvwx", "yz"};
  std::set<std::string> orig = {"abc",  "defg", "higk", "lmno",
                                "pqst", "uvwx", "yz"};
  EXPECT_EQ(*my.begin(), *orig.begin());
}

TEST(Set, CopyConstructor) {
  s21::Set<int> a = {6, 3, 9, 1, 4};
  s21::Set<int> b(a);
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(*a.begin(), *b.begin());
}

TEST(Set, MoveConstructor) {
  s21::Set<int> a = {6, 3, 9, 1, 4};
  size_t a_size_before = a.size();
  s21::Set<int> b(std::move(a));
  EXPECT_TRUE(a.empty());
  EXPECT_EQ(b.size(), a_size_before);
}

TEST(Set, EqualOverload1) {
  s21::Set<int> a = {6, 3, 9, 1, 4};
  s21::Set<int> b = a;
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(*a.begin(), *b.begin());
}

TEST(Set, EqualOverload2) {
  s21::Set<int> a = {6, 3, 9, 1, 4};
  size_t a_size_before = a.size();
  s21::Set<int> b = std::move(a);
  EXPECT_TRUE(a.empty());
  EXPECT_EQ(b.size(), a_size_before);
}

TEST(Set, EqualOverload3) {
  s21::Set<int> a = {6, 3, 9, 1, 4};
  size_t a_size_before = a.size();
  s21::Set<int> b = {7, 12, 5};
  a = b;
  size_t b_size = b.size();
  size_t a_size_after = a.size();
  EXPECT_TRUE((a_size_after != a_size_before));
  EXPECT_TRUE((a_size_after == b_size));
}

/* SET ITERATORS */
/*----------------------------------------------------------------------------*/

TEST(Set, Begin) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  std::set<int> orig = {6, 3, 9, 1, 4};
  auto my_it = my.begin();
  auto orig_it = orig.begin();
  EXPECT_EQ(*my_it, *orig_it);
}

TEST(Set, BeginEmpty) {
  s21::Set<int> my;
  EXPECT_ANY_THROW(my.begin());
}

TEST(Set, EndEmpty) {
  s21::Set<int> my;
  EXPECT_ANY_THROW(my.end());
}

TEST(Set, IteratorEqual) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  auto it = my.begin();
  it = it;
  auto it2 = it;
  EXPECT_EQ(*it, *it2);
}

TEST(Set, IteratorDereference) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  auto it = my.end();
  EXPECT_ANY_THROW(*it);
}

TEST(Set, IteratorDereference2) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  auto it = my.end();
  EXPECT_ANY_THROW(it->key);
}

TEST(Set, IteratorIncrementDecrement) {
  s21::Set<int> my;
  my.insert(40);
  my.insert(20);
  my.insert(80);
  my.insert(10);
  my.insert(90);
  my.insert(5);
  my.insert(60);
  my.insert(70);
  my.insert(50);
  my.insert(45);

  auto it = my.begin();

  for (size_t i = 1; i < my.size(); ++i) {
    ++it;
  }
  EXPECT_EQ(*it, 90);
  for (size_t i = my.size(); i > 1; --i) {
    --it;
  }
  EXPECT_EQ(*it, 5);
}

TEST(Set, IteratorDecrement) {
  s21::Set<int> my = {6, 3, 9};
  auto it = my.begin();
  ++it;
  ++it;
  --it;
  it--;
  EXPECT_EQ(*it, 3);
}

/* SET CAPACITY */
/*----------------------------------------------------------------------------*/

TEST(Set, Empty1) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  EXPECT_FALSE(my.empty());
}

TEST(Set, Empty2) {
  s21::Set<int> my;
  EXPECT_TRUE(my.empty());
}

TEST(Set, Size) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  std::set<int> orig = {6, 3, 9, 1, 4};
  EXPECT_EQ(my.size(), orig.size());
}

TEST(Set, SizeEmpty) {
  s21::Set<int> my;
  std::set<int> orig;
  EXPECT_EQ(my.size(), orig.size());
}

/* SET MODIFIERS */
/*----------------------------------------------------------------------------*/

TEST(Set, Clear) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  std::set<int> orig = {6, 3, 9, 1, 4};
  my.clear();
  orig.clear();
  EXPECT_EQ(my.size(), 0U);
  EXPECT_EQ(my.size(), orig.size());
}

TEST(Set, ClearEmpty) {
  s21::Set<int> my;
  std::set<int> orig;
  my.clear();
  orig.clear();
  EXPECT_EQ(my.size(), 0);
  EXPECT_EQ(my.size(), orig.size());
}

TEST(Set, Insert) {
  s21::Set<int> my;
  my.insert(6);
  my.insert(3);
  my.insert(9);
  my.insert(1);
  my.insert(4);
  std::set<int> orig;
  orig.insert(6);
  orig.insert(3);
  orig.insert(9);
  orig.insert(1);
  orig.insert(4);
  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(*my.begin(), *orig.begin());
}

TEST(Set, InsertNotUnique) {
  s21::Set<int> my;
  my.insert(6);
  my.insert(3);
  my.insert(9);

  my.insert(6);

  std::set<int> orig;
  orig.insert(6);
  orig.insert(3);
  orig.insert(9);

  orig.insert(6);

  EXPECT_EQ(my.size(), orig.size());
}

TEST(Set, InsertMany) {
  s21::Set<std::string> my;
  my.insert_many("one", "two", "three");
  auto it = my.begin();
  EXPECT_EQ(my.size(), 3);
  EXPECT_EQ(*my.begin(), "one");
}

TEST(Set, Erase) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  std::set<int> orig = {6, 3, 9, 1, 4};

  auto my_it = my.begin();
  my_it++;
  my.erase(my_it);

  auto orig_it = orig.begin();
  orig_it++;
  orig.erase(orig_it);

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.size(), 4U);
}

TEST(Set, Erase2) {
  s21::Set<int> my;
  auto it = my.insert(6);
  my.insert(3);
  my.erase(it.first);
  EXPECT_EQ(my.size(), 1U);
}

TEST(Set, Erase3) {
  s21::Set<int> my;
  auto it = my.insert(40);
  my.insert(20);
  my.insert(80);
  my.insert(10);
  my.insert(90);
  my.insert(5);
  my.insert(60);
  auto it2 = my.insert(70);
  my.insert(50);
  my.insert(45);

  size_t size = my.size();

  my.erase(it2.first);
  my.erase(it.first);
  EXPECT_EQ(my.size(), (size - 2));
}

TEST(Set, Erase4) {
  s21::Set<int> my;
  my.insert(40);
  my.insert(20);
  my.insert(80);
  my.insert(10);
  my.insert(90);
  my.insert(5);
  my.insert(60);
  my.insert(70);
  auto it = my.insert(50);
  my.insert(45);

  size_t size = my.size();

  my.erase(it.first);
  EXPECT_EQ(my.size(), (size - 1));
}

TEST(Set, Erase5) {
  s21::Set<int> my;
  my.insert(40);
  my.insert(20);
  my.insert(80);
  my.insert(10);
  my.insert(90);
  my.insert(5);
  auto it = my.insert(60);
  my.insert(70);
  my.insert(50);
  my.insert(45);

  size_t size = my.size();

  my.erase(it.first);
  EXPECT_EQ(my.size(), (size - 1));
}

TEST(Set, EraseBegin) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  std::set<int> orig = {6, 3, 9, 1, 4};

  auto my_it = my.begin();
  my.erase(my_it);

  auto orig_it = orig.begin();
  orig.erase(orig_it);

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.size(), 4);
  EXPECT_EQ(*my.begin(), *orig.begin());
}

TEST(Set, EraseNonExistent) {
  s21::Set<int> my = {6, 3, 9, 1, 4};
  auto it = my.begin();
  my.erase(my.begin());
  EXPECT_ANY_THROW(my.erase(it));
}

TEST(Set, EraseEmpty) {
  s21::Set<int> my;
  my.insert(1);
  auto it = my.begin();
  my.erase(it);
  EXPECT_ANY_THROW(my.erase(it));
}

TEST(Set, Swap) {
  s21::Set<int> my = {6, 3, 9, 5, 4};
  std::set<int> orig = {6, 3, 9, 5, 4};
  int my_begin_before = *my.begin();
  size_t my_size_before = my.size();

  s21::Set<int> my2 = {1, 2, 3};
  std::set<int> orig2 = {1, 2, 3};
  int my2_begin_before = *my2.begin();
  size_t my2_size_before = my2.size();

  my.swap(my2);
  orig.swap(orig2);

  int my_begin_after = *my.begin();
  int my2_begin_after = *my2.begin();
  size_t my_size_after = my.size();
  size_t my2_size_after = my2.size();

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my2.size(), orig2.size());
  EXPECT_EQ(my_begin_after, my2_begin_before);
  EXPECT_EQ(my2_begin_after, my_begin_before);
  EXPECT_EQ(my_size_after, my2_size_before);
  EXPECT_EQ(my2_size_after, my_size_before);
}

TEST(Set, SwapEmptyAndNonEmpty) {
  s21::Set<int> my = {6, 3, 9, 5, 4};
  size_t my_size_before = my.size();
  s21::Set<int> my2;
  size_t my2_size_before = my2.size();

  my.swap(my2);

  size_t my_size_after = my.size();
  size_t my2_size_after = my2.size();

  EXPECT_EQ(my_size_after, my2_size_before);
  EXPECT_EQ(my2_size_after, my_size_before);
}

TEST(Set, Merge) {
  s21::Set<int> my = {6, 3, 9, 5, 4};
  std::set<int> orig = {6, 3, 9, 5, 4};
  int my_begin_before = *my.begin();
  size_t my_size_before = my.size();

  s21::Set<int> my2 = {1, 1, 3};
  std::set<int> orig2 = {1, 1, 3};

  my.merge(my2);
  orig.merge(orig2);

  int my_begin_after = *my.begin();
  size_t my_size_after = my.size();

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_TRUE((my_size_before != my_size_after));
  EXPECT_TRUE((my_begin_before != my_begin_after));
}

TEST(Set, MergeEmpty) {
  s21::Set<int> my = {6, 3, 9, 5, 4};
  std::set<int> orig = {6, 3, 9, 5, 4};
  size_t my_size_before = my.size();

  s21::Set<int> my2;
  std::set<int> orig2;

  my.merge(my2);
  orig.merge(orig2);

  size_t my_size_after = my.size();

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_TRUE((my_size_before == my_size_after));
}

/* SET LOOKUP */
/*----------------------------------------------------------------------------*/

TEST(Set, FindExistent) {
  s21::Set<int> my = {6, 3, 9, 5, 4};
  std::set<int> orig = {6, 3, 9, 5, 4};
  auto it_my = my.find(5);
  auto it_orig = orig.find(5);
  EXPECT_EQ(*it_my, *it_orig);
}

TEST(Set, FindNonExistent) {
  s21::Set<int> my = {6, 3, 9, 5, 4};
  auto it_my = my.find(33);
  EXPECT_ANY_THROW(*it_my);
}

TEST(Set, FindEmpty) {
  s21::Set<int> my;
  EXPECT_ANY_THROW(my.find(33));
}

TEST(Set, ContainsExistent) {
  s21::Set<int> my = {6, 3, 9, 5, 4};
  bool res = my.contains(3);
  EXPECT_TRUE(res);
}

TEST(Set, ContainsNonExistent) {
  s21::Set<int> my = {6, 3, 9, 5, 4};
  bool res = my.contains(33);
  EXPECT_FALSE(res);
}

TEST(Set, ContainsEmpty) {
  s21::Set<int> my;
  bool res = my.contains(33);
  EXPECT_FALSE(res);
}

/*----------------------------------------------------------------------------*/