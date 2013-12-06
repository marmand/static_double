/*!
 * \author  Armand Leclercq
 * \file  maths/double/shifted.hh
 * \date  Wed 04 Dec 2013 05:48:57 PM CET
 */

#ifndef MATHS_DOUBLE_SHIFTED_HH_
# define MATHS_DOUBLE_SHIFTED_HH_
# include <maths/double/type.hh>
# include <maths/add.hh>
# include <maths/sub.hh>
# include <maths/mul.hh>
# include <maths/pow.hh>

namespace maths
{
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
} /* maths */

#endif /* !MATHS_DOUBLE_SHIFTED_HH_ */
