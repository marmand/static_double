/*!
 * \author  Armand Leclercq
 * \file  maths/pow.hh
 * \date  Mon 18 Nov 2013 06:20:22 PM CET
 */

#ifndef MATHS_POW_HH_
# define MATHS_POW_HH_

namespace maths
{
  /*!
   * \brief Returns \a lhs to the power of \a rhs
   * \todo Double ** Double
   * \todo Long ** Double
   */
  template <typename lhs, typename rhs>
  struct pow {};
} /* maths */

# include <maths/long/pow.hh>
# include <maths/double/pow.hh>
#endif /* !MATHS_POW_HH_ */
