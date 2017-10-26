/*!
 * \author  Armand Leclercq
 * \file  algorithms/acker.hh
 * \date  Mon 06 Jan 2014 02:51:53 PM CET
 */

#ifndef MATHS_ALGORITHMS_ACKER_HH_
# define MATHS_ALGORITHMS_ACKER_HH_
# include <long.hh>

namespace maths
{
  namespace algorithms
  {
    template <typename M, typename N>
    struct acker {};

    template <long m, long n>
    struct acker<Long<m>, Long<n>>
    {
      typedef typename acker
              <
                Long<m - 1>
                , typename acker<Long<m>, Long<n - 1>>::type
              >::type type;
    };
    template <long m>
    struct acker<Long<m>, Long<0>>
    {
      typedef typename acker<Long<m - 1>, Long<1>>::type type;
    };
    template <long n>
    struct acker<Long<0>, Long<n>>
    {
      typedef Long<n + 1> type;
    };
  } /* algorithms */
} /* maths */

#endif /* !MATHS_ALGORITHMS_ACKER_HH_ */
