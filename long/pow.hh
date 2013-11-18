/*!
 * \author  Armand Leclercq
 * \file  maths/long/pow.hh
 * \date  Sun 17 Nov 2013 05:36:19 PM CET
 */

#ifndef MATHS_LONG_POW_HH_
# define MATHS_LONG_POW_HH_
# include <maths/long/type.hh>
# include <maths/mult.hh>

namespace maths
{
  template <long v1, long v2>
  struct pow<Long<v1>, Long<v2>>
  {
    typedef typename mult<Long<v1>, typename pow<Long<v1>, Long<v2 - 1>>::type>::type type;
  };

  template <long v1>
  struct pow<Long<v1>, Long<0>>
  {
    typedef Long<1> type;
  };

} /* maths */

#endif /* !MATHS_LONG_POW_HH_ */
