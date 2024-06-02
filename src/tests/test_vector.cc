#include <gtest/gtest.h>
#include "../containers/s21_vector.h"

TEST(constructor, Default) {
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

TEST(constructor, parametrized) {
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

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}