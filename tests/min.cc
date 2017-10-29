/*!
 * \author: Armand Leclercq
 * \file: min.cc
 * \date: Sun 29 Oct 2017 09:30:46 PM UTC
 */
#include <gtest/gtest.h>

#include <min.hh>

TEST(Min, long_positives_rhs)
{
  typedef Long<20> lhs;
  typedef Long<10> rhs;
  typedef maths::min<lhs, rhs>::type result;
  ASSERT_EQ(10, result());
}

TEST(Min, long_positives_lhs)
{
  typedef Long<10> lhs;
  typedef Long<20> rhs;
  typedef maths::min<lhs, rhs>::type result;
  ASSERT_EQ(10, result());
}

TEST(Min, long_positives_both)
{
  typedef Long<20> lhs;
  typedef Long<20> rhs;
  typedef maths::min<lhs, rhs>::type result;
  ASSERT_EQ(20, result());
}

TEST(Min, double_positives_rhs)
{
  typedef DOUBLE(3, 14) lhs;
  typedef DOUBLE(1, 8) rhs;
  typedef maths::min<lhs, rhs>::type result;
  ASSERT_EQ(1.8, result());
}

TEST(Min, double_positives_lhs)
{
  typedef DOUBLE(1, 8) lhs;
  typedef DOUBLE(3, 14) rhs;
  typedef maths::min<lhs, rhs>::type result;
  ASSERT_EQ(1.8, result());
}

TEST(Min, double_positives_both)
{
  typedef DOUBLE(3, 14) lhs;
  typedef DOUBLE(3, 14) rhs;
  /// \fixme: min cannot give a result in case of a double equality
  // typedef maths::min<lhs, rhs>::type result;
  // ASSERT_EQ(3.14, result());
}
