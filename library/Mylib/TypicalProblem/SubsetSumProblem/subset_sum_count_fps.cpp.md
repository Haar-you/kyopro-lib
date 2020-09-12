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


# :x: Subset sum problem (Count, FPS)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2e380218d9fd214c2f91a8ade734af1c">Mylib/TypicalProblem/SubsetSumProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/SubsetSumProblem/subset_sum_count_fps.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/sharp_p_subset_sum/main.test.cpp.html">test/yosupo-judge/sharp_p_subset_sum/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Subset sum problem (Count, FPS)
 * @docs subset_sum_count_fps.md
 */
namespace haar_lib {
  template <typename Fps>
  auto subset_sum_count_fps(std::vector<int> s, int t){
    using T = typename Fps::value_type;

    std::vector<int> c(t + 1);
    for(int i : s) c[i] += 1;

    Fps ret(t + 1);

    for(int i = 1; i <= t; ++i){
      if(c[i] == 0) continue;

      for(int j = 1; j * i <= t; ++j){
        const int k = j * i;
        const T x = (j % 2 == 1 ? 1 : -1) * i * ((T)k).inv();
        ret[k] += x * c[i];
      }
    }

    ret = ret.exp();

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_count_fps.cpp"
#include <vector>

/**
 * @title Subset sum problem (Count, FPS)
 * @docs subset_sum_count_fps.md
 */
namespace haar_lib {
  template <typename Fps>
  auto subset_sum_count_fps(std::vector<int> s, int t){
    using T = typename Fps::value_type;

    std::vector<int> c(t + 1);
    for(int i : s) c[i] += 1;

    Fps ret(t + 1);

    for(int i = 1; i <= t; ++i){
      if(c[i] == 0) continue;

      for(int j = 1; j * i <= t; ++j){
        const int k = j * i;
        const T x = (j % 2 == 1 ? 1 : -1) * i * ((T)k).inv();
        ret[k] += x * c[i];
      }
    }

    ret = ret.exp();

    return ret;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

