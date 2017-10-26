/*!
 * \author  Armand Leclercq
 * \file  double/eq.hh
 * \date  Tue 17 Dec 2013 08:02:13 PM CET
 */

#ifndef MATHS_DOUBLE_EQ_HH_
# define MATHS_DOUBLE_EQ_HH_
# include <double/type.hh>

namespace maths
{
  template
  <
    long e
    , unsigned long d
    , unsigned long m
    , bool n
    , bool z
  >
  struct eq<Double<e, d, m, n, z>, Double<e, d, m, n, z>>
  {
    enum { value = true };
  };
} /* maths */

#endif /* !MATHS_DOUBLE_EQ_HH_ */
