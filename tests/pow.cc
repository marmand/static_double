/*!
 * \author: Armand Leclercq
 * \file: pow.cc
 * \date: Wed 01 Nov 2017 12:36:38 PM UTC
 */
#include <gtest/gtest.h>

#include <pow.hh>

TEST(Pow, Long_nul)
{
  typedef Long<1> lhs;
  typedef Long<0> rhs;
  typedef maths::pow<lhs, rhs>::type result;
  ASSERT_EQ(std::pow(1, 0), result());
}

TEST(Pow, Long_one)
{
  typedef Long<0> lhs;
  typedef Long<1> rhs;
  typedef maths::pow<lhs, rhs>::type result;
  ASSERT_EQ(std::pow(0, 1), result());
}

TEST(Pow, Long_neg)
{
  typedef Long<1> lhs;
  typedef Long<-1> rhs;
  typedef maths::pow<lhs, rhs>::type result;
  ASSERT_EQ(std::pow(1, -1), result());
}
