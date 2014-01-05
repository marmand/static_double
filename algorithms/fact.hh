/*!
 * \author  Armand Leclercq
 * \file  maths/algorithms/fact.hh
 * \date  Sun 05 Jan 2014 07:49:59 PM CET
 */

#ifndef MATHS_ALGORITHMS_FACT_HH_
# define MATHS_ALGORITHMS_FACT_HH_
# include <maths/long.hh>
# include <maths/mul.hh>

namespace maths
{
  namespace algorithms
  {
    namespace long_
    {
      template <typename LongType>
      struct impl
      {
      };
      template <long v>
      struct impl<Long<v>>
      {
        typedef typename maths::mul
                <
                  Long<v>
                  , typename impl<Long<v - 1>>::type
                >::type type;
      };
      template<>
      struct impl<Long<0>>
      {
        typedef Long<1> type;
      };
    } /* long_ */
    template <typename e>
    struct fact
    {
    };
    template <long v>
    struct fact<Long<v>>
      : public long_::impl<Long<v>>
    {
    };
  } /* algorithms */
} /* maths */

#endif /* !MATHS_ALGORITHMS_FACT_HH_ */
