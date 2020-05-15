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


# :heavy_check_mark: 二次元累積和

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#606b6851a96c8708fa4cdcf98aebb7c1">Mylib/Algorithm/CumulativeSum</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-12 04:30:23+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yukicoder/755/main.test.cpp.html">test/yukicoder/755/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <functional>
#include <cassert>

/**
 * @title 二次元累積和
 * @docs cumulative_sum_2d.md
 */
template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
class CumulativeSum2D{
  std::vector<std::vector<T>> data;
  const int N, M;
  const Add add;
  const Minus minus;
  bool is_built = false;

public:
  CumulativeSum2D(const std::vector<std::vector<T>> &a, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(a.size()), M(a[0].size()), add(add), minus(minus)
  {
    data.assign(N+1, std::vector<T>(M+1, e));
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < M; ++j){
        data[i+1][j+1] = a[i][j];
      }
    }
  }

  CumulativeSum2D(int N, int M, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(N), M(M), add(add), minus(minus)
  {
    data.assign(N+1, std::vector<T>(M+1, e));
  }

  auto& update(int i, int j, const T &val){
    assert(not is_built);
    data[i+1][j+1] = add(data[i+1][j+1], val);
    return *this;
  }

  auto& build(){
    assert(not is_built);
    for(int i = 1; i <= N; ++i) for(int j = 0; j <= M; ++j) data[i][j] = add(data[i][j], data[i-1][j]);
    for(int i = 0; i <= N; ++i) for(int j = 1; j <= M; ++j) data[i][j] = add(data[i][j], data[i][j-1]);
    is_built = true;
    return *this;
  }

  T get(int x1, int y1, int x2, int y2) const { // [x1,x2), [y1,y2)
    assert(is_built);
    return add(minus(data[x2][y2], add(data[x1][y2], data[x2][y1])), data[x1][y1]);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp"
#include <vector>
#include <functional>
#include <cassert>

/**
 * @title 二次元累積和
 * @docs cumulative_sum_2d.md
 */
template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
class CumulativeSum2D{
  std::vector<std::vector<T>> data;
  const int N, M;
  const Add add;
  const Minus minus;
  bool is_built = false;

public:
  CumulativeSum2D(const std::vector<std::vector<T>> &a, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(a.size()), M(a[0].size()), add(add), minus(minus)
  {
    data.assign(N+1, std::vector<T>(M+1, e));
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < M; ++j){
        data[i+1][j+1] = a[i][j];
      }
    }
  }

  CumulativeSum2D(int N, int M, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(N), M(M), add(add), minus(minus)
  {
    data.assign(N+1, std::vector<T>(M+1, e));
  }

  auto& update(int i, int j, const T &val){
    assert(not is_built);
    data[i+1][j+1] = add(data[i+1][j+1], val);
    return *this;
  }

  auto& build(){
    assert(not is_built);
    for(int i = 1; i <= N; ++i) for(int j = 0; j <= M; ++j) data[i][j] = add(data[i][j], data[i-1][j]);
    for(int i = 0; i <= N; ++i) for(int j = 1; j <= M; ++j) data[i][j] = add(data[i][j], data[i][j-1]);
    is_built = true;
    return *this;
  }

  T get(int x1, int y1, int x2, int y2) const { // [x1,x2), [y1,y2)
    assert(is_built);
    return add(minus(data[x2][y2], add(data[x1][y2], data[x2][y1])), data[x1][y1]);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

