/*!
 * \author  Armand Leclercq
 * \file  maths/double/sub.hh
 * \date  Tue 19 Nov 2013 03:32:45 PM CET
 */

#ifndef MATHS_DOUBLE_SUB_HH_
# define MATHS_DOUBLE_SUB_HH_
# include <maths/double/type.hh>
# include <maths/add.hh>

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
  struct sub<Double<e1, d1, m1>, Double<e2, d2, m2>>
  {
    typedef typename maths::add<Double<e1, d1, m1>, Double<-e2, d2, m2>>::type type;
  };
} /* maths */

#endif /* !MATHS_DOUBLE_SUB_HH_ */
