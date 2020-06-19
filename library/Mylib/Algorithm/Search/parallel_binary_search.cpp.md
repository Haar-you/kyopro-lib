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


# :heavy_check_mark: Parallel binary search

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a7582795d3062b8fdf2ece0fd4f2d90d">Mylib/Algorithm/Search</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/Search/parallel_binary_search.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

## Requirements

## Notes

## Problems

- [CODE THANKS FESTIVAL 2017 H - Union Sets](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h)

## References

- [http://pazzle1230.hatenablog.com/entry/2017/12/26/163616](http://pazzle1230.hatenablog.com/entry/2017/12/26/163616)
- [https://betrue12.hateblo.jp/entry/2019/08/14/152227](https://betrue12.hateblo.jp/entry/2019/08/14/152227)
- [http://codeforces.com/blog/entry/45578](http://codeforces.com/blog/entry/45578)


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/0575/main.test.cpp.html">test/aoj/0575/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cmath>

/**
 * @title Parallel binary search
 * @docs parallel_binary_search.md
 */
template <typename F>
auto parallel_binary_search(int M, int Q, F f){
  std::vector<int> lb(Q, -1), ub(Q, M);

  while(1){
    bool check = true;
    std::vector<std::vector<int>> mids(M);
    for(int i = 0; i < Q; ++i){
      if(std::abs(lb[i] - ub[i]) > 1){
        check = false;
        int mid = (lb[i] + ub[i]) / 2;
        mids[mid].push_back(i);
      }
    }

    if(check) break;

    f(
      [&](auto process, auto checker){
        for(int i = 0; i < M; ++i){
          process(i);
          for(int j : mids[i]){
            if(checker(j)){
              ub[j] = i;
            }else{
              lb[j] = i;
            }
          }
        }
      }
    );
  }

  return ub;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/Search/parallel_binary_search.cpp"
#include <vector>
#include <cmath>

/**
 * @title Parallel binary search
 * @docs parallel_binary_search.md
 */
template <typename F>
auto parallel_binary_search(int M, int Q, F f){
  std::vector<int> lb(Q, -1), ub(Q, M);

  while(1){
    bool check = true;
    std::vector<std::vector<int>> mids(M);
    for(int i = 0; i < Q; ++i){
      if(std::abs(lb[i] - ub[i]) > 1){
        check = false;
        int mid = (lb[i] + ub[i]) / 2;
        mids[mid].push_back(i);
      }
    }

    if(check) break;

    f(
      [&](auto process, auto checker){
        for(int i = 0; i < M; ++i){
          process(i);
          for(int j : mids[i]){
            if(checker(j)){
              ub[j] = i;
            }else{
              lb[j] = i;
            }
          }
        }
      }
    );
  }

  return ub;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

