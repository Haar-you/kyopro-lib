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


# :x: Euler tour (BFS)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a41ea9974466d4f509bcbf59f2ee921e">Mylib/Graph/TreeUtils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/TreeUtils/euler_tour_bfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 18:23:32+09:00




## Operations

- `EulerTourBFS(tree, int root)`
- `query_children(int i, int d, f)`
	- `i`の`d`個下の子孫に`f`を適用する。
- `query_at(int i, f)`
	- `query_children(i, 0, f)`と同等。
- `get_parent`
	- `i`の親を返す。
- `get_ancestor(int i, int k)`
	- `i`の`k`個遡った祖先を返す。
	- `get_ancestor(i, 0) = i`
	- `get_ancestor(i, 1) = get_parent(i)`
	- Time complexity $O(k)$

## Requirements

## Notes

## Problems

- [yukicoder No.899 γatheree](https://yukicoder.me/problems/no/899)

## References

- [https://niuez.hatenablog.com/entry/2019/10/05/002503](https://niuez.hatenablog.com/entry/2019/10/05/002503)
- [https://niuez.github.io/2020/03/dfs_bfs_et/](https://niuez.github.io/2020/03/dfs_bfs_et/)




## Depends on

* :question: <a href="../Template/graph.cpp.html">Basic graph</a>


## Verified with

* :x: <a href="../../../../verify/test/yukicoder/899/main.test.cpp.html">test/yukicoder/899/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Euler tour (BFS)
 * @docs euler_tour_bfs.md
 */
template <typename T>
struct EulerTourBFS{
  int N;
  std::vector<int> parent;
  std::vector<int> depth;

  std::vector<std::vector<int>> bfs_order;
  std::vector<std::vector<int>> dfs_order;
  std::vector<int> left, right;

  EulerTourBFS(const Tree<T> &tree, int root):
    N(tree.size()), parent(N), depth(N), left(N), right(N)
  {
    {
      int ord = 0;
      dfs(tree, root, -1, 0, ord);
    }

    {
      std::queue<std::pair<int,int>> q;
      q.emplace(root, 0);
      int ord = 0;

      while(not q.empty()){
        auto [i, d] = q.front(); q.pop();

        if((int)bfs_order.size() <= d) bfs_order.push_back(std::vector<int>());
        bfs_order[d].push_back(ord);
        ++ord;

        for(auto &e : tree[i]){
          if(e.to == parent[i]) continue;
          q.emplace(e.to, d + 1);
        }
      }
    }
  }

  void dfs(const Tree<T> &tree, int cur, int par, int d, int &ord){
    parent[cur] = par;
    depth[cur] = d;

    if((int)dfs_order.size() <= d) dfs_order.push_back(std::vector<int>());
    dfs_order[d].push_back(ord);
    left[cur] = ord;
    ++ord;

    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs(tree, e.to, cur, d + 1, ord);
    }

    right[cur] = ord;
  }

public:
  template <typename Func>
  void query_children(int i, int d, const Func &f) const {
    if(i != -1){
      d += depth[i];
      if((int)bfs_order.size() > d){
        int l = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), left[i]) - dfs_order[d].begin();
        int r = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), right[i]) - dfs_order[d].begin();

        if(l >= (int)bfs_order[d].size()) return;
        if(r == l) return;

        f(bfs_order[d][l], bfs_order[d][r-1] + 1);
      }
    }
  }

  template <typename Func>
  void query_at(int i, const Func &f) const {
    query_children(i, 0, f);
  }
  
  int get_parent(int i) const {
    if(i == -1) return -1;
    return parent[i];
  }

  int get_ancestor(int i, int k) const {
    int ret = i;
    for(int i = 0; i < k; ++i){
      ret = get_parent(ret);
      if(ret == -1) break;
    }
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"
#include <vector>
#include <queue>
#line 3 "Mylib/Graph/Template/graph.cpp"

/**
 * @title Basic graph
 * @docs graph.md
 */
template <typename T>
struct Edge{
  int from, to;
  T cost;
  int index = -1;
  Edge(){}
  Edge(int from, int to, T cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}
};

template <typename T>
struct Graph{
  using weight_type = T;
  using edge_type = Edge<T>;
  
  std::vector<std::vector<Edge<T>>> data;

  auto& operator[](size_t i){return data[i];}
  const auto& operator[](size_t i) const {return data[i];}
  
  auto begin() const {return data.begin();}
  auto end() const {return data.end();}

  Graph(){}
  Graph(int N): data(N){}

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
using Tree = Graph<T>;
#line 5 "Mylib/Graph/TreeUtils/euler_tour_bfs.cpp"

/**
 * @title Euler tour (BFS)
 * @docs euler_tour_bfs.md
 */
template <typename T>
struct EulerTourBFS{
  int N;
  std::vector<int> parent;
  std::vector<int> depth;

  std::vector<std::vector<int>> bfs_order;
  std::vector<std::vector<int>> dfs_order;
  std::vector<int> left, right;

  EulerTourBFS(const Tree<T> &tree, int root):
    N(tree.size()), parent(N), depth(N), left(N), right(N)
  {
    {
      int ord = 0;
      dfs(tree, root, -1, 0, ord);
    }

    {
      std::queue<std::pair<int,int>> q;
      q.emplace(root, 0);
      int ord = 0;

      while(not q.empty()){
        auto [i, d] = q.front(); q.pop();

        if((int)bfs_order.size() <= d) bfs_order.push_back(std::vector<int>());
        bfs_order[d].push_back(ord);
        ++ord;

        for(auto &e : tree[i]){
          if(e.to == parent[i]) continue;
          q.emplace(e.to, d + 1);
        }
      }
    }
  }

  void dfs(const Tree<T> &tree, int cur, int par, int d, int &ord){
    parent[cur] = par;
    depth[cur] = d;

    if((int)dfs_order.size() <= d) dfs_order.push_back(std::vector<int>());
    dfs_order[d].push_back(ord);
    left[cur] = ord;
    ++ord;

    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs(tree, e.to, cur, d + 1, ord);
    }

    right[cur] = ord;
  }

public:
  template <typename Func>
  void query_children(int i, int d, const Func &f) const {
    if(i != -1){
      d += depth[i];
      if((int)bfs_order.size() > d){
        int l = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), left[i]) - dfs_order[d].begin();
        int r = std::lower_bound(dfs_order[d].begin(), dfs_order[d].end(), right[i]) - dfs_order[d].begin();

        if(l >= (int)bfs_order[d].size()) return;
        if(r == l) return;

        f(bfs_order[d][l], bfs_order[d][r-1] + 1);
      }
    }
  }

  template <typename Func>
  void query_at(int i, const Func &f) const {
    query_children(i, 0, f);
  }
  
  int get_parent(int i) const {
    if(i == -1) return -1;
    return parent[i];
  }

  int get_ancestor(int i, int k) const {
    int ret = i;
    for(int i = 0; i < k; ++i){
      ret = get_parent(ret);
      if(ret == -1) break;
    }
    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

