#pragma once

namespace haar_lib {
  template <typename Func>
  void enumerate_subsets_between(int a, int b, const Func &f){
    const int x = b ^ (a & b);
    for(int t = x; ; t = (t - 1) & x){
      if(not f(t | a)) break;
      if(t == 0) break;
    }
  }
}
