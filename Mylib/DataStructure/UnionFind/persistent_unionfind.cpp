#pragma once
#include <vector>
#include "Mylib/DataStructure/Array/persistent_array.cpp"

namespace haar_lib {
  class persistent_unionfind {
    persistent_array<int> par;

    persistent_unionfind(persistent_array<int> par): par(par){}

  public:
    persistent_unionfind(){}
    persistent_unionfind(int n): par(persistent_array<int>(std::vector<int>(n, -1))){}

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

    persistent_unionfind merge(int i, int j) const {
      const int ri = root_of(i), rj = root_of(j);
      if(ri == rj) return *this;

      const int size_i = -par[ri];
      const int size_j = -par[rj];

      persistent_array<int> ret = par;

      if(size_i > size_j){
        ret = ret.set(ri, -(size_i + size_j));
        ret = ret.set(rj, ri);
      }else{
        ret = ret.set(rj, -(size_i + size_j));
        ret = ret.set(ri, rj);
      }

      return persistent_unionfind(ret);
    }
  };
}
