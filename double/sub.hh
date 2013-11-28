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
  namespace double_
  {
    namespace sub_
    {
      template
      <
        unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
        , unsigned long Mult
        , bool inf
      >
      struct d {};

      template
      <
        unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
        , unsigned long Mult
      >
      struct d<d1, d2, m1, m2, Mult, true>
      {
        typedef typename maths::sub
                <
                  typename maths::add
                  <
                    typename maths::mult
                    <
                      Long<d1>
                      , typename maths::pow
                        <
                          Long<10>
                          , typename maths::abs<typename maths::sub<Long<m1>, Long<m2>>::type>::type
                        >::type
                    >::type
                    , typename maths::pow<Long<10>, Long<Mult>>::type
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
        , unsigned long Mult
      >
      struct d<d1, d2, m1, m2, Mult, false>
      {
        typedef typename maths::sub
                <
                  typename maths::add
                  <
                    Long<d1>
                    , typename maths::pow<Long<10>, Long<Mult>>::type
                  >::type
                  , typename maths::mult
                    <
                      Long<d2>
                      , typename maths::pow
                        <
                          Long<10>
                          , typename maths::abs<typename maths::sub
                                                <
                                                  Long<m1>
                                                  , Long<m2>
                                                >::type>::type
                        >::type
                    >::type
                >::type
                type;
      };

      template <typename lhs, typename rhs>
      struct dist {};

      template
      <
        long e1
        , long e2
        , unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
      >
      struct dist<Double<e1, d1, m1>, Double<e2, d2, m2>>
      {
      private:
        enum { Mult = maths::max<Long<m1>, Long<m2>>::type::value };
        enum { D = d<d1, d2, m1, m2, Mult, m1 < m2>::type::value };
        enum { Dec = maths::mod<Long<D>, typename maths::pow<Long<10>, Long<Mult>>::type>::type::value };
        enum { Ent = maths::add
                     <
                       typename maths::sub
                       <
                         Long<e1>
                         , typename maths::add<Long<1>, Long<e2>>::type
                       >::type
                       , typename maths::div<Long<D>, typename maths::pow<Long<10>, Long<Mult>>::type>::type
                     >::type::value
             };
      public:
        typedef Double<Ent, Dec, Mult> type;
      };

      template <typename lhs, typename rhs, bool first_inf>
      struct impl {};

      template
      <
        long e1
        , long e2
        , unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
      >
      struct impl<Double<e1, d1, m1>, Double<e2, d2, m2>, true>
      {
      private:
        typedef typename dist<Double<e2, d2, m2>, Double<e1, d1, m1>>::type tmp;
      public:
        typedef Double<-tmp::Ent, tmp::Dec, tmp::Mult> type;
      };

      template
      <
        long e1
        , long e2
        , unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
      >
      struct impl<Double<e1, d1, m1>, Double<e2, d2, m2>, false>
        : public dist<Double<e1, d1, m1>, Double<e2, d2, m2>>
      {
      };
    } /* sub_ */
  } /* double_ */
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
    : public double_::sub_::impl<Double<e1, d1, m1>, Double<e2, d2, m2>, e1 < e2>
  {
  };
} /* maths */

#endif /* !MATHS_DOUBLE_SUB_HH_ */
