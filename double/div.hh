/*!
 * \author  Armand Leclercq
 * \file  double/div.hh
 * \date  Mon 02 Dec 2013 09:30:43 PM CET
 */

#ifndef MATHS_DOUBLE_DIV_HH_
# define MATHS_DOUBLE_DIV_HH_
# if defined HAVE_CONFIG_H
#  include <config.hh>
# endif /* HAVE_CONFIG_H */
# include <double/type.hh>
# include <shifted.hh>
# include <eq.hh>
# include <abs.hh>
# include <mul.hh>
# include <div.hh>
# include <mod.hh>
# include <pow.hh>

namespace maths
{
  namespace double_
  {
    namespace div_
    {
      template <typename lhs, typename rhs, typename res, unsigned n, bool z>
      struct recurse
      {
      private:
        typedef typename maths::div<lhs, rhs>::type resultat;
        typedef typename maths::mod<lhs, rhs>::type reste;
        typedef recurse
                <
                  typename maths::mul<lhs, Long<10>>::type
                  , rhs
                  , resultat
                  , n - 1
                  , maths::eq<reste, Long<0>>::value
                >
                compute;
      public:
        typedef typename compute::type type;
        enum { N = 1 + compute::N };
      };

      template <typename lhs, typename rhs, typename res, bool z>
      struct recurse<lhs, rhs, res, 0, z>
      {
        typedef res type;
        enum { N = 0 };
      };

      template <typename lhs, typename rhs, typename res, unsigned n>
      struct recurse<lhs, rhs, res, n, true>
      {
        typedef res type;
        enum { N = 0 };
      };

      template <typename lhs, typename rhs>
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
      struct impl<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
      {
      private:
        /// lhs = maths::shifted<lhs>
        typedef shifted<Double<e1, d1, m1, n1, z1>> compute_lhs;
        typedef typename compute_lhs::type lhs;
        /// rhs = maths::shifted<rhs>
        typedef shifted<Double<e2, d2, m2, n2, z2>> compute_rhs;
        typedef typename compute_rhs::type rhs;

        typedef recurse<lhs, rhs, Long<0>, DIVISION_PRECISION, false> compute;
        typedef typename compute::type result;

        enum { Mul = compute_lhs::Recursion // Digits number in #1
                   + compute_rhs::Recursion // Digits number in #2
                   + compute::N - 1         // Overflow
             };

        typedef typename pow<Long<10>, Long<Mul>>::type exp;
        enum { Ent = div<result, exp>::type::value };
        enum { Dec = abs<typename mod<result, exp>::type>::type::value };
        enum { Sig = result::value < 0 };
        enum { Zero = Ent == 0 };
      public:
        typedef Double<Ent, Dec, Mul, Sig, Zero> type;
      };
    } /* div_ */
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
  struct div<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
    : public double_::div_::impl<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
  {
  };

  /*!
   * \brief Make a division by zero not work
   *
   * This specialisation exists in order to make a division by zero to not
   * compile
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
  struct div<Double<e, d, m1, n1, z1>, Double<0, 0, m2, n2, z2>>
  {
    /*!
     * Here the inexistence of typedef and of type value declaration is wanted
     * in order to create a compilation error on div by zero call.
     */
  };
} /* maths */

#endif /* !MATHS_DOUBLE_DIV_HH_ */
