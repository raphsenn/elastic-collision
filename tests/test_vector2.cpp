#include "./vector2.h"
#include <gtest/gtest.h>

// Constructor tests
TEST(test_vector2, constructor) {
  Vector2 vec(1.0, 2.0);
  ASSERT_DOUBLE_EQ(vec.x, 1.0);
  ASSERT_DOUBLE_EQ(vec.y, 2.0);
}

// Add method tests
TEST(test_vector2, add) {
  Vector2 vec_1(1.0, 2.0);
  Vector2 vec_2(2.0, 3.0);
  double scalar = 1.5;

  Vector2 result = vec_1.add(vec_2, scalar);

  ASSERT_DOUBLE_EQ(result.x, 4.0);  // 1 + 2 * 1.5 = 4.0
  ASSERT_DOUBLE_EQ(result.y, 6.5);  // 2 + 3 * 1.5 = 6.5
}

// AddVectors method tests
TEST(test_vector2, addVectors_method) {
  Vector2 vec_1(1.0, 2.0);
  Vector2 vec_2(2.0, 3.0);
  Vector2 vec_3(3.0, 4.0);

  Vector2 result = vec_1.addVectors(vec_2, vec_3);

  ASSERT_DOUBLE_EQ(result.x, 5.0);  // 2 + 3 = 5.0
  ASSERT_DOUBLE_EQ(result.y, 7.0);  // 3 + 4 = 7.0
}

// SubVectors method tests
TEST(test_vector2, subVectors_method) {
  Vector2 vec_1(3.0, 4.0);
  Vector2 vec_2(1.0, 2.0);
  Vector2 vec_3(2.0, 1.0);

  Vector2 result = vec_1.subVectors(vec_2, vec_3);

  ASSERT_DOUBLE_EQ(result.x, -1.0);  // 1 - 2 = -1.0
  ASSERT_DOUBLE_EQ(result.y, 1.0);  // 2 - 1 = 1.0
}

// ScalarMultVector tests
TEST(test_vector2, scalarMultVector) {
  Vector2 vec(1.0, 2.0);
  double scalar = 3.0;

  Vector2 result = vec.scalarMultVector(vec, scalar);

  ASSERT_DOUBLE_EQ(result.x, 3.0);
  ASSERT_DOUBLE_EQ(result.y, 6.0);
}

// ScaleVector tests
TEST(test_vector2, scaleVector) {
  Vector2 vec(1.0, 2.0);
  double scalar = 3.0;

  vec.scaleVector(scalar);

  ASSERT_DOUBLE_EQ(vec.x, 3.0);
  ASSERT_DOUBLE_EQ(vec.y, 6.0);
}

// Dot tests
TEST(test_vector2, dot) {
  Vector2 vec_1(1.0, 2.0);
  Vector2 vec_2(2.0, 3.0);

  double result = vec_1.dot(vec_2);

  ASSERT_DOUBLE_EQ(result, 8.0);
}

// Length tests
TEST(test_vector2, length) {
  Vector2 vec(3.0, 4.0);

  double result = vec.length();

  ASSERT_DOUBLE_EQ(result, 5.0);
}

// Equality tests
TEST(test_vector2, equality) {
  Vector2 vec_1(1.0, 2.0);
  Vector2 vec_2(1.0, 2.0);
  Vector2 vec_3(2.0, 3.0);

  ASSERT_TRUE(vec_1 == vec_2);
  ASSERT_FALSE(vec_1 == vec_3);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
