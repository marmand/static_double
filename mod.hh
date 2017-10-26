/*!
 * \author  Armand Leclercq
 * \file  mod.hh
 * \date  Tue 19 Nov 2013 12:42:57 PM CET
 */

#ifndef MATHS_MOD_HH_
# define MATHS_MOD_HH_

namespace maths
{
  /*!
   * \brief Returns the rest of the natural division of lhs by rhs.
   */
  template <typename lhs, typename rhs>
  struct mod {};
} /* maths */

# include <long/mod.hh>
#endif /* !MATHS_MOD_HH_ */
