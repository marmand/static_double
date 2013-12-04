/*!
 * \author  Armand Leclercq
 * \file  maths/double/shifted.hh
 * \date  Wed 04 Dec 2013 05:48:57 PM CET
 */

#ifndef MATHS_DOUBLE_SHIFTED_HH_
# define MATHS_DOUBLE_SHIFTED_HH_
# include <maths/add.hh>
# include <maths/sub.hh>
# include <maths/mul.hh>
# include <maths/pow.hh>

namespace maths
{
  namespace double_
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

    template
    <
      long e
      , unsigned long d
      , unsigned long m
      , bool n
      , bool z
    >
    struct shifted<Double<e, d, m, n, z>>
      : public maths::add
               <
                 typename maths::mul
                 <
                   Long<e>
                   , typename maths::pow<Long<10>, Long<m>>::type
                 >::type
                 , Long<d>
               >
    {
    };
    template
    <
      long e
      , unsigned long d
      , unsigned long m
      , bool z
    >
    struct shifted<Double<e, d, m, true, z>>
      : public maths::sub
               <
                 typename maths::mul
                 <
                   Long<e>
                   , typename maths::pow<Long<10>, Long<m>>::type
                 >::type
                 , Long<d>
               >
    {
    };
  } /* double_ */
} /* maths */

#endif /* !MATHS_DOUBLE_SHIFTED_HH_ */
