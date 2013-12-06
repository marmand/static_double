/*!
 * \author  Armand Leclercq
 * \file  maths/double/div.hh
 * \date  Mon 02 Dec 2013 09:30:43 PM CET
 */

#ifndef MATHS_DOUBLE_DIV_HH_
# define MATHS_DOUBLE_DIV_HH_
# include <maths/double/type.hh>
# include <maths/shifted.hh>

namespace maths
{
  namespace double_
  {
    namespace div_
    {
      template <typename lhs, typename rhs>
      struct impl {};

      template
      <
        long e1
        , long e2
        , unsigned long d1
        , unsigned long d2
        , unsigned long m1
        , unsigned long m2
        , bool n1
        , bool n2
        , bool z1
        , bool z2
      >
      struct impl<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
      {
      private:
        /// lhs = maths::double_::shifted<lhs>
        typedef typename shifted<Double<e1, d1, m1, n1, z1>>::type lhs;
        /// rhs = maths::double_::shifted<rhs>
        typedef typename shifted<Double<e2, d2, m2, n2, z2>>::type rhs;
      };
    } /* div_ */
  } /* double_ */
  template
  <
    long e1
    , long e2
    , unsigned long d1
    , unsigned long d2
    , unsigned long m1
    , unsigned long m2
    , bool n1
    , bool n2
    , bool z1
    , bool z2
  >
  struct div<Double<e1, d1, m1, n1, z1>, Double<e2, d2, m2, n2, z2>>
  {
    typedef DOUBLE(0, 0) type;
  };

  /*!
   * \brief Make a division by zero not work
   *
   * This specialisation exists in order to make a division by zero to not
   * compile
   */
  template
  <
    long e
    , unsigned long d
    , unsigned long m1
    , unsigned long m2
    , bool n1
    , bool n2
    , bool z1
    , bool z2
  >
  struct div<Double<e, d, m1, n1, z1>, Double<0, 0, m2, n2, z2>>
  {
    /*!
     * Here the inexistence of typedef and of type value declaration is wanted
     * in order to create a compilation error on div by zero call.
     */
  };
} /* maths */

#endif /* !MATHS_DOUBLE_DIV_HH_ */
