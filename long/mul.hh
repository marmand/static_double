/*!
 * \author  Armand Leclercq
 * \file  long/mul.hh
 * \date  Mon 18 Nov 2013 02:25:42 PM CET
 */

#ifndef MATHS_LONG_MUL_HH_
# define MATHS_LONG_MUL_HH_
# include <long/type.hh>

namespace maths
{
  template <long v1, long v2>
  struct mul<Long<v1>, Long<v2>>
  {
    typedef Long<v1 * v2> type;
  };

} /* maths */

#endif /* !MATHS_LONG_MUL_HH_ */
