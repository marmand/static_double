/*!
 * \author  Armand Leclercq
 * \file  max.hh
 * \date  Mon 18 Nov 2013 05:47:47 PM CET
 */

#ifndef MATHS_MAX_HH_
# define MATHS_MAX_HH_

namespace maths
{
  /*!
   * \brief Returns the biggest of the two elements
   */
  template <typename lhs, typename rhs>
  struct max {};
} /* maths */

# include <long/max.hh>
# include <double/max.hh>
#endif /* !MATHS_MAX_HH_ */
