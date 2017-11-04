/*!
 * \author: Armand Leclercq
 * \file: digits.cc
 * \date: Mon 23 Oct 2017 08:36:38 PM UTC
 */
#include <gtest/gtest.h>

#include <digits.hh>

TEST(Digits, base)
{
  ASSERT_EQ(1ul, DIGITS(0));
  ASSERT_EQ(1ul, DIGITS(1));
  ASSERT_EQ(1ul, DIGITS(2));
  ASSERT_EQ(1ul, DIGITS(3));
  ASSERT_EQ(1ul, DIGITS(4));
  ASSERT_EQ(1ul, DIGITS(9));
  ASSERT_EQ(2ul, DIGITS(10));
}
