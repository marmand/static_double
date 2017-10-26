/*!
 * \author  Armand Leclercq
 * \file  div.hh
 * \date  Mon 18 Nov 2013 10:32:10 PM CET
 */

#ifndef MATHS_DIV_HH_
# define MATHS_DIV_HH_

namespace maths
{
  /*!
   * \brief Computes the division lhs/rhs
   *
   * This methods computes the division of lhs by rhs giving the result in the
   * same type as operands.
   * \todo Create a division of Double by Long
   * \todo Create a division of Long by Double
   * \todo Make division of Long by Long returns a Double
   */
  template <typename lhs, typename rhs>
  struct div {};
} /* maths */

# include <long/div.hh>
# include <double/div.hh>
#endif /* !MATHS_DIV_HH_ */
