/*!
 * \author: Armand Leclercq
 * \file: double.cc
 * \date: Wed 25 Oct 2017 06:31:38 AM UTC
 */
#include <gtest/gtest.h>

#include <double.hh>

TEST(Double, create)
{
  typedef DOUBLE(3, 14) value;
  // Construct and implicit cast to double
  ASSERT_EQ(3.14, value());
  ASSERT_EQ(3, value::Ent);
  ASSERT_EQ(14, value::Dec);
  ASSERT_EQ(2, value::Mult);
  ASSERT_FALSE(value::Neg);
  ASSERT_FALSE(value::Zero);
}
