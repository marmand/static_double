/*!
 * \author  Armand Leclercq
 * \file  maths/add.hh
 * \date  Mon 18 Nov 2013 02:49:43 PM CET
 */

#ifndef MATHS_ADD_HH_
# define MATHS_ADD_HH_

namespace maths
{
  template <typename lhs, typename rhs>
  struct add {};
} /* maths */

# include <maths/long/add.hh>
#endif /* !MATHS_ADD_HH_ */
