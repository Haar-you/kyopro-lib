#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  class forest {
    std::vector<tree<T>> trees_;
    std::vector<int> tree_id_, vertex_id_;
    std::vector<std::vector<int>> rid_;

  public:
    forest(){}
    forest(const graph<T> &g){
      const int N = g.size();

      tree_id_.resize(N);
      vertex_id_.resize(N);

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
          const int k = trees_.size();

          rid_.emplace_back(m);

          for(int i = 0; i < (int)vertices.size(); ++i){
            tree_id_[vertices[i]] = k;
            vertex_id_[vertices[i]] = i;
            rid_[k][i] = vertices[i];
          }

          trees_.push_back(m);

          for(auto &e : edges){
            trees_[k].add_edge(vertex_id_[e.from], vertex_id_[e.to], e.cost);
          }
        }
      }
    }

    const auto& trees() const {return trees_;}
    auto id(int i) const {return std::make_pair(tree_id_[i], vertex_id_[i]);}
    int tree_id(int i) const {return tree_id_[i];}
    int vertex_id(int i) const {return vertex_id_[i];}
    int rid(int t, int u) const {return rid_[t][u];}

    bool in_same_tree(int i, int j) const {
      return tree_id_[i] == tree_id_[j];
    }
  };
}
