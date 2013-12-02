/*!
 * \author  Armand Leclercq
 * \file  maths/double/div.hh
 * \date  Mon 02 Dec 2013 09:30:43 PM CET
 */

#ifndef MATHS_DOUBLE_DIV_HH_
# define MATHS_DOUBLE_DIV_HH_
# include <maths/double/type.hh>

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
  struct div<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
  {
    typedef DOUBLE(0, 0) type;
  };
} /* maths */

#endif /* !MATHS_DOUBLE_DIV_HH_ */
