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


# :x: 1D cumulative sum

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#606b6851a96c8708fa4cdcf98aebb7c1">Mylib/Algorithm/CumulativeSum</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00




## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/static_range_sum/main.test.cpp.html">test/yosupo-judge/static_range_sum/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <functional>
#include <cassert>

/**
 * @title 1D cumulative sum
 * @docs cumulative_sum_1d.md
 */
template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
class CumulativeSum1D {
  std::vector<T> data;
  const int N;
  const Add add;
  const Minus minus;
  bool is_built = false;

public:
  CumulativeSum1D(const std::vector<T> &a, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(a.size()), add(add), minus(minus)
  {
    data.assign(N + 1, e);
    for(int i = 0; i < N; ++i) data[i + 1] = a[i];
  }

  CumulativeSum1D(int N, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(N), add(add), minus(minus)
  {
    data.assign(N + 1, e);
  }

  auto& update(int i, const T &val){
    assert(not is_built);
    data[i + 1] = add(data[i + 1], val);
    return *this;
  }

  auto& build(){
    assert(not is_built);
    for(int i = 0; i < N; ++i) data[i + 1] = add(data[i + 1], data[i]);
    is_built = true;
    return *this;
  }

  /**
   * @attention [i, j)
   */
  T get(int i, int j) const {
    assert(is_built);
    return minus(data[j], data[i]);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp"
#include <vector>
#include <functional>
#include <cassert>

/**
 * @title 1D cumulative sum
 * @docs cumulative_sum_1d.md
 */
template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
class CumulativeSum1D {
  std::vector<T> data;
  const int N;
  const Add add;
  const Minus minus;
  bool is_built = false;

public:
  CumulativeSum1D(const std::vector<T> &a, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(a.size()), add(add), minus(minus)
  {
    data.assign(N + 1, e);
    for(int i = 0; i < N; ++i) data[i + 1] = a[i];
  }

  CumulativeSum1D(int N, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(N), add(add), minus(minus)
  {
    data.assign(N + 1, e);
  }

  auto& update(int i, const T &val){
    assert(not is_built);
    data[i + 1] = add(data[i + 1], val);
    return *this;
  }

  auto& build(){
    assert(not is_built);
    for(int i = 0; i < N; ++i) data[i + 1] = add(data[i + 1], data[i]);
    is_built = true;
    return *this;
  }

  /**
   * @attention [i, j)
   */
  T get(int i, int j) const {
    assert(is_built);
    return minus(data[j], data[i]);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

