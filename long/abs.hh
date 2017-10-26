/*!
 * \author  Armand Leclercq
 * \file  long/abs.hh
 * \date  Sun 24 Nov 2013 06:44:16 PM CET
 */

#ifndef MATHS_LONG_ABS_HH_
# define MATHS_LONG_ABS_HH_
# include <long/type.hh>

namespace maths
{
  namespace long_
  {
    namespace abs_
    {
      template <long v, bool neg>
      struct impl {};

      template <long v>
      struct impl<v, true>
      {
        typedef Long<-v> type;
      };

      template <long v>
      struct impl<v, false>
      {
        typedef Long<v> type;
      };
    } /* abs_ */
  } /*  long_ */

  template <long v>
  struct abs<Long<v>>
    : public long_::abs_::impl<v, v < 0>
  {
  };
} /* maths */

#endif /* !MATHS_LONG_ABS_HH_ */
