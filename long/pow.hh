/*!
 * \author  Armand Leclercq
 * \file  long/pow.hh
 * \date  Sun 17 Nov 2013 05:36:19 PM CET
 */

#ifndef MATHS_LONG_POW_HH_
# define MATHS_LONG_POW_HH_
# include <long/type.hh>
# include <mul.hh>
# include <div.hh>

namespace maths
{
  namespace long_
  {
    namespace pow_
    {
      template <typename lhs, long v2, bool pos>
      struct impl {};

      template <typename lhs, long v2>
      struct impl<lhs, v2, true>
      {
        typedef typename mul<lhs, typename pow<lhs, Long<v2 - 1>>::type>::type type;
      };

      template <typename lhs, long v2>
      struct impl<lhs, v2, false>
      {
        typedef typename div<Long<1>, typename pow<lhs, Long<-v2 - 1>>::type>::type type;
      };
    } /* pow_ */
  } /* long_ */

  template <typename lhs, long v2>
  struct pow<lhs, Long<v2>>
    : public long_::pow_::impl<lhs, v2, 0 <= v2>
  {
  };

  template <typename lhs>
  struct pow<lhs, Long<0>>
  {
    typedef Long<1> type;
  };

} /* maths */

#endif /* !MATHS_LONG_POW_HH_ */
