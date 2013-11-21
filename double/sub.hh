/*!
 * \author  Armand Leclercq
 * \file  maths/double/sub.hh
 * \date  Tue 19 Nov 2013 03:32:45 PM CET
 */

#ifndef MATHS_DOUBLE_SUB_HH_
# define MATHS_DOUBLE_SUB_HH_
# include <maths/double/type.hh>
# include <maths/max.hh>
# include <maths/add.hh>
# include <maths/sub.hh>
# include <maths/mult.hh>
# include <maths/mod.hh>
# include <maths/pow.hh>

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
  private:
    enum { Mult = maths::max<Long<m1>, Long<m2>>::type::value };
    enum { Over = maths::pow<Long<10>, typename maths::add<Long<Mult>, Long<1>>::type>::type::value };
    enum { PreDec = maths::sub
                    <
                      typename maths::add
                      <
                        typename maths::mult<Long<d1>, typename maths::pow<Long<10>, Long<m1>>::type>::type
                        , Long<Over>
                      >::type
                      , typename maths::add
                        <
                          typename maths::mult<Long<d2>, typename maths::pow<Long<10>, Long<m2>>::type>::type
                          , Long<Over>
                        >::type
                    >::type::value
         };
    enum { Dec = maths::mod<Long<PreDec>, Long<Over>>::type::value };
    enum { Ent = maths::add
                 <
                   typename maths::sub<Long<e1>, typename maths::add<Long<1>, Long<e1>>::type>::type
                   , typename maths::div<Long<PreDec>, Long<Over>>::type
                 >::type::value
         };
  public:
    typedef Double<Ent, Dec, Mult> type;
  };
} /* maths */

#endif /* !MATHS_DOUBLE_SUB_HH_ */
