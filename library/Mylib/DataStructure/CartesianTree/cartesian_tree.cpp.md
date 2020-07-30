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


# :heavy_check_mark: Cartesian tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b28da20868b326226cf0a4223d060067">Mylib/DataStructure/CartesianTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/CartesianTree/cartesian_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 08:23:59+09:00




## Operations

## Requirements

- 数列`a`はdistinctでなければならない。

## Notes

## Problems

- [Manthan, Codefest 18 F. Maximum Reduction](https://codeforces.com/contest/1037/problem/F)

## References

- [https://kimiyuki.net/blog/2020/07/27/recursion-on-cartesian-tree/](https://kimiyuki.net/blog/2020/07/27/recursion-on-cartesian-tree/)
- [https://en.wikipedia.org/wiki/Cartesian_tree](https://en.wikipedia.org/wiki/Cartesian_tree)


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/cartesian_tree/main.test.cpp.html">test/yosupo-judge/cartesian_tree/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <tuple>

/**
 * @title Cartesian tree
 * @docs cartesian_tree.md
 */
template <typename T, typename Compare>
auto cartesian_tree(const std::vector<T> &a, Compare compare){
  const int n = a.size();
  std::vector<std::optional<int>> p(n), l(n), r(n);
  int root = 0;

  for(int i = 0; i < n; ++i){
    if(i == 0){
      continue;
    }
    
    int j = i - 1;

    while(1){
      if(compare(a[i], a[j])){
        if(not p[j]){
          p[j] = i;
          l[i] = j;
          root = i;
          break;
        }

        j = *p[j];
        continue;
      }

      auto t = r[j];
      r[j] = i;
      p[i] = j;

      l[i] = t;
      if(t) p[*t] = i;
      
      break;
    }
  }

  return std::make_tuple(root, p, l, r);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/CartesianTree/cartesian_tree.cpp"
#include <vector>
#include <tuple>

/**
 * @title Cartesian tree
 * @docs cartesian_tree.md
 */
template <typename T, typename Compare>
auto cartesian_tree(const std::vector<T> &a, Compare compare){
  const int n = a.size();
  std::vector<std::optional<int>> p(n), l(n), r(n);
  int root = 0;

  for(int i = 0; i < n; ++i){
    if(i == 0){
      continue;
    }
    
    int j = i - 1;

    while(1){
      if(compare(a[i], a[j])){
        if(not p[j]){
          p[j] = i;
          l[i] = j;
          root = i;
          break;
        }

        j = *p[j];
        continue;
      }

      auto t = r[j];
      r[j] = i;
      p[i] = j;

      l[i] = t;
      if(t) p[*t] = i;
      
      break;
    }
  }

  return std::make_tuple(root, p, l, r);
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

