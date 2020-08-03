#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

/**
 * @title Mo's algorithm
 * @docs mo_algorithm.md
 */
template <typename F, typename G, typename H>
class MoAlgorithm{
  int N, Q, index, width;
  std::vector<int> left, right, ord;

  const F append;
  const G remove;
  const H query;

  bool is_built = false;

public:
  MoAlgorithm(int N, int Q, const F &append, const G &remove, const H &query):
    N(N), Q(Q), index(0), width(sqrt(N)),
    left(Q), right(Q), ord(Q),
    append(append), remove(remove), query(query)
  {}

  // [l, r)
  void add(int l, int r){
    left[index] = l;
    right[index] = r;
    ord[index] = index;
    ++index;
  }

  void build(){
    std::sort(
      ord.begin(),
      ord.end(),
      [&](int i, int j){
        const int a = left[i] / width, b = left[j] / width;
        if(a == b){
          if(a & 1){
            return right[i] < right[j];
          }else{
            return right[i] > right[j];
          }
        }else{
          return a < b;
        }
      }
    );

    is_built = true;
  }

  void run(){
    assert(is_built);
    
    int q = 0;
    int l = left[ord[0]], r = left[ord[0]];
    
    for(int i = 0; i < Q; ++i){
      int id = ord[q++];

      while(l != left[id] or r != right[id]){
        if(l > left[id]) append(--l, -1);
        if(l < left[id]) remove(l++, -1);
        if(r < right[id]) append(r++, 1);
        if(r > right[id]) remove(--r, 1);
      }

      query(id);
    }
  }
};

template <typename F, typename G, typename H>
auto make_mo(int N, int Q, F append, G remove, H query){
  return MoAlgorithm<F, G, H>(N, Q, append, remove, query);
}
