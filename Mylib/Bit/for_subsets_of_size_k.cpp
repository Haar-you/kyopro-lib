#pragma once

/**
 * @docs for_subsets_of_size_k.md
 */
template <typename Func>
void for_subsets_of_size_k(int n, int k, const Func &f){
  int c = (1 << k) - 1;
  while(c < (1 << n)){
    f(c);
    int x = c & (-c);
    int y = c + x;
    c = ((c & (~y)) / x >> 1) | y;
  }
}
