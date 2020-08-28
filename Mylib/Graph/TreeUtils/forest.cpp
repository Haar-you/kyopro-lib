#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Decompose forest
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
