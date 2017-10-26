/*!
** \author  armand
** \file  compare.hh
** \date  Sun 01 Sep 2013 02:38:30 PM CEST
*/

#ifndef MATHS_COMPARE_HH_
# define MATHS_COMPARE_HH_

namespace maths
{
  /*!
   * \brief Returns a type on comparision basis.
   *
   * This methods return the first element or the second one depending on the
   * values given afterward.
   *
   * As shown by following pseudo-code snippet:
   *
     \code
     if(first)
       return lhs;
     else if (second)
       return rhs;
     else if (eq_first)
       return lhs;
     else if (eq_second)
       return rhs;
     else
       assert(false && "break compilation");
     \endcode
   */
  template
  <
    typename lhs
    , typename rhs
    , bool first
    , bool second
    , bool eq_first
    , bool eq_second
  >
  struct compare {};

  template
  <
    typename lhs
    , typename rhs
    , bool second
    , bool eq_first
    , bool eq_second
  >
  struct compare
  <
    lhs
    , rhs
    , true
    , second
    , eq_first
    , eq_second
  >
  {
    typedef lhs type;
  };
  template
  <
    typename lhs
    , typename rhs
    , bool eq_first
    , bool eq_second
  >
  struct compare
  <
    lhs
    , rhs
    , false
    , true
    , eq_first
    , eq_second
  >
  {
    typedef rhs type;
  };
  template
  <
    typename lhs
    , typename rhs
    , bool eq_second
  >
  struct compare
  <
    lhs
    , rhs
    , false
    , false
    , true
    , eq_second
  >
  {
    typedef lhs type;
  };
  template
  <
    typename lhs
    , typename rhs
  >
  struct compare
  <
    lhs
    , rhs
    , false
    , false
    , false
    , true
  >
  {
    typedef rhs type;
  };
} /* maths */

#endif /* !MATHS_COMPARE_HH_ */
