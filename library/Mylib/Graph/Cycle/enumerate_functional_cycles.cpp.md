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


# :warning: Enumerate cycles in functional graph

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a962efc2861dbe1e0963e7d8bf7dda18">Mylib/Graph/Cycle</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Cycle/enumerate_functional_cycles.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>
#include <algorithm>

/**
 * @title Enumerate cycles in functional graph
 * @docs enumerate_functional_cycles.md
 */
std::vector<std::vector<int>> enumerate_functional_cycles(std::vector<int> g){
  const int n = g.size();

  std::vector<std::vector<int>> ret;
  std::vector<int> check(n);

  constexpr int SEARCHED = 1;
  constexpr int SEARCHING = 2;

  auto rec =
    [&](auto &rec, int cur, std::vector<int> &temp) -> std::optional<int> {
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      const int i = g[cur];

      if(auto res = rec(rec, i, temp); res){
        if(*res != -1){
          temp.push_back(i);
          if(*res == cur){
            check[cur] = SEARCHED;
            return {-1};
          }
        }

        check[cur] = SEARCHED;
        return res;
      }

      check[cur] = SEARCHED;
      return std::nullopt;
    };

  for(int i = 0; i < n; ++i){
    if(check[i] == 0){
      std::vector<int> temp;
      auto res = rec(rec, i, temp);
      if(res){
        std::reverse(temp.begin(), temp.end());
        ret.push_back(temp);
      }
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Cycle/enumerate_functional_cycles.cpp"
#include <vector>
#include <optional>
#include <algorithm>

/**
 * @title Enumerate cycles in functional graph
 * @docs enumerate_functional_cycles.md
 */
std::vector<std::vector<int>> enumerate_functional_cycles(std::vector<int> g){
  const int n = g.size();

  std::vector<std::vector<int>> ret;
  std::vector<int> check(n);

  constexpr int SEARCHED = 1;
  constexpr int SEARCHING = 2;

  auto rec =
    [&](auto &rec, int cur, std::vector<int> &temp) -> std::optional<int> {
      if(check[cur] == SEARCHED) return std::nullopt;
      if(check[cur] == SEARCHING) return {cur};
      check[cur] = SEARCHING;

      const int i = g[cur];

      if(auto res = rec(rec, i, temp); res){
        if(*res != -1){
          temp.push_back(i);
          if(*res == cur){
            check[cur] = SEARCHED;
            return {-1};
          }
        }

        check[cur] = SEARCHED;
        return res;
      }

      check[cur] = SEARCHED;
      return std::nullopt;
    };

  for(int i = 0; i < n; ++i){
    if(check[i] == 0){
      std::vector<int> temp;
      auto res = rec(rec, i, temp);
      if(res){
        std::reverse(temp.begin(), temp.end());
        ret.push_back(temp);
      }
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

