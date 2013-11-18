/*!
 * \author  Armand Leclercq
 * \file  maths/max.hh
 * \date  Mon 18 Nov 2013 05:47:47 PM CET
 */

#ifndef MATHS_MAX_HH_
# define MATHS_MAX_HH_

namespace maths
{
  template <typename lhs, typename rhs>
  struct max {};
} /* maths */

# include <maths/long/max.hh>
# include <maths/double/max.hh>
#endif /* !MATHS_MAX_HH_ */
