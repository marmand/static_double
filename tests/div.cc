/*!
 * \author: Armand Leclercq
 * \file: div.cc
 * \date: Tue 31 Oct 2017 08:45:56 PM UTC
 */
#include <gtest/gtest.h>

#include <div.hh>

TEST(Div, Long_positives)
{
  typedef Long<10> lhs;
  typedef Long<1> rhs;
  typedef maths::div<lhs, rhs>::type result;
  ASSERT_EQ(10 / 1, result());
}
