/*!
 * \author: Armand Leclercq
 * \file: add.cc
 * \date: Mon 30 Oct 2017 07:51:15 AM UTC
 */
#include <add.hh>

#include <gtest/gtest.h>

#include <utility>

// T must be a std::pair
template <typename T>
class AddTest: public ::testing::Test
{
  using lhs = typename T::first_type;
  using rhs = typename T::second_type;
  using result = typename maths::add<lhs, rhs>::type;
protected:
  lhs lhs_;
  rhs rhs_;
  result result_;
}; // class AddTest

using MyTypes = ::testing::Types
                  <
                    std::pair<Long<0>, Long<1>>
                    , std::pair<Long<1>, Long<0>>
                    , std::pair<Long<10>, Long<20>>
                    // , std::pair<DOUBLE(1, 2), Long<1>>
                    // , std::pair<Long<1>, DOUBLE(1, 2)>
                    , std::pair<DOUBLE(1, 2), DOUBLE(1, 2)>
                    , std::pair<DOUBLE(1, 2), DOUBLE(-1, 2)>
                  >;

TYPED_TEST_SUITE(AddTest, MyTypes, );

TYPED_TEST(AddTest, LongAdd)
{
  ASSERT_EQ(this->lhs_ + this->rhs_, this->result_);
}

TYPED_TEST(AddTest, DoubleAdd)
{
  ASSERT_FLOAT_EQ(this->lhs_ + this->rhs_, this->result_);
}
