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

# define DOUBLE(Ent, Dec) Double<Ent, Dec, DIGITS(Dec), DIGITS(Ent), Ent == 0>

#endif /* !DOUBLE_TYPE_HH_ */
