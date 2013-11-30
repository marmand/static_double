/*!
 * \author  Armand Leclercq
 * \file  maths/double/mul.hh
 * \date  Thu 28 Nov 2013 06:25:02 PM CET
 */

#ifndef MATHS_DOUBLE_MUL_HH_
# define MATHS_DOUBLE_MUL_HH_
# include <maths/double/type.hh>
# include <maths/add.hh>
# include <maths/mul.hh>
# include <maths/div.hh>
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
    , unsigned long s1
    , unsigned long s2
    , bool n1
    , bool n2
  >
  struct mul<Double<e1, d1, m1, s1, n1>, Double<e2, d2, m2, s2, n2>>
  {
  private:
    enum { CommaLess = maths::mul
                       <
                         typename maths::add
                         <
                           typename maths::mul
                           <
                             Long<e1>
                             , typename maths::pow<Long<10>, Long<m1>>::type
                           >::type
                           , Long<d1>
                         >::type
                         , typename maths::add
                           <
                             typename maths::mul
                             <
                               Long<e2>
                               , typename maths::pow<Long<10>, Long<m2>>::type
                             >::type
                             , Long<d2>
                           >::type
                       >::type::value
         };
    enum { Mult = maths::add<Long<m1>, Long<m2>>::type::value };
    enum { Dec = maths::mod
                 <
                   Long<CommaLess>
                   , typename maths::pow<Long<10>, Long<Mult>>::type
                 >::type::value
         };
    enum { Ent = maths::div
                 <
                   Long<CommaLess>
                   , typename maths::pow<Long<10>, Long<Mult>>::type
                 >::type::value
         };
    enum { Sign = 0 };
    enum { Null = 0 };
  public:
    typedef Double<Ent, Dec, Mult, Sign, Null> type;
  };

  /*!
   * Fast special case shortcut
   */
  template
  <
    long e
    , unsigned long d
    , unsigned long m1
    , unsigned long m2
    , unsigned long s1
    , unsigned long s2
    , bool n1
    , bool n2
  >
  struct mul<Double<0, 0, m1, s1, n1>, Double<e, d, m2, s2, n2>>
  {
    typedef DOUBLE(0, 0) type;
  };
  /*!
   * Fast special case shortcut
   */
  template
  <
    long e
    , unsigned long d
    , unsigned long m1
    , unsigned long m2
    , unsigned long s1
    , unsigned long s2
    , bool n1
    , bool n2
  >
  struct mul<Double<e, d, m1, s1, n1>, Double<0, 0, m2, s2, n2>>
  {
    typedef DOUBLE(0, 0) type;
  };
} /* maths */

#endif /* !MATHS_DOUBLE_MUL_HH_ */
