/*!
 * \author  Armand Leclercq
 * \file  maths/pow.hh
 * \date  Mon 18 Nov 2013 06:20:22 PM CET
 */

#ifndef MATHS_POW_HH_
# define MATHS_POW_HH_

namespace maths
{
  template <typename lhs, typename rhs>
  struct pow {};
} /* maths */

# include <maths/long/pow.hh>
#endif /* !MATHS_POW_HH_ */
