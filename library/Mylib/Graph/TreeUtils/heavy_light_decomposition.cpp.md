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


# :question: Heavy-light decomposition

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

- `HLDecomposition(tree, root)`
- `path_query_vertex(int x, int y, f)`
	- `x`, `y`間のパス上の頂点に`f`を適用する。
- `path_query_vertex(int x, int y, f, g)`
- `path_query_edge(int x, int y, f)`
	- `x`, `y`間のパス上の辺に`f`を適用する。
- `subtree_query_vertext(int x, f)`
	- `x`の部分木の頂点に`f`を適用する。
- `subtree_query_edge(int x, f)`
	- `x`の部分木の辺に`f`を適用する。
- `get_edge_id(int u, int v)`
	- 辺`(u, v)`に対応するidを返す。
- `parent(int x)`
	- `x`の親を返す。
- `lca(int u, int v)`
	- `u`と`v`の最小共通祖先を返す。
- `get_id(int x)`
	- 頂点`x`に対応する`id[x]`を返す。

## Requirements

## Notes

## Problems

- [yukicoder No.399 動的な領主](https://yukicoder.me/problems/no/399) (パスに対する頂点クエリ)
- [AOJ 2667 Tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667) (パス・部分木に対する辺クエリ)
- [Codeforces Round #329 (Div. 2) D. Happy Tree Party](https://codeforces.com/contest/593/problem/D) (パスに対する辺クエリ)
- [yukicoder No.650 行列木クエリ](https://yukicoder.me/problems/no/650) (パスに対する辺クエリ)
- [Codeforces Round #200 (Div. 1) D. Water Tree](https://codeforces.com/contest/343/problem/D) (パス・部分木に対する頂点クエリ)

## References

- [https://math314.hateblo.jp/entry/2014/06/24/220107](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [https://beet-aizu.hatenablog.com/entry/2017/12/12/235950](https://beet-aizu.hatenablog.com/entry/2017/12/12/235950)
- [https://www.hamayanhamayan.com/entry/2017/04/10/172636](https://www.hamayanhamayan.com/entry/2017/04/10/172636)



## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2667/main.test.cpp.html">test/aoj/2667/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_add_path_sum/main.test.cpp.html">test/yosupo-judge/vertex_add_path_sum/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/1030/main.test.cpp.html">test/yukicoder/1030/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Heavy-light decomposition
 * @docs heavy_light_decomposition.md
 */
namespace haar_lib {
  template <typename T>
  class hl_decomposition {
    int n;

    std::vector<int> sub, // subtree size
      par, // parent id
      head, // chain head id
      id, // id[original id] = hld id
      rid, // rid[hld id] = original id
      next, // next node in a chain
      end; //

    int dfs_sub(tree<T> &tr, int cur, int p){
      par[cur] = p;
      int t = 0;
      for(auto &e : tr[cur]){
        if(e.to == p) continue;
        sub[cur] += dfs_sub(tr, e.to, cur);
        if(sub[e.to] > t){
          t = sub[e.to];
          next[cur] = e.to;
          std::swap(e, tr[cur][0]);
        }
      }
      return sub[cur];
    }

    void dfs_build(const tree<T> &tr, int cur, int &i){
      id[cur] = i;
      rid[i] = cur;
      ++i;

      for(auto &e : tr[cur]){
        if(e.to == par[cur]) continue;
        head[e.to] = (e.to == tr[cur][0].to ? head[cur] : e.to);
        dfs_build(tr, e.to, i);
      }

      end[cur] = i;
    }

  public:
    hl_decomposition(tree<T> tr, int root):
      n(tr.size()), sub(n, 1), par(n, -1), head(n), id(n), rid(n), next(n, -1), end(n, -1){
      dfs_sub(tr, root, -1);
      int i = 0;
      dfs_build(tr, root, i);
    }

    template <typename Func> // std::function<void(int, int)>
    void path_query_vertex(int x, int y, const Func &f) const {
      while(1){
        if(id[x] > id[y]) std::swap(x, y);
        f(std::max(id[head[y]], id[x]), id[y] + 1);
        if(head[x] == head[y]) return;
        y = par[head[y]];
      }
    }

    template <typename LeftFunc, typename RightFunc>
    void path_query_vertex(int x, int y, const LeftFunc &f, const RightFunc &g) const {
      const int w = lca(x, y);

      path_query_vertex(x, w, f);

      x = y;
      y = w;

      while(1){
        if(id[x] > id[y]){
          std::swap(x, y);
        }
        g(std::max({id[head[y]], id[x], id[w] + 1}), id[y] + 1);
        if(head[x] == head[y]) return;
        y = par[head[y]];
      }
    }

    template <typename Func> // std::function<void(int, int)>
    void path_query_edge(int x, int y, const Func &f) const {
      while(1){
        if(id[x] > id[y]) std::swap(x, y);
        if(head[x] == head[y]){
          if(x != y) f(id[x] + 1, id[y] + 1);
          return;
        }
        f(id[head[y]], id[y] + 1);
        y = par[head[y]];
      }
    }

    template <typename Func> // std::function<void(int, int)>
    void subtree_query_edge(int x, const Func &f) const {
      f(id[x] + 1, end[x]);
    }

    template <typename Func> // std::function<void(int, int)>
    void subtree_query_vertex(int x, const Func &f) const {
      f(id[x], end[x]);
    }

    int get_edge_id(int u, int v) const { // 辺に対応するid
      if(par[u] == v){
        return id[u];
      }else if(par[v] == u){
        return id[v];
      }

      return -1;
    }

    int parent(int x) const {return par[x];};

    int lca(int u, int v) const {
      while(1){
        if(id[u] > id[v]) std::swap(u, v);
        if(head[u] == head[v]) return u;
        v = par[head[v]];
      }
    }

    int get_id(int x) const {
      return id[x];
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"
#include <vector>
#include <utility>
#include <algorithm>
#line 3 "Mylib/Graph/Template/graph.cpp"
#include <iostream>

/**
 * @title Basic graph
 * @docs graph.md
 */
namespace haar_lib {
  template <typename T>
  struct edge {
    int from, to;
    T cost;
    int index = -1;
    edge(){}
    edge(int from, int to, T cost): from(from), to(to), cost(cost){}
    edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
  };

  template <typename T>
  struct graph {
    using weight_type = T;
    using edge_type = edge<T>;

    std::vector<std::vector<edge<T>>> data;

    auto& operator[](size_t i){return data[i];}
    const auto& operator[](size_t i) const {return data[i];}

    auto begin() const {return data.begin();}
    auto end() const {return data.end();}

    graph(){}
    graph(int N): data(N){}

    bool empty() const {return data.empty();}
    int size() const {return data.size();}

    void add_edge(int i, int j, T w, int index = -1){
      data[i].emplace_back(i, j, w, index);
    }

    void add_undirected(int i, int j, T w, int index = -1){
      add_edge(i, j, w, index);
      add_edge(j, i, w, index);
    }

    template <size_t I, bool DIRECTED = true, bool WEIGHTED = true>
    void read(int M){
      for(int i = 0; i < M; ++i){
        int u, v; std::cin >> u >> v;
        u -= I;
        v -= I;
        T w = 1;
        if(WEIGHTED) std::cin >> w;
        if(DIRECTED) add_edge(u, v, w, i);
        else add_undirected(u, v, w, i);
      }
    }
  };

  template <typename T>
  using tree = graph<T>;
}
#line 6 "Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp"

/**
 * @title Heavy-light decomposition
 * @docs heavy_light_decomposition.md
 */
namespace haar_lib {
  template <typename T>
  class hl_decomposition {
    int n;

    std::vector<int> sub, // subtree size
      par, // parent id
      head, // chain head id
      id, // id[original id] = hld id
      rid, // rid[hld id] = original id
      next, // next node in a chain
      end; //

    int dfs_sub(tree<T> &tr, int cur, int p){
      par[cur] = p;
      int t = 0;
      for(auto &e : tr[cur]){
        if(e.to == p) continue;
        sub[cur] += dfs_sub(tr, e.to, cur);
        if(sub[e.to] > t){
          t = sub[e.to];
          next[cur] = e.to;
          std::swap(e, tr[cur][0]);
        }
      }
      return sub[cur];
    }

    void dfs_build(const tree<T> &tr, int cur, int &i){
      id[cur] = i;
      rid[i] = cur;
      ++i;

      for(auto &e : tr[cur]){
        if(e.to == par[cur]) continue;
        head[e.to] = (e.to == tr[cur][0].to ? head[cur] : e.to);
        dfs_build(tr, e.to, i);
      }

      end[cur] = i;
    }

  public:
    hl_decomposition(tree<T> tr, int root):
      n(tr.size()), sub(n, 1), par(n, -1), head(n), id(n), rid(n), next(n, -1), end(n, -1){
      dfs_sub(tr, root, -1);
      int i = 0;
      dfs_build(tr, root, i);
    }

    template <typename Func> // std::function<void(int, int)>
    void path_query_vertex(int x, int y, const Func &f) const {
      while(1){
        if(id[x] > id[y]) std::swap(x, y);
        f(std::max(id[head[y]], id[x]), id[y] + 1);
        if(head[x] == head[y]) return;
        y = par[head[y]];
      }
    }

    template <typename LeftFunc, typename RightFunc>
    void path_query_vertex(int x, int y, const LeftFunc &f, const RightFunc &g) const {
      const int w = lca(x, y);

      path_query_vertex(x, w, f);

      x = y;
      y = w;

      while(1){
        if(id[x] > id[y]){
          std::swap(x, y);
        }
        g(std::max({id[head[y]], id[x], id[w] + 1}), id[y] + 1);
        if(head[x] == head[y]) return;
        y = par[head[y]];
      }
    }

    template <typename Func> // std::function<void(int, int)>
    void path_query_edge(int x, int y, const Func &f) const {
      while(1){
        if(id[x] > id[y]) std::swap(x, y);
        if(head[x] == head[y]){
          if(x != y) f(id[x] + 1, id[y] + 1);
          return;
        }
        f(id[head[y]], id[y] + 1);
        y = par[head[y]];
      }
    }

    template <typename Func> // std::function<void(int, int)>
    void subtree_query_edge(int x, const Func &f) const {
      f(id[x] + 1, end[x]);
    }

    template <typename Func> // std::function<void(int, int)>
    void subtree_query_vertex(int x, const Func &f) const {
      f(id[x], end[x]);
    }

    int get_edge_id(int u, int v) const { // 辺に対応するid
      if(par[u] == v){
        return id[u];
      }else if(par[v] == u){
        return id[v];
      }

      return -1;
    }

    int parent(int x) const {return par[x];};

    int lca(int u, int v) const {
      while(1){
        if(id[u] > id[v]) std::swap(u, v);
        if(head[u] == head[v]) return u;
        v = par[head[v]];
      }
    }

    int get_id(int x) const {
      return id[x];
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
