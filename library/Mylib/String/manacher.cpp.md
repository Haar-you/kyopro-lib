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


# :warning: Manacher algorithm

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/manacher.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Operations

- `manacher(s)`
	- 各位置`i`を中心とした最長奇数長回文の片側長さ(回文長`L`に対して`L/2+1`)の配列を返す。

## Requirements

## Notes

## Problems

## References


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Manacher algorithm
 * @docs manacher.md
 */
template <typename Container, typename T = typename Container::value_type>
std::vector<int> manacher(const Container &s){
  const int n = s.size();
  std::vector<int> ret(n);
  int center = 0;

  for(int cur = 0; cur < n; ++cur){
    int left = center - (cur - center);

    if(left >= 0 and cur + ret[left] < center + ret[center]){
      ret[cur] = ret[left];
    }else{
      int len = center + ret[center] - cur;
      while(cur - len >= 0 and cur + len < n and s[cur - len] == s[cur + len]) ++len;
      ret[cur] = len;
      center = cur;
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/manacher.cpp"
#include <vector>

/**
 * @title Manacher algorithm
 * @docs manacher.md
 */
template <typename Container, typename T = typename Container::value_type>
std::vector<int> manacher(const Container &s){
  const int n = s.size();
  std::vector<int> ret(n);
  int center = 0;

  for(int cur = 0; cur < n; ++cur){
    int left = center - (cur - center);

    if(left >= 0 and cur + ret[left] < center + ret[center]){
      ret[cur] = ret[left];
    }else{
      int len = center + ret[center] - cur;
      while(cur - len >= 0 and cur + len < n and s[cur - len] == s[cur + len]) ++len;
      ret[cur] = len;
      center = cur;
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

