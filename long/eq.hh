/*!
 * \author  Armand Leclercq
 * \file  long/eq.hh
 * \date  Sat 07 Dec 2013 03:26:09 PM CET
 */

#ifndef MATHS_LONG_EQ_HH_
# define MATHS_LONG_EQ_HH_
# include <long/type.hh>

namespace maths
{
  template <long v>
  struct eq<Long<v>, Long<v>>
    : public std::true_type
  {
  };
} /* maths */

#endif /* !MATHS_LONG_EQ_HH_ */
