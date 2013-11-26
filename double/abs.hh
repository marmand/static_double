/*!
 * \author  Armand Leclercq
 * \file  maths/double/abs.hh
 * \date  Sun 24 Nov 2013 07:28:15 PM CET
 */

#ifndef MATHS_DOUBLE_ABS_HH_
# define MATHS_DOUBLE_ABS_HH_
# include <maths/double/type.hh>

namespace maths
{
  namespace double_
  {
    namespace abs_
    {
      template <long e, unsigned long d, unsigned long m, bool neg>
      struct impl {};

      template <long e, unsigned long d, unsigned long m>
      struct impl<e, d, m, true>
      {
        typedef Double<-e, d, m> type;
      };

      template <long e, unsigned long d, unsigned long m>
      struct impl<e, d, m, false>
      {
        typedef Double<e, d, m> type;
      };
    } /* abs_ */
  } /*  double_ */

  template <long e, unsigned long d, unsigned long m>
  struct abs<Double<e, d, m>>
    : public double_::abs_::impl<e, d, m, e < 0>
  {
  };
} /* maths */

#endif /* !MATHS_DOUBLE_ABS_HH_ */
