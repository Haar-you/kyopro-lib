#pragma once
#include <vector>

/**
 * @title Montmort数
 * @see https://atcoder.jp/contests/arc009/tasks/arc009_3
 * @note 完全順列,撹乱順列の個数
 * @note 1..nの順列を並び変えた時にどの要素も元の要素と異なるような並び替えの総数。
 */
template <typename T>
auto montmort_number(int n){
  std::vector<T> ret(n+1);

  ret[0] = 1;
  ret[1] = 0;
  ret[2] = 1;

  for(int i = 3; i <= n; ++i){
    ret[i] = (ret[i-1] + ret[i-2]) * (i-1);
  }

  return ret;
}
