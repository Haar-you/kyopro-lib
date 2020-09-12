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


# :x: test/yosupo-judge/cartesian_tree/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#31920c7695bb8892c8a9f6ce31237986">test/yosupo-judge/cartesian_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/cartesian_tree/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="https://judge.yosupo.jp/problem/cartesian_tree">https://judge.yosupo.jp/problem/cartesian_tree</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DataStructure/CartesianTree/cartesian_tree.cpp.html">Cartesian tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include <iostream>
#include <tuple>
#include <functional>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/DataStructure/CartesianTree/cartesian_tree.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;
  auto a = hl::input_vector<int>(N);

  auto ans = std::get<1>(hl::cartesian_tree(a, std::less<>()));

  for(int i = 0; i < N; ++i){
    std::cout << ans[i].value_or(i) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/cartesian_tree/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include <iostream>
#include <tuple>
#include <functional>
#line 3 "Mylib/IO/input_vector.cpp"
#include <vector>

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
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
namespace haar_lib {
  template <typename Iter>
  std::string join(Iter first, Iter last, std::string delim = " "){
    std::stringstream s;

    for(auto it = first; it != last; ++it){
      if(it != first) s << delim;
      s << *it;
    }

    return s.str();
  }
}
#line 4 "Mylib/DataStructure/CartesianTree/cartesian_tree.cpp"
#include <optional>

/**
 * @title Cartesian tree
 * @docs cartesian_tree.md
 */
namespace haar_lib {
  template <typename T, typename Compare>
  auto cartesian_tree(const std::vector<T> &a, Compare compare){
    const int n = a.size();
    std::vector<std::optional<int>> p(n), l(n), r(n);
    int root = 0;

    for(int i = 0; i < n; ++i){
      if(i == 0){
        continue;
      }

      int j = i - 1;

      while(1){
        if(compare(a[i], a[j])){
          if(not p[j]){
            p[j] = i;
            l[i] = j;
            root = i;
            break;
          }

          j = *p[j];
          continue;
        }

        auto t = r[j];
        r[j] = i;
        p[i] = j;

        l[i] = t;
        if(t) p[*t] = i;

        break;
      }
    }

    return std::make_tuple(root, p, l, r);
  }
}
#line 9 "test/yosupo-judge/cartesian_tree/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;
  auto a = hl::input_vector<int>(N);

  auto ans = std::get<1>(hl::cartesian_tree(a, std::less<>()));

  for(int i = 0; i < N; ++i){
    std::cout << ans[i].value_or(i) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

