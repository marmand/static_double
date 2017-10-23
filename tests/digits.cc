/*!
 * \author: Armand Leclercq
 * \file: digits.cc
 * \date: Mon 23 Oct 2017 08:36:38 PM UTC
 */
#include <gtest/gtest.h>

#include <digits.hh>

TEST(Digits, base)
{
  ASSERT_EQ(1, DIGITS(0));
  ASSERT_EQ(1, DIGITS(1));
  ASSERT_EQ(1, DIGITS(2));
  ASSERT_EQ(1, DIGITS(3));
  ASSERT_EQ(1, DIGITS(4));
  ASSERT_EQ(1, DIGITS(9));
  ASSERT_EQ(2, DIGITS(10));
}
