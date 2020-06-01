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
  
  int get_root(int i){
    if(parent[i] == i) return i;
    else {
      int p = get_root(parent[i]);
      weight[i] += weight[parent[i]];
      return parent[i] = p;
    }
  }

  T get_weight(int i){get_root(i); return weight[i];} 
  bool is_same(int i, int j){return get_root(i) == get_root(j);}
  T diff(int i, int j){return get_weight(i)-get_weight(j);}
  
  int merge(int i, int j, T w){
    int ri = get_root(i), rj = get_root(j);
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
  
  int get_size(int i){return size[get_root(i)];}
  int count_group(){return count;}
};
