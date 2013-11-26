/*!
 * \author  Armand Leclercq
 * \file  maths/abs.hh
 * \date  Sun 24 Nov 2013 06:36:52 PM CET
 */

#ifndef MATHS_ABS_HH_
# define MATHS_ABS_HH_

namespace maths
{
  template <typename lhs>
  struct abs {};
} /* maths */

# include <maths/long/abs.hh>
# include <maths/double/abs.hh>
#endif /* !MATHS_ABS_HH_ */
