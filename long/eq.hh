/*!
 * \author  Armand Leclercq
 * \file  maths/long/eq.hh
 * \date  Sat 07 Dec 2013 03:26:09 PM CET
 */

#ifndef MATHS_LONG_EQ_HH_
# define MATHS_LONG_EQ_HH_

namespace maths
{
  template <long v>
  struct eq<Long<v>, Long<v>>
  {
    enum { value = true };
  };
} /* maths */

#endif /* !MATHS_LONG_EQ_HH_ */
