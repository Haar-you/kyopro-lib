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


# :warning: Unzip function

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/unzip.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <initializer_list>
#include <utility>
#include <tuple>

/**
 * @title Unzip function
 * @docs unzip.cpp
 */
namespace haar_lib {
  template <typename T, typename U, size_t ... I>
  void unzip_helper(T &ret, U &a, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::get<I>(ret).push_back(std::get<I>(a))), 0) ...};
  }

  template <typename ... Args>
  auto unzip(std::vector<std::tuple<Args ...>> a){
    const int N = a.size();
    std::tuple<std::vector<Args> ...> ret;

    for(int i = 0; i < N; ++i){
      unzip_helper(ret, a[i], std::make_index_sequence<sizeof ... (Args)>());
    }

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/unzip.cpp"
#include <vector>
#include <initializer_list>
#include <utility>
#include <tuple>

/**
 * @title Unzip function
 * @docs unzip.cpp
 */
namespace haar_lib {
  template <typename T, typename U, size_t ... I>
  void unzip_helper(T &ret, U &a, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::get<I>(ret).push_back(std::get<I>(a))), 0) ...};
  }

  template <typename ... Args>
  auto unzip(std::vector<std::tuple<Args ...>> a){
    const int N = a.size();
    std::tuple<std::vector<Args> ...> ret;

    for(int i = 0; i < N; ++i){
      unzip_helper(ret, a[i], std::make_index_sequence<sizeof ... (Args)>());
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

