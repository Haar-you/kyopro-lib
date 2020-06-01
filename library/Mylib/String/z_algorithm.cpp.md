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


# :x: Z-algorithm

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/z_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Required by

* :x: <a href="run_enumerate.cpp.html">Run enumerate</a>


## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/runenumerate/main.test.cpp.html">test/yosupo-judge/runenumerate/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/zalgorithm/main.test.cpp.html">test/yosupo-judge/zalgorithm/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Z-algorithm
 * @docs z_algorithm
 */
template <typename Container, typename T = typename Container::value_type>
std::vector<int> z_algorithm(const Container &s){
  const int n = s.size();
  std::vector<int> ret(n, 0);
  int j = 0;

  for(int i = 1; i < n; ++i){
    if(i+ret[i-j] < j+ret[j]){
      ret[i] = ret[i-j];
    }else{
      int k = std::max<int>(0, j+ret[j]-i);
      while(i+k < n and s[k] == s[i+k]) ++k;
      ret[i] = k;
      j = i;
    }
  }

  ret[0] = n;

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/z_algorithm.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Z-algorithm
 * @docs z_algorithm
 */
template <typename Container, typename T = typename Container::value_type>
std::vector<int> z_algorithm(const Container &s){
  const int n = s.size();
  std::vector<int> ret(n, 0);
  int j = 0;

  for(int i = 1; i < n; ++i){
    if(i+ret[i-j] < j+ret[j]){
      ret[i] = ret[i-j];
    }else{
      int k = std::max<int>(0, j+ret[j]-i);
      while(i+k < n and s[k] == s[i+k]) ++k;
      ret[i] = k;
      j = i;
    }
  }

  ret[0] = n;

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

