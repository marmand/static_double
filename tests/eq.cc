/*!
 * \author: Armand Leclercq
 * \file: eq.cc
 * \date: Thu 26 Oct 2017 08:27:26 PM UTC
 */
#include <eq.hh>

#include <gtest/gtest.h>

#include <tuple>

// T must be a std::tuple
template <typename T>
class EqTest: public ::testing::Test
{
  using expected = typename std::tuple_element<0, T>::type;
  using lhs = typename std::tuple_element<1, T>::type;
  using rhs = typename std::tuple_element<2, T>::type;
  // FIXME: should eq return a type
  using result = typename maths::eq<lhs, rhs>;
protected:
  expected expected_;
  lhs lhs_;
  rhs rhs_;
}; // class EqTest

using MyTypes = ::testing::Types
                  <
                    std::tuple<std::true_type, Long<10>, Long<10>>
                    , std::tuple<std::false_type, Long<10>, Long<20>>
                  >;

TYPED_TEST_CASE(EqTest, MyTypes);

TYPED_TEST(EqTest, Eq)
{
  if(this->expected_)
    ASSERT_TRUE(result::value);
  else
    ASSERT_FALSE(result::value);
}

TEST(Eq, long_equals)
{
  typedef Long<10> lhs;
  typedef Long<10> rhs;
  typedef maths::eq<lhs, rhs> result;
  ASSERT_TRUE(result::value);
}

TEST(Eq, long_not_equals)
{
  typedef Long<10> lhs;
  typedef Long<20> rhs;
  typedef maths::eq<lhs, rhs> result;
  ASSERT_FALSE(result::value);
}

TEST(Eq, double_equals)
{
  typedef DOUBLE(2, 12) lhs;
  typedef DOUBLE(2, 12) rhs;
  typedef maths::eq<lhs, rhs> result;
  ASSERT_TRUE(result::value);
}

TEST(Eq, double_not_equals)
{
  typedef DOUBLE(3, 124) lhs;
  typedef DOUBLE(2, 212) rhs;
  typedef maths::eq<lhs, rhs> result;
  ASSERT_FALSE(result::value);
}
