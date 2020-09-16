#pragma once

namespace haar_lib {
  template <typename Func>
  void enumerate_sets_of_size_k(int k, int n, const Func &f){
    int c = (1 << k) - 1;
    while(c < (1 << n)){
      if(not f(c)) break;
      const int x = c & (-c);
      const int y = c + x;
      c = ((c & (~y)) / x >> 1) | y;
    }
  }
}
