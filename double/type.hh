/*!
** \author  armand
** \file    double/type.hh
** \date    Sat 17 Aug 2013 12:21:20 PM CEST
*/

#ifndef DOUBLE_TYPE_HH_
# define DOUBLE_TYPE_HH_
# include <cmath>
# include <digits.hh>

template
<
  long entiere
  , unsigned long decimal
  , unsigned long mult
>
struct Double
{
  enum { Ent = entiere };
  enum { Dec = decimal };
  enum { Mult = mult };
  operator double() const
  {
    return Ent < 0
      ? Ent - (Dec / std::pow(10.0, Mult))
      : Ent + (Dec / std::pow(10.0, Mult));
  }
};

# define DOUBLE(Ent, Dec) Double<Ent, Dec, DIGITS(Dec)>

#endif /* !DOUBLE_TYPE_HH_ */
