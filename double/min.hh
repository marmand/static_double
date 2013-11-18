/*!
 * \author  Armand Leclercq
 * \file  maths/double/min.hh
 * \date  Mon 18 Nov 2013 04:47:55 PM CET
 */

#ifndef MATHS_DOUBLE_MIN_HH_
# define MATHS_DOUBLE_MIN_HH_
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
  >
  struct min
  <
    Double<e1, d1, m1>
    , Double<e2, d2, m2>
  >
  : public compare
  <
    Double<e1, d1, m1>
    , Double<e2, d2, m2>
    , (e1 < e2)
    , (e1 > e2)
    , (d1 < d2)
    , (d1 > d2)
  >
  {
  };

} /* maths */

#endif /* !MATHS_DOUBLE_MIN_HH_ */
