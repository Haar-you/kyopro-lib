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
    - Last commit date: 2020-09-10 18:36:08+09:00


* see: <a href="https://yukicoder.me/problems/no/922">https://yukicoder.me/problems/no/922</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Graph/Template/graph.cpp.html">Basic graph</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/forest.cpp.html">Decompose forest</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/lca_doubling.cpp.html">Lowest common ancestor (Doubling)</a>
* :question: <a href="../../../../library/Mylib/Graph/TreeUtils/rerooting.cpp.html">Rerooting DP</a>
* :x: <a href="../../../../library/Mylib/Graph/TreeUtils/tree_distance.cpp.html">Tree distance</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/922"

#include <iostream>
#include <vector>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/lca_doubling.cpp"
#include "Mylib/Graph/TreeUtils/forest.cpp"
#include "Mylib/Graph/TreeUtils/rerooting.cpp"
#include "Mylib/Graph/TreeUtils/tree_distance.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int N, M, Q; std::cin >> N >> M >> Q;

  hl::graph<int64_t> g(N);
  g.read<1, false, false>(M);

  int64_t ans = 0;

  hl::forest<int64_t> forest(g);

  const int tree_num = forest.trees.size();
  std::vector<hl::lowest_common_ancestor_doubling<int64_t>> lcas(tree_num);
  std::vector<std::vector<int64_t>> dists(tree_num);

  for(int i = 0; i < tree_num; ++i){
    lcas[i] = hl::lowest_common_ancestor_doubling(forest.trees[i], 0);
    dists[i] = hl::tree_distance(forest.trees[i], 0);
  }

  std::vector<std::vector<int>> plans(tree_num);
  for(int i = 0; i < tree_num; ++i){
    plans[i] = std::vector<int>(forest.trees[i].size());
  }

  for(auto [a, b] : hl::input_tuples<int, int>(Q)){
    --a, --b;

    if(forest.in_same_tree(a, b)){
      ans += lcas[forest.tree_id[a]].distance(forest.vertex_id[a], forest.vertex_id[b], dists[forest.tree_id[a]]);
    }else{
      plans[forest.tree_id[a]][forest.vertex_id[a]] += 1;
      plans[forest.tree_id[b]][forest.vertex_id[b]] += 1;
    }
  }

  for(int i = 0; i < tree_num; ++i){
    const auto &tree = forest.trees[i];
    const auto &plan = plans[i];

    auto res =
      hl::rerooting<std::pair<int, int>>(
        tree,
        std::make_pair(0, 0),
        [](const auto &a, const auto &b){
          return std::make_pair(a.first + b.first, a.second + b.second);
        },
        [](const auto &x, const auto &e){
          return std::make_pair(x.first, x.second + x.first);
        },
        [&](const auto &x, int v){
          return std::make_pair(x.first + plan[v], x.second);
        }
      );

    ans +=
      std::min_element(
        res.begin(),
        res.end(),
        [](const auto &a, const auto &b){
          return a.second < b.second;
        }
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
#line 4 "Mylib/Graph/Template/graph.cpp"

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
#line 3 "Mylib/Graph/TreeUtils/lca_doubling.cpp"
#include <cmath>
#line 5 "Mylib/Graph/TreeUtils/lca_doubling.cpp"

/**
 * @title Lowest common ancestor (Doubling)
 * @docs lca_doubling.md
 */
namespace haar_lib {
  template <typename T>
  class lowest_common_ancestor_doubling {
  private:
    std::vector<std::vector<int>> parent;
    int n, log2n;

    void dfs(const tree<T> &tr, int cur, int par, int d){
      parent[cur][0] = par;
      depth[cur] = d;

      for(auto &e : tr[cur]){
        if(e.to != par){
          dfs(tr, e.to, cur, d + 1);
        }
      }
    }

  public:
    std::vector<int> depth;

    lowest_common_ancestor_doubling(){}
    lowest_common_ancestor_doubling(const tree<T> &tr, int root):
      n(tr.size()), depth(n)
    {
      log2n = (int)ceil(log2(n)) + 1;
      parent = std::vector(n, std::vector<int>(log2n, 0));

      dfs(tr, root, -1, 0);
      for(int k = 0; k < log2n - 1; ++k){
        for(int v = 0; v < n; ++v){
          if(parent[v][k] == -1) parent[v][k + 1] = -1;
          else parent[v][k + 1] = parent[parent[v][k]][k];
        }
      }
    }

    int lca(int a, int b) const {
      if(depth[a] >= depth[b]) std::swap(a, b);
      for(int k = 0; k < log2n; ++k){
        if((depth[b] - depth[a]) >> k & 1) b = parent[b][k];
      }
      if(a == b) return a;
      for(int k = log2n; --k >= 0;){
        if(parent[a][k] != parent[b][k]){a = parent[a][k]; b = parent[b][k];}
      }
      return parent[a][0];
    }

    int operator()(int a, int b) const {return lca(a, b);}

    T distance(int u, int v, const std::vector<T> &dist) const {
      return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }
  };
}
#line 3 "Mylib/Graph/TreeUtils/forest.cpp"
#include <algorithm>
#line 6 "Mylib/Graph/TreeUtils/forest.cpp"

/**
 * @title Decompose forest
 * @docs forest.md
 */
namespace haar_lib {
  template <typename T>
  struct forest {
    std::vector<tree<T>> trees;
    std::vector<int> tree_id;
    std::vector<int> vertex_id;
    std::vector<std::vector<int>> rid;

    forest(const graph<T> &g){
      const int N = g.size();

      tree_id.resize(N);
      vertex_id.resize(N);

      std::vector<bool> check(N);

      auto dfs =
        [&](auto &dfs, int cur, std::vector<int> &vertices, std::vector<edge<T>> &edges) -> void {
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
          std::vector<edge<T>> edges;
          dfs(dfs, i, vertices, edges);

          const int m = vertices.size();
          const int k = trees.size();

          rid.emplace_back(m);

          for(int i = 0; i < (int)vertices.size(); ++i){
            tree_id[vertices[i]] = k;
            vertex_id[vertices[i]] = i;
            rid[k][i] = vertices[i];
          }

          trees.push_back(m);

          for(auto &e : edges){
            trees[k].add_edge(vertex_id[e.from], vertex_id[e.to], e.cost);
          }
        }
      }
    }

    bool in_same_tree(int i, int j) const {
      return tree_id[i] == tree_id[j];
    }
  };
}
#line 4 "Mylib/Graph/TreeUtils/rerooting.cpp"

/**
 * @title Rerooting DP
 * @docs rerooting.md
 */
namespace haar_lib {
  namespace rerooting_impl {
    template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
    T rec1(
      tree<U> &tr,
      T id,
      const Merge &merge,
      const EdgeF &f,
      const VertexF &g,
      std::vector<std::vector<T>> &dp,
      int cur,
      int par = -1
    ){
      T acc = id;

      for(int i = 0; i < (int)tr[cur].size(); ++i){
        auto &e = tr[cur][i];
        if(e.to == par) continue;
        dp[cur][i] = rec1(tr, id, merge, f, g, dp, e.to, cur);
        acc = merge(acc, f(dp[cur][i], e));
      }

      return g(acc, cur);
    }

    template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
    void rec2(
      const tree<U> &tr,
      T id,
      const Merge &merge,
      const EdgeF &f,
      const VertexF &g,
      std::vector<std::vector<T>> &dp,
      int cur,
      int par,
      T value
    ){
      const int l = tr[cur].size();

      for(int i = 0; i < l; ++i){
        if(tr[cur][i].to == par){
          dp[cur][i] = value;
        }
      }

      std::vector<T> left(l + 1, id), right(l + 1, id);

      for(int i = 0; i < l - 1; ++i){
        const auto &e = tr[cur][i];
        left[i + 1] = merge(left[i], f(dp[cur][i], e));
      }

      for(int i = l - 1; i >= 1; --i){
        const auto &e = tr[cur][i];
        right[i - 1] = merge(right[i], f(dp[cur][i], e));
      }

      for(int i = 0; i < l; ++i){
        const auto &e = tr[cur][i];
        if(e.to == par) continue;

        rec2(tr, id, merge, f, g, dp, e.to, cur, g(merge(left[i], right[i]), cur));
      }
    }
  }

  template <typename T, typename U, typename Merge, typename EdgeF, typename VertexF>
  auto rerooting(tree<U> tr, T id, Merge merge, EdgeF f, VertexF g){
    const int N = tr.size();
    std::vector<std::vector<T>> dp(N);
    std::vector<T> ret(N, id);

    for(int i = 0; i < N; ++i) dp[i].assign(tr[i].size(), id);
    rerooting_impl::rec1(tr, id, merge, f, g, dp, 0);
    rerooting_impl::rec2(tr, id, merge, f, g, dp, 0, -1, id);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < (int)tr[i].size(); ++j){
        ret[i] = merge(ret[i], f(dp[i][j], tr[i][j]));
      }

      ret[i] = g(ret[i], i);
    }

    return ret;
  }
}
#line 3 "Mylib/Graph/TreeUtils/tree_distance.cpp"
#include <stack>
#line 5 "Mylib/Graph/TreeUtils/tree_distance.cpp"

/**
 * @title Tree distance
 * @docs tree_distance.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<T> tree_distance(const tree<T> &tr, int root){
    const int n = tr.size();
    std::vector<T> ret(n);
    std::vector<bool> visited(n);

    std::stack<int> st;
    st.push(root);
    ret[root] = 0;

    while(not st.empty()){
      int cur = st.top(); st.pop();
      visited[cur] = true;

      for(auto &e : tr[cur]){
        if(not visited[e.to]){
          ret[e.to] = ret[cur] + e.cost;
          st.push(e.to);
        }
      }
    }

    return ret;
  }
}
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
namespace haar_lib {
  template <typename T, size_t ... I>
  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
  }

  template <typename T, typename U>
  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
    s >> value.first >> value.second;
    return s;
  }

  template <typename ... Args>
  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
    return s;
  }
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
namespace haar_lib {
  template <typename ... Args>
  class InputTuples {
    struct iter {
      using value_type = std::tuple<Args ...>;
      value_type value;
      bool fetched = false;
      int N, c = 0;

      value_type operator*(){
        if(not fetched){
          std::cin >> value;
        }
        return value;
      }

      void operator++(){
        ++c;
        fetched = false;
      }

      bool operator!=(iter &) const {
        return c < N;
      }

      iter(int N): N(N){}
    };

    int N;

  public:
    InputTuples(int N): N(N){}

    iter begin() const {return iter(N);}
    iter end() const {return iter(N);}
  };

  template <typename ... Args>
  auto input_tuples(int N){
    return InputTuples<Args ...>(N);
  }
}
#line 12 "test/yukicoder/922/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int N, M, Q; std::cin >> N >> M >> Q;

  hl::graph<int64_t> g(N);
  g.read<1, false, false>(M);

  int64_t ans = 0;

  hl::forest<int64_t> forest(g);

  const int tree_num = forest.trees.size();
  std::vector<hl::lowest_common_ancestor_doubling<int64_t>> lcas(tree_num);
  std::vector<std::vector<int64_t>> dists(tree_num);

  for(int i = 0; i < tree_num; ++i){
    lcas[i] = hl::lowest_common_ancestor_doubling(forest.trees[i], 0);
    dists[i] = hl::tree_distance(forest.trees[i], 0);
  }

  std::vector<std::vector<int>> plans(tree_num);
  for(int i = 0; i < tree_num; ++i){
    plans[i] = std::vector<int>(forest.trees[i].size());
  }

  for(auto [a, b] : hl::input_tuples<int, int>(Q)){
    --a, --b;

    if(forest.in_same_tree(a, b)){
      ans += lcas[forest.tree_id[a]].distance(forest.vertex_id[a], forest.vertex_id[b], dists[forest.tree_id[a]]);
    }else{
      plans[forest.tree_id[a]][forest.vertex_id[a]] += 1;
      plans[forest.tree_id[b]][forest.vertex_id[b]] += 1;
    }
  }

  for(int i = 0; i < tree_num; ++i){
    const auto &tree = forest.trees[i];
    const auto &plan = plans[i];

    auto res =
      hl::rerooting<std::pair<int, int>>(
        tree,
        std::make_pair(0, 0),
        [](const auto &a, const auto &b){
          return std::make_pair(a.first + b.first, a.second + b.second);
        },
        [](const auto &x, const auto &e){
          return std::make_pair(x.first, x.second + x.first);
        },
        [&](const auto &x, int v){
          return std::make_pair(x.first + plan[v], x.second);
        }
      );

    ans +=
      std::min_element(
        res.begin(),
        res.end(),
        [](const auto &a, const auto &b){
          return a.second < b.second;
        }
      )->second;
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

