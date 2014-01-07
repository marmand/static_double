/*!
** \author  Armand Leclercq
** \file    double/type.hh
** \date    Sat 17 Aug 2013 12:21:20 PM CEST
*/

#ifndef DOUBLE_TYPE_HH_
# define DOUBLE_TYPE_HH_
# include <cmath>
# include <digits.hh>

namespace maths
{
  namespace double_
  {
    namespace type_
    {
      template
      <
        long e
        , unsigned long d
        , unsigned long m
        , bool n
        , bool z
      >
      struct impl {};

      template
      <
        long e
        , unsigned long d
        , unsigned long m
        , bool n
      >
      struct impl<e, d, m, n, false>
      {
        enum { Ent = e };
        enum { Dec = d };
        enum { Mult = m };
        enum { Neg = n };
        enum { Zero = false };
        operator double() const
        {
          return Neg
            ? Ent - (Dec / std::pow(10.0, Mult))
            : Ent + (Dec / std::pow(10.0, Mult));
        }
      };
      template
      <
        long e
        , unsigned long d
        , unsigned long m
        , bool n
      >
      struct impl<e, d, m, n, true>
      {
        enum { Ent = e };
        enum { Dec = d };
        enum { Mult = m };
        enum { Neg = n };
        enum { Zero = true };
        operator double() const
        {
          return Neg
            ? Ent - (Dec / std::pow(10.0, Mult))
            : Ent + (Dec / std::pow(10.0, Mult));
        }
      };
    } /* type_ */
  } /* double_ */
} /* maths */

/*!
 * \class Double
 * \brief Represent a double in static world
 *
 * This class aims to represent doubles as types. I choosed not to used C++11
 * constexpr in order to test my adaptability to the static world
 */
template
<
  long entiere
  , unsigned long decimal
  , unsigned long mult
  , bool neg
  , bool zero
>
struct Double
  : public maths::double_::type_::impl<entiere, decimal, mult, neg, zero>
{
};

/// Represent a double as Ent + 0.Dec * 10 ^ -Exp
/// \todo Rename this macro
# define SMALL_DOUBLE(Ent, Dec, Exp)            \
  Double                                        \
  <                                             \
    (Ent)                                       \
    , (Dec)                                     \
    , (Exp + DIGITS(Dec))                       \
    , (Ent == 0 ? DIGITS(Ent) > 1 : Ent < 0)    \
    , (Ent == 0)                                \
  >

/// Represent a double as Ent.Dec
# define DOUBLE(Ent, Dec) SMALL_DOUBLE(Ent, Dec, 0)

// Define usefull constants
namespace maths
{
  /// \typedef e from math.h M_E
  typedef DOUBLE(2, 7182818284590452354) e;
  /// \typedef pi from math.h M_PI
  typedef DOUBLE(3, 1415926535897932385) pi;
} /* maths */

#endif /* !DOUBLE_TYPE_HH_ */
