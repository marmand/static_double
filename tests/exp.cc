/*!
 * \author: Armand Leclercq
 * \file: exp.cc
 * \date: dim. 30 juin 2019 16:30:10 CEST
 */
#include <exp.hh>

#include <gtest/gtest.h>

#include <cmath>

template <typename T>
class ExpTest: public ::testing::Test
{
  using lhs = T;
  using result = typename maths::exp<lhs>::type;
protected:
  lhs lhs_;
  result result_;
}; // class ExpTest

using MyTypes = ::testing::Types
                <
                  Long<1>
                  // , Long<2>
                  // , Long<3>
                  // , Long<4>
                >;

TYPED_TEST_SUITE(ExpTest, MyTypes, );

TYPED_TEST(ExpTest, Exp)
{
  // +0 forces integral type
  ASSERT_DOUBLE_EQ(std::exp(this->lhs_ + 0), this->result_);
}
