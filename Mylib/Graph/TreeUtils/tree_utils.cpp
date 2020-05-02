#pragma once
#include <vector>
#include <utility>
#include <stack>
#include <tuple>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title TreeUtils
 * @docs tree_utils.md
 */
template <typename T> class TreeUtils{
public:
  static std::pair<int,T> farthest(const Tree<T> &tree, int cur, int par = -1){
    auto d = std::make_pair(cur, 0);
    for(auto &e : tree[cur]){
      if(e.to == par) continue;
      auto t = farthest(tree, e.to, cur);
      t.second += e.cost;
      if(t.second > d.second) d = t;
    }
    return d;
  }

  static std::vector<T> distance(const Tree<T> &tree, int root){
    int n = tree.size();
    std::vector<T> ret(n);
    std::vector<bool> visited(n);
    
    std::stack<int> st;
    st.push(root);
    ret[root] = 0;
    
    while(not st.empty()){
      int cur = st.top(); st.pop();
      visited[cur] = true;
      
      for(auto &e : tree[cur]){
        if(not visited[e.to]){
          ret[e.to] = ret[cur] + e.cost;
          st.push(e.to);
        }
      }
    }
    
    return ret;
  }
  
  static std::tuple<int, int, T> diameter(const Tree<T> &tree){
    auto a = farthest(tree, 0);
    auto b = farthest(tree, a.first);
    return std::make_tuple(a.first, b.first, b.second);
  }

  static std::vector<T> height(const Tree<T> &tree){
    auto a = farthest(tree, 0);
    auto b = farthest(tree, a.first);

    int n = tree.size();

    auto d1 = distance(tree, a.first);
    auto d2 = distance(tree, b.first);

    std::vector<T> h(n);
    for(int i = 0; i < n; ++i) h[i] = std::max(d1[i], d2[i]);
    
    return h;
  }
};
