/*!
 * \author: Armand Leclercq
 * \file: sub.cc
 * \date: Mon 30 Oct 2017 07:50:39 AM UTC
 */
#include <gtest/gtest.h>

#include <sub.hh>

TEST(Add, Positives)
{
  typedef Long<20> lhs;
  typedef Long<10> rhs;
  typedef maths::sub<lhs, rhs>::type result;
  ASSERT_EQ(10, result());
}
