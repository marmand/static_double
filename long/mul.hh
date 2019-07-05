/*!
 * \author  Armand Leclercq
 * \file  long/mul.hh
 * \date  Mon 18 Nov 2013 02:25:42 PM CET
 */

#ifndef MATHS_LONG_MUL_HH_
# define MATHS_LONG_MUL_HH_
# include <long/type.hh>
# include <add.hh>
# include <sub.hh>
# include <compare.hh>

namespace maths
{
  namespace long_
  {
    namespace mul_
    {
      template <typename lhs, long l, bool pos>
      struct impl {};

      template <typename lhs, long l>
      struct impl<lhs, l, true>
      {
        typedef typename add<lhs, typename impl<lhs, l - 1, true>::type>::type type;
      };

      template <typename lhs>
      struct impl<lhs, 0, true>
      {
        typedef Long<0> type;
      };

      template <typename lhs>
      struct impl<lhs, 1, true>
      {
        typedef lhs type;
      };

      template <typename lhs, long l>
      struct impl<lhs, l, false>
      {
        // a*-b == -a*b
        typedef typename impl<lhs, -l, true>::type type;
      };

      template <typename lhs>
      struct impl<lhs, 0, false>
      {
        typedef Long<0> type;
      };

      template <typename lhs>
      struct impl<lhs, -1, false>
      {
        typedef typename sub<Long<0>, lhs>::type type;
      };
    } /* mul_ */
  } /* long_ */

  template <typename lhs, long l>
  struct mul<lhs, Long<l>>
  {
    typedef typename long_::mul_::impl<lhs, l, l >= 0>::type type;
  };

  template <long l, typename rhs>
  struct mul<Long<l>, rhs>
  {
    // a*b == b*a
    typedef typename mul<rhs, Long<l>>::type type;
  };

  template <long v1, long v2>
  struct mul<Long<v1>, Long<v2>>
  {
    typedef Long<v1 * v2> type;
  };
} /* maths */

#endif /* !MATHS_LONG_MUL_HH_ */
