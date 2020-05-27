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
    - Last commit date: 2020-05-02 14:18:42+09:00




## Required by

* :heavy_check_mark: <a href="BipartiteGraph/check_bipartite_graph.cpp.html">二部グラフ判定</a>
* :warning: <a href="EulerianPath/directed_eulerian_path.cpp.html">有向Euler路</a>
* :warning: <a href="EulerianPath/undirected_eulerian_path.cpp.html">無向Euler路</a>
* :heavy_check_mark: <a href="GraphUtils/articulation_points.cpp.html">間接点列挙</a>
* :heavy_check_mark: <a href="GraphUtils/bridges.cpp.html">橋列挙</a>
* :warning: <a href="GraphUtils/decompose_pseudotree.cpp.html">Pseudotreeの分解</a>
* :heavy_check_mark: <a href="GraphUtils/strongly_connected_components.cpp.html">強連結成分分解</a>
* :heavy_check_mark: <a href="GraphUtils/two_edge_connected_components.cpp.html">二重辺連結成分分解</a>
* :heavy_check_mark: <a href="MinimumSpanningTree/chu_liu_edmonds.cpp.html">Chu-Liu/Edmonds</a>
* :heavy_check_mark: <a href="MinimumSpanningTree/kruskal.cpp.html">Kruskal法</a>
* :heavy_check_mark: <a href="MinimumSpanningTree/prim.cpp.html">Prim法</a>
* :warning: <a href="ShortestCycle/directed_shortest_cycle.cpp.html">有向グラフの最小閉路</a>
* :warning: <a href="ShortestCycle/undirected_shortest_cycle.cpp.html">無向グラフの最小閉路</a>
* :heavy_check_mark: <a href="ShortestPath/bellman_ford.cpp.html">Bellman-Ford法</a>
* :warning: <a href="ShortestPath/bfs_0_1.cpp.html">0-1 BFS</a>
* :heavy_check_mark: <a href="ShortestPath/bfs_shortest_path.cpp.html">BFS最短路</a>
* :heavy_check_mark: <a href="ShortestPath/dijkstra.cpp.html">Dijkstra法</a>
* :heavy_check_mark: <a href="ShortestPath/warshall_floyd.cpp.html">Warshall-Floyd法</a>
* :heavy_check_mark: <a href="TopologicalSort/topological_sort.cpp.html">トポロジカルソート</a>
* :warning: <a href="TopologicalSort/topological_sort_lexicographical.cpp.html">トポロジカルソート (辞書順最小)</a>
* :warning: <a href="TreeUtils/centroid.cpp.html">重心列挙</a>
* :warning: <a href="TreeUtils/centroid_decomposition.cpp.html">重心分解</a>
* :heavy_check_mark: <a href="TreeUtils/euler_tour_bfs.cpp.html">BFSEulerTour</a>
* :heavy_check_mark: <a href="TreeUtils/euler_tour_vertex.cpp.html">頂点EulerTour</a>
* :heavy_check_mark: <a href="TreeUtils/forest.cpp.html">森の分解</a>
* :heavy_check_mark: <a href="TreeUtils/heavy_light_decomposition.cpp.html">HL分解</a>
* :heavy_check_mark: <a href="TreeUtils/lca_based_on_doubling.cpp.html">最小共通祖先 (ダブリング)</a>
* :heavy_check_mark: <a href="TreeUtils/lca_based_on_hld.cpp.html">最小共通祖先 (HLD)</a>
* :heavy_check_mark: <a href="TreeUtils/rerooting.cpp.html">全方位木dp</a>
* :warning: <a href="TreeUtils/rooting.cpp.html">根付き木</a>
* :heavy_check_mark: <a href="TreeUtils/tree_diameter.cpp.html">木の直径</a>
* :heavy_check_mark: <a href="TreeUtils/tree_distance.cpp.html">木の距離</a>
* :heavy_check_mark: <a href="TreeUtils/tree_height.cpp.html">木の高さ</a>
* :heavy_check_mark: <a href="chinese_postman_problem.cpp.html">中国人郵便配達問題</a>
* :heavy_check_mark: <a href="travelling_salesman_problem.cpp.html">巡回セールスマン問題</a>
* :heavy_check_mark: <a href="two_sat.cpp.html">2-SAT</a>
* :heavy_check_mark: <a href="../Grid/grid_to_graph.cpp.html">グリッドをグラフに変換する</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0558/main.graph.test.cpp.html">test/aoj/0558/main.graph.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/0575/main.test.cpp.html">test/aoj/0575/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1595/main.test.cpp.html">test/aoj/1595/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2370/main.test.cpp.html">test/aoj/2370/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.binomial_heap.test.cpp.html">test/aoj/2559/main.binomial_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.leftist_heap.test.cpp.html">test/aoj/2559/main.leftist_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.skew_heap.test.cpp.html">test/aoj/2559/main.skew_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2667/main.test.cpp.html">test/aoj/2667/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_2_A/main.test.cpp.html">test/aoj/DPL_2_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_2_B/main.test.cpp.html">test/aoj/DPL_2_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_A/main.test.cpp.html">test/aoj/GRL_1_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_B/main.test.cpp.html">test/aoj/GRL_1_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_C/main.test.cpp.html">test/aoj/GRL_1_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_A/main.kruskal.test.cpp.html">test/aoj/GRL_2_A/main.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_A/main.prim.test.cpp.html">test/aoj/GRL_2_A/main.prim.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_B/main.test.cpp.html">test/aoj/GRL_2_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_A/main.test.cpp.html">test/aoj/GRL_3_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_B/main.test.cpp.html">test/aoj/GRL_3_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_C/main.test.cpp.html">test/aoj/GRL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_A/main.test.cpp.html">test/aoj/GRL_5_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_B/main.test.cpp.html">test/aoj/GRL_5_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_C/main.doubling.test.cpp.html">test/aoj/GRL_5_C/main.doubling.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_C/main.hld.test.cpp.html">test/aoj/GRL_5_C/main.hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/scc/main.test.cpp.html">test/yosupo-judge/scc/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/tree_diameter/main.test.cpp.html">test/yosupo-judge/tree_diameter/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/two_edge_connected_components/main.test.cpp.html">test/yosupo-judge/two_edge_connected_components/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/two_sat/main.test.cpp.html">test/yosupo-judge/two_sat/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_add_path_sum/main.test.cpp.html">test/yosupo-judge/vertex_add_path_sum/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1030/main.test.cpp.html">test/yukicoder/1030/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/899/main.test.cpp.html">test/yukicoder/899/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/922/main.test.cpp.html">test/yukicoder/922/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

