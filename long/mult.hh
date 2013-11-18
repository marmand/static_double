/*!
 * \author  Armand Leclercq
 * \file  maths/long/mult.hh
 * \date  Mon 18 Nov 2013 02:25:42 PM CET
 */

#ifndef MATHS_LONG_MULT_HH_
# define MATHS_LONG_MULT_HH_
# include <maths/long/type.hh>

namespace maths
{
  template <long v1, long v2>
  struct mult<Long<v1>, Long<v2>>
  {
    typedef Long<v1 * v2> type;
  };

} /* maths */

#endif /* !MATHS_LONG_MULT_HH_ */
