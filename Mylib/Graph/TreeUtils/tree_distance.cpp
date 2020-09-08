#pragma once
#include <vector>
#include <stack>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Tree distance
 * @docs tree_distance.md
 */
namespace haar_lib {
  template <typename T>
  std::vector<T> tree_distance(const Tree<T> &tree, int root){
    const int n = tree.size();
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
}
