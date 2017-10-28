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
}
