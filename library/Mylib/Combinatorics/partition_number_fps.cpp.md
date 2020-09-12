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


# :x: Partition number (FPS)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/partition_number_fps.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 05:03:27+09:00




## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/partition_function/main.fps.test.cpp.html">test/yosupo-judge/partition_function/main.fps.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cmath>

/**
 * @title Partition number (FPS)
 * @docs partition_number_fps.cpp
 */
namespace haar_lib {
  template <typename Fps>
  auto partition_number_fps(int N){
    using T = typename Fps::value_type;

    std::vector<T> f(N + 1);
    f[0] = 1;

    {
      const int M = (std::sqrt(1 + 24 * N) - 1) / 6;
      for(int i = 1; i <= M; ++i){
        f[i * (3 * i + 1) / 2] += (i % 2 == 0 ? 1 : -1);
      }
    }

    {
      const int M = (std::sqrt(1 + 24 * N) + 1) / 6;
      for(int i = 1; i <= M; ++i){
        f[i * (3 * i - 1) / 2] += (i % 2 == 0 ? 1 : -1);
      }
    }

    Fps ret(f);
    ret = ret.inv();

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/partition_number_fps.cpp"
#include <vector>
#include <cmath>

/**
 * @title Partition number (FPS)
 * @docs partition_number_fps.cpp
 */
namespace haar_lib {
  template <typename Fps>
  auto partition_number_fps(int N){
    using T = typename Fps::value_type;

    std::vector<T> f(N + 1);
    f[0] = 1;

    {
      const int M = (std::sqrt(1 + 24 * N) - 1) / 6;
      for(int i = 1; i <= M; ++i){
        f[i * (3 * i + 1) / 2] += (i % 2 == 0 ? 1 : -1);
      }
    }

    {
      const int M = (std::sqrt(1 + 24 * N) + 1) / 6;
      for(int i = 1; i <= M; ++i){
        f[i * (3 * i - 1) / 2] += (i % 2 == 0 ? 1 : -1);
      }
    }

    Fps ret(f);
    ret = ret.inv();

    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

