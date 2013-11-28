/*!
 * \author  Armand Leclercq
 * \file  maths/double/mult.hh
 * \date  Thu 28 Nov 2013 06:25:02 PM CET
 */

#ifndef MATHS_DOUBLE_MULT_HH_
# define MATHS_DOUBLE_MULT_HH_
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
  >
  struct mult<Double<e1, d1, m1>, Double<e2, d2, m2>>
  {
    typedef DOUBLE(0, 0) type;
  };
} /* maths */

#endif /* !MATHS_DOUBLE_MULT_HH_ */
