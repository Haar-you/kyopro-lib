#pragma once
#include <vector>
#include "Mylib/DataStructure/Array/persistent_array.cpp"

/**
 * @title Persistent union-find
 * @docs persistent_unionfind.md
 */
class PersistentUnionFind{
  PersistentArray<int> par;

  PersistentUnionFind(PersistentArray<int> par): par(par){}

public:
  PersistentUnionFind(){}
  PersistentUnionFind(int n): par(PersistentArray<int>(std::vector<int>(n, -1))){}
  
  int get_root(int i) const {
    int p = par.get(i);
    if(p < 0) return i;
    return get_root(p);
  }
  
  bool is_same(int i, int j) const {
    return get_root(i) == get_root(j);
  }

  int size(int i) const {
    return -par.get(get_root(i));
  }
  
  PersistentUnionFind merge(int i, int j) const {
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return *this;

    int size_i = -par.get(ri);
    int size_j = -par.get(rj);

    PersistentArray<int> ret = par;

    if(size_i > size_j){
      ret = ret.update(ri, -(size_i + size_j));
      ret = ret.update(rj, ri);
    }else{
      ret = ret.update(rj, -(size_i + size_j));
      ret = ret.update(ri, rj);
    }
    
    return PersistentUnionFind(ret);
  }
};
