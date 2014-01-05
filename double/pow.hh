/*!
 * \author  Armand Leclercq
 * \file  maths/double/pow.hh
 * \date  Sat 04 Jan 2014 09:11:34 PM CET
 */

#ifndef MATHS_DOUBLE_POW_HH_
# define MATHS_DOUBLE_POW_HH_
# include <maths/convert.hh>

namespace maths
{
  namespace double_
  {
    namespace pow_
    {
    } /* pow_ */
  } /* double_ */
  template
  <
    long e1
    , long e2
    , unsigned long d1
    , unsigned long d2
    , unsigned long m1
    , unsigned long m2
    , bool n1
    , bool n2
    , bool z1
    , bool z2
  >
  struct pow<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
  {
  };
} /* maths */

#endif /* !MATHS_DOUBLE_POW_HH_ */
