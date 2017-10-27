/*!
 * \author: Armand Leclercq
 * \file: mod.cc
 * \date: Fri 27 Oct 2017 06:26:18 AM UTC
 */
#include <gtest/gtest.h>

#include <mod.hh>

/// \todo: put that test in a compilation test, making that failed to compile
#if 0
TEST(Mod, 0)
{
  typedef Long<10> lhs;
  typedef Long<0> rhs;
  typedef maths::mod<lhs, rhs>::type result;
  ASSERT_EQ(0, result());
}
#endif

TEST(Mod, one)
{
  typedef Long<10> lhs;
  typedef Long<1> rhs;
  typedef maths::mod<lhs, rhs>::type result;
  ASSERT_EQ(10 % 1, result());
}

TEST(Mod, two)
{
  typedef Long<10> lhs;
  typedef Long<2> rhs;
  typedef maths::mod<lhs, rhs>::type result;
  ASSERT_EQ(10 % 2, result());
}

TEST(Mod, three)
{
  typedef Long<10> lhs;
  typedef Long<3> rhs;
  typedef maths::mod<lhs, rhs>::type result;
  ASSERT_EQ(10 % 3, result());
}
