#pragma once

/**
 * @title Enumerate supersets (Descending order)
 * @docs enumerate_supersets_desc.md
 */
namespace haar_lib {
  template <typename Func>
  void enumerate_supersets_desc(int a, int n, const Func &f){
    const int x = (1 << n) - 1, y = x ^ (a & x);
    for(int t = y; ; t = (t - 1) & y){
      if(not f(t | a)) break;
      if(t == 0) break;
    }
  }
}
