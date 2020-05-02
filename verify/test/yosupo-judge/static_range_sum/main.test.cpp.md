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


# :x: test/yosupo-judge/static_range_sum/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e057ba653ff4e1918cbb7491bf73d8e0">test/yosupo-judge/static_range_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/static_range_sum/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_sum">https://judge.yosupo.jp/problem/static_range_sum</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp.html">一次元累積和</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#include "Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;
  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  auto c = CumulativeSum1D(a);
  c.build();

  while(Q--){
    int l, r; std::cin >> l >> r;
    std::cout << c.get(l, r) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/static_range_sum/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#line 2 "Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp"
#include <vector>
#include <functional>
#include <cassert>

/**
 * @title 一次元累積和
 * @docs cumulative_sum_1d.md
 */
template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
class CumulativeSum1D{
  std::vector<T> data;
  const int N;
  const Add add;
  const Minus minus;
  bool is_built = false;

public:
  CumulativeSum1D(const std::vector<T> &a, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(a.size()), add(add), minus(minus)
  {
    data.assign(N+1, e);
    for(int i = 0; i < N; ++i) data[i+1] = a[i];
  }

  CumulativeSum1D(int N, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(N), add(add), minus(minus)
  {
    data.assign(N+1, e);
  }

  inline void update(int i, const T &val){
    assert(not is_built);
    data[i+1] = add(data[i+1], val);
  }

  inline void build(){
    assert(not is_built);
    for(int i = 0; i < N; ++i) data[i+1] = add(data[i+1], data[i]);
    is_built = true;
  }
  
  /**
   * @attention [i, j)
   */
  inline T get(int i, int j) const {
    assert(is_built);
    return minus(data[j], data[i]);
  }
};

#line 5 "test/yosupo-judge/static_range_sum/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;
  std::vector<int64_t> a(N);
  for(int i = 0; i < N; ++i) std::cin >> a[i];

  auto c = CumulativeSum1D(a);
  c.build();

  while(Q--){
    int l, r; std::cin >> l >> r;
    std::cout << c.get(l, r) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

