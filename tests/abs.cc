/*!
 * \author: Armand Leclercq
 * \file: abs.cc
 * \date: Thu 26 Oct 2017 08:32:43 PM UTC
 */
#include <abs.hh>

#include <gtest/gtest.h>

#include <cmath>
#include <limits>

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

                    , Long<std::numeric_limits<long>::max()>
                    // |min| cannot be represented but |min + 1| can
                    , Long<std::numeric_limits<long>::min() + 1>
                    , Long<std::numeric_limits<long long>::max()>
                    // |min| cannot be represented but |min + 1| can
                    , Long<std::numeric_limits<long long>::min() + 1>

                    , DOUBLE(1, 12)
                    , DOUBLE(-1, 12)
                  >;

TYPED_TEST_CASE(AbsTest, MyTypes);

TYPED_TEST(AbsTest, Abs)
{
  ASSERT_EQ(std::abs(this->lhs_), this->result_);
}
