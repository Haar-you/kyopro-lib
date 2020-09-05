#pragma once

/**
 * @title Enumerate subsets (Descending order)
 * @docs enumerate_subsets_desc.md
 */
template <typename Func>
void enumerate_subsets_desc(int a, const Func &f){
  for(int t = a; ; t = (t - 1) & a){
    if(not f(t)) break;
    if(t == 0) break;
  }
}
