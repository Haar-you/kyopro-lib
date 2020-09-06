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


# :x: test/yosupo-judge/factorize/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#503c2e18c5ca98964c4b89d4addd4577">test/yosupo-judge/factorize</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/factorize/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="https://judge.yosupo.jp/problem/factorize">https://judge.yosupo.jp/problem/factorize</a>


## Depends on

* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>
* :x: <a href="../../../../library/Mylib/Misc/int128.cpp.html">128-bit int</a>
* :x: <a href="../../../../library/Mylib/Number/Prime/miller_rabin.cpp.html">Primality test (Miller-Rabin algorithm)</a>
* :x: <a href="../../../../library/Mylib/Number/Prime/pollard_rho.cpp.html">Prime factorization (Pollard's rho algorithm)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Number/Prime/pollard_rho.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int Q; std::cin >> Q;

  for(auto [a] : input_tuples<int64_t>(Q)){
    auto res = pollard_rho(a);

    std::vector<int64_t> ans;
    for(auto [x, k] : res){
      while(k--) ans.push_back(x);
    }

    std::cout << ans.size() << " " << join(ans.begin(), ans.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/factorize/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>
#line 3 "Mylib/IO/input_tuples.cpp"
#include <vector>
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
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
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
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
#line 2 "Mylib/Number/Prime/pollard_rho.cpp"
#include <optional>
#line 5 "Mylib/Number/Prime/pollard_rho.cpp"
#include <numeric>
#include <algorithm>
#include <cassert>
#line 2 "Mylib/Misc/int128.cpp"

/**
 * @title 128-bit int
 * @docs int128.md
 */
#ifdef __SIZEOF_INT128__
using uint128_t = __uint128_t;
using int128_t = __int128_t;
#else
#include <boost/multiprecision/cpp_int.hpp>
using uint128_t = boost::multiprecision::uint128_t;
using int128_t = boost::multiprecision::int128_t;
#endif
#line 2 "Mylib/Number/Prime/miller_rabin.cpp"
#include <cstdint>
#line 5 "Mylib/Number/Prime/miller_rabin.cpp"

/**
 * @title Primality test (Miller-Rabin algorithm)
 * @docs miller_rabin.md
 */
class MillerRabin {
  uint128_t power(uint128_t a, uint128_t b, uint128_t p) const {
    uint128_t ret = 1;

    while(b > 0){
      if(b & 1) ret = ret * a % p;
      a = a * a % p;
      b >>= 1;
    }

    return ret;
  }

  bool is_composite(uint64_t a, uint64_t p, int s, uint64_t d) const {
    uint128_t x = power(a, d, p);

    if(x == 1) return false;

    for(int i = 0; i < s; ++i){
      if(x == p - 1) return false;
      x = x * x % p;
    }

    return true;
  }

public:
  bool operator()(uint64_t n) const {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    int s = 0;
    uint64_t d = n - 1;
    while((d & 1) == 0){
      s += 1;
      d >>= 1;
    }

    if(n < 4759123141){
      for(uint64_t x : {2, 7, 61}){
        if(x < n and is_composite(x, n, s, d)) return false;
      }

      return true;
    }

    for(uint64_t x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
      if(x < n and is_composite(x, n, s, d)) return false;
    }

    return true;
  }
};
#line 10 "Mylib/Number/Prime/pollard_rho.cpp"

/**
 * @title Prime factorization (Pollard's rho algorithm)
 * @docs pollard_rho.md
 */
namespace pollard_rho_impl {
  int128_t f(int128_t x){
    return x * x + 1;
  }

  std::optional<int64_t> rho(int64_t n){
    int64_t x = 2, y = 2, d = 1;

    while(d == 1){
      x = f(x) % n;
      y = f(f(y) % n) % n;
      d = std::gcd(std::abs(x - y), n);
      if(d == n) return {};
    }

    return {d};
  }
}

auto pollard_rho(int64_t n){
  std::vector<std::pair<int64_t, int64_t>> ret;

  for(int i = 2; i <= 1000000; ++i){
    if(n % i == 0){
      int c = 0;
      while(n % i == 0){
        n /= i;
        ++c;
      }
      ret.emplace_back(i, c);
    }
    if(i > n) break;
  }

  MillerRabin is_prime;

  while(n > 1){
    if(is_prime(n)){
      ret.emplace_back(n, 1);
      break;
    }

    auto res = pollard_rho_impl::rho(n);
    if(not res){
      assert(false);
    }

    auto r = *res;
    if(r == 1) break;

    int c = 0;
    while(n % r == 0){
      n /= r;
      ++c;
    }

    ret.emplace_back(r, c);
  }

  std::sort(ret.begin(), ret.end());

  return ret;
}
#line 7 "test/yosupo-judge/factorize/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int Q; std::cin >> Q;

  for(auto [a] : input_tuples<int64_t>(Q)){
    auto res = pollard_rho(a);

    std::vector<int64_t> ans;
    for(auto [x, k] : res){
      while(k--) ans.push_back(x);
    }

    std::cout << ans.size() << " " << join(ans.begin(), ans.end()) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

