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


# :x: test/aoj/DSL_5_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#09186009013fcd05167f7dbee66a64e6">test/aoj/DSL_5_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_5_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Algorithm/Imos/imos_2d.cpp.html">二次元Imos法</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <iostream>
#include <algorithm>
#include "Mylib/Algorithm/Imos/imos_2d.cpp"

int main(){
  int N; std::cin >> N;
  Imos2D<int> imos(1000, 1000);

  for(int i = 0; i < N; ++i){
    int x1,y1,x2,y2; std::cin >> x1 >> y1 >> x2 >> y2;
    imos.add(x1,y1,x2,y2);
  }

  imos.build();

  int ans = 0;
  for(int i = 0; i < 1000; ++i){
    for(int j = 0; j < 1000; ++j){
      ans = std::max(ans, imos[i][j]);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_5_B/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <iostream>
#include <algorithm>
#line 2 "Mylib/Algorithm/Imos/imos_2d.cpp"
#include <vector>

/**
 * @title 二次元Imos法
 * @docs imos_2d.md
 */
template <typename T> struct Imos2D{
  std::vector<std::vector<T>> vec;
  int n, m;
  Imos2D(int n, int m): vec(n+1, std::vector<T>(m+1)), n(n), m(m){}

  void add(int a1, int b1, int a2, int b2){ // [a1,a2) [b1,b2)
    vec[a1][b1] += 1;
    vec[a2][b2] += 1;
    vec[a1][b2] -= 1;
    vec[a2][b1] -= 1;
  }

  void build(){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m+1; ++j){
        vec[i+1][j] += vec[i][j];
      }
    }

    for(int i = 0; i < n+1; ++i){
      for(int j = 0; j < m; ++j){
        vec[i][j+1] += vec[i][j];
      }
    }
  }

  inline const std::vector<T>& operator[](size_t i) const {return vec[i];}
};
#line 6 "test/aoj/DSL_5_B/main.test.cpp"

int main(){
  int N; std::cin >> N;
  Imos2D<int> imos(1000, 1000);

  for(int i = 0; i < N; ++i){
    int x1,y1,x2,y2; std::cin >> x1 >> y1 >> x2 >> y2;
    imos.add(x1,y1,x2,y2);
  }

  imos.build();

  int ans = 0;
  for(int i = 0; i < 1000; ++i){
    for(int j = 0; j < 1000; ++j){
      ans = std::max(ans, imos[i][j]);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

