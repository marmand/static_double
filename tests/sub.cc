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

template <typename T>
class LongSubTest : public SubTest<T>
{
};

template <typename T>
class DoubleSubTest : public SubTest<T>
{
};

using LongTypes = ::testing::Types
                  <
                    std::pair<Long<0>, Long<1>>
                    , std::pair<Long<1>, Long<0>>
                    , std::pair<Long<10>, Long<20>>
                    , std::pair<Long<20>, Long<10>>
                  >;
TYPED_TEST_SUITE(LongSubTest, LongTypes, );

using DoubleTypes = ::testing::Types
                    <
                      std::pair<DOUBLE(0, 0), DOUBLE(1, 0)>
                      , std::pair<DOUBLE(1, 2), DOUBLE(0, 2)>
                      , std::pair<DOUBLE(1, 2), Long<1>>
                      , std::pair<DOUBLE(1, 2), Long<-1>>
                      , std::pair<Long<1>, DOUBLE(1, 2)>
                      , std::pair<Long<-1>, DOUBLE(1, 2)>
                      , std::pair<DOUBLE(1, 2), DOUBLE(1, 2)>
                      , std::pair<DOUBLE(1, 2), DOUBLE(-1, 2)>
                      , std::pair<DOUBLE(-1, 2), DOUBLE(-1, 2)>
                      , std::pair<maths::pi, maths::pi>
                      , std::pair<maths::e, maths::e>
                      , std::pair<maths::pi, maths::e>
                    >;
TYPED_TEST_SUITE(DoubleSubTest, DoubleTypes, );

TYPED_TEST(LongSubTest, Sub)
{
  ASSERT_EQ(this->lhs_ - this->rhs_, this->result_);
}

TYPED_TEST(DoubleSubTest, Sub)
{
  ASSERT_DOUBLE_EQ(this->lhs_ - this->rhs_, this->result_);
}
