/*!
 * \author  Armand Leclercq
 * \file  maths/algorithms/sudan.hh
 * \date  Mon 06 Jan 2014 03:13:21 PM CET
 */

#ifndef MATHS_ALGORITHMS_SUDAN_HH_
# define MATHS_ALGORITHMS_SUDAN_HH_
# include <maths/long.hh>
# include <maths/double.hh>
# include <maths/add.hh>
# include <maths/sub.hh>

namespace maths
{
  namespace algorithms
  {
    /*!
     * \brief implement the first created non primitive recursive function.
     *
     * http://en.wikipedia.org/wiki/Sudan_function
     */
    template <typename N, typename X, typename Y>
    struct sudan {};

    template <long n, typename X, typename Y>
    struct sudan<Long<n>, X, Y>
    {
      typedef typename sudan
              <
                Long<n - 1>
                , typename sudan
                  <
                    Long<n>
                    , X
                    , typename maths::sub<Y, Long<1>>::type
                  >::type
                , typename maths::add
                  <
                    typename sudan
                    <
                      Long<n>
                      , X
                      , typename maths::sub<Y, Long<1>>::type
                    >::type
                  , Y
                >::type
              >::type type;
    };

    template <long n, typename X>
    struct sudan<Long<n>, X, Long<0>>
    {
      typedef X type;
    };

    template <typename X, typename Y>
    struct sudan<Long<0>, X, Y>
    {
      typedef typename maths::add<X, Y>::type type;
    };

    // ambigious template clearing
    template <typename X>
    struct sudan<Long<0>, X, Long<0>>
    {
      typedef X type;
    };
  } /* algorithms */
} /* maths */

#endif /* !MATHS_ALGORITHMS_SUDAN_HH_ */
