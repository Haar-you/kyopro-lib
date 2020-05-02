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


# :x: test/aoj/GRL_5_C/main.doubling.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#502e31dec0efb369b23aee4c6aa81a7e">test/aoj/GRL_5_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_C/main.doubling.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp.html">最小共通祖先 (ダブリング)</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp"

int main(){
  int n; std::cin >> n;

  Tree<int> tree(n);
  for(int i = 0; i < n; ++i){
    int k; std::cin >> k;
    for(int j = 0; j < k; ++j){
      int c; std::cin >> c;
      add_edge(tree, i, c, 1);
    }
  }

  auto lca = LCA(tree, 0);

  int q; std::cin >> q;
  while(q--){
    int u, v; std::cin >> u >> v;
    
    std::cout << lca.lca(u, v) << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_5_C/main.doubling.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include <iostream>
#line 2 "Mylib/Graph/graph_template.cpp"
#include <vector>
#line 4 "Mylib/Graph/graph_template.cpp"

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
#line 3 "Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp"
#include <cmath>
#line 5 "Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp"

/**
 * @title 最小共通祖先 (ダブリング)
 * @docs lca_based_on_doubling.md
 */
template <typename T> class LCA{
private:
  std::vector<std::vector<int>> parent;
  int n, log2n;
  
  void dfs(const Tree<T> &tree, int cur, int par, int d){
    parent[cur][0] = par;
    depth[cur] = d;

    for(auto &e : tree[cur]){
      if(e.to != par){
        dist[e.to] = dist[cur] + e.cost;
        dfs(tree, e.to, cur, d+1);
      }
    }
  }
  
public:
  std::vector<int> depth;
  std::vector<T> dist;
  
  LCA(const Tree<T> &tree, int root):
    n(tree.size()), depth(n), dist(n)
  {
    log2n = (int)ceil(log(n) / log(2)) + 1;
    parent = std::vector<std::vector<int>>(n, std::vector<int>(log2n, 0));

    dfs(tree, root, -1, 0);
    for(int k = 0; k < log2n-1; ++k){
      for(int v = 0; v < n; ++v){
        if(parent[v][k] == -1) parent[v][k+1] = -1;
        else parent[v][k+1] = parent[parent[v][k]][k];
      }
    }
  }

  int lca(int a, int b) const {
    if(depth[a] >= depth[b]) std::swap(a,b);
    for(int k = 0; k < log2n; ++k) if((depth[b] - depth[a]) >> k & 1) b = parent[b][k];
    if(a == b) return a;
    for(int k = log2n-1; k >= 0; --k) if(parent[a][k] != parent[b][k]){a = parent[a][k]; b = parent[b][k];}
    return parent[a][0];
  }

  T distance(int a, int b) const {
    return dist[a] + dist[b] - 2 * dist[lca(a,b)];
  }
};
#line 6 "test/aoj/GRL_5_C/main.doubling.test.cpp"

int main(){
  int n; std::cin >> n;

  Tree<int> tree(n);
  for(int i = 0; i < n; ++i){
    int k; std::cin >> k;
    for(int j = 0; j < k; ++j){
      int c; std::cin >> c;
      add_edge(tree, i, c, 1);
    }
  }

  auto lca = LCA(tree, 0);

  int q; std::cin >> q;
  while(q--){
    int u, v; std::cin >> u >> v;
    
    std::cout << lca.lca(u, v) << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

