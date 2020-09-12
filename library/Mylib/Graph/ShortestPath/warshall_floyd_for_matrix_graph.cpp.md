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


# :heavy_check_mark: Warshall-Floyd algorithm (For adjacency matrix graph)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9a0780c4ad89eac4e850657d1e57c23a">Mylib/Graph/ShortestPath</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2171/main.test.cpp.html">test/aoj/2171/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <optional>

/**
 * @title Warshall-Floyd algorithm (For adjacency matrix graph)
 * @docs warshall_floyd_for_matrix_graph.md
 */
namespace haar_lib {
  namespace warshall_floyd_for_matrix_impl {
    template <typename T>
    struct result {
      std::vector<std::vector<std::optional<T>>> dist;
      bool has_negative_cycle;
      const auto& operator[](int i) const {return dist[i];}
    };
  }

  template <typename T, T INVALID>
  auto warshall_floyd_for_matrix(const std::vector<std::vector<T>> &g){
    const int n = g.size();
    auto dist = std::vector(n, std::vector<std::optional<T>>(n));

    for(int i = 0; i < n; ++i) dist[i][i] = 0;

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(g[i][j] != INVALID){
          dist[i][j] = g[i][j];
        }
      }
    }

    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(dist[i][k] and dist[k][j]){
            if(not dist[i][j]){
              dist[i][j] = *dist[i][k] + *dist[k][j];
            }else{
              dist[i][j] = std::min(*dist[i][j], *dist[i][k] + *dist[k][j]);
            }
          }
        }
      }
    }

    bool has_negative_cycle = false;
    for(int i = 0; i < n; ++i) if(*dist[i][i] < 0) has_negative_cycle = true;

    return warshall_floyd_for_matrix_impl::result<T>{dist, has_negative_cycle};
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp"
#include <vector>
#include <optional>

/**
 * @title Warshall-Floyd algorithm (For adjacency matrix graph)
 * @docs warshall_floyd_for_matrix_graph.md
 */
namespace haar_lib {
  namespace warshall_floyd_for_matrix_impl {
    template <typename T>
    struct result {
      std::vector<std::vector<std::optional<T>>> dist;
      bool has_negative_cycle;
      const auto& operator[](int i) const {return dist[i];}
    };
  }

  template <typename T, T INVALID>
  auto warshall_floyd_for_matrix(const std::vector<std::vector<T>> &g){
    const int n = g.size();
    auto dist = std::vector(n, std::vector<std::optional<T>>(n));

    for(int i = 0; i < n; ++i) dist[i][i] = 0;

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        if(g[i][j] != INVALID){
          dist[i][j] = g[i][j];
        }
      }
    }

    for(int k = 0; k < n; ++k){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
          if(dist[i][k] and dist[k][j]){
            if(not dist[i][j]){
              dist[i][j] = *dist[i][k] + *dist[k][j];
            }else{
              dist[i][j] = std::min(*dist[i][j], *dist[i][k] + *dist[k][j]);
            }
          }
        }
      }
    }

    bool has_negative_cycle = false;
    for(int i = 0; i < n; ++i) if(*dist[i][i] < 0) has_negative_cycle = true;

    return warshall_floyd_for_matrix_impl::result<T>{dist, has_negative_cycle};
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

