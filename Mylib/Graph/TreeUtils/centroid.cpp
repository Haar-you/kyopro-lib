#pragma once
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Enumerate centroids
 * @docs centroid.md
 */
namespace haar_lib {
  namespace enumerate_centroids_impl {
    template <typename T>
    void dfs(const tree<T> &tr, std::vector<int> &subtree, std::vector<int> &ret, int N, int cur, int par){
      subtree[cur] = 1;
      bool check = true;

      for(auto &e : tr[cur]){
        if(e.to == par) continue;
        dfs(tr, subtree, ret, N, e.to, cur);

        if(subtree[e.to] > N / 2) check = false;
        subtree[cur] += subtree[e.to];
      }

      if(N - subtree[cur] > N / 2) check = false;

      if(check) ret.push_back(cur);
    }
  }

  template <typename T>
  auto enumerate_centroids(const tree<T> &tr){
    const int N = tr.size();
    std::vector<int> subtree(N), ret;
    enumerate_centroids_impl::dfs(tr, subtree, ret, N, 0, -1);
    return ret;
  }
}
