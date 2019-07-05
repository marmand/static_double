/*!
 * \author  Armand Leclercq
 * \file  double/mul.hh
 * \date  Thu 28 Nov 2013 06:25:02 PM CET
 */

#ifndef MATHS_DOUBLE_MUL_HH_
# define MATHS_DOUBLE_MUL_HH_
# include <double/type.hh>
# include <shifted.hh>
# include <abs.hh>
# include <add.hh>
# include <mul.hh>
# include <div.hh>
# include <mod.hh>
# include <pow.hh>
# include <convert.hh>
# include <compare.hh>

namespace maths
{
  namespace double_
  {
    namespace mul_
    {
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
    typedef typename maths::compare
    <
      Double<Ent, Dec, Mult, Neg, Zero>
      , Double <-Ent, Dec, Mult, Neg, Zero>
      , !Neg
      , Neg
      , !Neg
      , Neg
    >::type type;
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
  /*!
   * Fast special case shortcut
   */
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
