/*!
 * \author: Armand Leclercq
 * \file: add.cc
 * \date: Mon 30 Oct 2017 07:51:15 AM UTC
 */
#include <gtest/gtest.h>

#include <add.hh>

TEST(Add, Positives)
{
  typedef Long<10> lhs;
  typedef Long<20> rhs;
  typedef maths::add<lhs, rhs>::type result;
  ASSERT_EQ(30, result());
}
