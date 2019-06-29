/*!
 * \author: Armand Leclercq
 * \file: convert.cc
 * \date: Fri 27 Oct 2017 05:58:32 AM UTC
 */
#include <convert.hh>

#include <gtest/gtest.h>

// T must be a std::pair
template <typename T>
class ConvertTest: public ::testing::Test
{
  using expected = typename T::first_type;
  using result = typename T::second_type;
protected:
  expected expected_;
  result result_;
}; // class ConvertTest

using MyTypes = ::testing::Types
                  <
                  // Expected, Result
                  std::pair<Long<3>, DOUBLE(3, 0)>
                  , std::pair<DOUBLE(3, 0), Long<3>>
                  >;

TYPED_TEST_SUITE(ConvertTest, MyTypes, );

TYPED_TEST(ConvertTest, Convert)
{
  ASSERT_EQ(this->expected_, this->result_);
}
