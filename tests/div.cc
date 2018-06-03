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
//                      The division by 0 must not compile
//                     std::pair<Long<10>, Long<0>>
//                     , std::pair<DOUBLE(1, 0), DOUBLE(0, 0)>
//                     ,
                    std::pair<Long<10>, Long<1>>
                    , std::pair<Long<10>, Long<2>>
                    , std::pair<Long<10>, Long<5>>
                    , std::pair<Long<100>, Long<10>>
                    , std::pair<Long<1>, Long<10>>
//                     , std::pair<DOUBLE(3, 14), Long<2>>
                    , std::pair<DOUBLE(10, 0), DOUBLE(1, 0)>
//                     , std::pair<DOUBLE(10, 0), DOUBLE(2, 5)>
                    , std::pair<DOUBLE(1, 0), DOUBLE(10, 0)>
                  >;

TYPED_TEST_CASE(DivTest, MyTypes);

TYPED_TEST(DivTest, Div)
{
  ASSERT_EQ(this->lhs_ / this->rhs_, this->result_);
}
