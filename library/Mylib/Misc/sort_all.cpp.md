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


# :warning: Mylib/Misc/sort_all.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/sort_all.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 08:41:26+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

namespace sort_all{
  template <typename T>
  void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a){
    std::vector<T> temp(N);
    for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
    std::swap(temp, a);
  }

  template <typename T, typename ...Args>
  void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a, Args&... args){
    std::vector<T> temp(N);
    for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
    std::swap(temp, a);
    sort_with_ord(ord, N, args...);
  }

  template <typename Compare, typename ...Args>
  void run(const Compare &compare, int N, Args&... args){
    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), compare);

    sort_with_ord(ord, N, args...);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/sort_all.cpp"
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

namespace sort_all{
  template <typename T>
  void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a){
    std::vector<T> temp(N);
    for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
    std::swap(temp, a);
  }

  template <typename T, typename ...Args>
  void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a, Args&... args){
    std::vector<T> temp(N);
    for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
    std::swap(temp, a);
    sort_with_ord(ord, N, args...);
  }

  template <typename Compare, typename ...Args>
  void run(const Compare &compare, int N, Args&... args){
    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), compare);

    sort_with_ord(ord, N, args...);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

