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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: グラフ用テンプレート

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/graph_template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00




## Required by

* :warning: <a href="BipartiteGraph/check_bipartite_graph.cpp.html">連結グラフの二部グラフ判定</a>
* :warning: <a href="BipartiteGraph/check_bipartite_graph_disconnected.cpp.html">非連結グラフの二部グラフ判定</a>
* :warning: <a href="EulerianPath/directed_eulerian_path.cpp.html">有向Euler路</a>
* :warning: <a href="EulerianPath/undirected_eulerian_path.cpp.html">無向Euler路</a>
* :heavy_check_mark: <a href="GraphUtils/articulation_points.cpp.html">間接点列挙</a>
* :heavy_check_mark: <a href="GraphUtils/bridges.cpp.html">橋列挙</a>
* :warning: <a href="GraphUtils/decompose_pseudotree.cpp.html">Pseudotreeの分解</a>
* :heavy_check_mark: <a href="GraphUtils/strongly_connected_components.cpp.html">強連結成分分解</a>
* :heavy_check_mark: <a href="GraphUtils/two_edge_connected_components.cpp.html">二重辺連結成分分解</a>
* :heavy_check_mark: <a href="MinimumSpanningTree/kruskal.cpp.html">Kruskal法</a>
* :heavy_check_mark: <a href="MinimumSpanningTree/prim.cpp.html">Prim法</a>
* :warning: <a href="ShortestCycle/directed_shortest_cycle.cpp.html">有向グラフの最小閉路</a>
* :warning: <a href="ShortestCycle/undirected_shortest_cycle.cpp.html">無向グラフの最小閉路</a>
* :heavy_check_mark: <a href="ShortestPath/bellman_ford.cpp.html">Bellman-Ford法</a>
* :warning: <a href="ShortestPath/bfs_0_1.cpp.html">0-1 BFS</a>
* :warning: <a href="ShortestPath/bfs_shortest_path.cpp.html">BFS最小路</a>
* :heavy_check_mark: <a href="ShortestPath/dijkstra.cpp.html">Dijkstra法</a>
* :heavy_check_mark: <a href="ShortestPath/warshall_floyd.cpp.html">Warshall-Floyd法</a>
* :heavy_check_mark: <a href="TopologicalSort/topological_sort.cpp.html">トポロジカルソート</a>
* :warning: <a href="TopologicalSort/topological_sort_lexicographical.cpp.html">辞書順最小のトポロジカルソート</a>
* :warning: <a href="TreeUtils/centroid.cpp.html">重心列挙</a>
* :warning: <a href="TreeUtils/centroid_decomposition.cpp.html">重心分解</a>
* :warning: <a href="TreeUtils/euler_tour_bfs.cpp.html">BFS Euler tour</a>
* :heavy_check_mark: <a href="TreeUtils/euler_tour_vertex.cpp.html">頂点Euler tour</a>
* :warning: <a href="TreeUtils/forest.cpp.html">Mylib/Graph/TreeUtils/forest.cpp</a>
* :heavy_check_mark: <a href="TreeUtils/heavy_light_decomposition.cpp.html">重軽分解</a>
* :heavy_check_mark: <a href="TreeUtils/lca_based_on_doubling.cpp.html">ダブリング実装の最小共通祖先</a>
* :heavy_check_mark: <a href="TreeUtils/lca_based_on_hld.cpp.html">HLD実装の最小共通祖先</a>
* :warning: <a href="TreeUtils/rooting.cpp.html">根付き木</a>
* :heavy_check_mark: <a href="TreeUtils/tree_utils.cpp.html">Mylib/Graph/TreeUtils/tree_utils.cpp</a>
* :heavy_check_mark: <a href="chinese_postman_problem.cpp.html">中国人郵便配達問題</a>
* :heavy_check_mark: <a href="travelling_salesman_problem.cpp.html">巡回セールスマン問題</a>
* :heavy_check_mark: <a href="two_sat.cpp.html">2-SAT</a>
* :warning: <a href="../Grid/grid_to_graph.cpp.html">グリッドをグラフに変換する</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2667/main.test.cpp.html">test/aoj/2667/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_2_A/main.test.cpp.html">test/aoj/DPL_2_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_2_B/main.test.cpp.html">test/aoj/DPL_2_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_A/main.test.cpp.html">test/aoj/GRL_1_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_B/main.test.cpp.html">test/aoj/GRL_1_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_C/main.test.cpp.html">test/aoj/GRL_1_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_A/main.kruskal.test.cpp.html">test/aoj/GRL_2_A/main.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_A/main.prim.test.cpp.html">test/aoj/GRL_2_A/main.prim.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_A/main.test.cpp.html">test/aoj/GRL_3_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_B/main.test.cpp.html">test/aoj/GRL_3_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_C/main.test.cpp.html">test/aoj/GRL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_A/main.test.cpp.html">test/aoj/GRL_5_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_B/main.test.cpp.html">test/aoj/GRL_5_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_C/main.doubling.test.cpp.html">test/aoj/GRL_5_C/main.doubling.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_C/main.hld.test.cpp.html">test/aoj/GRL_5_C/main.hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/scc/main.test.cpp.html">test/yosupo-judge/scc/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/two_edge_connected_components/main.test.cpp.html">test/yosupo-judge/two_edge_connected_components/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/two_sat/main.test.cpp.html">test/yosupo-judge/two_sat/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_add_path_sum/main.test.cpp.html">test/yosupo-judge/vertex_add_path_sum/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
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

  Edge rev() const {return Edge(to,from,cost);}
  
  friend std::ostream& operator<<(std::ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].emplace_back(from, to, w);
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  add_edge(g, a, b, w);
  add_edge(g, b, a, w);
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

  Edge rev() const {return Edge(to,from,cost);}
  
  friend std::ostream& operator<<(std::ostream &os, const Edge &e){
    os << "(FROM: " << e.from << "," << "TO: " << e.to << "," << "COST: " << e.cost << ")";
    return os;
  }
};

template <typename T> using Graph = std::vector<std::vector<Edge<T>>>;
template <typename T> using Tree = std::vector<std::vector<Edge<T>>>;

template <typename C, typename T> void add_edge(C &g, int from, int to, T w){
  g[from].emplace_back(from, to, w);
}

template <typename C, typename T> void add_undirected(C &g, int a, int b, T w){
  add_edge(g, a, b, w);
  add_edge(g, b, a, w);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

