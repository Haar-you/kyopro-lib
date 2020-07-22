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


# :heavy_check_mark: test/aoj/3119/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#59b3322e8805b9ff175a68f1a5d31d67">test/aoj/3119</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/3119/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-08 12:08:32+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3119">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3119</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Convolution/fast_mobius_transform_superset.cpp.html">Fast Möbius transform (Supersets)</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Convolution/fast_zeta_transform_superset.cpp.html">Fast Zeta transform (Supersets)</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3119"

#include <iostream>
#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Convolution/fast_zeta_transform_superset.cpp"
#include "Mylib/Convolution/fast_mobius_transform_superset.cpp"
#include "Mylib/IO/input_vector.cpp"

using mint = ModInt<1000000007>;

int main(){
  int n; std::cin >> n;

  auto a = input_vector<int>(n);

  std::vector<int> dp(1<<20);
  for(auto x : a) dp[x] += 1;

  dp = fast_zeta_transform_superset(dp);

  std::vector<mint> f(1<<20);
  for(int i = 0; i < 1<<20; ++i) f[i] = mint::power(2, dp[i]) - 1;

  auto ans = fast_mobius_transform_superset(f);

  std::cout << ans[0] << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/3119/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3119"

#include <iostream>
#include <vector>
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title Modint
 * @docs mint.md
 */
template <uint32_t M> class ModInt{
public:
  constexpr static uint32_t MOD = M;
  uint64_t val;
  
  constexpr ModInt(): val(0){}
  constexpr ModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  constexpr auto operator+(const ModInt &a) const {return ModInt(val + a.val);}
  constexpr auto operator-(const ModInt &a) const {return ModInt(val - a.val);}
  constexpr auto operator*(const ModInt &a) const {return ModInt(val * a.val);}
  constexpr auto operator/(const ModInt &a) const {return ModInt(val * a.inv().val);}
  
  constexpr auto& operator=(const ModInt &a){val = a.val; return *this;}
  constexpr auto& operator+=(const ModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  constexpr auto& operator-=(const ModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  constexpr auto& operator*=(const ModInt &a){(val *= a.val) %= M; return *this;}
  constexpr auto& operator/=(const ModInt &a){(val *= a.inv().val) %= M; return *this;}
 
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
 
  friend constexpr auto operator-(const ModInt &a){return ModInt(-a.val);}
 
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
#line 3 "Mylib/Convolution/fast_zeta_transform_superset.cpp"
#include <functional>

/**
 * @title Fast Zeta transform (Supersets)
 * @docs fast_zeta_transform_superset.md
 */
template <typename T, typename Func = std::plus<T>>
std::vector<T> fast_zeta_transform_superset(std::vector<T> f, const Func &op = std::plus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(!(j & (1<<i))) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}
#line 4 "Mylib/Convolution/fast_mobius_transform_superset.cpp"

/**
 * @title Fast Möbius transform (Supersets)
 * @docs fast_mobius_transform_superset.md
 */
template <typename T, typename Func = std::minus<T>>
std::vector<T> fast_mobius_transform_superset(std::vector<T> f, const Func &op = std::minus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(!(j & (1<<i))) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
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
#line 9 "test/aoj/3119/main.test.cpp"

using mint = ModInt<1000000007>;

int main(){
  int n; std::cin >> n;

  auto a = input_vector<int>(n);

  std::vector<int> dp(1<<20);
  for(auto x : a) dp[x] += 1;

  dp = fast_zeta_transform_superset(dp);

  std::vector<mint> f(1<<20);
  for(int i = 0; i < 1<<20; ++i) f[i] = mint::power(2, dp[i]) - 1;

  auto ans = fast_mobius_transform_superset(f);

  std::cout << ans[0] << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

