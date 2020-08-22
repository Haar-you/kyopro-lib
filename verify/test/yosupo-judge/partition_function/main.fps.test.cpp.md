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


# :heavy_check_mark: test/yosupo-judge/partition_function/main.fps.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3c72a5f9e51247cad1bcbc8d30f4715f">test/yosupo-judge/partition_function</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/partition_function/main.fps.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-21 11:48:40+09:00


* see: <a href="https://judge.yosupo.jp/problem/partition_function">https://judge.yosupo.jp/problem/partition_function</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Combinatorics/partition_number_fps.cpp.html">Partition number (FPS)</a>
* :question: <a href="../../../../library/Mylib/Convolution/ntt_convolution.cpp.html">Number theoretic transform</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>
* :question: <a href="../../../../library/Mylib/Math/formal_power_series.cpp.html">Formal power series</a>
* :question: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include <functional>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/partition_number_fps.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/IO/join.cpp"

constexpr int PRIM = 3;
using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;
using NTT = NumberTheoreticTransform<mint,PRIM,1<<20>;

int main(){
  using namespace std::placeholders;
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto ntt = NTT();
  FPS::convolve = std::bind(&NTT::convolve<mint>, &ntt, _1, _2);

  auto ans = partition_number<FPS>(N);
  std::cout << join(ans.begin(), ans.begin() + (N + 1)) << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/partition_function/main.fps.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include <functional>
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title Modint
 * @docs mint.md
 */
template <int32_t M> class ModInt{
public:
  constexpr static int32_t MOD = M;
  uint32_t val;
  
  constexpr ModInt(): val(0){}
  constexpr ModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  constexpr auto& operator=(const ModInt &a){val = a.val; return *this;}
  constexpr auto& operator+=(const ModInt &a){
    if(val + a.val >= M) val = (uint64_t)val + a.val - M;
    else val += a.val;
    return *this;
  }
  constexpr auto& operator-=(const ModInt &a){
    if(val < a.val) val += M;
    val -= a.val;
    return *this;
  }
  constexpr auto& operator*=(const ModInt &a){
    val = (uint64_t)val * a.val % M;
    return *this;
  }
  constexpr auto& operator/=(const ModInt &a){
    val = (uint64_t)val * a.inv().val % M;
    return *this;
  }

  constexpr auto operator+(const ModInt &a) const {return ModInt(*this) += a;}
  constexpr auto operator-(const ModInt &a) const {return ModInt(*this) -= a;}
  constexpr auto operator*(const ModInt &a) const {return ModInt(*this) *= a;}
  constexpr auto operator/(const ModInt &a) const {return ModInt(*this) /= a;}
  
  constexpr bool operator==(const ModInt &a) const {return val == a.val;}
  constexpr bool operator!=(const ModInt &a) const {return val != a.val;}
  
  constexpr auto& operator++(){*this += 1; return *this;}
  constexpr auto& operator--(){*this -= 1; return *this;}
  
  constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
  constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}
  
  constexpr static ModInt power(int64_t n, int64_t p){
    if(p < 0) return power(n, -p).inv();
    
    int64_t ret = 1, e = n % M;
    for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
    return ret;
  }
  
  constexpr static ModInt inv(int64_t a){
    int64_t b = M, u = 1, v = 0;
    
    while(b){
      int64_t t = a / b;
      a -= t * b; std::swap(a,b);
      u -= t * v; std::swap(u,v);
    }
    
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
  
  constexpr static auto frac(int64_t a, int64_t b){return ModInt(a) / ModInt(b);}
  
  constexpr auto power(int64_t p) const {return power(val, p);}
  constexpr auto inv() const {return inv(val);}
  
  friend constexpr auto operator-(const ModInt &a){return ModInt(M-a.val);}
  
  friend constexpr auto operator+(int64_t a, const ModInt &b){return ModInt(a) + b;}
  friend constexpr auto operator-(int64_t a, const ModInt &b){return ModInt(a) - b;}
  friend constexpr auto operator*(int64_t a, const ModInt &b){return ModInt(a) * b;}
  friend constexpr auto operator/(int64_t a, const ModInt &b){return ModInt(a) / b;}
  
  friend std::istream& operator>>(std::istream &s, ModInt<M> &a){s >> a.val; return s;}
  friend std::ostream& operator<<(std::ostream &s, const ModInt<M> &a){s << a.val; return s;}

  template <int N>
  static auto div(){
    static auto value = inv(N);
    return value;
  }

  explicit operator int32_t() const noexcept {return val;}
  explicit operator int64_t() const noexcept {return val;}
};
#line 2 "Mylib/Combinatorics/partition_number_fps.cpp"
#include <vector>
#include <cmath>

/**
 * @title Partition number (FPS)
 * @docs partition_number_fps.cpp
 */
template <typename Fps>
auto partition_number(int N){
  using T = typename Fps::value_type;
  
  std::vector<T> f(N + 1);
  f[0] = 1;

  {
    const int M = (sqrt(1 + 24 * N) - 1) / 6;
    for(int i = 1; i <= M; ++i){
      f[i * (3 * i + 1) / 2] += (i % 2 == 0 ? 1 : -1);
    }
  }

  {
    const int M = (sqrt(1 + 24 * N) + 1) / 6;
    for(int i = 1; i <= M; ++i){
      f[i * (3 * i - 1) / 2] += (i % 2 == 0 ? 1 : -1);
    }
  }

  Fps ret(f);
  ret = ret.inv();

  return ret;
}
#line 3 "Mylib/Convolution/ntt_convolution.cpp"
#include <cassert>
#line 5 "Mylib/Convolution/ntt_convolution.cpp"
#include <algorithm>
#line 7 "Mylib/Convolution/ntt_convolution.cpp"

/**
 * @title Number theoretic transform
 * @docs ntt_convolution.md
 */
template <typename T, int PRIM_ROOT, int MAX_SIZE>
class NumberTheoreticTransform{
public:
  using value_type = T;
  constexpr static int primitive_root = PRIM_ROOT;

private:
  const int MAX_POWER;
  std::vector<T> BASE, INV_BASE;
  
public:
  NumberTheoreticTransform():
    MAX_POWER(__builtin_ctz(MAX_SIZE)),
    BASE(MAX_POWER + 1),
    INV_BASE(MAX_POWER + 1)
  {
    static_assert((MAX_SIZE & (MAX_SIZE - 1)) == 0, "MAX_SIZE must be power of 2.");

    T t = T::power(PRIM_ROOT, (T::MOD-1) >> (MAX_POWER + 2));
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
    assert((n & (n-1)) == 0 and n <= MAX_SIZE); // データ数は2の冪乗個

    if(INVERSE){
      for(int b = 1; b < n; b <<= 1){
        T w = 1;
        for(int j = 0, k = 1; j < n; j += 2 * b, ++k){
          for(int i = 0; i < b; ++i){
            const auto s = f[i+j];
            const auto t = f[i+j+b];
            
            f[i+j] = s + t;
            f[i+j+b] = (s - t) * w;
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
            const auto s = f[i+j];
            const auto t = f[i+j+b] * w;
            
            f[i+j] = s + t;
            f[i+j+b] = s - t;
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
  
  auto res1 = NumberTheoreticTransform<ModInt<M1>, P1, 1 << 20>().convolve(f, g);
  auto res2 = NumberTheoreticTransform<ModInt<M2>, P2, 1 << 20>().convolve(f, g);
  auto res3 = NumberTheoreticTransform<ModInt<M3>, P3, 1 << 20>().convolve(f, g);

  const int n = res1.size();

  std::vector<T> ret(n);

  const int64_t M12 = (int64_t)ModInt<M2>::inv(M1);
  const int64_t M13 = (int64_t)ModInt<M3>::inv(M1);
  const int64_t M23 = (int64_t)ModInt<M3>::inv(M2);

  for(int i = 0; i < n; ++i){
    const int64_t r[3] = {(int64_t)res1[i].val, (int64_t)res2[i].val, (int64_t)res3[i].val};

    const int64_t t0 = r[0] % M1;
    const int64_t t1 = (r[1] - t0 + M2) * M12 % M2;
    const int64_t t2 = ((r[2] - t0 + M3) * M13 % M3 - t1 + M3) * M23 % M3;
    
    ret[i] = T(t0) + T(t1) * M1 + T(t2) * M1 * M2;
  }

  return ret;
}
#line 2 "Mylib/Math/formal_power_series.cpp"

#line 5 "Mylib/Math/formal_power_series.cpp"
#include <initializer_list>

/**
 * @title Formal power series
 * @docs formal_power_series.md
 */
template <typename T>
struct FormalPowerSeries{
  using value_type = T;
  
  static std::function<std::vector<T>(std::vector<T>, std::vector<T>)> convolve;
  static std::function<std::optional<T>(T)> get_sqrt;

  std::vector<T> data;

  FormalPowerSeries(const std::vector<T> &data): data(data){}
  FormalPowerSeries(std::initializer_list<T> init): data(init.begin(), init.end()){}
  FormalPowerSeries(int N): data(N){}
  
  int size() const {
    return data.size();
  }

  const T& operator[](int i) const {
    return data[i];
  }

  T& operator[](int i){
    return data[i];
  }

  auto begin() {return data.begin();}
  auto end() {return data.end();}

  void resize(int n){
    data.resize(n);
  }
  
  auto operator+(const FormalPowerSeries &rhs) const {
    std::vector<T> ret(data);
    ret.resize(rhs.size());
    for(int i = 0; i < (int)rhs.size(); ++i) ret[i] += rhs[i];
    return FormalPowerSeries(ret);
  }

  auto operator-(const FormalPowerSeries &rhs) const {
    std::vector<T> ret(data);
    ret.resize(rhs.size());
    for(int i = 0; i < (int)rhs.size(); ++i) ret[i] -= rhs[i];
    return FormalPowerSeries(ret);
  }

  auto operator*(const FormalPowerSeries &rhs) const {
    auto ret = convolve(data, rhs.data);
    return FormalPowerSeries(ret);
  }

  auto operator*(T b) const {
    std::vector<T> ret(data);
    for(auto &x : ret) x *= b;
    return FormalPowerSeries(ret);
  }

  auto differentiate() const {
    const int n = data.size();
    std::vector<T> ret(n-1);
    for(int i = 0; i < n-1; ++i){
      ret[i] = data[i+1] * (i + 1);
    }
    
    return FormalPowerSeries(ret);
  }

  auto integrate() const {
    const int n = data.size();
    std::vector<T> ret(n+1);
    for(int i = 0; i < n; ++i){
      ret[i+1] = data[i] / (i + 1);
    }

    return FormalPowerSeries(ret);
  }

  auto inv() const {
    assert(data[0] != 0);
    const int n = data.size();
    
    int t = 1;
    std::vector<T> ret = {data[0].inv()};
    ret.reserve(n * 2);
    
    while(t <= n * 2){
      std::vector<T> c(data.begin(), data.begin() + std::min(t, n));
      c = convolve(c, convolve(ret, ret));

      c.resize(t);
      ret.resize(t);

      for(int i = 0; i < t; ++i){
        ret[i] = ret[i] * 2 - c[i];
      }
      
      t <<= 1;
    }
    
    ret.resize(n);

    return FormalPowerSeries(ret);
  }

  auto log() const {
    assert(data[0] == 1);
    const int n = data.size();
    auto ret = (differentiate() * inv()).integrate();
    ret.resize(n);
    return ret;
  }

  auto exp() const {
    const int n = data.size();

    int t = 1;
    FormalPowerSeries b({1});

    while(t <= n * 2){
      t <<= 1;
      auto temp = b.log();
      temp.resize(t);

      for(int i = 0; i < t; ++i) temp[i] = -temp[i];
      temp[0] += 1;
      for(int i = 0; i < std::min(t, n); ++i) temp[i] += data[i];
      
      b = b * temp;
      b.resize(t);
    }
    
    b.resize(n);

    return b;
  }


  auto shift(int64_t k) const {
    const int64_t n = data.size();
    FormalPowerSeries ret(n);

    if(k >= 0){
      for(int64_t i = k; i < n; ++i){
        ret[i] = data[i - k];
      }
    }else{
      for(int64_t i = 0; i < n + k; ++i){
        ret[i] = data[i - k];
      }
    }

    return ret;
  }

  
  auto power(int64_t M) const {
    assert(M >= 0);
    
    const int n = data.size();
    int k = 0;
    for(; k < n; ++k){
      if(data[k] != 0){
        break;
      }
    }

    if(k >= n) return *this;

    T a = data[k];

    FormalPowerSeries ret = *this;
    ret = (ret.shift(-k)) * a.inv();
    ret = (ret.log() * (T)M).exp();
    ret = (ret * a.power(M)).shift(M * k);
    
    return ret;
  }

  std::optional<FormalPowerSeries> sqrt() const {
    const int n = data.size();
    int k = 0;
    for(; k < n; ++k) if(data[k] != 0) break;

    if(k >= n) return *this;
    if(k % 2 != 0) return {};

    int t = 1;
    auto x = get_sqrt(data[k]);

    if(not x) return {};

    const int m = n - k;

    auto it = data.begin() + k;
    FormalPowerSeries ret({*x});

    while(t <= m * 2){
      FormalPowerSeries f(std::vector(it, it + std::min(t, m)));
      ret.resize(t);
      f.resize(t);
      ret = (ret + f * ret.inv()) * T(2).inv();      
      t <<= 1;
    }

    ret.resize(n);
    ret = ret.shift(k / 2);

    return ret;
  }
};


template <typename T>
std::function<std::vector<T>(std::vector<T>, std::vector<T>)> FormalPowerSeries<T>::convolve;

template <typename T>
std::function<std::optional<T>(T)> FormalPowerSeries<T>::get_sqrt;
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
template <typename ITER>
std::string join(ITER first, ITER last, std::string delim = " "){
  std::stringstream s;

  for(auto it = first; it != last; ++it){
    if(it != first) s << delim;
    s << *it;
  }

  return s.str();
}
#line 10 "test/yosupo-judge/partition_function/main.fps.test.cpp"

constexpr int PRIM = 3;
using mint = ModInt<998244353>;
using FPS = FormalPowerSeries<mint>;
using NTT = NumberTheoreticTransform<mint,PRIM,1<<20>;

int main(){
  using namespace std::placeholders;
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto ntt = NTT();
  FPS::convolve = std::bind(&NTT::convolve<mint>, &ntt, _1, _2);

  auto ans = partition_number<FPS>(N);
  std::cout << join(ans.begin(), ans.begin() + (N + 1)) << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

