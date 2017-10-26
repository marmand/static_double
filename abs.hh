/*!
 * \author  Armand Leclercq
 * \file  abs.hh
 * \date  Sun 24 Nov 2013 06:36:52 PM CET
 */

#ifndef MATHS_ABS_HH_
# define MATHS_ABS_HH_

namespace maths
{
  /*!
   * \brief Compute the absolute value of a number
   *
   * This method computes the absolute value of a number, and returns in term
   * of ::type accessor the absolute value in the same type as input
   * for example
     \code
     maths::abs<DOUBLE(-3, 14)>::type == DOUBLE(3, 14)
     maths::abs<Long<-50>>::type == Long<50>
     \endcode
   *
   */
  template <typename lhs>
  struct abs {};
} /* maths */

# include <long/abs.hh>
# include <double/abs.hh>
#endif /* !MATHS_ABS_HH_ */
