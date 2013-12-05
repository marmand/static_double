/*!
 * \author  Armand Leclercq
 * \file  maths/convert.hh
 * \date  Tue 19 Nov 2013 11:48:12 AM CET
 */

#ifndef MATHS_CONVERT_HH_
# define MATHS_CONVERT_HH_
# include <maths/long.hh>
# include <maths/double.hh>

namespace maths
{
  /*!
   * \brief Convert a number type to another
   *
   * As we do not have dynamic conversion, but we can through operators:
   *
     \code
     template <long v>
     Long<v>::operator long () { return v; }

     template<>
     Double<>::operator double () { return value; }
     \endcode
   *
   * As expected these are pseudo-code methods, in order to avoid code
   * replication in documentation.
   *
   * We do also have static conversion with maths::convert, that converts from
   * Long to Double and from Double to Long.
   */
  template <typename e>
  struct convert {};

  template <long e, unsigned long d, unsigned long m, bool n, bool z>
  struct convert<Double<e, d, m, n, z>>
  {
    typedef Long<e> type;
  };

  template <long v>
  struct convert<Long<v>>
  {
    typedef Double<v, 0, 1, v < 0, v == 0> type;
  };
} /* maths */

#endif /* !MATHS_CONVERT_HH_ */
