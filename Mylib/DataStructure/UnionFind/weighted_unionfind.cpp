#pragma once
#include <vector>
#include <numeric>

/**
 * @title Weighted union-find
 * @docs weighted_unionfind.md
 */

template <typename T> class WeightedUnionFind{
  std::vector<int> parent, depth, size;
  std::vector<T> weight;
  int count;

public:
  WeightedUnionFind(int n): parent(n), depth(n,1), size(n,1), weight(n,0){
    std::iota(parent.begin(), parent.end(),0);
  }
  
  int root_of(int i){
    if(parent[i] == i) return i;
    else {
      int p = root_of(parent[i]);
      weight[i] += weight[parent[i]];
      return parent[i] = p;
    }
  }

  T weight_of(int i){root_of(i); return weight[i];} 
  bool is_same(int i, int j){return root_of(i) == root_of(j);}
  T diff(int i, int j){return weight_of(i) - weight_of(j);}
  
  int merge(int i, int j, T w){
    int ri = root_of(i), rj = root_of(j);
    if(ri == rj) return ri;
    else{
      if(depth[ri] < depth[rj]){
        parent[ri] = rj; size[rj] += size[ri]; weight[ri] = w - weight[i] + weight[j];
        return rj;
      }else{
        parent[rj] = ri; size[ri] += size[rj]; weight[rj] = -w + weight[i] - weight[j];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }
  
  int size_of(int i){return size[root_of(i)];}
  int count_group(){return count;}
};
