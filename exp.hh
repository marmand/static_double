/*!
 * \author: Armand Leclercq
 * \file: exp.hh
 * \date: dim. 03 juin 2018 20:05:08 CEST
 */

#ifndef EXP_HH
# define EXP_HH

# include <pow.hh>

namespace maths
{
  /*!
   * \brief Returns e ^ lhs
   */
  template <typename lhs>
  struct exp
  {
    typedef typename pow<e, lhs>::type type;
  };
} /* maths */

#endif /* !EXP_HH */
