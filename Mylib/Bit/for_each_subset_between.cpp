#pragma once

/**
 * @title Enumerate subsets (Between)
 * @docs for_each_subset_between.md
 */
template <typename Func>
void subset_between(int a, int b, const Func &f){
  const int x = b ^ (a & b);
  for(int t = x; ; t = (t - 1) & x){
    if(not f(t | a)) break;
    if(t == 0) break;
  }
}
