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


# :x: test/aoj/ITP2_11_D/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#94d9d16d204cbf810b90bed914562ba2">test/aoj/ITP2_11_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ITP2_11_D/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Bit/enumerate_sets_of_size_k.cpp.html">Enumerate sets of size k</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D"

#include <iostream>
#include <vector>
#include <map>
#include "Mylib/Bit/enumerate_sets_of_size_k.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, k; std::cin >> n >> k;

  std::map<int, std::vector<int>> ans;

  hl::enumerate_sets_of_size_k(
    k, n,
    [&](int d){
      for(int i = 0; i < n; ++i){
        if(d & (1 << i)) ans[d].push_back(i);
      }
      return true;
    }
  );

  for(auto &[m, v] : ans){
    std::cout << m << ":";
    for(auto x : v) std::cout << " " << x;
    std::cout << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ITP2_11_D/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D"

#include <iostream>
#include <vector>
#include <map>
#line 2 "Mylib/Bit/enumerate_sets_of_size_k.cpp"

/**
 * @title Enumerate sets of size k
 * @docs enumerate_sets_of_size_k.md
 */
namespace haar_lib {
  template <typename Func>
  void enumerate_sets_of_size_k(int k, int n, const Func &f){
    int c = (1 << k) - 1;
    while(c < (1 << n)){
      if(not f(c)) break;
      const int x = c & (-c);
      const int y = c + x;
      c = ((c & (~y)) / x >> 1) | y;
    }
  }
}
#line 7 "test/aoj/ITP2_11_D/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, k; std::cin >> n >> k;

  std::map<int, std::vector<int>> ans;

  hl::enumerate_sets_of_size_k(
    k, n,
    [&](int d){
      for(int i = 0; i < n; ++i){
        if(d & (1 << i)) ans[d].push_back(i);
      }
      return true;
    }
  );

  for(auto &[m, v] : ans){
    std::cout << m << ":";
    for(auto x : v) std::cout << " " << x;
    std::cout << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
