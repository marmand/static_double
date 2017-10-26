/*!
 * \author: Armand Leclercq
 * \file: eq.cc
 * \date: Thu 26 Oct 2017 08:27:26 PM UTC
 */
#include <gtest/gtest.h>

#include <eq.hh>

TEST(Eq, long_equals)
{
  typedef Long<10> lhs;
  typedef Long<10> rhs;
  typedef maths::eq<lhs, rhs> result;
  ASSERT_TRUE(result::value);
}

TEST(Eq, long_not_equals)
{
  typedef Long<10> lhs;
  typedef Long<20> rhs;
  typedef maths::eq<lhs, rhs> result;
  ASSERT_FALSE(result::value);
}

TEST(Eq, double_equals)
{
  typedef DOUBLE(2, 12) lhs;
  typedef DOUBLE(2, 12) rhs;
  typedef maths::eq<lhs, rhs> result;
  ASSERT_TRUE(result::value);
}

TEST(Eq, double_not_equals)
{
  typedef DOUBLE(3, 124) lhs;
  typedef DOUBLE(2, 212) rhs;
  typedef maths::eq<lhs, rhs> result;
  ASSERT_FALSE(result::value);
}
