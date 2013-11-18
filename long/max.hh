/*!
 * \author  Armand Leclercq
 * \file  maths/long/max.hh
 * \date  Mon 18 Nov 2013 05:49:17 PM CET
 */

#ifndef MATHS_LONG_MAX_HH_
# define MATHS_LONG_MAX_HH_
# include <maths/long/type.hh>
# include <maths/compare.hh>

namespace maths
{
  template <long e1, long e2>
  struct max<Long<e1>, Long<e2>>
    : public compare
  <
    Long<e1>
    , Long<e2>
    , (e1 > e2)
    , (e1 < e2)
    , true // In case of incertainty, use the left as the max
    , false
  >
  {
  };
} /* maths */

#endif /* !MATHS_LONG_MAX_HH_ */
