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


# :x: test/aoj/ALDS1_15_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#dfb9b4b04978b5abf401139b8f15bff5">test/aoj/ALDS1_15_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_15_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling.cpp.html">Interval scheduling problem</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  auto [left, right] = hl::input_tuple_vector<int, int>(n);
  for(auto &x : right) x += 1;

  auto ans = hl::interval_scheduling(left, right);

  std::cout << ans.size() << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_15_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling.cpp"
#include <numeric>
#include <algorithm>
#include <limits>
#include <utility>

/**
 * @title Interval scheduling problem
 * @docs interval_scheduling.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<std::pair<T, T>> interval_scheduling(const std::vector<T> &l, const std::vector<T> &r){
    const int N = l.size();
    std::vector<std::pair<T, T>> ret;
    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j){return r[i] < r[j];});

    auto b = std::numeric_limits<T>::lowest();

    for(int i : ord){
      if(l[i] >= b){
        ret.emplace_back(l[i], r[i]);
        b = r[i];
      }
    }

    return ret;
  }
}
#line 4 "Mylib/IO/input_tuple_vector.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuple_vector.cpp"
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
namespace haar_lib {
  template <typename T, size_t ... I>
  void input_tuple_vector_init(T &val, int N, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)), 0) ...};
  }

  template <typename T, size_t ... I>
  void input_tuple_vector_helper(T &val, int i, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)[i]), 0) ...};
  }

  template <typename ... Args>
  auto input_tuple_vector(int N){
    std::tuple<std::vector<Args> ...> ret;

    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());
    for(int i = 0; i < N; ++i){
      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof ... (Args)>());
    }

    return ret;
  }
}
#line 7 "test/aoj/ALDS1_15_C/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int n; std::cin >> n;

  auto [left, right] = hl::input_tuple_vector<int, int>(n);
  for(auto &x : right) x += 1;

  auto ans = hl::interval_scheduling(left, right);

  std::cout << ans.size() << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

