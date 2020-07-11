#pragma once

/**
 * @docs monoid_utils.md
 */
template <typename Monoid, typename value_type = typename Monoid::value_type>
value_type times(value_type a, int64_t p){
  Monoid M;
  auto ret = M.id();

  while(p > 0){
    if(p & 1) ret = M.op(ret, a);
    a = M.op(a, a);
    p >>= 1;
  }

  return ret;
}
