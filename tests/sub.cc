/*!
 * \author: Armand Leclercq
 * \file: sub.cc
 * \date: Mon 30 Oct 2017 07:50:39 AM UTC
 */
#include <sub.hh>

#include <gtest/gtest.h>

// T must be a std::pair
template <typename T>
class SubTest: public ::testing::Test
{
  using lhs = typename T::first_type;
  using rhs = typename T::second_type;
  using result = typename maths::sub<lhs, rhs>::type;
protected:
  lhs lhs_;
  rhs rhs_;
  result result_;
}; // class SubTest

using MyTypes = ::testing::Types
                  <
                    std::pair<Long<20>, Long<10>>
                    , std::pair<DOUBLE(1, 2), DOUBLE(0, 2)>
                  >;

TYPED_TEST_SUITE(SubTest, MyTypes, );

TYPED_TEST(SubTest, Sub)
{
  ASSERT_EQ(this->lhs_ - this->rhs_, this->result_);
}
