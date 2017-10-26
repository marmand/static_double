/*!
 * \author  Armand Leclercq
 * \file  double/shifted.hh
 * \date  Wed 04 Dec 2013 05:48:57 PM CET
 */

#ifndef MATHS_DOUBLE_SHIFTED_HH_
# define MATHS_DOUBLE_SHIFTED_HH_
# include <double/type.hh>
# include <add.hh>
# include <sub.hh>
# include <mul.hh>
# include <div.hh>
# include <pow.hh>

namespace maths
{
  namespace double_
  {
    namespace shifted_
    {
      template
      <
        long e
        , unsigned long d
        , unsigned long m
        , bool n
        , bool z
      >
      struct impl
      {
      private:
        typedef typename maths::mul<Long<e>, Long<10>>::type prev_ent;
        enum { Exp = m - 1 };
        typedef typename maths::div<Long<d>, typename maths::pow<Long<10>, Long<Exp>>::type>::type ent_add;
        typedef typename maths::add<prev_ent, ent_add>::type Ent;
        typedef typename maths::sub
                <
                  Long<d>
                  , typename maths::mul
                    <
                      ent_add
                      , typename maths::pow<Long<10>, Long<Exp>
                    >::type
                  >::type
                >::type Dec;
        typedef impl<Ent::value, Dec::value, Exp, n, z> compute;
      public:
        typedef typename compute::type type;
        enum { Recursion = 1 + compute::Recursion };
      };
      template
      <
        long e
        , unsigned long d
        , unsigned long m
        , bool z
      >
      struct impl<e, d, m, true, z>
      {
      private:
        typedef typename maths::mul<Long<e>, Long<10>>::type prev_ent;
        enum { Exp = m - 1 };
        typedef typename maths::div
                <
                  Long<d>
                  , typename maths::pow
                    <
                      Long<10>
                      , Long<Exp>
                    >::type
                >::type ent_add;
        typedef typename maths::sub<prev_ent, ent_add>::type Ent;
        typedef typename maths::sub
                <
                  Long<d>
                  , typename maths::mul
                    <
                      ent_add
                      , typename maths::pow<Long<10>, Long<Exp>>::type
                    >::type
                >::type Dec;
        typedef impl<Ent::value, Dec::value, Exp, true, z> compute;
      public:
        typedef typename compute::type type;
        enum { Recursion = 1 + compute::Recursion };
      };
      template
      <
        long e
        , unsigned long m
        , bool n
        , bool z
      >
      struct impl<e, 0, m, n, z>
      {
        typedef Long<e> type;
        enum { Recursion = 0 };
      };
      template
      <
        long e
        , unsigned long m
        , bool z
      >
      struct impl<e, 0, m, true, z>
      {
        typedef Long<e> type;
        enum { Recursion = 0 };
      };
    } /* shifted_ */
  } /* double_ */
  /*!
   * Computes the shifted value of the Double passed as parameter
   */
  template
  <
    long e
    , unsigned long d
    , unsigned long m
    , bool n
    , bool z
  >
  struct shifted<Double<e, d, m, n, z>>
    : public double_::shifted_::impl<e, d, m, n, z>
  {
  };
} /* maths */

#endif /* !MATHS_DOUBLE_SHIFTED_HH_ */
