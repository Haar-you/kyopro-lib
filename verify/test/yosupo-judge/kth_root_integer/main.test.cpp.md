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


# :heavy_check_mark: test/yosupo-judge/kth_root_integer/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#1cb80c56a7c118816814801df618d931">test/yosupo-judge/kth_root_integer</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/kth_root_integer/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-04 05:12:56+09:00


* see: <a href="https://judge.yosupo.jp/problem/kth_root_integer">https://judge.yosupo.jp/problem/kth_root_integer</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/kth_root_integer.cpp.html">Kth root integer</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Number/kth_root_integer.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int T; std::cin >> T;

  for(auto [A, K] : input_tuples<uint64_t, uint64_t>(T)){
    std::cout << kth_root(A, K) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/kth_root_integer/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

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
#line 2 "Mylib/Number/kth_root_integer.cpp"
#include <cassert>

/**
 * @title Kth root integer
 * @docs kth_root_integer.md
 */
uint64_t kth_root(uint64_t a, int k){
  assert(k >= 1);
  if(k == 1) return a;
  if(a == 1) return 1;
  
  uint64_t lb = 0, ub = a;

  auto check =
    [](uint64_t a, int k, uint64_t n){
      uint64_t r = 1;
  
      while(k > 0){
        if(k & 1){
          if(__builtin_umulll_overflow(r, a, (unsigned long long int*)&r)) return false;
        }
        if(__builtin_umulll_overflow(a, a, (unsigned long long int*)&a) and k > 1) return false;
        k >>= 1;
      }

      return r <= n;
    };

  while(ub - lb > 1){
    uint64_t mid = lb + (ub - lb) / 2;
    
    if(check(mid, k, a)){
      lb = mid;
    }else{
      ub = mid;
    }
  }
  
  return lb;  
}
#line 6 "test/yosupo-judge/kth_root_integer/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int T; std::cin >> T;

  for(auto [A, K] : input_tuples<uint64_t, uint64_t>(T)){
    std::cout << kth_root(A, K) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

