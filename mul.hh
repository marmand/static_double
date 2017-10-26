/*!
 * \author  Armand Leclercq
 * \file  mul.hh
 * \date  Mon 18 Nov 2013 02:51:38 PM CET
 */

#ifndef MATHS_MUL_HH_
# define MATHS_MUL_HH_

namespace maths
{
  /*!
   * \brief Returns lhs * rhs
   * \todo Add Double * Long
   * \todo Add Long * Double
   */
  template <typename lhs, typename rhs>
  struct mul {};
} /* maths */

# include <long/mul.hh>
# include <double/mul.hh>
#endif /* !MATHS_MUL_HH_ */
