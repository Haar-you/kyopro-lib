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


# :warning: Longest path on DAG

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#65714f932d9658b7e9e55eb052732de1">Mylib/Graph/DAG</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/DAG/dag_longest_path.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Longest path on DAG
 * @docs dag_longest_path.md
 */
namespace haar_lib {
  int dag_longest_path(const std::vector<std::vector<int>> &g){
    const int n = g.size();
    std::vector<int> ret(n);
    std::vector<bool> visited(n);

    auto dfs =
      [&](auto &f, int cur) -> int {
        if(visited[cur]) return ret[cur];
        visited[cur] = true;

        for(auto &nxt : g[cur]){
          ret[cur] = std::max(ret[cur], f(f, nxt) + 1);
        }

        return ret[cur];
      };

    for(int i = 0; i < n; ++i) if(not visited[i]) dfs(dfs, i);

    return *std::max_element(ret.begin(), ret.end());
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/DAG/dag_longest_path.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Longest path on DAG
 * @docs dag_longest_path.md
 */
namespace haar_lib {
  int dag_longest_path(const std::vector<std::vector<int>> &g){
    const int n = g.size();
    std::vector<int> ret(n);
    std::vector<bool> visited(n);

    auto dfs =
      [&](auto &f, int cur) -> int {
        if(visited[cur]) return ret[cur];
        visited[cur] = true;

        for(auto &nxt : g[cur]){
          ret[cur] = std::max(ret[cur], f(f, nxt) + 1);
        }

        return ret[cur];
      };

    for(int i = 0; i < n; ++i) if(not visited[i]) dfs(dfs, i);

    return *std::max_element(ret.begin(), ret.end());
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
