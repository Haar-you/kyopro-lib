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


# :x: test/aoj/DPL_3_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#77278594f11f13b0335038a90fe07d8b">test/aoj/DPL_3_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_3_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp.html">Largest rectangle</a>
* :x: <a href="../../../../library/Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp.html">Largest rectangle in histogram</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main(){
  int H, W; std::cin >> H >> W;

  auto c = hl::input_vector<int>(H, W);

  auto ans = hl::max_rectangle(c, 0);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_3_B/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp"
#include <algorithm>
#line 3 "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"
#include <stack>
#include <utility>

/**
 * @title Largest rectangle in histogram
 * @docs max_rectangle_in_histogram.md
 */
namespace haar_lib {
  template <typename T>
  T max_rectangle_in_histogram(const std::vector<T> &h){
    std::stack<std::pair<T, int>> st;
    T ret = 0;

    for(size_t i = 0; i < h.size(); ++i){
      if(st.empty()){
        st.emplace(h[i], i);
      }else if(st.top().first < h[i]){
        st.emplace(h[i], i);
      }else if(st.top().first > h[i]){
        int j = i;
        while(not st.empty() and st.top().first > h[i]){
          ret = std::max(ret, st.top().first * ((T)i - st.top().second));
          j = st.top().second;
          st.pop();
        }
        st.emplace(h[i], j);
      }
    }

    while(not st.empty()){
      ret = std::max(ret, st.top().first * ((T)h.size() - st.top().second));
      st.pop();
    }

    return ret;
  }
}
#line 5 "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle.cpp"

/**
 * @title Largest rectangle
 * @docs max_rectangle.md
 */
namespace haar_lib {
  template <typename T>
  int max_rectangle(const std::vector<std::vector<T>> &d, T value){
    const int H = d.size();
    const int W = d[0].size();

    std::vector<std::vector<int>> c(H, std::vector<int>(W));
    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(d[i][j] == value) c[i][j] = 1;
      }
    }

    for(int i = 1; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(c[i][j]){
          c[i][j] += c[i - 1][j];
        }
      }
    }

    int ret = 0;
    for(int i = 0; i < H; ++i){
      int t = max_rectangle_in_histogram<int>(c[i]);
      ret = std::max(ret, t);
    }

    return ret;
  }
}
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
#line 7 "test/aoj/DPL_3_B/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int H, W; std::cin >> H >> W;

  auto c = hl::input_vector<int>(H, W);

  auto ans = hl::max_rectangle(c, 0);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

