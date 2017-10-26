/*!
 * \author: Armand Leclercq
 * \file: max.cc
 * \date: Thu 26 Oct 2017 08:39:13 PM UTC
 */
#include <gtest/gtest.h>

#include <max.hh>

TEST(Max, long_positives_lhs)
{
  typedef Long<20> lhs;
  typedef Long<10> rhs;
  typedef maths::max<lhs, rhs>::type result;
  ASSERT_EQ(20, result());
}

TEST(Max, long_positives_rhs)
{
  typedef Long<10> lhs;
  typedef Long<20> rhs;
  typedef maths::max<lhs, rhs>::type result;
  ASSERT_EQ(20, result());
}

TEST(Max, long_positives_both)
{
  typedef Long<20> lhs;
  typedef Long<20> rhs;
  typedef maths::max<lhs, rhs>::type result;
  ASSERT_EQ(20, result());
}

TEST(Max, double_positives_lhs)
{
  typedef DOUBLE(3, 14) lhs;
  typedef DOUBLE(1, 8) rhs;
  typedef maths::max<lhs, rhs>::type result;
  ASSERT_EQ(3.14, result());
}

TEST(Max, double_positives_rhs)
{
  typedef DOUBLE(1, 8) lhs;
  typedef DOUBLE(3, 14) rhs;
  typedef maths::max<lhs, rhs>::type result;
  ASSERT_EQ(3.14, result());
}

TEST(Max, double_positives_both)
{
  typedef DOUBLE(3, 14) lhs;
  typedef DOUBLE(3, 14) rhs;
  /// \fixme: max cannot give a result in case of a double equality
  // typedef maths::max<lhs, rhs>::type result;
  // ASSERT_EQ(3.14, result());
}
