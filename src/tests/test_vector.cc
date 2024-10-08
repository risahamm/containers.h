#include <gtest/gtest.h>
#include "../containers/s21_vector.h"

TEST(Vector, DefaultConstructor1) {
  s21::Vector<int> a;
  s21::Vector<double> b;
  s21::Vector<char> c;
  int i = a.size();
  int j = b.size();
  int k = c.size();
  EXPECT_EQ(i, 0);
  EXPECT_EQ(j, 0);
  EXPECT_EQ(k, 0);
}

TEST(Vector, ParametrizedConstructor) {
  s21::Vector<int> a(2);
  s21::Vector<double> b(45);
  s21::Vector<char> c(200);
  int i = a.size();
  int j = b.size();
  int k = c.size();
  int l = a.capacity();
  int m = b.capacity();
  int n = c.capacity();
  EXPECT_EQ(i, 2);
  EXPECT_EQ(j, 45);
  EXPECT_EQ(k, 200);
  EXPECT_EQ(l, 2);
  EXPECT_EQ(m, 45);
  EXPECT_EQ(n, 200);
}

TEST(Vector, InitListConstructor) {
  s21::Vector<int> a = {1, 2, 3, 4, 5};
  s21::Vector<double> b = {};
  s21::Vector<char> c = {'a', 'b', 'c'};
  int i = a.size();
  int j = b.size();
  int k = c.size();
  EXPECT_EQ(i, 5);
  EXPECT_EQ(j, 0);
  EXPECT_EQ(k, 3);
}

TEST(Vector, DefaultConstructor2) {
  s21::Vector<int> our_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(Vector, SizeConstructor) {
  const size_t size = 5;
  s21::Vector<int> our_vector(size);
  std::vector<int> std_vector(size);
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(our_vector[i], std_vector[i]);
  }
}

TEST(Vector, SizeConstructorZero) {
  const size_t size = 0;
  s21::Vector<int> our_vector(size);
  std::vector<int> std_vector(size);
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(Vector, InitializerListEmpty) {
  s21::Vector<int> our_vector = {};
  std::vector<int> std_vector = {};
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(Vector, InitializerListConstructor) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[0], std_vector[0]);
  EXPECT_EQ(our_vector[4], std_vector[4]);
}

TEST(Vector, CopyConstructorEmpty) {
  s21::Vector<int> our_vector;
  s21::Vector<int> our_vector_copy(our_vector);
  std::vector<int> std_vector;
  std::vector<int> std_vector_copy(std_vector);
  EXPECT_EQ(our_vector_copy.empty(), std_vector_copy.empty());
  EXPECT_EQ(our_vector_copy.size(), std_vector_copy.size());
}

TEST(Vector, ConstructorCopy) {
  s21::Vector<int> our_vector = {1, 2, 3};
  s21::Vector<int> our_vector_copy(our_vector);
  EXPECT_EQ(our_vector_copy.size(), our_vector.size());
  for (size_t i = 0; i < our_vector.size(); ++i) {
    EXPECT_EQ(our_vector_copy[i], our_vector[i]);
  }
}

TEST(Vector, MoveConstructorEmpty) {
  s21::Vector<int> our_vector;
  s21::Vector<int> our_vector_copy(std::move(our_vector));
  EXPECT_TRUE(our_vector_copy.empty());
  EXPECT_EQ(our_vector_copy.size(), (size_t)0);
}

TEST(Vector, MoveConstructorNonEmpty) {
  s21::Vector<int> our_vector = {1, 2, 3};
  s21::Vector<int> our_vector_copy(std::move(our_vector));
  std::vector<int> std_vector = {1, 2, 3};
  std::vector<int> std_vector_copy(std::move(std_vector));
  EXPECT_EQ(our_vector_copy.size(), std_vector_copy.size());
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(Vector, DestructorEmpty) {
  s21::Vector<int> *v = new s21::Vector<int>();
  delete v;
}

TEST(Vector, DestructorNonEmpty) {
  s21::Vector<int> *v = new s21::Vector<int>{1, 2, 3};
  delete v;
}

TEST(Vector, MoveAssignmentOperatorNonEmptyToEmpty) {
  s21::Vector<int> our_vector = {1, 2, 3};
  s21::Vector<int> our_vector_move;
  std::vector<int> std_vector = {1, 2, 3};
  std::vector<int> std_vector_move;
  our_vector_move = std::move(our_vector);
  std_vector_move = std::move(std_vector);
  EXPECT_EQ(our_vector_move.size(), std_vector_move.size());
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(Vector, MoveAssignmentOperatorNonEmptyToNonEmpty) {
  s21::Vector<int> our_vector = {1, 2, 3};
  s21::Vector<int> our_vector_move = {4, 5, 6};
  std::vector<int> std_vector = {1, 2, 3};
  std::vector<int> std_vector_move = {4, 5, 6};
  our_vector_move = std::move(our_vector);
  std_vector_move = std::move(std_vector);
  EXPECT_EQ(our_vector_move.size(), std_vector_move.size());
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(Vector, AtValid) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.at(0), std_vector.at(0));
  EXPECT_EQ(our_vector.at(2), std_vector.at(2));
  EXPECT_EQ(our_vector.at(4), std_vector.at(4));
}

TEST(Vector, AtInvalid) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  EXPECT_THROW(our_vector.at(5), std::out_of_range);
  EXPECT_THROW(our_vector.at(10), std::out_of_range);
}

TEST(Vector, IndexOperatorValid) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector[0], std_vector[0]);
  EXPECT_EQ(our_vector[2], std_vector[2]);
  EXPECT_EQ(our_vector[4], std_vector[4]);
}

TEST(Vector, ConstIndexOperatorValidI) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector[0], std_vector[0]);
  EXPECT_EQ(our_vector[2], std_vector[2]);
  EXPECT_EQ(our_vector[4], std_vector[4]);
}

TEST(Vector, FrontConst) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.front(), std_vector.front());
}

TEST(Vector, BackConst) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(our_vector.back(), std_vector.back());
}

TEST(Vector, Data) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  int *dataPtr = our_vector.data();
  int *dataPtr1 = std_vector.data();
  EXPECT_EQ(*dataPtr, *dataPtr1);
  *dataPtr = 10;
  *dataPtr1 = 10;
  EXPECT_EQ(our_vector[0], std_vector[0]);
}

TEST(Vector, DataEmpty) {
  s21::Vector<int> our_vector;
  int *dataPtr = our_vector.data();
  EXPECT_EQ(dataPtr, nullptr);
}

TEST(Vector, Begin) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  auto it = our_vector.begin();
  auto it1 = std_vector.begin();
  EXPECT_EQ(*it, *it1);
  *it = 10;
  *it1 = 10;
  EXPECT_EQ(our_vector[0], std_vector[0]);
}

TEST(Vector, BeginEmpty) {
  s21::Vector<int> our_vector;
  auto it = our_vector.begin();
  EXPECT_EQ(it, our_vector.end());
}

TEST(Vector, End) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  auto it = our_vector.end();
  auto beginIt = our_vector.begin();
  EXPECT_NE(it, beginIt);
}

TEST(Vector, EndEmpty) {
  s21::Vector<int> our_vector;
  auto it = our_vector.end();
  EXPECT_EQ(it, our_vector.begin());
}

TEST(Vector, Empty) {
  s21::Vector<int> our_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(Vector, EmptyNonEmptyVector) {
  s21::Vector<int> our_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(our_vector.empty(), std_vector.empty());
}

TEST(Vector, SizeEmpty) {
  s21::Vector<int> our_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(Vector, Size) {
  s21::Vector<int> our_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(Vector, MaxSize) {
  s21::Vector<int> our_vector;
  EXPECT_GT(our_vector.max_size(), 0U);
}

TEST(Vector, ReserveIncreaseCapacity) {
  s21::Vector<int> our_vector;
  size_t initialCapacity = our_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  our_vector.reserve(newCapacity);
  EXPECT_GE(our_vector.capacity(), newCapacity);
}

TEST(Vector, ReserveDecreaseCapacity) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  size_t initialCapacity = our_vector.capacity();
  size_t newCapacity = initialCapacity - 2;
  our_vector.reserve(newCapacity);
  EXPECT_LE(our_vector.capacity(), initialCapacity);
  EXPECT_GE(our_vector.capacity(), newCapacity);
}

TEST(Vector, CapacityEmpty) {
  s21::Vector<int> our_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(our_vector.capacity(), std_vector.capacity());
}

TEST(Vector, CapacityNonEmptyVector) {
  s21::Vector<int> our_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(our_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(our_vector.size(), std_vector.size());
}

TEST(Vector, ShrinkToFitEmptyVector) {
  s21::Vector<int> our_vector;
  our_vector.shrink_to_fit();
  EXPECT_GE(our_vector.capacity(), 0U);
}

TEST(Vector, ShrinkToFitNonEmptyVector) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  size_t initialCapacity = our_vector.capacity();
  our_vector.pop_back();
  our_vector.shrink_to_fit();
  EXPECT_LE(our_vector.capacity(), our_vector.size());
  EXPECT_LE(our_vector.capacity(), initialCapacity);
}

TEST(Vector, ClearEmptyVector) {
  s21::Vector<int> our_vector;
  our_vector.clear();
  EXPECT_TRUE(our_vector.empty());
  EXPECT_EQ(our_vector.size(), 0U);
  EXPECT_GE(our_vector.capacity(), 0U);
}

TEST(Vector, ClearNonEmptyVector) {
  s21::Vector<int> our_vector = {1, 2, 3, 4, 5};
  our_vector.clear();
  EXPECT_TRUE(our_vector.empty());
  EXPECT_EQ(our_vector.size(), 0U);
  EXPECT_GE(our_vector.capacity(), 0U);
}

TEST(Vector, InsertBeginning) {
  s21::Vector<int> our_vector = {2, 3, 4};
  auto it = our_vector.insert(our_vector.begin(), 1);
  std::vector<int> std_vector = {2, 3, 4};
  auto it1 = std_vector.insert(std_vector.begin(), 1);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[0], std_vector[0]);
  EXPECT_EQ(*it, *it1);
}

TEST(Vector, InsertMiddle) {
  s21::Vector<int> our_vector = {2, 3, 4};
  auto it = our_vector.insert(our_vector.begin() + 1, 2);
  std::vector<int> std_vector = {2, 3, 4};
  auto it1 = std_vector.insert(std_vector.begin() + 1, 2);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[1], std_vector[1]);
  EXPECT_EQ(*it, *it1);
}

TEST(Vector, InsertEnd) {
  s21::Vector<int> our_vector = {2, 3, 4};
  auto it = our_vector.insert(our_vector.end(), 5);
  std::vector<int> std_vector = {2, 3, 4};
  auto it1 = std_vector.insert(std_vector.end(), 5);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[3], std_vector[3]);
  EXPECT_EQ(*it, *it1);
}

TEST(Vector, EraseBeginning) {
  s21::Vector<int> our_vector = {1, 2, 3, 4};
  our_vector.erase(our_vector.begin());
  std::vector<int> std_vector = {1, 2, 3, 4};
  std_vector.erase(std_vector.begin());
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[0], std_vector[0]);
}

TEST(Vector, EraseMiddle) {
  s21::Vector<int> our_vector = {1, 2, 3, 4};
  our_vector.erase(our_vector.begin() + 1);
  std::vector<int> std_vector = {1, 2, 3, 4};
  std_vector.erase(std_vector.begin() + 1);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[1], std_vector[1]);
}

TEST(Vector, EraseEnd) {
  s21::Vector<int> our_vector = {1, 2, 3, 4};
  our_vector.erase(our_vector.end() - 1);
  std::vector<int> std_vector = {1, 2, 3, 4};
  std_vector.erase(std_vector.end() - 1);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[2], std_vector[2]);
}

TEST(Vector, PushBackEmptyVector) {
  s21::Vector<int> our_vector;
  our_vector.push_back(1);
  std::vector<int> std_vector;
  std_vector.push_back(1);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[0], std_vector[0]);
}

TEST(Vector, PushBackNonEmptyVector) {
  s21::Vector<int> our_vector = {1, 2, 3};
  our_vector.push_back(4);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.push_back(4);
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector[3], std_vector[3]);
}

TEST(Vector, PopBackNonEmptyVector) {
  s21::Vector<int> our_vector = {1, 2, 3};
  our_vector.pop_back();
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.pop_back();
  EXPECT_EQ(our_vector.size(), std_vector.size());
  EXPECT_EQ(our_vector.back(), std_vector.back());
}

TEST(Vector, PopBackEmptyVector) {
  s21::Vector<int> our_vector;
  our_vector.pop_back();
  EXPECT_EQ(our_vector.empty(), 1);
}

TEST(Vector, SwapNonEmptyVectors) {
  s21::Vector<int> our_vector = {1, 2, 3};
  s21::Vector<int> our_vector_swap = {4, 5, 6};
  our_vector.swap(our_vector_swap);
  EXPECT_EQ(our_vector.size(), 3U);
  EXPECT_EQ(our_vector_swap.size(), 3U);
  EXPECT_EQ(our_vector[0], 4);
  EXPECT_EQ(our_vector[2], 6);
  EXPECT_EQ(our_vector_swap[0], 1);
  EXPECT_EQ(our_vector_swap[2], 3);
}

TEST(Vector, SwapEmptyAndNonEmptyVectors) {
  s21::Vector<int> our_vector;
  s21::Vector<int> our_vector_swap = {1, 2, 3};
  our_vector.swap(our_vector_swap);
  EXPECT_EQ(our_vector.size(), 3U);
  EXPECT_FALSE(our_vector.empty());
  EXPECT_EQ(our_vector_swap.size(), 0U);
  EXPECT_TRUE(our_vector_swap.empty());
}

TEST(VectorTest, InsertManyBack) {
  s21::Vector<int> our_vector = {1, 2, 3, 4};
  our_vector.insert_many_back(5, 6, 7);
  EXPECT_EQ(our_vector.size(), 7U);
  for (std::size_t i = 0; i < our_vector.size(); ++i) {
    EXPECT_EQ(our_vector[i], (int)i + 1);
  }
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}