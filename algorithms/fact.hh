/*!
 * \author  Armand Leclercq
 * \file  maths/algorithms/fact.hh
 * \date  Sun 05 Jan 2014 07:49:59 PM CET
 */

#ifndef MATHS_ALGORITHMS_FACT_HH_
# define MATHS_ALGORITHMS_FACT_HH_
# include <maths/long.hh>

namespace maths
{
  namespace algorithms
  {
    template <typename e>
    struct fact
    {
      typedef e type;
    };
  } /* algorithms */
} /* maths */

#endif /* !MATHS_ALGORITHMS_FACT_HH_ */
