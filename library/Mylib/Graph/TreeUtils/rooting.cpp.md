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


# :warning: 根付き木

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/rooting.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 09:17:56+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 根付き木
 */
template <typename T>
void rooting(Tree<T> &tree, int cur, int par = -1){
  if(par != -1){
    for(auto it = tree[cur].begin(); it != tree[cur].end(); ++it){
      if(it->to == par){
        tree[cur].erase(it);
        break;
      }
    }
  }

  for(auto &e : tree[cur]){
    rooting(tree, e.to, cur);
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#include <iostream>

/**
 * @title グラフ用テンプレート
 */
template <typename Cost = int> class Edge{
public:
  int from,to;
  Cost cost;
  Edge() {}
  Edge(int to, Cost cost): to(to), cost(cost){}
  Edge(int from, int to, Cost cost): from(from), to(to), cost(cost){}
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename T, typename C> void add_edge(C &g, int from, int to, T w = 1){
  g[from].emplace_back(from, to, w);
}

template <typename T, typename C> void add_undirected(C &g, int a, int b, T w = 1){
  add_edge<T, C>(g, a, b, w);
  add_edge<T, C>(g, b, a, w);
}
#line 3 "Mylib/Graph/TreeUtils/rooting.cpp"

/**
 * @title 根付き木
 */
template <typename T>
void rooting(Tree<T> &tree, int cur, int par = -1){
  if(par != -1){
    for(auto it = tree[cur].begin(); it != tree[cur].end(); ++it){
      if(it->to == par){
        tree[cur].erase(it);
        break;
      }
    }
  }

  for(auto &e : tree[cur]){
    rooting(tree, e.to, cur);
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

