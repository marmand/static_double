/*!
 * \author  Armand Leclercq
 * \file  min.hh
 * \date  Mon 18 Nov 2013 04:40:56 PM CET
 */

#ifndef MATHS_MIN_HH_
# define MATHS_MIN_HH_

namespace maths
{
  /*!
   * \brief Returns the smallest of the two elements
   */
  template <typename lhs, typename rhs>
  struct min {};
} /* maths */

# include <long/min.hh>
# include <double/min.hh>
#endif /* !MATHS_MIN_HH_ */
