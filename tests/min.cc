/*!
 * \author: Armand Leclercq
 * \file: min.cc
 * \date: Sun 29 Oct 2017 09:30:46 PM UTC
 */
#include <min.hh>

#include <gtest/gtest.h>

#include <algorithm>

// T must be a std::pair
template <typename T>
class MinTest: public ::testing::Test
{
  using lhs = typename T::first_type;
  using rhs = typename T::second_type;
  using result = typename maths::min<lhs, rhs>::type;
protected:
  lhs lhs_;
  rhs rhs_;
  result result_;
}; // class MinTest

using MyTypes = ::testing::Types
                  <
                    std::pair<Long<10>, Long<20>>
                    , std::pair<Long<20>, Long<10>>
                    , std::pair<Long<20>, Long<20>>
                    , std::pair<DOUBLE(3, 14), DOUBLE(1, 8)>
                    , std::pair<DOUBLE(1, 8), DOUBLE(3, 14)>
/// \fixme: min cannot give a result in case of a double equality
//                     , std::pair<DOUBLE(3, 14), DOUBLE(3, 14)>
                  >;

TYPED_TEST_SUITE(MinTest, MyTypes, );

TYPED_TEST(MinTest, Min)
{
  // +0 forces the type to an integral one
  ASSERT_EQ((std::min(this->lhs_ + 0, this->rhs_ + 0)), this->result_);
}
