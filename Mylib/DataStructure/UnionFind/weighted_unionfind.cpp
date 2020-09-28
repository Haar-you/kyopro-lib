#pragma once
#include <vector>
#include <numeric>

namespace haar_lib {
  template <typename T>
  class weighted_unionfind {
  public:
    using value_type = T;

  private:
    std::vector<int> parent_, depth_, size_;
    std::vector<T> weight_;
    int count_;

  public:
    weighted_unionfind(){}
    weighted_unionfind(int n): parent_(n), depth_(n, 1), size_(n, 1), weight_(n, 0){
      std::iota(parent_.begin(), parent_.end(), 0);
    }

    int root_of(int i){
      if(parent_[i] == i) return i;
      else {
        const int p = root_of(parent_[i]);
        weight_[i] += weight_[parent_[i]];
        return parent_[i] = p;
      }
    }

    T weight_of(int i){root_of(i); return weight_[i];}
    bool is_same(int i, int j){return root_of(i) == root_of(j);}
    T diff(int i, int j){return weight_of(i) - weight_of(j);}

    int merge(int i, int j, T w){
      const int ri = root_of(i), rj = root_of(j);
      if(ri == rj) return ri;
      else{
        if(depth_[ri] < depth_[rj]){
          parent_[ri] = rj; size_[rj] += size_[ri]; weight_[ri] = w - weight_[i] + weight_[j];
          return rj;
        }else{
          parent_[rj] = ri; size_[ri] += size_[rj]; weight_[rj] = -w + weight_[i] - weight_[j];
          if(depth_[ri] == depth_[rj]) ++depth_[ri];
          return ri;
        }
      }
    }

    int size_of(int i){return size_[root_of(i)];}
    int count_groups(){return count_;}
  };
}
