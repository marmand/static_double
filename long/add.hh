/*!
 * \author  Armand Leclercq
 * \file  add.hh
 * \date  Mon 16 Sep 2013 01:30:24 PM CEST
 */

#ifndef ADD_HH_
# define ADD_HH_
# include <double.hh>
# include <max.hh>

namespace maths
{

  template <typename Lhs, typename Rhs>
  struct add;

  template
  <
    long e1
    , unsigned long d1
    , unsigned long m1
    , long e2
    , unsigned long d2
    , unsigned long m2
  >
  struct add<Double<e1, d1, m1>, Double<e2, d2, m2>>
  {
  private:
    enum { Mult = max<Long<m1>, Long<m2>>::type::value };
    enum { Dec = d1 + d2 };
    enum { Ent = e1 + e2 + (Dec % Mult) };
  public:
    typedef Double<Ent, Dec, Mult> type;
  };

} /* maths */

#endif /* !ADD_HH_ */
