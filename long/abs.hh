/*!
 * \author  Armand Leclercq
 * \file  maths/long/abs.hh
 * \date  Sun 24 Nov 2013 06:44:16 PM CET
 */

#ifndef MATHS_LONG_ABS_HH_
# define MATHS_LONG_ABS_HH_
# include <maths/long/type.hh>

namespace maths
{
  namespace
  {
    template <long v, bool neg>
    struct long_abs_impl {};

    template <long v>
    struct long_abs_impl<v, true>
    {
      typedef Long<-v> type;
    };

    template <long v>
    struct long_abs_impl<v, false>
    {
      typedef Long<v> type;
    };
  } /*  */

  template <long v>
  struct abs<Long<v>>
    : public long_abs_impl<v, v < 0>
  {
  };
} /* maths */

#endif /* !MATHS_LONG_ABS_HH_ */
