#pragma once

/**
 * @title Enumerate subsets (Ascending order)
 * @docs enumerate_subsets_asc.md
 */
namespace haar_lib {
  template <typename Func>
  void enumerate_subsets_asc(int a, const Func &f){
    for(int t = 0; ; t = (t - a) & a){
      if(not f(t)) break;
      if(t == a) break;
    }
  }
}
