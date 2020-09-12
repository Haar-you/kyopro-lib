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


# :x: test/yukicoder/1084/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f3418e7f5c6444b91848f405b9401880">test/yukicoder/1084</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/1084/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://yukicoder.me/problems/no/1084">https://yukicoder.me/problems/no/1084</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Algorithm/Imos/linear_imos_1d.cpp.html">1D Imos algorithm (Linear addition)</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1084"

#include <iostream>
#include <vector>
#include <algorithm>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Algorithm/Imos/linear_imos_1d.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;
const int MAX = 1000000000;

int main(){
  int N; std::cin >> N;
  auto A = hl::input_vector<int64_t>(N);

  mint ans = 0;

  if(std::count(A.begin(), A.end(), 0) == 0){
    hl::linear_imos_1d<int64_t> p(N);

    std::vector<int> next(N);
    for(int i = N; --i >= 0;){
      if(A[i] == 1){
        if(i == N - 1) next[i] = N;
        else{
          if(A[i + 1] == 1){
            next[i] = next[i + 1];
          }else{
            next[i] = i + 1;
          }
        }
      }else{
        next[i] = i + 1;
      }
    }

    for(int l = 0; l < N; ++l){
      int64_t prod = 1;

      int r = l;

      for(int i = 0; i < 100; ++i){
        if(r == N or prod * A[r] >= MAX) break;
        prod *= A[r];
        r = next[r];
      }

      p.add(l, r, -1, r);
    }

    p.build();

    ans = 1;
    for(int i = 0; i < N; ++i){
      ans *= mint::power(A[i], p[i]);
    }
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/1084/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1084"

#include <iostream>
#include <vector>
#include <algorithm>
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
#line 3 "Mylib/Algorithm/Imos/linear_imos_1d.cpp"

/**
 * @title 1D Imos algorithm (Linear addition)
 * @docs linear_imos_1d.md
 */
namespace haar_lib {
  template <typename T>
  struct linear_imos_1d {
    using value_type = T;

    std::vector<T> vec_a, vec_a_end, vec_b, vec;
    int n;

    linear_imos_1d(int n):
      vec_a(n + 1), vec_a_end(n + 1), vec_b(n + 1), vec(n + 1), n(n){}

    void add(int s, int t, const T &a, const T &b){ // x ∈ [s, t)にax+bを加算する。
      vec_a[s + 1] += a;
      vec_a[t] -= a;

      vec_a_end[t] -= a * (t - s - 1);

      vec_b[s] += a * s + b;
      vec_b[t] -= a * s + b;
    }

    void build(){
      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];
      for(int i = 0; i <= n; ++i) vec_a[i] += vec_a_end[i];
      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];

      for(int i = 0; i < n; ++i) vec_b[i + 1] += vec_b[i];

      for(int i = 0; i <= n; ++i) vec[i] = vec_a[i] + vec_b[i];
    }

    T operator[](size_t i) const {return vec[i];}
  };
}
#line 9 "test/yukicoder/1084/main.test.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;
const int MAX = 1000000000;

int main(){
  int N; std::cin >> N;
  auto A = hl::input_vector<int64_t>(N);

  mint ans = 0;

  if(std::count(A.begin(), A.end(), 0) == 0){
    hl::linear_imos_1d<int64_t> p(N);

    std::vector<int> next(N);
    for(int i = N; --i >= 0;){
      if(A[i] == 1){
        if(i == N - 1) next[i] = N;
        else{
          if(A[i + 1] == 1){
            next[i] = next[i + 1];
          }else{
            next[i] = i + 1;
          }
        }
      }else{
        next[i] = i + 1;
      }
    }

    for(int l = 0; l < N; ++l){
      int64_t prod = 1;

      int r = l;

      for(int i = 0; i < 100; ++i){
        if(r == N or prod * A[r] >= MAX) break;
        prod *= A[r];
        r = next[r];
      }

      p.add(l, r, -1, r);
    }

    p.build();

    ans = 1;
    for(int i = 0; i < N; ++i){
      ans *= mint::power(A[i], p[i]);
    }
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
