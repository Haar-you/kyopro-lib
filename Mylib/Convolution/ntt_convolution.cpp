#pragma once
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include "Mylib/Number/Mod/mod_power.cpp"
#include "Mylib/Number/Mod/mod_inv.cpp"

/**
 * @title Number Theoretic Transform
 */
template <int MOD, int PRIM_ROOT, int MAX_SIZE>
class NumberTheoreticTransform{
  const int MAX_POWER;
  std::vector<int64_t> BASE, INV_BASE;
  
public:
  NumberTheoreticTransform():
    MAX_POWER(__builtin_ctz(MAX_SIZE)),
    BASE(MAX_POWER),
    INV_BASE(MAX_POWER)
  {
    static_assert((MAX_SIZE & (MAX_SIZE - 1)) == 0, "MAX_SIZE must be power of 2.");

    const int64_t t = (MOD - 1) * mod_inv(MAX_SIZE, MOD) % MOD;
    const int64_t h = power(PRIM_ROOT, t, MOD);

    BASE[MAX_POWER - 1] = h;
    INV_BASE[MAX_POWER - 1] = mod_inv(h, MOD);

    for(int i = MAX_POWER - 2; i >= 0; --i){
      BASE[i] = BASE[i+1] * BASE[i+1] % MOD;
      INV_BASE[i] = INV_BASE[i+1] * INV_BASE[i+1] % MOD;
    }
  }

  void run_ntt(std::vector<int64_t> &f, bool INVERSE = false){
    const int n = f.size();
    assert((n & (n-1)) == 0 and n <= MAX_SIZE); // データ数は2の冪乗個
    
    const int p = __builtin_ctz(n);
    
    for(int i = 0; i < n; ++i){
      int j = 0;
      for(int k = 0; k < p; ++k) j |= (i >> k & 1) << (p-1-k);
      if(i < j) std::swap(f[i], f[j]);
    }
    
    for(auto &x : f) if(x > MOD) x %= MOD;
    
    if(p > 0){
      for(int b = 1, k = 0; b < n; b <<= 1, ++k){
        int64_t w = 1;
        
        for(int i = 0; i < b; ++i){
          for(int j = 0; j < n; j += 2*b){
            const auto s = f[i+j];
            const auto t = f[i+j+b] * w % MOD;
            
            f[i+j] = s + t;
            if(f[i+j] >= MOD) f[i+j] -= MOD;
            
            f[i+j+b] = s - t;
            if(f[i+j+b] < 0) f[i+j+b] += MOD;
          }
          
          if(INVERSE) (w *= INV_BASE[k]) %= MOD;
          else (w *= BASE[k]) %= MOD;
        }
      }
    }
    
    if(INVERSE){
      const int64_t t = mod_inv(n, MOD);
      for(auto &x : f) (x *= t) %= MOD;
    }
  }

  std::vector<int64_t> run_convolution(std::vector<int64_t> f, std::vector<int64_t> g){
    const int m = f.size() + g.size() - 1;
    int n = 1;
    while(n < m) n *= 2;

    std::vector<int64_t> f2(n), g2(n);

    std::copy(f.begin(), f.end(), f2.begin());
    std::copy(g.begin(), g.end(), g2.begin());
  
    run_ntt(f2);
    run_ntt(g2);
  
    for(int i = 0; i < n; ++i) (f2[i] *= g2[i]) %= MOD;
    run_ntt(f2, true);
  
    return f2;
  }
};


template <int MOD>
std::vector<int64_t> ntt_convolution(std::vector<int64_t> f, std::vector<int64_t> g){
  static constexpr int M1 = 167772161, P1 = 3;
  static constexpr int M2 = 469762049, P2 = 3;
  static constexpr int M3 = 1224736769, P3 = 3;

  for(auto &x : f) x %= MOD;
  for(auto &x : g) x %= MOD;
  
  auto res1 = NumberTheoreticTransform<M1, P1, 1 << 20>().run_convolution(f, g);
  auto res2 = NumberTheoreticTransform<M2, P2, 1 << 20>().run_convolution(f, g);
  auto res3 = NumberTheoreticTransform<M3, P3, 1 << 20>().run_convolution(f, g);

  const int n = res1.size();

  std::vector<int64_t> ret(n);

  const int64_t M12 = mod_inv(M1, M2);
  const int64_t M13 = mod_inv(M1, M3);
  const int64_t M23 = mod_inv(M2, M3);

  for(int i = 0; i < n; ++i){
    const int64_t r[3] = {res1[i], res2[i], res3[i]};

    const int64_t t0 = r[0] % M1;
    const int64_t t1 = (r[1] - t0 + M2) * M12 % M2;
    const int64_t t2 = ((r[2] - t0 + M3) * M13 % M3 - t1 + M3) * M23 % M3;
    
    ret[i] = t0;
    (ret[i] += t1 * M1 % MOD) %= MOD;
    (ret[i] += t2 * M1 % MOD * M2 % MOD) %= MOD;
  }

  return ret;
}
