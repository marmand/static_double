/*!
 * \author  Armand Leclercq
 * \file  maths/mul.hh
 * \date  Mon 18 Nov 2013 02:51:38 PM CET
 */

#ifndef MATHS_MUL_HH_
# define MATHS_MUL_HH_

namespace maths
{
  template <typename lhs, typename rhs>
  struct mul {};
} /* maths */

# include <maths/long/mul.hh>
# include <maths/double/mul.hh>
#endif /* !MATHS_MUL_HH_ */
