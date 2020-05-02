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


# :x: test/aoj/DSL_5_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#59b5a0a6c0973fef022e4b1a7cf092fc">test/aoj/DSL_5_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_5_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Algorithm/Imos/imos_1d.cpp.html">一次元Imos法</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"

#include <iostream>
#include <algorithm>
#include "Mylib/Algorithm/Imos/imos_1d.cpp"

int main(){
  int N, T; std::cin >> N >> T;
  Imos1D<int> imos(T+1);

  for(int i = 0; i < N; ++i){
    int l, r; std::cin >> l >> r;
    imos.add(l, r, 1);
  }

  imos.build();

  int ans = 0;

  for(int i = 0; i <= T; ++i){
    ans = std::max(ans, imos[i]);
  }

  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_5_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"

#include <iostream>
#include <algorithm>
#line 2 "Mylib/Algorithm/Imos/imos_1d.cpp"
#include <vector>

/**
 * @title 一次元Imos法
 * @docs imos_1d.md
 */
template <typename T> struct Imos1D{
  std::vector<T> data;
  Imos1D(int n): data(n+1){}

  void add(int a, int b, const T& val){ // [a,b)
    data[a] += 1;
    data[b] -= 1;
  }

  void build(){
    for(int i = 0; i < (int)data.size()-1; ++i){
      data[i+1] += data[i];
    }
  }

  inline const T operator[](size_t i) const {return data[i];}
};
#line 6 "test/aoj/DSL_5_A/main.test.cpp"

int main(){
  int N, T; std::cin >> N >> T;
  Imos1D<int> imos(T+1);

  for(int i = 0; i < N; ++i){
    int l, r; std::cin >> l >> r;
    imos.add(l, r, 1);
  }

  imos.build();

  int ans = 0;

  for(int i = 0; i <= T; ++i){
    ans = std::max(ans, imos[i]);
  }

  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

