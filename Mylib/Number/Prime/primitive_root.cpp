#pragma once
#include "Mylib/Number/Mod/mod_pow.cpp"

namespace haar_lib {
  constexpr int primitive_root(int p){
    int pf[30] = {};
    int k = 0;
    {
      int n = p - 1;
      for(int64_t i = 2; i * i <= p; ++i){
        if(n % i == 0){
          pf[k++] = i;
          while(n % i == 0) n /= i;
        }
      }
      if(n != 1)
        pf[k++] = n;
    }

    for(int g = 2; g <= p; ++g){
      bool ok = true;
      for(int i = 0; i < k; ++i){
        if(mod_pow(g, (p - 1) / pf[i], p) == 1){
          ok = false;
          break;
        }
      }

      if(not ok) continue;

      return g;
    }
    return -1;
  }
}
