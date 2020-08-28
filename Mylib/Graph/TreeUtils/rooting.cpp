#pragma once
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Rooting
 * @docs rooting.md
 */
template <typename T>
void rooting(Tree<T> &tree, int cur, int par = -1){
  if(par != -1){
    for(auto it = tree[cur].begin(); it != tree[cur].end(); ++it){
      if(it->to == par){
        tree[cur].erase(it);
        break;
      }
    }
  }

  for(auto &e : tree[cur]){
    rooting(tree, e.to, cur);
  }
}
