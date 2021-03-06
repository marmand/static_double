/*!
 * \author: Armand Leclercq
 * \file: shifted.cc
 * \date: Sat 28 Oct 2017 08:07:23 AM UTC
 */
#include <gtest/gtest.h>

#include <shifted.hh>

TEST(Shifted, Long)
{
  ASSERT_EQ(Long<10>(), maths::shifted<Long<10>>::type());
  ASSERT_EQ(Long<-10>(), maths::shifted<Long<-10>>::type());
}

TEST(Shifted, Double_Null)
{
  {
    typedef DOUBLE(0, 0) null;
    typedef maths::shifted<null>::type result;
    ASSERT_EQ(0, null());
    ASSERT_EQ(0, result());
  }
  {
    typedef DOUBLE(-0, 0) null;
    typedef maths::shifted<null>::type result;
    ASSERT_EQ(0, null());
    ASSERT_EQ(0, result());
  }
  // This case should never occur
  {
    typedef DOUBLE(0, -0) null;
    typedef maths::shifted<null>::type result;
    ASSERT_EQ(0, null());
    ASSERT_EQ(0, result());
  }
  // This case should never occur
  {
    typedef DOUBLE(-0, -0) null;
    typedef maths::shifted<null>::type result;
    ASSERT_EQ(0, null());
    ASSERT_EQ(0, result());
  }
}

TEST(Shifted, Double_Pi)
{
  {
    typedef DOUBLE(3, 14) pi;
    typedef maths::shifted<pi>::type result;
    ASSERT_EQ(314, result());
    ASSERT_EQ(2, maths::shifted<pi>::Recursion);
  }
  {
    typedef DOUBLE(31, 4) pi;
    typedef maths::shifted<pi>::type result;
    ASSERT_EQ(314, result());
    ASSERT_EQ(1, maths::shifted<pi>::Recursion);
  }
  {
    typedef DOUBLE(314, 0) pi;
    typedef maths::shifted<pi>::type result;
    ASSERT_EQ(314, result());
    ASSERT_EQ(0, maths::shifted<pi>::Recursion);
  }
  {
    typedef DOUBLE(314, 00) pi;
    typedef maths::shifted<pi>::type result;
    ASSERT_EQ(314, result());
    ASSERT_EQ(0, maths::shifted<pi>::Recursion);
  }
}

TEST(Shifted, SmallDouble)
{
  {
    // PI = 3.1415, representing here 3.0005
    // 3 + 0.5 * 10E-3
    // Can see 3 as the number of zeros before the 5
    typedef SMALL_DOUBLE(3, 5, 3) pi_parts;
    typedef maths::shifted<pi_parts>::type result;
    ASSERT_EQ(30005, result());
    ASSERT_EQ(4, maths::shifted<pi_parts>::Recursion);
  }
}

TEST(Shifted, Negative_Double)
{
  {
    typedef DOUBLE(-2, 12) lhs;
    typedef maths::shifted<lhs>::type result;
    ASSERT_EQ(-212, result());
    ASSERT_EQ(2, maths::shifted<lhs>::Recursion);
  }
}
