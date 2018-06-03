/*!
 * \author: Armand Leclercq
 * \file: div.cc
 * \date: Tue 31 Oct 2017 08:45:56 PM UTC
 */
#include <div.hh>

#include <gtest/gtest.h>

#include <utility>

// T must be a std::pair
template <typename T>
class DivTest: public ::testing::Test
{
  using lhs = typename T::first_type;
  using rhs = typename T::second_type;
  using result = typename maths::div<lhs, rhs>::type;
protected:
  lhs lhs_;
  rhs rhs_;
  result result_;
}; // class DivTest

using MyTypes = ::testing::Types
                  <
                    std::pair<Long<10>, Long<1>>
                    , std::pair<Long<10>, Long<2>>
                  >;

TYPED_TEST_CASE(DivTest, MyTypes);

TYPED_TEST(DivTest, Div)
{
  ASSERT_EQ(this->lhs_ / this->rhs_, this->result_);
}
