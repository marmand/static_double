/*!
** \author  armand
** \file  compare.hh
** \date  Sun 01 Sep 2013 02:38:30 PM CEST
*/

#ifndef COMPARE_HH_
# define COMPARE_HH_

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

#endif /* !COMPARE_HH_ */
