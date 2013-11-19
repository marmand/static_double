/*!
 * \author  Armand Leclercq
 * \file  maths/double/add.hh
 * \date  Mon 18 Nov 2013 03:04:33 PM CET
 */

#ifndef MATHS_DOUBLE_ADD_HH_
# define MATHS_DOUBLE_ADD_HH_
# include <maths/double/type.hh>
# include <maths/max.hh>
# include <maths/mod.hh>
# include <maths/pow.hh>

namespace maths
{
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
    enum { Mult = maths::max<Long<m1>, Long<m2>>::type::value };
    enum { Dec = maths::mod
                 <
                   typename maths::add<Long<d1>, Long<d2>>::type
                   , typename maths::pow<Long<10>, Long<Mult>>::type
                 >::type::value
          };
    enum { Ent = e1 + e2 + (Dec % Mult) };
  public:
    typedef Double<Ent, Dec, Mult> type;
  };
} /* maths */

#endif /* !MATHS_DOUBLE_ADD_HH_ */
