#pragma once
#include <vector>
#include <numeric>

/**
 * @title Union-find
 * @docs unionfind.md
 */
class UnionFind{
  std::vector<int> parent, depth, size;
  int count;

public:
  UnionFind(){}
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }
  
  int root_of(int i){
    if(parent[i] == i) return i;
    else return parent[i] = root_of(parent[i]);
  }
  
  bool is_same(int i, int j){return root_of(i) == root_of(j);}

  int merge(int i, int j){
    int ri = root_of(i), rj = root_of(j);
    if(ri == rj) return ri;
    else{
      --count;
      if(depth[ri] < depth[rj]){
        parent[ri] = rj;
        size[rj] += size[ri];
        return rj;
      }else{
        parent[rj] = ri;
        size[ri] += size[rj];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }

  int size_of(int i){return size[root_of(i)];}

  int count_group(){return count;}
};
