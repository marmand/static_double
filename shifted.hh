/*!
 * \author  Armand Leclercq
 * \file  shifted.hh
 * \date  Fri 06 Dec 2013 08:38:52 PM CET
 */

#ifndef MATHS_SHIFTED_HH_
# define MATHS_SHIFTED_HH_

namespace maths
{
  /*!
   * \brief This computes the value of the Double in complete Long
   * representation.
   *
   * This structure computes the value of the Double diven as template
   * parameter as a single long, in order to make multiplication easier.
   *
     \code
     if (s)
       v = e * 10 ^ m - d;
     else
       v = e * 10 ^ m + d;
     \endcode
   *
   */
  template <typename T>
  struct shifted {};
} /* maths */

# include <long/shifted.hh>
# include <double/shifted.hh>
#endif /* !MATHS_SHIFTED_HH_ */
