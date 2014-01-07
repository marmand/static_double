/*!
 * \author  Armand Leclercq
 * \file  maths/double/mul.hh
 * \date  Thu 28 Nov 2013 06:25:02 PM CET
 */

#ifndef MATHS_DOUBLE_MUL_HH_
# define MATHS_DOUBLE_MUL_HH_
# include <maths/double/type.hh>
# include <maths/shifted.hh>
# include <maths/abs.hh>
# include <maths/add.hh>
# include <maths/mul.hh>
# include <maths/div.hh>
# include <maths/mod.hh>
# include <maths/pow.hh>

namespace maths
{
  namespace double_
  {
    namespace mul_
    {
      template <typename T, bool neg>
      struct impl {};

      template
      <
        long e
        , unsigned long d
        , unsigned long m
        , bool n
        , bool z
      >
      struct impl<Double<e, d, m, n, z>, true>
      {
        typedef Double<-e, d, m, n, z> type;
      };
      template
      <
        long e
        , unsigned long d
        , unsigned long m
        , bool n
        , bool z
      >
      struct impl<Double<e, d, m, n, z>, false>
      {
        typedef Double<e, d, m, n, z> type;
      };
    } /* mul_ */
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
  struct mul<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
  {
  private:
    /// CommaLess = (e1 * 10 ^ m1 +/- d1) * (e2 * 10 ^ m2 +/- d2)
    enum { CommaLess = maths::mul
                       <
                         typename shifted<Double<e1, d1, m1, n1, z1>>::type
                         , typename shifted<Double<e2, d2, m2, n2, z2>>::type
                       >::type::value
         };
    /// m = m1 + m2
    enum { Mult = maths::add
                  <
                    Long<shifted<Double<e1, d1, m1, n1, z1>>::Recursion>
                    , Long<shifted<Double<e2, d2, m2, n2, z2>>::Recursion>
                  >::type::value
         };
    /// d = | CommaLess % 10 ^ m |
    enum { Dec = maths::abs
                 <
                   typename maths::mod
                     <
                       Long<CommaLess>
                       , typename maths::pow<Long<10>, Long<Mult>>::type
                     >::type
                 >::type::value
         };
    /// e = | CommaLess / 10 ^ m |
    enum { Ent = maths::abs
                 <
                   typename maths::div
                   <
                     Long<CommaLess>
                     , typename maths::pow<Long<10>, Long<Mult>>::type
                   >::type
                 >::type::value
         };
    enum { Neg = n1 ^ n2};
    enum { Zero = Ent == 0 };
  public:
    typedef typename double_::mul_::impl<Double<Ent, Dec, Mult, Neg, Zero>, Neg>::type type;
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
    , bool n1
    , bool n2
    , bool z1
    , bool z2
  >
  struct mul<Double<0, 0, m1, n1, z1>, Double<e, d, m2, n2, z2>>
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
    , bool n1
    , bool n2
    , bool z1
    , bool z2
  >
  struct mul<Double<e, d, m1, n1, z1>, Double<0, 0, m2, n2, z2>>
  {
    typedef DOUBLE(0, 0) type;
  };

  // ambiguity clarification
  template
  <
    unsigned long m1
    , unsigned long m2
    , bool n1
    , bool n2
    , bool z1
    , bool z2
  >
  struct mul<Double<0, 0, m1, n1, z1>, Double<0, 0, m2, n2, z2>>
  {
    typedef DOUBLE(0, 0) type;
  };
} /* maths */

#endif /* !MATHS_DOUBLE_MUL_HH_ */
