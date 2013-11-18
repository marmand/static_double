/*!
 * \author  Armand Leclercq
 * \file  mult.hh
 * \date  Mon 18 Nov 2013 02:25:42 PM CET
 */

#ifndef MULT_HH_
# define MULT_HH_
# include <double.hh>
# include <long.hh>

namespace maths
{
  template <typename lhs, typename rhs>
  struct mult {};

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
  private:
    enum { Mult = add<Long<m1>, Long<m2>>::type::value };
  };

} /* maths */

#endif /* !MULT_HH_ */
