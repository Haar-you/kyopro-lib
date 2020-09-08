#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Articulation points
 * @docs articulation_points.md
 */
namespace haar_lib {
  namespace articulation_points_impl {
    template <typename T>
    int dfs(
      const Graph<T> &graph,
      int root,
      int cur,
      std::vector<int> &visit,
      std::vector<int> &low,
      std::vector<int> &ret,
      int &v
    ){
      if(visit[cur] != -1) return visit[cur];
      visit[cur] = v;

      int temp = v;
      std::vector<int> children;
      ++v;

      for(auto &e : graph[cur]){
        if(visit[e.to] == -1) children.push_back(e.to);
        int t = dfs(graph, root, e.to, visit, low, ret, v);
        temp = std::min(temp, t);
      }

      low[cur] = temp;

      if(cur != root or children.size() >= 2){
        for(auto x : children){
          if(low[x] >= visit[cur]){
            ret.push_back(cur);
            break;
          }
        }
      }

      return low[cur];
    };
  }

  template <typename T>
  std::vector<int> articulation_points(const Graph<T> &graph){
    const int n = graph.size();
    std::vector<int> visit(n, -1), low(n, -1), ret;
    int v = 0;

    for(int i = 0; i < n; ++i){
      if(visit[i] == -1){
        articulation_points_impl::dfs(graph, i, i, visit, low, ret, v);
      }
    }

    return ret;
  }
}
