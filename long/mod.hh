/*!
 * \author  Armand Leclercq
 * \file  maths/long/mod.hh
 * \date  Tue 19 Nov 2013 12:58:01 PM CET
 */

#ifndef MATHS_LONG_MOD_HH_
# define MATHS_LONG_MOD_HH_
# include <maths/long/type.hh>

namespace maths
{
  template<long v1, long v2>
  struct mod<Long<v1>, Long<v2>>
  {
    typedef Long<v1 % v2> type;
  };
} /* maths */

#endif /* !MATHS_LONG_MOD_HH_ */