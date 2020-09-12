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


# :x: test/yukicoder/658/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a391646de6180927bf7c3f0bfac7f3df">test/yukicoder/658</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/658/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://yukicoder.me/problems/no/658">https://yukicoder.me/problems/no/658</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp.html">Kitamasa algorithm</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/658"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using mint = hl::modint<17>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int Q; std::cin >> Q;

  for(auto [N] : hl::input_tuples<int64_t>(Q)){
    hl::kitamasa_algorithm<mint> ka(4, {0, 0, 0, 1}, {1, 1, 1, 1});
    std::cout << ka[N - 1] << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/658/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/658"

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
#line 2 "Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp"
#include <vector>
#include <cstdint>

/**
 * @title Kitamasa algorithm
 * @docs kitamasa_algorithm.md
 */
namespace haar_lib {
  template <typename T>
  struct kitamasa_algorithm {
    int size;
    std::vector<T> initial_values, coeff;

    kitamasa_algorithm(int size, const std::vector<T> &initial_values, const std::vector<T> &coeff):
      size(size), initial_values(initial_values), coeff(coeff){}

    std::vector<T> inc(const std::vector<T> &a) const {
      std::vector<T> ret(size);

      for(int i = 0; i < size; ++i) ret[i] += a[size - 1] * coeff[i];
      for(int i = 1; i < size; ++i) ret[i] += a[i - 1];

      return ret;
    }

    std::vector<T> dbl(const std::vector<T> &a) const {
      std::vector<T> ret(size), b(a);

      for(int j = 0; j < size; ++j){
        for(int i = 0; i < size; ++i){
          ret[i] += a[j] * b[i];
        }

        b = inc(b);
      }

      return ret;
    }

    T calc(const std::vector<T> &v) const {
      T ret = 0;
      for(int i = 0; i < size; ++i) ret += v[i] * initial_values[i];
      return ret;
    }

    std::vector<T> get(int64_t index) const {
      std::vector<T> ret(size);
      ret[0] = 1;

      bool check = false;
      for(int i = 63; i >= 0; --i){
        if(check) ret = dbl(ret);

        if(index & (1LL << i)){
          ret = inc(ret);
          check = true;
        }
      }

      return ret;
    }

    T operator[](int64_t index) const {
      if(index < size) return initial_values[index];
      return calc(get(index));
    }
  };
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
namespace haar_lib {
  template <typename T, size_t ... I>
  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
  }

  template <typename T, typename U>
  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
    s >> value.first >> value.second;
    return s;
  }

  template <typename ... Args>
  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
    return s;
  }
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
namespace haar_lib {
  template <typename ... Args>
  class InputTuples {
    struct iter {
      using value_type = std::tuple<Args ...>;
      value_type value;
      bool fetched = false;
      int N, c = 0;

      value_type operator*(){
        if(not fetched){
          std::cin >> value;
        }
        return value;
      }

      void operator++(){
        ++c;
        fetched = false;
      }

      bool operator!=(iter &) const {
        return c < N;
      }

      iter(int N): N(N){}
    };

    int N;

  public:
    InputTuples(int N): N(N){}

    iter begin() const {return iter(N);}
    iter end() const {return iter(N);}
  };

  template <typename ... Args>
  auto input_tuples(int N){
    return InputTuples<Args ...>(N);
  }
}
#line 7 "test/yukicoder/658/main.test.cpp"

namespace hl = haar_lib;

using mint = hl::modint<17>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int Q; std::cin >> Q;

  for(auto [N] : hl::input_tuples<int64_t>(Q)){
    hl::kitamasa_algorithm<mint> ka(4, {0, 0, 0, 1}, {1, 1, 1, 1});
    std::cout << ka[N - 1] << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

