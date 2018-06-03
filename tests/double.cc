/*!
 * \author: Armand Leclercq
 * \file: double.cc
 * \date: Wed 25 Oct 2017 06:31:38 AM UTC
 */
#include <gtest/gtest.h>

#include <double.hh>

TEST(Double, zero)
{
  typedef DOUBLE(0, 0) value;
  // Construct and implicit cast to double
  ASSERT_EQ(0, value());
  ASSERT_EQ(0, value::Ent);
  ASSERT_EQ(0, value::Dec);
  ASSERT_EQ(1, value::Mult);
  ASSERT_FALSE(value::Neg);
  ASSERT_TRUE(value::Zero);
}

TEST(Double, pi)
{
  typedef DOUBLE(3, 14) value;
  // Construct and implicit cast to double
  ASSERT_EQ(3.14, value());
  ASSERT_EQ(3, value::Ent);
  ASSERT_EQ(14, value::Dec);
  ASSERT_EQ(2, value::Mult);
  ASSERT_FALSE(value::Neg);
  ASSERT_FALSE(value::Zero);
}

TEST(Double, minus_pi)
{
  typedef DOUBLE(-3, 14) value;
  // Construct and implicit cast to double
  ASSERT_EQ(-3.14, value());
  ASSERT_EQ(-3, value::Ent);
  ASSERT_EQ(14, value::Dec);
  ASSERT_EQ(2, value::Mult);
  ASSERT_TRUE(value::Neg);
  ASSERT_FALSE(value::Zero);
}

TEST(Double, three_zero_one)
{
  typedef DOUBLE(3, 01) value;
  ASSERT_EQ(3.01, value());
  typedef SMALL_DOUBLE(3, 1, 1) other;
  ASSERT_EQ(3.01, other());
  ASSERT_EQ(value(), other());
}

TEST(Double, constants)
{
  ASSERT_FLOAT_EQ(M_E, maths::e());
  ASSERT_FLOAT_EQ(M_PI, maths::pi());
}
