/*!
 * \author  Armand Leclercq
 * \file  maths/eq.hh
 * \date  Sat 07 Dec 2013 03:22:46 PM CET
 */

#ifndef MATHS_EQ_HH_
# define MATHS_EQ_HH_

namespace maths
{
  /*!
   * \brief Represent the equality operation
   * \todo Create a logical namespace in which put boolean representation
   * \todo Make compare by usable for eq
   * \todo Create logical testsuite
   */
  template <typename lhs, typename rhs>
  struct eq
  {
    enum { value = false };
  };
} /* maths */

# include <maths/long/eq.hh>
#endif /* !MATHS_EQ_HH_ */
