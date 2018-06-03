/*!
 * \author: Armand Leclercq
 * \file: max.cc
 * \date: Thu 26 Oct 2017 08:39:13 PM UTC
 */
#include <max.hh>

#include <gtest/gtest.h>

#include <algorithm>

// T must be a std::pair
template <typename T>
class MaxTest: public ::testing::Test
{
  using lhs = typename T::first_type;
  using rhs = typename T::second_type;
  using result = typename maths::max<lhs, rhs>::type;
protected:
  lhs lhs_;
  rhs rhs_;
  result result_;
}; // class MaxTest

using MyTypes = ::testing::Types
                  <
                    std::pair<Long<10>, Long<20>>
                    , std::pair<Long<20>, Long<10>>
                    , std::pair<Long<20>, Long<20>>
                    , std::pair<DOUBLE(3, 14), DOUBLE(1, 8)>
                    , std::pair<DOUBLE(1, 8), DOUBLE(3, 14)>
/// \fixme: max cannot give a result in case of a double equality
//                     , std::pair<DOUBLE(3, 14), DOUBLE(3, 14)>
                  >;

TYPED_TEST_CASE(MaxTest, MyTypes);

TYPED_TEST(MaxTest, Max)
{
  // +0 forces the type to an integral one
  ASSERT_EQ((std::max(this->lhs_ + 0, this->rhs_ + 0)), this->result_);
}
