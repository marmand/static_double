/*!
 * \author: Armand Leclercq
 * \file: convert.cc
 * \date: Fri 27 Oct 2017 05:58:32 AM UTC
 */
#include <gtest/gtest.h>

#include <convert.hh>

TEST(Convert, double_to_long)
{
  typedef DOUBLE(3, 0) lhs;
  typedef maths::convert<lhs>::type result;
  ASSERT_EQ(3, result());
}

TEST(Convert, long_to_double)
{
  typedef Long<3> lhs;
  typedef maths::convert<lhs>::type result;
  ASSERT_FLOAT_EQ(3.0, result());
}
