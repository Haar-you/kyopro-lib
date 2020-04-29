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


# :heavy_check_mark: test/yukicoder/660/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a98572782bc888d5914d5fef365c5125">test/yukicoder/660</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/660/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:25:30+09:00


* see: <a href="https://yukicoder.me/problems/no/660">https://yukicoder.me/problems/no/660</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Combinatorics/catalan_number.cpp.html">Catalan数</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Combinatorics/combinatorics.cpp.html">組み合わせ計算用の前計算クラス</a>
* :question: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/660"

#include <iostream>
#include <vector>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/combinatorics.cpp"
#include "Mylib/Combinatorics/catalan_number.cpp"

using mint = ModInt<1000000007>;
using C = Combinatorics<mint>;

int main(){
  C::init(500000);
  
  int N; std::cin >> N;

  std::vector<mint> c(N+1);
  for(int i = 0; i <= N; ++i){
    c[i] = C::catalan_number(i);
  }

  for(int i = 1; i <= N; ++i){
    c[i] += c[i-1];
  }


  mint ans = 0;
  
  for(int k = 0; k <= N / 2; ++k){
    ans += C::C(N+2*k, k);
  }

  for(int k = 0; k < N / 2; ++k){
    ans -= C::C(N+2*k, k) * c[N/2-k-1] * 2;
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/660/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/660"

#include <iostream>
#include <vector>
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title modint
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
  
  inline constexpr auto operator+(const ModInt &a) const {return ModInt(val + a.val);}
  inline constexpr auto operator-(const ModInt &a) const {return ModInt(val - a.val);}
  inline constexpr auto operator*(const ModInt &a) const {return ModInt(val * a.val);}
  inline constexpr auto operator/(const ModInt &a) const {return ModInt(val * a.inv().val);}
  
  inline constexpr auto& operator=(const ModInt &a){val = a.val; return *this;}
  inline constexpr auto& operator+=(const ModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  inline constexpr auto& operator-=(const ModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  inline constexpr auto& operator*=(const ModInt &a){(val *= a.val) %= M; return *this;}
  inline constexpr auto& operator/=(const ModInt &a){(val *= a.inv().val) %= M; return *this;}
 
  inline constexpr bool operator==(const ModInt &a) const {return val == a.val;}
  inline constexpr bool operator!=(const ModInt &a) const {return val != a.val;}
 
  inline constexpr auto& operator++(){*this += 1; return *this;}
  inline constexpr auto& operator--(){*this -= 1; return *this;}
 
  inline constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
  inline constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}
 
  inline constexpr static ModInt power(int64_t n, int64_t p){
    if(p < 0) return power(n, -p).inv();
    
    int64_t ret = 1, e = n % M;
    for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
    return ret;
  }
 
  inline constexpr static ModInt inv(int64_t a){
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
 
  inline constexpr static auto frac(int64_t a, int64_t b){return ModInt(a) / ModInt(b);}
  
  inline constexpr auto power(int64_t p) const {return power(val, p);}
  inline constexpr auto inv() const {return inv(val);}
 
  friend inline constexpr auto operator-(const ModInt &a){return ModInt(-a.val);}
 
  friend inline constexpr auto operator+(int64_t a, const ModInt &b){return ModInt(a) + b;}
  friend inline constexpr auto operator-(int64_t a, const ModInt &b){return ModInt(a) - b;}
  friend inline constexpr auto operator*(int64_t a, const ModInt &b){return ModInt(a) * b;}
  friend inline constexpr auto operator/(int64_t a, const ModInt &b){return ModInt(a) / b;}
 
  friend std::istream& operator>>(std::istream &s, ModInt<M> &a){s >> a.val; return s;}
  friend std::ostream& operator<<(std::ostream &s, const ModInt<M> &a){s << a.val; return s;}

  template <int N>
  inline static auto div(){
    static auto value = inv(N);
    return value;
  }

  explicit operator int32_t() const noexcept {return val;}
  explicit operator int64_t() const noexcept {return val;}
};
#line 3 "Mylib/Combinatorics/combinatorics.cpp"
#include <cassert>

/**
 * @title 組み合わせ計算用の前計算クラス
 * @docs combinatorics.md
 * @attention 使用前にinit関数を呼び出す
 */
template <typename T> class Combinatorics{
public:
  static std::vector<T> facto;
  static std::vector<T> ifacto;

  static void init(int N){
    facto.assign(N+1, 1);
    ifacto.assign(N+1, 1);
    
    for(int i = 1; i <= N; ++i){
      facto[i] = facto[i-1] * i;
    }
    
    ifacto[N] = facto[N].inv();

    for(int i = N-1; i >= 0; --i){
      ifacto[i] = ifacto[i+1] * (i+1);
    }
  }
  
  static T f(int64_t i){
    assert(i < facto.size());
    return facto[i];
  }
  
  static T finv(int64_t i){
    assert(i < ifacto.size());
    return ifacto[i];
  }

  static T P(int64_t n, int64_t k);
  static T C(int64_t n, int64_t k);
  static T H(int64_t n, int64_t k);
  static T stirling_number(int64_t n, int64_t k);
  static T bell_number(int64_t n, int64_t k);
  static std::vector<T> bernoulli_number(int64_t n);
  static T catalan_number(int64_t n);
};

template <typename T> std::vector<T> Combinatorics<T>::facto = std::vector<T>();
template <typename T> std::vector<T> Combinatorics<T>::ifacto = std::vector<T>();

template <typename T> T Combinatorics<T>::P(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return f(n) * finv(n-k);
}

template <typename T> T Combinatorics<T>::C(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return P(n,k) * finv(k);
}

template <typename T> T Combinatorics<T>::H(int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  return C(n+k-1, k);
}
#line 3 "Mylib/Combinatorics/catalan_number.cpp"

/**
 * @title Catalan数
 * @docs catalan_number.md
 */
template <typename T> T Combinatorics<T>::catalan_number(int64_t n){
  return C(2*n,n) - C(2*n,n-1);
}
#line 8 "test/yukicoder/660/main.test.cpp"

using mint = ModInt<1000000007>;
using C = Combinatorics<mint>;

int main(){
  C::init(500000);
  
  int N; std::cin >> N;

  std::vector<mint> c(N+1);
  for(int i = 0; i <= N; ++i){
    c[i] = C::catalan_number(i);
  }

  for(int i = 1; i <= N; ++i){
    c[i] += c[i-1];
  }


  mint ans = 0;
  
  for(int k = 0; k <= N / 2; ++k){
    ans += C::C(N+2*k, k);
  }

  for(int k = 0; k < N / 2; ++k){
    ans -= C::C(N+2*k, k) * c[N/2-k-1] * 2;
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

