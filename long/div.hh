/*!
 * \author  Armand Leclercq
 * \file  maths/long/div.hh
 * \date  Mon 18 Nov 2013 10:33:37 PM CET
 */

#ifndef MATHS_LONG_DIV_HH_
# define MATHS_LONG_DIV_HH_
# include <maths/long/type.hh>

namespace maths
{
  template <long v1, long v2>
  struct div<Long<v1>, Long<v2>>
  {
    typedef Long<v1 / v2> type;
  };
} /* maths */

#endif /* !MATHS_LONG_DIV_HH_ */
