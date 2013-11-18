/*!
 * \author  Armand Leclercq
 * \file  maths/long/min.hh
 * \date  Mon 18 Nov 2013 04:43:55 PM CET
 */

#ifndef MATHS_LONG_MIN_HH_
# define MATHS_LONG_MIN_HH_
# include <maths/long/type.hh>
# include <maths/compare.hh>

namespace maths
{
  template <long v1, long v2>
  struct min
  <
    Long<v1>
    , Long<v2>
  >
  : public compare
  <
    Long<v1>
    , Long<v2>
    , (v1 < v2)
    , (v1 > v2)
    , false
    , true
  >
  {
  };
} /* maths */

#endif /* !MATHS_LONG_MIN_HH_ */
