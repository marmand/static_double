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
