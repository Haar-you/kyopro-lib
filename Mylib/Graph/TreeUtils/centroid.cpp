#pragma once
#include <vector>
#include "Mylib/Graph/graph_template.cpp"

template <typename T>
class Centroid{
public:
  int N;
  std::vector<int> subtree;
  std::vector<int> result;
  Centroid(const Tree<T> &tree): N(tree.size()), subtree(N){
    dfs(tree, 0, -1);    
  }

private:
  void dfs(const Tree<T> &tree, int cur, int par){
    subtree[cur] = 1;
    bool check = true;

    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs(tree, e.to, cur);

      if(subtree[e.to] > N / 2) check = false;
      subtree[cur] += subtree[e.to];
    }

    if(N - subtree[cur] > N / 2) check = false;

    if(check) result.push_back(cur);
  }
};
