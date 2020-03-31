#pragma once
#include <vector>
#include <queue>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @see https://yukicoder.me/submissions/390077
 */
template <typename T> struct EulerTourBFS{
  Tree<T> tree;
  int N;
  std::vector<int> bfs_order;
  std::vector<int> parent;

  EulerTourBFS(const Tree<T> &tree, int root): tree(tree), N(tree.size()), bfs_order(N, -1), parent(N, -1){
    std::vector<bool> visited(N);
    std::queue<int> q;
    q.push(root);

    int i = 0;
    while(q.size()){
      int cur = q.front(); q.pop();

      if(visited[cur]) continue;
      visited[cur] = true;

      bfs_order[cur] = i;
      ++i;

      for(auto &e : tree[cur]){
        if(not visited[e.to]){
          q.push(e.to);
        }
      }
    }
    
    dfs_parent(root, -1);
  }

  void dfs_parent(int cur, int par){
    parent[cur] = par;
    
    for(auto it = tree[cur].begin(); it != tree[cur].end(); ++it){
      if(it->to == par){
        tree[cur].erase(it);
        break;
      }
    }
    
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      dfs_parent(e.to, cur);
    }
  }

public:
  inline int get_parent(int i) const {
    if(i == -1) return -1;
    return parent[i];
  }
  
  template <typename Func> inline void query_at(int i, const Func &f) const {
    if(i != -1){
      f(bfs_order[i], bfs_order[i]+1);
    }
  }

  template <typename Func> inline void query_children(int i, const Func &f) const {
    if(i != -1 and tree[i].size()){
      f(bfs_order[tree[i].front().to], bfs_order[tree[i].back().to]+1);
    }
  }
};
