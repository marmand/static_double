/*!
 * \author  Armand Leclercq
 * \file  maths/div.hh
 * \date  Mon 18 Nov 2013 10:32:10 PM CET
 */

#ifndef MATHS_DIV_HH_
# define MATHS_DIV_HH_

namespace maths
{
  template <typename lhs, typename rhs>
  struct div {};
} /* maths */

# include <maths/long/div.hh>
#endif /* !MATHS_DIV_HH_ */
