/*!
 * \author  Armand Leclercq
 * \file  double/sub.hh
 * \date  Tue 19 Nov 2013 03:32:45 PM CET
 */

#ifndef MATHS_DOUBLE_SUB_HH_
# define MATHS_DOUBLE_SUB_HH_
# include <double/type.hh>
# include <max.hh>
# include <add.hh>
# include <sub.hh>
# include <mul.hh>
# include <div.hh>
# include <mod.hh>
# include <pow.hh>
# include <convert.hh>

namespace maths
{
  namespace double_
  {
    namespace sub_
    {
      template
      <
        bool neg1
        , bool neg2
        , unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
        , unsigned long Mult
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
        , unsigned long Mult
      >
      struct d<neg1, neg2, d1, d2, m1, m2, Mult, true>
      {
        typedef
        typename maths::abs
        <
          typename maths::sub
          <
            typename maths::add
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
              , typename maths::pow<Long<10>, Long<Mult>>::type
            >::type
            , Long<neg2 ? -d2 : d2>
          >::type
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
        , unsigned long Mult
      >
      struct d<neg1, neg2, d1, d2, m1, m2, Mult, false>
      {
        typedef
        typename maths::abs
        <
          typename maths::sub
          <
            typename maths::add
            <
              Long<neg1 ? -d1 : d1>
              , typename maths::pow<Long<10>, Long<Mult>>::type
            >::type
            , typename maths::mul
              <
                Long<neg2 ? -d2 : d2>
                , typename maths::pow
                  <
                    Long<10>
                    , typename maths::abs
                      <
                        typename maths::sub
                        <
                          Long<m1>
                          , Long<m2>
                        >::type
                      >::type
                  >::type
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
        , bool n1
        , bool n2
        , bool z1
        , bool z2
      >
      struct dist<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
      {
      private:
        enum { Mult = maths::max<Long<m1>, Long<m2>>::type::value };
        enum { D = d<e1 < 0, e2 < 0, d1, d2, m1, m2, Mult, m1 < m2>::type::value };
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
        enum { Neg = Ent < 0 };
        enum { Zero = Ent == 0 && Dec == 0};
      public:
        typedef Double<Ent, Dec, Mult, Neg, Zero> type;
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
        , bool n1
        , bool n2
        , bool z1
        , bool z2
      >
      struct impl<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>, true>
      {
      private:
        typedef typename dist<Double<e2, d2, m2, n2, z2>, Double<e1, d1, m1, n1, z1>>::type tmp;
      public:
        typedef Double<-tmp::Ent, tmp::Dec, tmp::Mult, !tmp::Neg, tmp::Zero> type;
      };

      template
      <
        long e1
        , long e2
        , unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
        , bool n1
        , bool n2
        , bool z1
        , bool z2
      >
      struct impl<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>, false>
        : public dist<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
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
    , bool n1
    , bool n2
    , bool z1
    , bool z2
  >
  struct sub<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
    : public double_::sub_::impl
      <
        Double<e1, d1, m1, n1, z1>
        , Double<e2, d2, m2, n2, z2>
        /// \todo Create an operator that tells you which one is the min/max
        , e1 != e2
          ? e1 < e2
          : (n1 ? -d1 : d1)  < (n2 ? -d2 : d2)
      >
  {
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
  struct sub<Double<e, d, m, n, z>, Long<l>>
  {
    typedef
    typename maths::sub
    <
      Double<e, d, m, n, z>
      , typename maths::convert<Long<l>>::type
    >::type
    type;
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
  struct sub<Long<l>, Double<e, d, m, n, z>>
  {
    typedef
    typename maths::sub
    <
      typename maths::convert<Long<l>>::type
      , Double<e, d, m, n, z>
    >::type
    type;
  };
} /* maths */

#endif /* !MATHS_DOUBLE_SUB_HH_ */
