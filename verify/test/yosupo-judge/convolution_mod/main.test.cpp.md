---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :x: test/yosupo-judge/convolution_mod/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#8dac0df2b87704e7ea660cabc39eb365">test/yosupo-judge/convolution_mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/convolution_mod/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod">https://judge.yosupo.jp/problem/convolution_mod</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Convolution/ntt_convolution.cpp.html">Number theoretic transform</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

const int mod = 998244353;
const int PRIM_ROOT = 3;

using mint = hl::modint<mod>;
using NTT = hl::number_theoretic_transform<mint, PRIM_ROOT, 1 << 20>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  auto a = hl::input_vector<int64_t>(n);
  auto b = hl::input_vector<int64_t>(m);

  auto ntt = NTT();
  auto ans = ntt.convolve(a, b);

  std::cout << hl::join(ans.begin(), ans.begin() + n + m - 1) << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/convolution_mod/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>
#line 3 "Mylib/Convolution/ntt_convolution.cpp"
#include <cassert>
#include <utility>
#include <algorithm>
#line 4 "Mylib/Number/Mint/mint.cpp"

/**
 * @title Modint
 * @docs mint.md
 */
namespace haar_lib {
  template <int32_t M>
  class modint {
  public:
    constexpr static int32_t MOD = M;
    uint32_t val;

    constexpr modint(): val(0){}
    constexpr modint(int64_t n){
      if(n >= M) val = n % M;
      else if(n < 0) val = n % M + M;
      else val = n;
    }

    constexpr auto& operator=(const modint &a){val = a.val; return *this;}
    constexpr auto& operator+=(const modint &a){
      if(val + a.val >= M) val = (uint64_t)val + a.val - M;
      else val += a.val;
      return *this;
    }
    constexpr auto& operator-=(const modint &a){
      if(val < a.val) val += M;
      val -= a.val;
      return *this;
    }
    constexpr auto& operator*=(const modint &a){
      val = (uint64_t)val * a.val % M;
      return *this;
    }
    constexpr auto& operator/=(const modint &a){
      val = (uint64_t)val * a.inv().val % M;
      return *this;
    }

    constexpr auto operator+(const modint &a) const {return modint(*this) += a;}
    constexpr auto operator-(const modint &a) const {return modint(*this) -= a;}
    constexpr auto operator*(const modint &a) const {return modint(*this) *= a;}
    constexpr auto operator/(const modint &a) const {return modint(*this) /= a;}

    constexpr bool operator==(const modint &a) const {return val == a.val;}
    constexpr bool operator!=(const modint &a) const {return val != a.val;}

    constexpr auto& operator++(){*this += 1; return *this;}
    constexpr auto& operator--(){*this -= 1; return *this;}

    constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
    constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}

    constexpr static modint power(int64_t n, int64_t p){
      if(p < 0) return power(n, -p).inv();

      int64_t ret = 1, e = n % M;
      for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
      return ret;
    }

    constexpr static modint inv(int64_t a){
      int64_t b = M, u = 1, v = 0;

      while(b){
        int64_t t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
      }

      u %= M;
      if(u < 0) u += M;

      return u;
    }

    constexpr static auto frac(int64_t a, int64_t b){return modint(a) / modint(b);}

    constexpr auto power(int64_t p) const {return power(val, p);}
    constexpr auto inv() const {return inv(val);}

    friend constexpr auto operator-(const modint &a){return modint(M - a.val);}

    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a) + b;}
    friend constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}
    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a) * b;}
    friend constexpr auto operator/(int64_t a, const modint &b){return modint(a) / b;}

    friend std::istream& operator>>(std::istream &s, modint<M> &a){s >> a.val; return s;}
    friend std::ostream& operator<<(std::ostream &s, const modint<M> &a){s << a.val; return s;}

    template <int N>
    static auto div(){
      static auto value = inv(N);
      return value;
    }

    explicit operator int32_t() const noexcept {return val;}
    explicit operator int64_t() const noexcept {return val;}
  };
}
#line 7 "Mylib/Convolution/ntt_convolution.cpp"

/**
 * @title Number theoretic transform
 * @docs ntt_convolution.md
 */
namespace haar_lib {
  template <typename T, int PRIM_ROOT, int MAX_SIZE>
  class number_theoretic_transform {
  public:
    using value_type = T;
    constexpr static int primitive_root = PRIM_ROOT;

  private:
    const int MAX_POWER;
    std::vector<T> BASE, INV_BASE;

  public:
    number_theoretic_transform():
      MAX_POWER(__builtin_ctz(MAX_SIZE)),
      BASE(MAX_POWER + 1),
      INV_BASE(MAX_POWER + 1)
    {
      static_assert((MAX_SIZE & (MAX_SIZE - 1)) == 0, "MAX_SIZE must be power of 2.");

      T t = T::power(PRIM_ROOT, (T::MOD - 1) >> (MAX_POWER + 2));
      T s = t.inv();

      for(int i = MAX_POWER - 1; i >= 0; --i){
        t *= t;
        s *= s;
        BASE[i] = -t;
        INV_BASE[i] = -s;
      }
    }

    void run(std::vector<T> &f, bool INVERSE = false){
      const int n = f.size();
      assert((n & (n - 1)) == 0 and n <= MAX_SIZE); // データ数は2の冪乗個

      if(INVERSE){
        for(int b = 1; b < n; b <<= 1){
          T w = 1;
          for(int j = 0, k = 1; j < n; j += 2 * b, ++k){
            for(int i = 0; i < b; ++i){
              const auto s = f[i + j];
              const auto t = f[i + j + b];

              f[i + j] = s + t;
              f[i + j + b] = (s - t) * w;
            }
            w *= INV_BASE[__builtin_ctz(k)];
          }
        }

        const T t = T::inv(n);
        for(auto &x : f) x *= t;
      }else{
        for(int b = n >> 1; b; b >>= 1){
          T w = 1;
          for(int j = 0, k = 1; j < n; j += 2 * b, ++k){
            for(int i = 0; i < b; ++i){
              const auto s = f[i + j];
              const auto t = f[i + j + b] * w;

              f[i + j] = s + t;
              f[i + j + b] = s - t;
            }
            w *= BASE[__builtin_ctz(k)];
          }
        }
      }
    }

    template <typename U>
    std::vector<T> convolve(std::vector<U> f, std::vector<U> g){
      const int m = f.size() + g.size() - 1;
      int n = 1;
      while(n < m) n *= 2;

      std::vector<T> f2(n), g2(n);

      for(int i = 0; i < (int)f.size(); ++i) f2[i] = f[i];
      for(int i = 0; i < (int)g.size(); ++i) g2[i] = g[i];

      run(f2);
      run(g2);

      for(int i = 0; i < n; ++i) f2[i] *= g2[i];
      run(f2, true);

      return f2;
    }
  };

  template <typename T, typename U>
  std::vector<T> convolve_general_mod(std::vector<U> f, std::vector<U> g){
    static constexpr int M1 = 167772161, P1 = 3;
    static constexpr int M2 = 469762049, P2 = 3;
    static constexpr int M3 = 1224736769, P3 = 3;

    for(auto &x : f) x %= T::MOD;
    for(auto &x : g) x %= T::MOD;

    auto res1 = number_theoretic_transform<modint<M1>, P1, 1 << 20>().convolve(f, g);
    auto res2 = number_theoretic_transform<modint<M2>, P2, 1 << 20>().convolve(f, g);
    auto res3 = number_theoretic_transform<modint<M3>, P3, 1 << 20>().convolve(f, g);

    const int n = res1.size();

    std::vector<T> ret(n);

    const int64_t M12 = (int64_t)modint<M2>::inv(M1);
    const int64_t M13 = (int64_t)modint<M3>::inv(M1);
    const int64_t M23 = (int64_t)modint<M3>::inv(M2);

    for(int i = 0; i < n; ++i){
      const int64_t r[3] = {(int64_t)res1[i], (int64_t)res2[i], (int64_t)res3[i]};

      const int64_t t0 = r[0] % M1;
      const int64_t t1 = (r[1] - t0 + M2) * M12 % M2;
      const int64_t t2 = ((r[2] - t0 + M3) * M13 % M3 - t1 + M3) * M23 % M3;

      ret[i] = T(t0) + T(t1) * M1 + T(t2) * M1 * M2;
    }

    return ret;
  }
}
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
namespace haar_lib {
  template <typename Iter>
  std::string join(Iter first, Iter last, std::string delim = " "){
    std::stringstream s;

    for(auto it = first; it != last; ++it){
      if(it != first) s << delim;
      s << *it;
    }

    return s.str();
  }
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<T> input_vector(int N){
    std::vector<T> ret(N);
    for(int i = 0; i < N; ++i) std::cin >> ret[i];
    return ret;
  }

  template <typename T>
  std::vector<std::vector<T>> input_vector(int N, int M){
    std::vector<std::vector<T>> ret(N);
    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
    return ret;
  }
}
#line 9 "test/yosupo-judge/convolution_mod/main.test.cpp"

namespace hl = haar_lib;

const int mod = 998244353;
const int PRIM_ROOT = 3;

using mint = hl::modint<mod>;
using NTT = hl::number_theoretic_transform<mint, PRIM_ROOT, 1 << 20>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  auto a = hl::input_vector<int64_t>(n);
  auto b = hl::input_vector<int64_t>(m);

  auto ntt = NTT();
  auto ans = ntt.convolve(a, b);

  std::cout << hl::join(ans.begin(), ans.begin() + n + m - 1) << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

