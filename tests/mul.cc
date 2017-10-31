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

TEST(Mul, Double_positives)
{
  typedef DOUBLE(1, 2) lhs;
  typedef DOUBLE(2, 4) rhs;
  typedef maths::mul<lhs, rhs>::type lhs_x_rhs;
  typedef maths::mul<rhs, lhs>::type rhs_x_lhs;
  ASSERT_FLOAT_EQ(1.2 * 2.4, lhs_x_rhs());
  ASSERT_FLOAT_EQ(1.2 * 2.4, rhs_x_lhs());
}

TEST(Mul, Double_negative)
{
  typedef DOUBLE(1, 2) lhs;
  typedef DOUBLE(-2, 4) rhs;
  typedef maths::mul<lhs, rhs>::type lhs_x_rhs;
  typedef maths::mul<rhs, lhs>::type rhs_x_lhs;
  ASSERT_FLOAT_EQ(1.2 * -2.4, lhs_x_rhs());
  ASSERT_FLOAT_EQ(1.2 * -2.4, rhs_x_lhs());
}

TEST(Mul, Double_negatives)
{
  typedef DOUBLE(-1, 2) lhs;
  typedef DOUBLE(-2, 4) rhs;
  typedef maths::mul<lhs, rhs>::type lhs_x_rhs;
  typedef maths::mul<rhs, lhs>::type rhs_x_lhs;
  ASSERT_FLOAT_EQ(-1.2 * -2.4, lhs_x_rhs());
  ASSERT_FLOAT_EQ(-1.2 * -2.4, rhs_x_lhs());
}

#if 0
/// \fixme: Not Implemented Yet
TEST(Mul, Double_Long)
{
  typedef DOUBLE(1, 2) lhs;
  typedef Long<2> rhs;
  typedef maths::mul<lhs, rhs>::type lhs_x_rhs;
  typedef maths::mul<rhs, lhs>::type rhs_x_lhs;
  ASSERT_FLOAT_EQ(1.2 * 2, lhs_x_rhs());
  ASSERT_FLOAT_EQ(1.2 * 2, rhs_x_lhs());
}
#endif
