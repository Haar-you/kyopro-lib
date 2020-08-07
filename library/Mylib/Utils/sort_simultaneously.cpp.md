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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Mylib/Utils/sort_simultaneously.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cf1ec978dae666792e23e53a3672d204">Mylib/Utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Utils/sort_simultaneously.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 20:09:17+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2426/main.test.cpp.html">test/aoj/2426/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <initializer_list>

/**
 * @docs sort_simultaneously.md
 */
template <typename T>
void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a){
  std::vector<T> temp(N);
  for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
  std::swap(temp, a);
}

template <typename Compare, typename ...Args>
void sort_simultaneously(const Compare &compare, int N, std::vector<Args> &... args){
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), compare);

  (void)std::initializer_list<int>{(sort_with_ord(ord, N, args), 0)...};
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Utils/sort_simultaneously.cpp"
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <initializer_list>

/**
 * @docs sort_simultaneously.md
 */
template <typename T>
void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a){
  std::vector<T> temp(N);
  for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
  std::swap(temp, a);
}

template <typename Compare, typename ...Args>
void sort_simultaneously(const Compare &compare, int N, std::vector<Args> &... args){
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), compare);

  (void)std::initializer_list<int>{(sort_with_ord(ord, N, args), 0)...};
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

