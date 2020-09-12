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


# :x: test/yosupo-judge/queue_operate_all_composite/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c8d31b5139983c6742fe36acb5e1ac81">test/yosupo-judge/queue_operate_all_composite</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/queue_operate_all_composite/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/queue_operate_all_composite">https://judge.yosupo.jp/problem/queue_operate_all_composite</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/affine.cpp.html">Affine monoid</a>
* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/dual.cpp.html">Dual monoid</a>
* :x: <a href="../../../../library/Mylib/DataStructure/Queue/sliding_window_aggregation.cpp.html">Sliding window aggregation</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"
#include "Mylib/DataStructure/Queue/sliding_window_aggregation.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;
using M = hl::dual_monoid<hl::affine_monoid<mint>>;

int main(){
  int Q; std::cin >> Q;

  hl::sliding_window_aggregation<M> swag;

  for(auto [type] : hl::input_tuples<int>(Q)){
    if(type == 0){
      int a, b; std::cin >> a >> b;
      swag.push({a, b});
    }else if(type == 1){
      swag.pop();
    }else{
      int x; std::cin >> x;
      auto res = swag.fold();
      if(res){
        auto [a, b] = *res;
        std::cout << a * x + b << std::endl;
      }else{
        std::cout << x << std::endl;
      }
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/queue_operate_all_composite/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

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
#line 3 "Mylib/AlgebraicStructure/Monoid/affine.cpp"

/**
 * @title Affine monoid
 * @docs affine.md
 */
namespace haar_lib {
  template <typename T>
  struct affine_monoid {
    using value_type = std::pair<T, T>;
    value_type operator()() const {return std::make_pair(1, 0);}
    value_type operator()(const value_type &a, const value_type &b) const {
      return std::make_pair(a.first * b.first, a.first * b.second + a.second);
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/Monoid/dual.cpp"

/**
 * @title Dual monoid
 * @docs dual.md
 */
namespace haar_lib {
  template <typename Monoid>
  struct dual_monoid {
    using value_type = typename Monoid::value_type;
    const static Monoid M;
    value_type operator()() const {return M();}
    value_type operator()(const value_type &a, const value_type &b) const {return M(b, a);}
  };
}
#line 2 "Mylib/DataStructure/Queue/sliding_window_aggregation.cpp"
#include <vector>
#include <stack>
#include <optional>

/**
 * @title Sliding window aggregation
 * @docs sliding_window_aggregation.md
 */
namespace haar_lib {
  template <typename Semigroup>
  class sliding_window_aggregation {
    using value_type = typename Semigroup::value_type;
    const static Semigroup S;

    std::stack<value_type> front_stack, back_stack;
    std::vector<value_type> front_sum, back_sum;

    std::optional<value_type> f(std::optional<value_type> a, std::optional<value_type> b) const {
      if(a){
        if(b) return {S(*a, *b)};
        else return {*a};
      }else{
        if(b) return {*b};
        else return {};
      }
    }

    std::optional<value_type> g(const std::vector<value_type> &a) const {
      return a.empty() ? std::nullopt : std::optional(a.back());
    }

  public:
    sliding_window_aggregation(){}

    std::optional<value_type> fold() const {
      return f(g(front_sum), g(back_sum));
    }

    void push(const value_type &value){
      back_stack.push(value);
      back_sum.push_back(f(g(back_sum), value).value());
    }

    void pop(){
      if(front_stack.empty()){
        back_sum.clear();

        while(not back_stack.empty()){
          const auto value = back_stack.top(); back_stack.pop();
          front_stack.push(value);
          front_sum.push_back(f(value, g(front_sum)).value());
        }
      }

      front_stack.pop();
      front_sum.pop_back();
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
#line 9 "test/yosupo-judge/queue_operate_all_composite/main.test.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;
using M = hl::dual_monoid<hl::affine_monoid<mint>>;

int main(){
  int Q; std::cin >> Q;

  hl::sliding_window_aggregation<M> swag;

  for(auto [type] : hl::input_tuples<int>(Q)){
    if(type == 0){
      int a, b; std::cin >> a >> b;
      swag.push({a, b});
    }else if(type == 1){
      swag.pop();
    }else{
      int x; std::cin >> x;
      auto res = swag.fold();
      if(res){
        auto [a, b] = *res;
        std::cout << a * x + b << std::endl;
      }else{
        std::cout << x << std::endl;
      }
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
