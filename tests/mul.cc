/*!
 * \author: Armand Leclercq
 * \file: mul.cc
 * \date: Mon 30 Oct 2017 07:59:18 AM UTC
 */
#include <mul.hh>

#include <gtest/gtest.h>

// T must be a std::pair
template <typename T>
class MulTest: public ::testing::Test
{
  using lhs = typename T::first_type;
  using rhs = typename T::second_type;
  using result = typename maths::mul<lhs, rhs>::type;
protected:
  lhs lhs_;
  rhs rhs_;
  result result_;
}; // class MulTest

using MyTypes = ::testing::Types
                  <
                    std::pair<Long<0>, Long<0>>
                    , std::pair<Long<0>, Long<10>>
                    , std::pair<Long<10>, Long<0>>
                    , std::pair<Long<10>, Long<20>>
                    , std::pair<DOUBLE(1, 2), Long<2>>
                    , std::pair<Long<2>, DOUBLE(1, 2)>
                    , std::pair<DOUBLE(0, 0), DOUBLE(0, 0)>
                    , std::pair<DOUBLE(0, 0), DOUBLE(1, 0)>
                    , std::pair<DOUBLE(1, 0), DOUBLE(0, 0)>
                    , std::pair<DOUBLE(1, 2), DOUBLE(2, 4)>
                    , std::pair<DOUBLE(2, 4), DOUBLE(1, 2)>
                    , std::pair<DOUBLE(1, 2), DOUBLE(-2, 4)>
                    , std::pair<DOUBLE(-2, 4), DOUBLE(1, 2)>
                    , std::pair<DOUBLE(-1, 2), DOUBLE(-2, 4)>
                    , std::pair<DOUBLE(-2, 4), DOUBLE(-1, 2)>
                  >;

TYPED_TEST_CASE(MulTest, MyTypes);

TYPED_TEST(MulTest, Mul)
{
  ASSERT_DOUBLE_EQ(this->lhs_ * this->rhs_, this->result_);
}
