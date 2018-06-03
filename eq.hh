/*!
 * \author  Armand Leclercq
 * \file  eq.hh
 * \date  Sat 07 Dec 2013 03:22:46 PM CET
 */

#ifndef MATHS_EQ_HH_
# define MATHS_EQ_HH_

# include <type_traits>

namespace maths
{
  /*!
   * \brief Represent the equality operation
   * \todo Make compare by usable for eq
   * \todo Create logical testsuite
   */
  template <typename lhs, typename rhs>
  struct eq : public std::false_type
  {
  };
} /* maths */

# include <long/eq.hh>
# include <double/eq.hh>
#endif /* !MATHS_EQ_HH_ */
