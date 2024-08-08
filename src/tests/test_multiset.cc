#include <gtest/gtest.h>

#include <set>

#include "../containers/s21_multiset.h"

/* MULTISET MEMBER FUNCTIONS */
/*----------------------------------------------------------------------------*/

TEST(Multiset, DefaultConstructor) {
  s21::Multiset<int> my;
  std::multiset<int> orig;

  EXPECT_TRUE(my.empty());
  EXPECT_TRUE(orig.empty());
}

TEST(Multiset, InitListConstructor1) {
  s21::Multiset<int> my = {6, 3, 9, 1, 4};
  std::multiset<int> orig = {6, 3, 9, 1, 4};
  EXPECT_EQ(*my.begin(), *orig.begin());
}

TEST(Multiset, InitListConstructor2) {
  s21::Multiset<double> my = {6.83656, 3.256, 9.873, 1.756, 4.323};
  std::multiset<double> orig = {6.83656, 3.256, 9.873, 1.756, 4.323};
  EXPECT_EQ(*my.begin(), *orig.begin());
}

TEST(Multiset, InitListConstructor3) {
  s21::Multiset<std::string> my = {"abc",  "defg", "higk", "lmno",
                              "pqst", "uvwx", "yz"};
  std::multiset<std::string> orig = {"abc",  "defg", "higk", "lmno",
                                "pqst", "uvwx", "yz"};
  EXPECT_EQ(*my.begin(), *orig.begin());
}

TEST(Multiset, CopyConstructor) {
  s21::Multiset<int> a = {6, 3, 9, 1, 4};
  s21::Multiset<int> b(a);
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(*a.begin(), *b.begin());
}

TEST(Multiset, MoveConstructor) {
  s21::Multiset<int> a = {6, 3, 9, 1, 4};
  size_t a_size_before = a.size();
  s21::Multiset<int> b(std::move(a));
  EXPECT_TRUE(a.empty());
  EXPECT_EQ(b.size(), a_size_before);
}

TEST(Multiset, EqualOverload1) {
  s21::Multiset<int> a = {6, 3, 9, 1, 4};
  s21::Multiset<int> b = a;
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(*a.begin(), *b.begin());
}

TEST(Multiset, EqualOverload2) {
  s21::Multiset<int> a = {6, 3, 9, 1, 4};
  size_t a_size_before = a.size();
  s21::Multiset<int> b = std::move(a);
  EXPECT_TRUE(a.empty());
  EXPECT_EQ(b.size(), a_size_before);
}

TEST(Multiset, EqualOverload3) {
  s21::Multiset<int> a = {6, 3, 9, 1, 4};
  size_t a_size_before = a.size();
  a = a;
  EXPECT_EQ(a.size(), a_size_before);
}

TEST(Multiset, EqualOverload4) {
  s21::Multiset<int> a = {6, 3, 9, 1, 4};
  size_t a_size_before = a.size();
  s21::Multiset<int> b = {7, 12, 5};
  a = b;
  size_t b_size = b.size();
  size_t a_size_after = a.size();
  EXPECT_TRUE((a_size_after != a_size_before));
  EXPECT_TRUE((a_size_after == b_size));
}

TEST(Multiset, EqualOverload5) {
  s21::Multiset<int> a = {6, 3, 9, 1, 4};
  size_t a_size_before = a.size();
  s21::Multiset<int> b = {7, 12, 5};
  size_t b_size = b.size();
  a = std::move(b);
  size_t a_size_after = a.size();
  EXPECT_TRUE((a_size_after != a_size_before));
  EXPECT_TRUE((a_size_after == b_size));
  EXPECT_TRUE(b.size() == 0);
}

/* MULTISET ITERATORS */
/*----------------------------------------------------------------------------*/

TEST(Multiset, Begin) {
  s21::Multiset<int> my = {6, 3, 9, 1, 4};
  std::multiset<int> orig = {6, 3, 9, 1, 4};
  auto my_it = my.begin();
  auto orig_it = orig.begin();
  EXPECT_EQ(*my_it, *orig_it);
}

TEST(Multiset, BeginEmpty) {
  s21::Multiset<int> my;
  EXPECT_ANY_THROW(my.begin());
}

TEST(Multiset, EndEmpty) {
  s21::Multiset<int> my;
  EXPECT_ANY_THROW(my.end());
}

TEST(Multiset, IteratorEqual) {
  s21::Multiset<int> my = {6, 3, 9, 1, 4};
  auto it = my.begin();
  it = it;
  auto it2 = it;
  EXPECT_EQ(*it, *it2);
}

TEST(Multiset, IteratorDereference) {
  s21::Multiset<int> my = {6, 3, 9, 1, 4};
  auto it = my.end();
  EXPECT_ANY_THROW(*it);
}

TEST(Multiset, IteratorDereference2) {
  s21::Multiset<int> my = {6, 3, 9, 1, 4};
  auto it = my.end();
  EXPECT_ANY_THROW(it->key);
}

TEST(Multiset, IteratorIncrementDecrement) {
  s21::Multiset<int> my;
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

TEST(Multiset, IteratorDecrement) {
  s21::Multiset<int> my = {6, 3, 9};
  auto it = my.begin();
  ++it;
  ++it;
  --it;
  it--;
  EXPECT_EQ(*it, 3);
}

/* MULTISET CAPACITY */
/*----------------------------------------------------------------------------*/

TEST(Multiset, Empty1) {
  s21::Multiset<int> my = {6, 3, 9, 1, 4};
  EXPECT_FALSE(my.empty());
}

TEST(Multiset, Empty2) {
  s21::Multiset<int> my;
  EXPECT_TRUE(my.empty());
}

TEST(Multiset, Size) {
  s21::Multiset<int> my = {6, 3, 9, 1, 4};
  std::multiset<int> orig = {6, 3, 9, 1, 4};
  EXPECT_EQ(my.size(), orig.size());
}

TEST(Multiset, SizeEmpty) {
  s21::Multiset<int> my;
  std::multiset<int> orig;
  EXPECT_EQ(my.size(), orig.size());
}

/* MULTISET MODIFIERS */
/*----------------------------------------------------------------------------*/

TEST(Multiset, Clear) {
  s21::Multiset<int> my = {6, 3, 9, 1, 4};
  std::multiset<int> orig = {6, 3, 9, 1, 4};
  my.clear();
  orig.clear();
  EXPECT_EQ(my.size(), 0);
  EXPECT_EQ(my.size(), orig.size());
}

TEST(Multiset, ClearEmpty) {
  s21::Multiset<int> my;
  std::multiset<int> orig;
  my.clear();
  orig.clear();
  EXPECT_EQ(my.size(), 0);
  EXPECT_EQ(my.size(), orig.size());
}

TEST(Multiset, Insert) {
  s21::Multiset<int> my;
  my.insert(6);
  my.insert(3);
  my.insert(9);
  my.insert(1);
  my.insert(4);
  std::multiset<int> orig;
  orig.insert(6);
  orig.insert(3);
  orig.insert(9);
  orig.insert(1);
  orig.insert(4);
  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(*my.begin(), *orig.begin());
}

TEST(Multiset, InsertNotUnique1) {
  s21::Multiset<int> my;
  my.insert(60);
  my.insert(40);
  my.insert(70);
  my.insert(30);
  my.insert(65);
  my.insert(50);
  my.insert(80);

  my.insert(70);

  std::multiset<int> orig;
  orig.insert(60);
  orig.insert(40);
  orig.insert(70);
  orig.insert(30);
  orig.insert(65);
  orig.insert(50);
  orig.insert(80);

  orig.insert(70);

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.count(70), orig.count(70));
  EXPECT_EQ(*my.lower_bound(70), *orig.lower_bound(70));
}

TEST(Multiset, InsertNotUnique2) {
  s21::Multiset<int> my;
  my.insert(60);
  my.insert(40);
  my.insert(70);
  my.insert(30);
  my.insert(65);
  my.insert(50);
  my.insert(80);
  my.insert(50);
  my.insert(50);
  my.insert(50);

  std::multiset<int> orig;
  orig.insert(60);
  orig.insert(40);
  orig.insert(70);
  orig.insert(30);
  orig.insert(65);
  orig.insert(50);
  orig.insert(80);
  orig.insert(50);
  orig.insert(50);
  orig.insert(50);

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.count(50), orig.count(50));
  EXPECT_EQ(*my.lower_bound(50), *orig.lower_bound(50));
  EXPECT_EQ(*my.upper_bound(50), *orig.upper_bound(50));
}

TEST(Multiset, InsertMany) {
  s21::Multiset<std::string> my;
  my.insert_many("one", "two", "three");
  auto it = my.begin();
  EXPECT_EQ(my.size(), 3);
  EXPECT_EQ(*my.begin(), "one");
}

TEST(Multiset, InsertManyNotUinique) {
  s21::Multiset<std::string> my;
  my.insert_many("one", "two", "three", "one", "one");
  auto it = my.begin();
  EXPECT_EQ(my.size(), 5);
  EXPECT_EQ(*my.begin(), "one");
}

TEST(Multiset, Erase) {
  s21::Multiset<int> my = {6, 3, 9, 1, 4};
  std::set<int> orig = {6, 3, 9, 1, 4};

  auto my_it = my.begin();
  my_it++;
  my.erase(my_it);

  auto orig_it = orig.begin();
  orig_it++;
  orig.erase(orig_it);

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_EQ(my.size(), 4);
}

TEST(Multiset, EraseNotUnique1) {
  s21::Multiset<int> my;
  my.insert(6);
  my.insert(3);
  auto my_it = my.insert(9);
  my.insert(1);
  my.insert(4);
  my.insert(9);
  my.insert(9);

  size_t count_before = my.count(9);

  std::multiset<int> orig;
  orig.insert(6);
  orig.insert(3);
  auto orig_it = orig.insert(9);
  orig.insert(1);
  orig.insert(4);
  orig.insert(9);
  orig.insert(9);

  my.erase(my_it);
  orig.erase(orig_it);

  size_t count_after = my.count(9);

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_TRUE(count_before != count_after);
}

TEST(Multiset, EraseNotUnique2) {
  s21::Multiset<int> my;
  my.insert(6);
  my.insert(3);
  auto my_it = my.insert(9);
  my.insert(1);
  my.insert(4);
  auto my_it2 = my.insert(9);


  std::multiset<int> orig;
  orig.insert(6);
  orig.insert(3);
  auto orig_it = orig.insert(9);
  orig.insert(1);
  orig.insert(4);
  auto orig_it2 = orig.insert(9);

  my.erase(my_it);
  my.erase(my_it2);
  orig.erase(orig_it);
  orig.erase(orig_it2);


  EXPECT_EQ(my.size(), orig.size());
  EXPECT_FALSE(my.contains(9));
}

TEST(Multiset, Swap) {
  s21::Multiset<int> my = {6, 3, 9, 5, 4};
  std::multiset<int> orig = {6, 3, 9, 5, 4};
  int my_begin_before = *my.begin();
  size_t my_size_before = my.size();

  s21::Multiset<int> my2 = {1, 2, 3};
  std::multiset<int> orig2 = {1, 2, 3};
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

TEST(Multiset, SwapEmptyAndNonEmpty) {
  s21::Multiset<int> my = {6, 3, 9, 5, 4};
  size_t my_size_before = my.size();
  s21::Multiset<int> my2;
  size_t my2_size_before = my2.size();

  my.swap(my2);

  size_t my_size_after = my.size();
  size_t my2_size_after = my2.size();

  EXPECT_EQ(my_size_after, my2_size_before);
  EXPECT_EQ(my2_size_after, my_size_before);
}

TEST(Multiset, Merge) {
  s21::Multiset<int> my = {6, 3, 9, 5, 4};
  std::set<int> orig = {6, 3, 9, 5, 4};
  int my_begin_before = *my.begin();
  size_t my_size_before = my.size();

  s21::Multiset<int> my2 = {1, 1, 3};
  std::set<int> orig2 = {1, 1, 3};

  my.merge(my2);
  orig.merge(orig2);

  int my_begin_after = *my.begin();
  size_t my_size_after = my.size();

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_TRUE((my_size_before != my_size_after));
  EXPECT_TRUE((my_begin_before != my_begin_after));
}

TEST(Multiset, MergeEmpty) {
  s21::Multiset<int> my = {6, 3, 9, 5, 4};
  std::set<int> orig = {6, 3, 9, 5, 4};
  size_t my_size_before = my.size();

  s21::Multiset<int> my2;
  std::set<int> orig2;

  my.merge(my2);
  orig.merge(orig2);

  size_t my_size_after = my.size();

  EXPECT_EQ(my.size(), orig.size());
  EXPECT_TRUE((my_size_before == my_size_after));
}

/* MULTISET LOOKUP */
/*----------------------------------------------------------------------------*/

