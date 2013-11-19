/*!
 * \author  Armand Leclercq
 * \file  maths/sub.hh
 * \date  Tue 19 Nov 2013 12:41:50 PM CET
 */

#ifndef MATHS_SUB_HH_
# define MATHS_SUB_HH_

namespace maths
{
  template <typename lhs, typename rhs>
  struct sub {};
} /* maths */

# include <maths/long/sub.hh>
# include <maths/double/sub.hh>
#endif /* !MATHS_SUB_HH_ */
