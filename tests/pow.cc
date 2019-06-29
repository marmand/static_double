/*!
 * \author: Armand Leclercq
 * \file: pow.cc
 * \date: Wed 01 Nov 2017 12:36:38 PM UTC
 */
#include <pow.hh>

#include <gtest/gtest.h>

#include <cmath>

// T must be a std::pair
template <typename T>
class PowTest: public ::testing::Test
{
  using lhs = typename T::first_type;
  using rhs = typename T::second_type;
  using result = typename maths::pow<lhs, rhs>::type;
protected:
  lhs lhs_;
  rhs rhs_;
  result result_;
}; // class PowTest

using MyTypes = ::testing::Types
                  <
                    std::pair<Long<1>, Long<0>>
                    , std::pair<Long<0>, Long<1>>
                    , std::pair<Long<1>, Long<-1>>
                    , std::pair<DOUBLE(1, 0), Long<0>>
                    , std::pair<DOUBLE(0, 0), Long<0>>
                    , std::pair<DOUBLE(1, 0), Long<-1>>
                  >;

TYPED_TEST_SUITE(PowTest, MyTypes, );

TYPED_TEST(PowTest, Pow)
{
  ASSERT_DOUBLE_EQ((std::pow(this->lhs_ + 0, this->rhs_ + 0))
                   , this->result_);
}
