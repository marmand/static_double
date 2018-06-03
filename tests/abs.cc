/*!
 * \author: Armand Leclercq
 * \file: abs.cc
 * \date: Thu 26 Oct 2017 08:32:43 PM UTC
 */
#include <cmath>

#include <gtest/gtest.h>

#include <abs.hh>

template <typename T>
class AbsTest: public ::testing::Test
{
  using lhs = T;
  using result = typename maths::abs<lhs>::type;
protected:
  lhs lhs_;
  result result_;
}; // class AbsTest

using MyTypes = ::testing::Types
                  <
                    Long<10>
                    , Long<-10>
                    , DOUBLE(1, 12)
                    , DOUBLE(-1, 12)
                  >;

TYPED_TEST_CASE(AbsTest, MyTypes);

TYPED_TEST(AbsTest, Div)
{
  ASSERT_EQ(std::abs(this->lhs_), this->result_);
}
