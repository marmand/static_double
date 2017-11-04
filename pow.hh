/*!
 * \author  Armand Leclercq
 * \file  pow.hh
 * \date  Mon 18 Nov 2013 06:20:22 PM CET
 */

#ifndef MATHS_POW_HH_
# define MATHS_POW_HH_

namespace maths
{
  /*!
   * \brief Returns \a lhs to the power of \a rhs
   */
  template <typename lhs, typename rhs>
  struct pow {};
} /* maths */

# include <long/pow.hh>
# include <double/pow.hh>
#endif /* !MATHS_POW_HH_ */
