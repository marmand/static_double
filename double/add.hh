/*!
 * \author  Armand Leclercq
 * \file  maths/double/add.hh
 * \date  Mon 18 Nov 2013 03:04:33 PM CET
 */

#ifndef MATHS_DOUBLE_ADD_HH_
# define MATHS_DOUBLE_ADD_HH_
# include <maths/double/type.hh>
# include <maths/max.hh>
# include <maths/abs.hh>
# include <maths/add.hh>
# include <maths/sub.hh>
# include <maths/mul.hh>
# include <maths/div.hh>
# include <maths/mod.hh>
# include <maths/pow.hh>

namespace maths
{
  namespace double_
  {
    namespace add_
    {
      /*!
       * This structure compute a temporary variables on condition.
       *
       * \code
         if (m1 < m2)
           d = d1 * 10 ^ |m1 - m2| + d2;
         else
           d = d1 + d2 * 10 ^ |m1 - m2|;
         \endcode
       *
       */
      template
      <
        unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
        , bool inf
      >
      struct d {};

      template
      <
        unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
      >
      struct d<d1, d2, m1, m2, true>
      {
        typedef typename maths::add
                <
                  typename maths::mul
                  <
                    Long<d1>
                    , typename maths::pow
                      <
                        Long<10>
                        , typename maths::abs<typename maths::sub<Long<m1>, Long<m2>>::type>::type
                      >::type
                  >::type
                  , Long<d2>
                >::type
                type;
      };

      template
      <
        unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
      >
      struct d<d1, d2, m1, m2, false>
      {
        typedef typename maths::add
                <
                  Long<d1>
                  , typename maths::mul
                    <
                      Long<d2>
                      , typename maths::pow
                        <
                          Long<10>
                          , typename maths::abs<typename maths::sub<Long<m1>, Long<m2>>::type>::type
                        >::type
                    >::type
                >::type
                type;
      };
    } /* add_ */
  } /* double_ */
  template
  <
    long e1
    , unsigned long d1
    , unsigned long m1
    , long e2
    , unsigned long d2
    , unsigned long m2
    , unsigned long s1
    , unsigned long s2
    , bool n1
    , bool n2
  >
  struct add<Double<e1, d1, m1, s1, n1>, Double<e2, d2, m2, s2, n2>>
  {
  private:
    enum { Mult = maths::max<Long<m1>, Long<m2>>::type::value };
    enum { D = double_::add_::d<d1, d2, m1, m2, m1 < m2>::type::value };
    /// Ent = e1 + e2 + d/(10 ^ Mult);
    enum { Ent = maths::add<typename maths::add<Long<e1>, Long<e2>>::type
                            , typename maths::div
                              <
                                Long<D>
                                , typename maths::pow<Long<10>, Long<Mult>>::type
                              >::type
                            >::type::value
         };
    /// Dec = d % (10 ^ Mult);
    enum { Dec = maths::mod<Long<D>, typename maths::pow<Long<10>, Long<Mult>>::type>::type::value };
    enum { Sign = 0 };
    enum { Null = 0 };
  public:
    typedef Double<Ent, Dec, Mult, Sign, Null> type;
  };
} /* maths */

#endif /* !MATHS_DOUBLE_ADD_HH_ */
