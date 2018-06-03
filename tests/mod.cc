/*!
 * \author: Armand Leclercq
 * \file: mod.cc
 * \date: Fri 27 Oct 2017 06:26:18 AM UTC
 */
#include <mod.hh>

#include <gtest/gtest.h>

// T must be a std::pair
template <typename T>
class ModTest: public ::testing::Test
{
  using lhs = typename T::first_type;
  using rhs = typename T::second_type;
  using result = typename maths::mod<lhs, rhs>::type;
protected:
  lhs lhs_;
  rhs rhs_;
  result result_;
}; // class ModTest

using MyTypes = ::testing::Types
                  <
                    std::pair<Long<10>, Long<1>>
                    , std::pair<Long<10>, Long<2>>
                    , std::pair<Long<10>, Long<3>>
                  >;

TYPED_TEST_CASE(ModTest, MyTypes);

TYPED_TEST(ModTest, Mod)
{
  ASSERT_EQ(this->lhs_ % this->rhs_, this->result_);
}

/// \todo: put that test in a compilation test, making that failed to compile
#if 0
TEST(Mod, 0)
{
  typedef Long<10> lhs;
  typedef Long<0> rhs;
  typedef maths::mod<lhs, rhs>::type result;
  ASSERT_EQ(0, result());
}
#endif
