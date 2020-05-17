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


# :x: test/yukicoder/922/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6a3ef3b964dcfd2b510ed368d9e357ba">test/yukicoder/922</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/922/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-17 13:16:12+09:00


* see: <a href="https://yukicoder.me/problems/no/922">https://yukicoder.me/problems/no/922</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/forest.cpp.html">森の分解</a>
* :question: <a href="../../../../library/Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp.html">最小共通祖先 (ダブリング)</a>
* :question: <a href="../../../../library/Mylib/Graph/TreeUtils/rerooting.cpp.html">全方位木dp</a>
* :question: <a href="../../../../library/Mylib/Graph/graph_template.cpp.html">グラフ用テンプレート</a>
* :question: <a href="../../../../library/Mylib/Misc/fix_point.cpp.html">不動点コンビネータ</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/922"

#include <iostream>
#include <vector>
#include <utility>

#include "Mylib/Misc/fix_point.cpp"
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp"
#include "Mylib/Graph/TreeUtils/forest.cpp"
#include "Mylib/Graph/TreeUtils/rerooting.cpp"


int main(){
  int N, M, Q; std::cin >> N >> M >> Q;
  
  Graph<int64_t> g(N);
    
  for(int i = 0; i < M; ++i){
    int u, v; std::cin >> u >> v;
    --u, --v;
    add_undirected(g, u, v, 1LL);
  }

  int64_t ans = 0;

  Forest<int64_t> forest(g);

  const int tree_num = forest.trees.size();
  std::vector<LCA<int64_t>> lcas(tree_num);

  for(int i = 0; i < tree_num; ++i){
    lcas[i] = LCA(forest.trees[i], 0);
  }

  std::vector<std::vector<int>> plans(tree_num);
  for(int i = 0; i < tree_num; ++i){
    plans[i] = std::vector<int>(forest.trees[i].size());
  }
    
  for(int i = 0; i < Q; ++i){
    int a, b; std::cin >> a >> b;
    --a, --b;

    if(forest.in_same_tree(a, b)){
      ans += lcas[forest.tree_id[a]].distance(forest.vertex_id[a], forest.vertex_id[b]);
    }else{
      plans[forest.tree_id[a]][forest.vertex_id[a]] += 1;
      plans[forest.tree_id[b]][forest.vertex_id[b]] += 1;
    }
  }

  for(int i = 0; i < tree_num; ++i){
    const auto &tree = forest.trees[i];
    const auto &plan = plans[i];

    auto res =
      make_rerooting<std::pair<int,int>>(
        tree,
        std::make_pair(0, 0),
        [](const auto &a, const auto &b){return std::make_pair(a.first + b.first, a.second + b.second);},
        [&](const auto &x, const auto &e){return std::make_pair(x.first, x.second + x.first);},
        [&](const auto &x, int v){return std::make_pair(x.first + plan[v], x.second);}
      ).result;
      
    ans +=
      std::min_element(
        res.begin(),
        res.end(),
        [](const auto &a, const auto &b){return a.second < b.second;}
      )->second;
  }
    
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/922/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/922"

#include <iostream>
#include <vector>
#include <utility>

#line 3 "Mylib/Misc/fix_point.cpp"

/**
 * @title 不動点コンビネータ
 * @docs fix_point.md
 */
template <typename F>
struct FixPoint : F{
  explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)){}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <typename F>
static inline constexpr decltype(auto) make_fix_point(F &&f){
  return FixPoint<F>(std::forward<F>(f));
}

template <typename F>
static inline constexpr decltype(auto) make_fix_point(F &f){
  return FixPoint<F>(std::forward<F>(f));
}
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

  LCA(){}
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
#line 3 "Mylib/Graph/TreeUtils/forest.cpp"
#include <algorithm>
#line 6 "Mylib/Graph/TreeUtils/forest.cpp"

/**
 * @title 森の分解
 * @docs forest.md
 */
template <typename T>
struct Forest{
  std::vector<Tree<T>> trees;
  std::vector<int> tree_id;
  std::vector<int> vertex_id;
  std::vector<std::vector<int>> rid;

  Forest(const Graph<T> &g){
    const int N = g.size();

    tree_id.resize(N);
    vertex_id.resize(N);

    std::vector<bool> check(N);

    auto dfs =
      [&](auto &dfs, int cur, std::vector<int> &vertices, std::vector<Edge<T>> &edges) -> void{
        check[cur] = true;
        vertices.push_back(cur);

        for(auto &e : g[cur]){
          edges.push_back(e);

          if(not check[e.to]){
            dfs(dfs, e.to, vertices, edges);
          }
        }
      };

    for(int i = 0; i < N; ++i){
      if(not check[i]){
        std::vector<int> vertices;
        std::vector<Edge<T>> edges;
        dfs(dfs, i, vertices, edges);
        
        const int m = vertices.size(); 
        const int k = trees.size();

        rid.push_back(std::vector<int>(m));

        for(int i = 0; i < (int)vertices.size(); ++i){
          tree_id[vertices[i]] = k;
          vertex_id[vertices[i]] = i;
          rid[k][i] = vertices[i];
        }

        trees.push_back(Tree<T>(m));

        for(auto &e : edges){
          trees[k][vertex_id[e.from]].emplace_back(vertex_id[e.from], vertex_id[e.to], e.cost);
        }
      }
    }
  }
  
  bool in_same_tree(int i, int j) const {
    return tree_id[i] == tree_id[j];
  }
};
#line 4 "Mylib/Graph/TreeUtils/rerooting.cpp"

/**
 * @title 全方位木dp
 * @docs rerooting.md
 */

template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
struct Rerooting{
  int N;
  T tree;
  U id;
  Merge merge;
  EdgeF f;
  VertexF g;
  
  std::vector<std::vector<U>> dp;
  std::vector<U> result;
  
  Rerooting(T tree, U id, Merge merge, EdgeF f, VertexF g):
    N(tree.size()), tree(tree), id(id), merge(merge), f(f), g(g), dp(N), result(N, id)
  {
    for(int i = 0; i < N; ++i) dp[i].assign((int)tree[i].size(), id);
    rec1(0);
    rec2(0, -1, id);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < (int)tree[i].size(); ++j){
        result[i] = merge(result[i], f(dp[i][j], tree[i][j]));
      }
      
      result[i] = g(result[i], i);
    }
  }

  U rec1(int cur, int par = -1){
    U acc = id;
    
    for(int i = 0; i < (int)tree[cur].size(); ++i){
      auto &e = tree[cur][i];
      if(e.to == par) continue;
      dp[cur][i] = rec1(e.to, cur);
      acc = merge(acc, f(dp[cur][i], e));
    }

    return g(acc, cur);
  }

  void rec2(int cur, int par, U value){
    const int l = tree[cur].size();

    for(int i = 0; i < l; ++i){
      if(tree[cur][i].to == par){
        dp[cur][i] = value;
      }
    }

    std::vector<U> left(l+1, id), right(l+1, id);

    for(int i = 0; i < l-1; ++i){
      const auto &e = tree[cur][i];
      left[i+1] = merge(left[i], f(dp[cur][i], e));
    }

    for(int i = l-1; i >= 1; --i){
      const auto &e = tree[cur][i];
      right[i-1] = merge(right[i], f(dp[cur][i], e));
    }

    for(int i = 0; i < l; ++i){
      const auto &e = tree[cur][i];
      if(e.to == par) continue;

      rec2(e.to, cur, g(merge(left[i], right[i]), cur));
    }
  }
};

template <typename T, typename G, typename Merge, typename EdgeF, typename VertexF>
auto make_rerooting(const G &tree, T id, Merge merge, EdgeF f, VertexF g){
  return Rerooting<G,T,Merge,EdgeF,VertexF>(tree, id, merge, f, g);
}
#line 12 "test/yukicoder/922/main.test.cpp"


int main(){
  int N, M, Q; std::cin >> N >> M >> Q;
  
  Graph<int64_t> g(N);
    
  for(int i = 0; i < M; ++i){
    int u, v; std::cin >> u >> v;
    --u, --v;
    add_undirected(g, u, v, 1LL);
  }

  int64_t ans = 0;

  Forest<int64_t> forest(g);

  const int tree_num = forest.trees.size();
  std::vector<LCA<int64_t>> lcas(tree_num);

  for(int i = 0; i < tree_num; ++i){
    lcas[i] = LCA(forest.trees[i], 0);
  }

  std::vector<std::vector<int>> plans(tree_num);
  for(int i = 0; i < tree_num; ++i){
    plans[i] = std::vector<int>(forest.trees[i].size());
  }
    
  for(int i = 0; i < Q; ++i){
    int a, b; std::cin >> a >> b;
    --a, --b;

    if(forest.in_same_tree(a, b)){
      ans += lcas[forest.tree_id[a]].distance(forest.vertex_id[a], forest.vertex_id[b]);
    }else{
      plans[forest.tree_id[a]][forest.vertex_id[a]] += 1;
      plans[forest.tree_id[b]][forest.vertex_id[b]] += 1;
    }
  }

  for(int i = 0; i < tree_num; ++i){
    const auto &tree = forest.trees[i];
    const auto &plan = plans[i];

    auto res =
      make_rerooting<std::pair<int,int>>(
        tree,
        std::make_pair(0, 0),
        [](const auto &a, const auto &b){return std::make_pair(a.first + b.first, a.second + b.second);},
        [&](const auto &x, const auto &e){return std::make_pair(x.first, x.second + x.first);},
        [&](const auto &x, int v){return std::make_pair(x.first + plan[v], x.second);}
      ).result;
      
    ans +=
      std::min_element(
        res.begin(),
        res.end(),
        [](const auto &a, const auto &b){return a.second < b.second;}
      )->second;
  }
    
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

