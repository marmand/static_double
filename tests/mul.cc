/*!
 * \author: Armand Leclercq
 * \file: mul.cc
 * \date: Mon 30 Oct 2017 07:59:18 AM UTC
 */
#include <gtest/gtest.h>

#include <mul.hh>

TEST(Mul, positives)
{
  typedef Long<10> lhs;
  typedef Long<20> rhs;
  typedef maths::mul<lhs, rhs>::type result;
  ASSERT_EQ(200, result());
}
