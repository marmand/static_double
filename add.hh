/*!
 * \author  Armand Leclercq
 * \file  maths/add.hh
 * \date  Mon 18 Nov 2013 02:49:43 PM CET
 */

#ifndef MATHS_ADD_HH_
# define MATHS_ADD_HH_

namespace maths
{
  /*!
   * \brief Computes the addition of two numbers
   *
   * This method computes the addition of two numbers represented as types.
   * \todo Create the addition between Long and Double
   */
  template <typename lhs, typename rhs>
  struct add {};
} /* maths */

# include <maths/long/add.hh>
# include <maths/double/add.hh>
#endif /* !MATHS_ADD_HH_ */
