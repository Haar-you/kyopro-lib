#pragma once
#include <vector>
#include "Mylib/DataStructure/Array/persistent_array.cpp"

/**
 * @title Persistent union-find
 * @docs persistent_unionfind.md
 */
class PersistentUnionFind {
  PersistentArray<int> par;

  PersistentUnionFind(PersistentArray<int> par): par(par){}

public:
  PersistentUnionFind(){}
  PersistentUnionFind(int n): par(PersistentArray<int>(std::vector<int>(n, -1))){}

  int root_of(int i) const {
    const int p = par[i];
    if(p < 0) return i;
    return root_of(p);
  }

  bool is_same(int i, int j) const {
    return root_of(i) == root_of(j);
  }

  int size_of(int i) const {
    return -par[root_of(i)];
  }

  PersistentUnionFind merge(int i, int j) const {
    const int ri = root_of(i), rj = root_of(j);
    if(ri == rj) return *this;

    const int size_i = -par[ri];
    const int size_j = -par[rj];

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
