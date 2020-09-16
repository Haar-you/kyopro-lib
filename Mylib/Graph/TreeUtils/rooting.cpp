#pragma once
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  void rooting(tree<T> &tr, int cur, int par = -1){
    if(par != -1){
      for(auto it = tr[cur].begin(); it != tr[cur].end(); ++it){
        if(it->to == par){
          tr[cur].erase(it);
          break;
        }
      }
    }

    for(auto &e : tr[cur]){
      rooting(tr, e.to, cur);
    }
  }
}
