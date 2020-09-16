#pragma once
#include <vector>
#include <complex>
#include <cassert>
#include <utility>

namespace haar_lib {
  template <typename T = double, bool INVERSE = false>
  auto fast_fourier_transform(std::vector<std::complex<T>> f){
    const int n = f.size();
    assert((n & (n - 1)) == 0); // データ数は2の冪乗個

    const int p = __builtin_ctz(n);

    for(int i = 0; i < n; ++i){
      int j = 0;
      for(int k = 0; k < p; ++k) j |= (i >> k & 1) << (p - 1 - k);
      if(i < j) std::swap(f[i], f[j]);
    }

    for(int b = 1; b < n; b <<= 1){
      for(int i = 0; i < b; ++i){
        T angle = 2.0 * M_PI * i / (2 * b);
        if(INVERSE) angle = -angle;
        std::complex<T> w = std::polar(1.0, angle);

        for(int j = 0; j < n; j += 2 * b){
          auto s = f[i + j];
          auto t = f[i + j + b] * w;

          f[i + j] = s + t;
          f[i + j + b] = s - t;
        }
      }
    }

    if(INVERSE) for(auto &x : f) x /= n;

    return f;
  }

  template <typename T = double>
  std::vector<std::complex<T>> fft_convolution(std::vector<std::complex<T>> f, std::vector<std::complex<T>> g){
    const int m = f.size() + g.size() - 1;
    int n = 1;
    while(n < m) n *= 2;

    f.resize(n);
    g.resize(n);

    f = fast_fourier_transform<T>(f);
    g = fast_fourier_transform<T>(g);

    std::vector<std::complex<T>> ret(n);
    for(int i = 0; i < n; ++i) ret[i] = f[i] * g[i];
    ret = fast_fourier_transform<T, true>(ret);

    return ret;
  }
}
