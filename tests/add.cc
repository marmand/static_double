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

template <typename T>
class LongAddTest : public AddTest<T>
{
};

template <typename T>
class DoubleAddTest : public AddTest<T>
{
};

using LongTypes = ::testing::Types
                  <
                    std::pair<Long<0>, Long<1>>
                    , std::pair<Long<1>, Long<0>>
                    , std::pair<Long<10>, Long<20>>
                    , std::pair<Long<20>, Long<10>>
                  >;
TYPED_TEST_SUITE(LongAddTest, LongTypes, );

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
TYPED_TEST_SUITE(DoubleAddTest, DoubleTypes, );

TYPED_TEST(LongAddTest, Add)
{
  ASSERT_EQ(this->lhs_ + this->rhs_, this->result_);
}

TYPED_TEST(DoubleAddTest, Add)
{
  ASSERT_DOUBLE_EQ(this->lhs_ + this->rhs_, this->result_);
}
