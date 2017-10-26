/*!
 * \author: Armand Leclercq
 * \file: abs.cc
 * \date: Thu 26 Oct 2017 08:32:43 PM UTC
 */
#include <gtest/gtest.h>

#include <abs.hh>

TEST(Abs, long_positive)
{
  typedef Long<10> lhs;
  typedef maths::abs<lhs>::type result;
  ASSERT_EQ(10, result());
}

TEST(Abs, long_negative)
{
  typedef Long<-10> lhs;
  typedef maths::abs<lhs>::type result;
  ASSERT_EQ(10, result());
}

TEST(Abs, double_positive)
{
  typedef DOUBLE(1, 12) lhs;
  typedef maths::abs<lhs>::type result;
  ASSERT_EQ(1.12, result());
}

TEST(Abs, double_negative)
{
  typedef DOUBLE(-1, 12) lhs;
  typedef maths::abs<lhs>::type result;
  ASSERT_EQ(1.12, result());
}
