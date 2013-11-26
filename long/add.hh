/*!
 * \author  Armand Leclercq
 * \file  maths/long/add.hh
 * \date  Mon 16 Sep 2013 01:30:24 PM CEST
 */

#ifndef MATHS_LONG_ADD_HH_
# define MATHS_LONG_ADD_HH_
# include <maths/long/type.hh>

namespace maths
{
  template <long v1, long v2>
  struct add<Long<v1>, Long<v2>>
  {
    typedef Long<v1 + v2> type;
  };
} /* maths */

#endif /* !MATHS_LONG_ADD_HH_ */
