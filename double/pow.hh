/*!
 * \author: Armand Leclercq
 * \file: pow.hh
 * \date: Sat 04 Nov 2017 09:42:12 AM UTC
 */

#ifndef MATHS_DOUBLE_POW_HH_
# define MATHS_DOUBLE_POW_HH_
# include <double/type.hh>

namespace maths
{

  template
  <
    long Integral
    , unsigned long Decimal
    , unsigned long Mult
    , bool neg
    , bool zero
  >
  struct pow<Double<Integral, Decimal, Mult, neg, zero>, Long<0>>
  {
    typedef Long<1> type;
  };

} /* maths */

#endif /* !MATHS_DOUBLE_POW_HH_ */
