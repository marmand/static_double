/*!
 * \author  Armand Leclercq
 * \file  algorithms/fibo.hh
 * \date  Mon 06 Jan 2014 02:15:25 PM CET
 */

#ifndef MATHS_ALGORITHMS_FIBO_HH_
# define MATHS_ALGORITHMS_FIBO_HH_
# include <long.hh>
# include <add.hh>

namespace maths
{
  namespace algorithms
  {
    template <typename V>
    struct fibo {};

    template <long v>
    struct fibo<Long<v>>
    {
      typedef typename maths::add
              <
                typename maths::algorithms::fibo<Long<v - 1>>::type
                , typename maths::algorithms::fibo<Long<v - 2 >>::type
              >::type type;
    };
    template<>
    struct fibo<Long<0>>
    {
      typedef Long<0> type;
    };
    template<>
    struct fibo<Long<1>>
    {
      typedef Long<1> type;
    };
  } /* algorithms */
} /* maths */

#endif /* !MATHS_ALGORITHMS_FIBO_HH_ */
