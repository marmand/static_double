/*!
 * \author  Armand Leclercq
 * \file  maths/double/max.hh
 * \date  Mon 18 Nov 2013 05:50:50 PM CET
 */

#ifndef MATHS_DOUBLE_MAX_HH_
# define MATHS_DOUBLE_MAX_HH_
# include <maths/double/type.hh>
# include <maths/compare.hh>

namespace maths
{
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
  struct max<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
    : public compare
  <
    Double<e1, d1, m1, n1, z1>
    , Double<e2, d2, m2, n2, z2>
    , (e1 > e2)
    , (e1 < e2)
    , (d1 > d2)
    , (d1 < d2)
  >
  {
  };
} /* maths */

#endif /* !MATHS_DOUBLE_MAX_HH_ */
