/*!
 * \author  Armand Leclercq
 * \file  long.hh
 * \date  Fri 15 Nov 2013 08:51:34 PM CET
 */

#ifndef LONG_HH_
# define LONG_HH_

template <long v>
struct Long
{
  enum { value = v };
  operator long() const
  {
    return value;
  }
};

#endif /* !LONG_HH_ */
