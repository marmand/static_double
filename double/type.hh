/*!
** \author  armand
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
        , unsigned long size
        , bool null
      >
      struct impl {};

      template
      <
        long e
        , unsigned long d
        , unsigned long m
        , unsigned long s
      >
      struct impl<e, d, m, s, false>
      {
        enum { Ent = e };
        enum { Dec = d };
        enum { Mult = m };
        enum { Sign = e < 0 };
        operator double() const
        {
          return Sign
            ? Ent - (Dec / std::pow(10.0, Mult))
            : Ent + (Dec / std::pow(10.0, Mult));
        }
      };
      template
      <
        long e
        , unsigned long d
        , unsigned long m
        , unsigned long s
      >
      struct impl<e, d, m, s, true>
      {
        enum { Ent = e };
        enum { Dec = d };
        enum { Mult = m };
        enum { Sign = s > 1 };
        operator double() const
        {
          return Sign
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
  , unsigned long size
  , bool null
>
struct Double
  : public maths::double_::type_::impl<entiere, decimal, mult, size, null>
{
};

/// Represent a double as Ent.Dec
# define DOUBLE(Ent, Dec) Double<Ent, Dec, DIGITS(Dec), DIGITS(Ent), Ent == 0>
/// Represent a double as Ent + 0.Dec * 10 ^ -Exp
# define SMALL_DOUBLE(Ent, Dec, Exp) Double<Ent, Dec, Exp + DIGITS(Dec), DIGITS(Ent), Ent == 0>

#endif /* !DOUBLE_TYPE_HH_ */
