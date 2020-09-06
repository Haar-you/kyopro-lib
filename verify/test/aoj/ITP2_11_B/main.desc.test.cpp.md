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


# :x: test/aoj/ITP2_11_B/main.desc.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ee41bb6b1ee97f3a5e094f7dfeadd68">test/aoj/ITP2_11_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ITP2_11_B/main.desc.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 04:37:36+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Bit/enumerate_supersets_desc.cpp.html">Enumerate supersets (Descending order)</a>
* :x: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B"

#include <iostream>
#include <vector>
#include <map>
#include "Mylib/Bit/enumerate_supersets_desc.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, k; std::cin >> n >> k;

  int t = 0;
  for(auto b : input_vector<int>(k)){
    t |= 1 << b;
  }

  std::map<int, std::vector<int>> ans;
  enumerate_supersets_desc(
    t, n,
    [&](int d){
      ans[d];
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
#line 1 "test/aoj/ITP2_11_B/main.desc.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B"

#include <iostream>
#include <vector>
#include <map>
#line 2 "Mylib/Bit/enumerate_supersets_desc.cpp"

/**
 * @title Enumerate supersets (Descending order)
 * @docs enumerate_supersets_desc.md
 */
template <typename Func>
void enumerate_supersets_desc(int a, int n, const Func &f){
  const int x = (1 << n) - 1, y = x ^ (a & x);
  for(int t = y; ; t = (t - 1) & y){
    if(not f(t | a)) break;
    if(t == 0) break;
  }
}
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
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
#line 8 "test/aoj/ITP2_11_B/main.desc.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, k; std::cin >> n >> k;

  int t = 0;
  for(auto b : input_vector<int>(k)){
    t |= 1 << b;
  }

  std::map<int, std::vector<int>> ans;
  enumerate_supersets_desc(
    t, n,
    [&](int d){
      ans[d];
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

