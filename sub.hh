/*!
 * \author  Armand Leclercq
 * \file  sub.hh
 * \date  Tue 19 Nov 2013 12:41:50 PM CET
 */

#ifndef MATHS_SUB_HH_
# define MATHS_SUB_HH_

namespace maths
{
  /*!
   * \brief Returns \a lhs - \a rhs
   */
  template <typename lhs, typename rhs>
  struct sub {};
} /* maths */

# include <long/sub.hh>
# include <double/sub.hh>
#endif /* !MATHS_SUB_HH_ */
