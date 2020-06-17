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


# :x: test/yosupo-judge/tetration_mod/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#8d2eb885a99697d1d568e2fa6fb51db3">test/yosupo-judge/tetration_mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/tetration_mod/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-16 23:16:56+09:00


* see: <a href="https://judge.yosupo.jp/problem/tetration_mod">https://judge.yosupo.jp/problem/tetration_mod</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/Number/euler_phi_function.cpp.html">Euler's totient function</a>
* :x: <a href="../../../../library/Mylib/Number/tetration.cpp.html">Tetration</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include <iostream>

#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Number/tetration.cpp"

int main(){
  int T; std::cin >> T;

  for(auto [A, B, M] : input_tuples<int, int, int>(T)){
    auto ans = tetration(A, B, M);
    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/tetration_mod/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include <iostream>

#line 3 "Mylib/IO/input_tuples.cpp"
#include <vector>
#include <tuple>
#include <utility>
#include <initializer_list>
#line 5 "Mylib/IO/input_tuple.cpp"
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
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
#line 2 "Mylib/Number/tetration.cpp"

#line 2 "Mylib/Number/euler_phi_function.cpp"

/**
 * @title Euler's totient function
 * @docs euler_phi_function.md
 */
int64_t totient(int64_t n){
  int64_t ret = n;

  for(int64_t i = 2; i * i <= n; ++i){
    if(n % i == 0){
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }

  if(n != 1) ret -= ret / n;

  return ret;
}
#line 4 "Mylib/Number/tetration.cpp"

/**
 * @title Tetration
 * @docs tetration.md
 */
int tetration(int64_t a, int64_t b, int64_t m){
  auto rec =
    [](auto &rec, int64_t a, int64_t b, int64_t m) -> int {
      if(b == 1) return a % m;
      if(b == 0) return 1 % m;
      if(b == 2){
        bool c = a >= m;
        int64_t ret = 1;
        int64_t p = a;
        a %= m;

        while(p > 0){
          if(p & 1) if((ret *= a) >= m) ret %= m, c = true;
          if((a *= a) >= m) a %= m, c = true;
          p >>= 1;
        }

        if(c) ret += m;
        return ret;
      }
      if(a == 0) return b % 2 == 1 ? 0 : 1;
      if(m == 1) return 1;
      
      int phi = totient(m);
      int p = rec(rec, a, b-1, phi);

      bool c = p >= phi;
      int64_t ret = 1;

      while(p > 0){
        if(p & 1) if((ret *= a) >= m) ret %= m, c = true;
        if((a *= a) >= m) a %= m, c = true;
        p >>= 1;
      }

      if(c) ret += m;
      return ret;
    };

  return rec(rec, a, b, m) % m;
}
#line 7 "test/yosupo-judge/tetration_mod/main.test.cpp"

int main(){
  int T; std::cin >> T;

  for(auto [A, B, M] : input_tuples<int, int, int>(T)){
    auto ans = tetration(A, B, M);
    std::cout << ans << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

