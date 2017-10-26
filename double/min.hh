/*!
 * \author  Armand Leclercq
 * \file  double/min.hh
 * \date  Mon 18 Nov 2013 04:47:55 PM CET
 */

#ifndef MATHS_DOUBLE_MIN_HH_
# define MATHS_DOUBLE_MIN_HH_
# include <double/type.hh>
# include <compare.hh>

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
  struct min
  <
    Double<e1, d1, m1, n1, z1>
    , Double<e2, d2, m2, n2, z2>
  >
  : public compare
  <
    Double<e1, d1, m1, n1, z1>
    , Double<e2, d2, m2, n2, z2>
    , (e1 < e2)
    , (e1 > e2)
    , (d1 < d2)
    , (d1 > d2)
  >
  {
  };
} /* maths */

#endif /* !MATHS_DOUBLE_MIN_HH_ */
