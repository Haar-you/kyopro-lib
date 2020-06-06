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


# :question: Graph template

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#791a56799ce3ef8e4fb5da8cbce3a9bf">Mylib/Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/graph_template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Required by

* :heavy_check_mark: <a href="BipartiteGraph/check_bipartite_graph.cpp.html">Check bipartite graph</a>
* :warning: <a href="EulerianPath/directed_eulerian_path.cpp.html">Directed Eulerian path</a>
* :warning: <a href="EulerianPath/undirected_eulerian_path.cpp.html">Undirected Eulerian path</a>
* :x: <a href="GraphUtils/articulation_points.cpp.html">Articulation points</a>
* :x: <a href="GraphUtils/bridges.cpp.html">Bridges</a>
* :warning: <a href="GraphUtils/decompose_pseudotree.cpp.html">Decompose pseudotree</a>
* :x: <a href="GraphUtils/strongly_connected_components.cpp.html">Strongly connected components</a>
* :x: <a href="GraphUtils/two_edge_connected_components.cpp.html">Two edge connected components</a>
* :x: <a href="MinimumSpanningTree/chu_liu_edmonds.cpp.html">Chu-Liu/Edmonds algorithm</a>
* :x: <a href="MinimumSpanningTree/kruskal.cpp.html">Kruskal algorithm</a>
* :question: <a href="MinimumSpanningTree/prim.cpp.html">Prim algorithm</a>
* :warning: <a href="ShortestCycle/directed_shortest_cycle.cpp.html">Directed shortest cycle</a>
* :warning: <a href="ShortestCycle/undirected_shortest_cycle.cpp.html">Undirected shortest cycle</a>
* :x: <a href="ShortestPath/bellman_ford.cpp.html">Bellman-Ford algorithm</a>
* :warning: <a href="ShortestPath/bfs_0_1.cpp.html">0-1 BFS</a>
* :heavy_check_mark: <a href="ShortestPath/bfs_shortest_path.cpp.html">BFS shortest path</a>
* :x: <a href="ShortestPath/dijkstra.cpp.html">Dijkstra algorithm</a>
* :x: <a href="ShortestPath/warshall_floyd.cpp.html">Warshall-Floyd algorithm</a>
* :x: <a href="ShortestPath/yen_algorithm.cpp.html">Yen's algorithm</a>
* :x: <a href="TopologicalSort/topological_sort.cpp.html">Topological sort</a>
* :warning: <a href="TopologicalSort/topological_sort_lexicographical.cpp.html">Topological sort (Lexicographically minimum)</a>
* :warning: <a href="TreeUtils/centroid.cpp.html">Enumerate centroids</a>
* :warning: <a href="TreeUtils/centroid_decomposition.cpp.html">Centroid decomposition</a>
* :x: <a href="TreeUtils/euler_tour_bfs.cpp.html">Euler tour (BFS)</a>
* :x: <a href="TreeUtils/euler_tour_vertex.cpp.html">Euler tour (Vertex)</a>
* :x: <a href="TreeUtils/forest.cpp.html">Decompose forest</a>
* :question: <a href="TreeUtils/heavy_light_decomposition.cpp.html">Heavy-light decomposition</a>
* :x: <a href="TreeUtils/lca_based_on_doubling.cpp.html">Lowest common ancestor (Doubling)</a>
* :x: <a href="TreeUtils/lca_based_on_hld.cpp.html">Lowest common ancestor (HLD)</a>
* :question: <a href="TreeUtils/rerooting.cpp.html">Rerooting DP</a>
* :warning: <a href="TreeUtils/rooting.cpp.html">Rooting</a>
* :x: <a href="TreeUtils/tree_diameter.cpp.html">Tree diameter</a>
* :x: <a href="TreeUtils/tree_distance.cpp.html">Tree distance</a>
* :x: <a href="TreeUtils/tree_height.cpp.html">Tree height</a>
* :x: <a href="chinese_postman_problem.cpp.html">Chinese postman problem</a>
* :x: <a href="travelling_salesman_problem.cpp.html">Travelling salesman problem</a>
* :x: <a href="two_sat.cpp.html">2-SAT</a>
* :heavy_check_mark: <a href="../Grid/grid_to_graph.cpp.html">Convert grid to graph</a>
* :question: <a href="../IO/input_graph.cpp.html">Mylib/IO/input_graph.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0558/main.graph.test.cpp.html">test/aoj/0558/main.graph.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/0575/main.test.cpp.html">test/aoj/0575/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1595/main.test.cpp.html">test/aoj/1595/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2370/main.test.cpp.html">test/aoj/2370/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.binomial_heap.test.cpp.html">test/aoj/2559/main.binomial_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.leftist_heap.test.cpp.html">test/aoj/2559/main.leftist_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.skew_heap.test.cpp.html">test/aoj/2559/main.skew_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2667/main.test.cpp.html">test/aoj/2667/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DPL_2_A/main.test.cpp.html">test/aoj/DPL_2_A/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DPL_2_B/main.test.cpp.html">test/aoj/DPL_2_B/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_1_A/main.test.cpp.html">test/aoj/GRL_1_A/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_1_B/main.test.cpp.html">test/aoj/GRL_1_B/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_1_C/main.test.cpp.html">test/aoj/GRL_1_C/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_2_A/main.kruskal.test.cpp.html">test/aoj/GRL_2_A/main.kruskal.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_2_A/main.prim.test.cpp.html">test/aoj/GRL_2_A/main.prim.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_2_B/main.test.cpp.html">test/aoj/GRL_2_B/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_3_A/main.test.cpp.html">test/aoj/GRL_3_A/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_3_B/main.test.cpp.html">test/aoj/GRL_3_B/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_3_C/main.test.cpp.html">test/aoj/GRL_3_C/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_5_A/main.test.cpp.html">test/aoj/GRL_5_A/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_5_B/main.test.cpp.html">test/aoj/GRL_5_B/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_5_C/main.doubling.test.cpp.html">test/aoj/GRL_5_C/main.doubling.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/GRL_5_C/main.hld.test.cpp.html">test/aoj/GRL_5_C/main.hld.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/scc/main.test.cpp.html">test/yosupo-judge/scc/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/tree_diameter/main.test.cpp.html">test/yosupo-judge/tree_diameter/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/two_edge_connected_components/main.test.cpp.html">test/yosupo-judge/two_edge_connected_components/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/two_sat/main.test.cpp.html">test/yosupo-judge/two_sat/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_add_path_sum/main.test.cpp.html">test/yosupo-judge/vertex_add_path_sum/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/1030/main.test.cpp.html">test/yukicoder/1030/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/1069/main.test.cpp.html">test/yukicoder/1069/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/899/main.test.cpp.html">test/yukicoder/899/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/922/main.test.cpp.html">test/yukicoder/922/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <iostream>

/**
 * @title Graph template
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
 * @title Graph template
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

