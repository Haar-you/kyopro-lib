#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Math/polynomial_taylor_shift.cpp"

namespace haar_lib {
  template <typename T, const auto &convolve>
  std::vector<T> stirling_number_of_first_kind_fft(int N){
    if(N == 0) return {1};

    std::vector<int> p;
    {
      int a = N;

      while(a > 0){
        if(a & 1) p.push_back(1);
        p.push_back(2);
        a >>= 1;
      }
    }

    std::vector<T> ret = {1};

    std::reverse(p.begin(), p.end());
    int t = 0;
    for(int x : p){
      if(x == 1){
        std::vector<T> a = {-t, 1};
        ret = convolve(ret, a);

        t += 1;
      }else{
        auto s = polynomial_taylor_shift<T>(ret, -t, convolve);
        ret = convolve(ret, s);
        ret.resize(t * 2 + 1);

        t *= 2;
      }
    }

    ret.resize(N + 1);

    return ret;
  }
}
