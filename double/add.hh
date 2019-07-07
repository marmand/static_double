/*!
 * \author  Armand Leclercq
 * \file  double/add.hh
 * \date  Mon 18 Nov 2013 03:04:33 PM CET
 */

#ifndef MATHS_DOUBLE_ADD_HH_
# define MATHS_DOUBLE_ADD_HH_
# include <double/type.hh>
# include <max.hh>
# include <abs.hh>
# include <add.hh>
# include <sub.hh>
# include <mul.hh>
# include <div.hh>
# include <mod.hh>
# include <pow.hh>

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
           d = ±d1 * 10 ^ |m1 - m2| + ±d2;
         else
           d = ±d1 + ±d2 * 10 ^ |m1 - m2|;
         \endcode
       *
       */
      template
      <
        bool neg1
        , bool neg2
        , unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
        , bool inf
      >
      struct d {};

      template
      <
        bool neg1
        , bool neg2
        , unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
      >
      struct d<neg1, neg2, d1, d2, m1, m2, true>
      {
        typedef typename maths::add
                <
                  typename maths::mul
                  <
                    Long<neg1 ? -d1 : d1>
                    , typename maths::pow
                      <
                        Long<10>
                        , typename maths::abs<typename maths::sub<Long<m1>, Long<m2>>::type>::type
                      >::type
                  >::type
                  , Long<neg2 ? -d2 : d2>
                >::type
                type;
      };

      template
      <
        bool neg1
        , bool neg2
        , unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
      >
      struct d<neg1, neg2, d1, d2, m1, m2, false>
      {
        typedef typename maths::add
                <
                  Long<neg1 ? -d1 : d1>
                  , typename maths::mul
                    <
                      Long<neg2 ? -d2 : d2>
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
  /// \todo Check If add doesn't break n and z meanings.
  template
  <
    long e1
    , unsigned long d1
    , unsigned long m1
    , long e2
    , unsigned long d2
    , unsigned long m2
    , bool n1
    , bool n2
    , bool z1
    , bool z2
  >
  struct add<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
  {
  private:
    enum { Mult = maths::max<Long<m1>, Long<m2>>::type::value };
    enum { D = double_::add_::d<e1 < 0, e2 < 0, d1, d2, m1, m2, m1 < m2>::type::value };
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
    enum { Neg = 0 };
    enum { Zero = 0 };
  public:
    typedef Double<Ent, Dec, Mult, Neg, Zero> type;
  };

  template
  <
    long e
    , unsigned long d
    , unsigned long m
    , bool n
    , bool z
    , long l
  >
  struct add<Double<e, d, m, n, z>, Long<l>>
  {
    typedef Double<e + l, d, m, n, z> type;
  };

  template
  <
    long e
    , unsigned long d
    , unsigned long m
    , bool n
    , bool z
    , long l
  >
  struct add<Long<l>, Double<e, d, m, n, z>>
  {
    typedef Double<l + e, d, m, n, z> type;
  };

} /* maths */

#endif /* !MATHS_DOUBLE_ADD_HH_ */
