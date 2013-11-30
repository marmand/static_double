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
      template <long e, unsigned long d, unsigned long m, unsigned long s, bool n, bool neg>
      struct impl {};

      template <long e, unsigned long d, unsigned long m, unsigned long s, bool n>
      struct impl<e, d, m, s, n, true>
      {
        typedef Double<-e, d, m, s, n> type;
      };

      template <long e, unsigned long d, unsigned long m, unsigned long s, bool n>
      struct impl<e, d, m, s, n, false>
      {
        typedef Double<e, d, m, s, n> type;
      };
    } /* abs_ */
  } /*  double_ */

  template <long e, unsigned long d, unsigned long m, unsigned long s, bool n>
  struct abs<Double<e, d, m, s, n>>
    : public double_::abs_::impl<e, d, m, s, n, e < 0>
  {
  };
} /* maths */

#endif /* !MATHS_DOUBLE_ABS_HH_ */
