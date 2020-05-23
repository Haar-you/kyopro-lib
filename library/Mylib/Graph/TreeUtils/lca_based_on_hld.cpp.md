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


# :heavy_check_mark: 最小共通祖先 (HLD)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/lca_based_on_hld.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Depends on

* :question: <a href="../graph_template.cpp.html">グラフ用テンプレート</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/GRL_5_C/main.hld.test.cpp.html">test/aoj/GRL_5_C/main.hld.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 最小共通祖先 (HLD)
 * @docs lca_based_on_hld.md
 */
template <typename T> class LCA{
  int n;
  std::vector<int> sub, par, head, id;
  
  int dfs_sub(int cur, int p, Tree<T> &tree){
    par[cur] = p;
    int t = 0;
    for(auto &e : tree[cur]){
      if(e.to == p) continue;
      sub[cur] += dfs_sub(e.to, cur, tree);
      if(sub[e.to] > t){
        t = sub[e.to];
        std::swap(e, tree[cur][0]);
      }
    }
    return sub[cur];
  }

  void dfs_build(int cur, int &i, Tree<T> &tree){
    id[cur] = i;
    ++i;

    for(auto &e : tree[cur]){
      if(e.to == par[cur]) continue;
      head[e.to] = (e.to == tree[cur][0].to ? head[cur] : e.to);
      dfs_build(e.to, i, tree);
    }
  }
  
public:
  LCA(Tree<T> tree, int root):
    n(tree.size()), sub(n,1), par(n,-1), head(n), id(n){
    dfs_sub(root, -1, tree);
    int i = 0;
    dfs_build(root, i, tree);
  }

  int lca(int u, int v) const {
    while(1){
      if(id[u] > id[v]) std::swap(u, v);
      if(head[u] == head[v]) return u;
      v = par[head[v]];
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/lca_based_on_hld.cpp"
#include <vector>
#include <utility>
#line 3 "Mylib/Graph/graph_template.cpp"
#include <iostream>

/**
 * @title グラフ用テンプレート
 * @docs graph_template.md
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
#line 5 "Mylib/Graph/TreeUtils/lca_based_on_hld.cpp"

/**
 * @title 最小共通祖先 (HLD)
 * @docs lca_based_on_hld.md
 */
template <typename T> class LCA{
  int n;
  std::vector<int> sub, par, head, id;
  
  int dfs_sub(int cur, int p, Tree<T> &tree){
    par[cur] = p;
    int t = 0;
    for(auto &e : tree[cur]){
      if(e.to == p) continue;
      sub[cur] += dfs_sub(e.to, cur, tree);
      if(sub[e.to] > t){
        t = sub[e.to];
        std::swap(e, tree[cur][0]);
      }
    }
    return sub[cur];
  }

  void dfs_build(int cur, int &i, Tree<T> &tree){
    id[cur] = i;
    ++i;

    for(auto &e : tree[cur]){
      if(e.to == par[cur]) continue;
      head[e.to] = (e.to == tree[cur][0].to ? head[cur] : e.to);
      dfs_build(e.to, i, tree);
    }
  }
  
public:
  LCA(Tree<T> tree, int root):
    n(tree.size()), sub(n,1), par(n,-1), head(n), id(n){
    dfs_sub(root, -1, tree);
    int i = 0;
    dfs_build(root, i, tree);
  }

  int lca(int u, int v) const {
    while(1){
      if(id[u] > id[v]) std::swap(u, v);
      if(head[u] == head[v]) return u;
      v = par[head[v]];
    }
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

