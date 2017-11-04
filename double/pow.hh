/*!
 * \author: Armand Leclercq
 * \file: pow.hh
 * \date: Sat 04 Nov 2017 09:42:12 AM UTC
 */

#ifndef MATHS_DOUBLE_POW_HH_
# define MATHS_DOUBLE_POW_HH_
# include <double/type.hh>

namespace maths
{
  namespace double_
  {
    namespace pow_
    {
      template
      <
        long Integral
        , unsigned long Decimal
        , unsigned long Mult
        , bool neg
        , bool zero
        , long l
        , bool pos
      >
      struct impl {};

      /// \fixme: factorize with Long implementation
      template
      <
        long Integral
        , unsigned long Decimal
        , unsigned long Mult
        , bool neg
        , bool zero
        , long l
      >
      struct impl<Integral, Decimal, Mult, neg, zero, l, true>
      {
        typedef typename mul
          <
            Double<Integral, Decimal, Mult, neg, zero>
            , typename pow
              <
                Double<Integral, Decimal, Mult, neg, zero>
                , Long<l - 1>
              >::type
          >::type type;
      };

      template
      <
        long Integral
        , unsigned long Decimal
        , unsigned long Mult
        , bool neg
        , bool zero
        , long l
      >
      struct impl<Integral, Decimal, Mult, neg, zero, l, false>
      {
        typedef typename div
        <
          DOUBLE(1, 0)
          , typename pow
            <
              Double<Integral, Decimal, Mult, neg, zero>
              , Long<-l - 1>
            >::type
        >::type type;
      };
    } /* pow_ */
  } /* double_ */

  template
  <
    long Integral
    , unsigned long Decimal
    , unsigned long Mult
    , bool neg
    , bool zero
    , long l
  >
  struct pow<Double<Integral, Decimal, Mult, neg, zero>, Long<l>>
    : public double_::pow_::impl<Integral, Decimal, Mult, neg, zero, l, 0 <= l>
  {
  };

  template
  <
    long Integral
    , unsigned long Decimal
    , unsigned long Mult
    , bool neg
    , bool zero
  >
  struct pow<Double<Integral, Decimal, Mult, neg, zero>, Long<0>>
  {
    typedef Long<1> type;
  };

} /* maths */

#endif /* !MATHS_DOUBLE_POW_HH_ */
