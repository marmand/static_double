/*!
** \author  armand
** \file    double/type.hh
** \date    Sat 17 Aug 2013 12:21:20 PM CEST
*/

#ifndef DOUBLE_TYPE_HH_
# define DOUBLE_TYPE_HH_
# include <cmath>
# include <digits.hh>

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
{
  enum { Ent = entiere };
  enum { Dec = decimal };
  enum { Mult = mult };
  enum { Neg = neg };
  enum { Zero = zero };
  operator double() const
  {
    return Neg
      ? Ent - (Dec / std::pow(10.0, Mult))
      : Ent + (Dec / std::pow(10.0, Mult));
  }
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
  // e from math.h M_E
  typedef DOUBLE(2, 7182818284590452354) e;
  // pi from math.h M_PI
  typedef DOUBLE(3, 1415926535897932385) pi;
} /* maths */

#endif /* !DOUBLE_TYPE_HH_ */
