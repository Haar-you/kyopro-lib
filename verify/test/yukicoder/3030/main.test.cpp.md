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


# :x: test/yukicoder/3030/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c3762d67768ccc7d2f909f02cd1756df">test/yukicoder/3030</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/3030/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 08:51:20+09:00


* see: <a href="https://yukicoder.me/problems/no/3030">https://yukicoder.me/problems/no/3030</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/Misc/int128.cpp.html">128-bit int</a>
* :question: <a href="../../../../library/Mylib/Number/Prime/miller_rabin.cpp.html">Primality test (Miller-Rabin algorithm)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
#include "Mylib/Number/Prime/miller_rabin.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  MillerRabin is_prime;

  for(auto [x] : input_tuples<int64_t>(N)){
    std::cout << x << " " << is_prime(x) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/3030/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <iostream>
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
#line 3 "Mylib/Number/Prime/miller_rabin.cpp"

/**
 * @title Primality test (Miller-Rabin algorithm)
 * @docs miller_rabin.md
 */
class MillerRabin{
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
      if(x == p-1) return false;
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
    uint64_t d = n-1;
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
#line 6 "test/yukicoder/3030/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  MillerRabin is_prime;

  for(auto [x] : input_tuples<int64_t>(N)){
    std::cout << x << " " << is_prime(x) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

