/*!
 * \author  Armand Leclercq
 * \file  shifted.hh
 * \date  Fri 06 Dec 2013 08:47:18 PM CET
 */

#ifndef SHIFTED_HH_
# define SHIFTED_HH_
# include <maths/long/type.hh>

namespace maths
{
  template <long v>
  struct shifted<Long<v>>
  {
    typedef Long<v> type;
  };
} /* maths */

#endif /* !SHIFTED_HH_ */
