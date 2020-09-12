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


# :x: test/aoj/DPL_5_I/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b72df8ce0758bb7606e41650e28ebb6a">test/aoj/DPL_5_I</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_5_I/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Combinatorics/factorial_table.cpp.html">Factorial table</a>
* :x: <a href="../../../../library/Mylib/Combinatorics/stirling_number_second.cpp.html">Stirling numbers of the second kind</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Combinatorics/stirling_number_second.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;

int main(){
  auto ft = hl::factorial_table<mint>(3000);

  int N, K; std::cin >> N >> K;

  std::cout << hl::stirling_number_of_second_kind(N, K, ft) << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_5_I/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include <iostream>
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

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
#line 2 "Mylib/Combinatorics/factorial_table.cpp"
#include <vector>
#include <cassert>
#include <cstdint>

/**
 * @title Factorial table
 * @docs factorial_table.md
 */
namespace haar_lib {
  template <typename T>
  class factorial_table {
  public:
    using value_type = T;

  private:
    std::vector<T> f_table;
    std::vector<T> if_table;

  public:
    factorial_table(int N){
      f_table.assign(N + 1, 1);
      if_table.assign(N + 1, 1);

      for(int i = 1; i <= N; ++i){
        f_table[i] = f_table[i - 1] * i;
      }

      if_table[N] = f_table[N].inv();

      for(int i = N; --i >= 0;){
        if_table[i] = if_table[i + 1] * (i + 1);
      }
    }

    T factorial(int64_t i) const {
      assert(i < (int)f_table.size());
      return f_table[i];
    }

    T inv_factorial(int64_t i) const {
      assert(i < (int)if_table.size());
      return if_table[i];
    }

    T P(int64_t n, int64_t k) const {
      if(n < k or n < 0 or k < 0) return 0;
      return factorial(n) * inv_factorial(n - k);
    }

    T C(int64_t n, int64_t k) const {
      if(n < k or n < 0 or k < 0) return 0;
      return P(n, k) * inv_factorial(k);
    }

    T H(int64_t n, int64_t k) const {
      if(n == 0 and k == 0) return 1;
      return C(n + k - 1, k);
    }
  };
}
#line 4 "Mylib/Combinatorics/stirling_number_second.cpp"

/**
 * @title Stirling numbers of the second kind
 * @docs stirling_number_second.md
 */
namespace haar_lib {
  template <typename Ft, typename T = typename Ft::value_type>
  T stirling_number_of_second_kind(int64_t n, int64_t k, const Ft &ft){
    if(n == 0 and k == 0) return 1;

    T ret = 0;
    for(int i = 1; i <= k; ++i){
      if((k - i) % 2 == 0) ret += ft.C(k, i) * T::power(i, n);
      else ret -= ft.C(k, i) * T::power(i, n);
    }
    ret *= ft.inv_factorial(k);
    return ret;
  }
}
#line 7 "test/aoj/DPL_5_I/main.test.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;

int main(){
  auto ft = hl::factorial_table<mint>(3000);

  int N, K; std::cin >> N >> K;

  std::cout << hl::stirling_number_of_second_kind(N, K, ft) << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

