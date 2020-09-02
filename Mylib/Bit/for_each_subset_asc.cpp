#pragma once

/**
 * @title Enumerate subsets (Ascending order)
 * @docs for_each_subset_asc.md
 */
template <typename Func>
void subset_asc(int a, const Func &f){
  for(int t = 0; ; t = (t - a) & a){
    if(not f(t)) break;
    if(t == a) break;
  }
}
