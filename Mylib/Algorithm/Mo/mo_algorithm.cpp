#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * @title Moのアルゴリズム
 * @see https://codeforces.com/contest/86/submission/62912624 (出現数)
 * @see https://www.spoj.com/problems/DQUERY/ (種類数)
 * @see https://atcoder.jp/contests/dwacon2017-honsen/submissions/8017651 (積の約数の個数)
 * @see https://codeforces.com/contest/375/submission/73875627 (部分木 / 出現数k以上の種類数)
 * @see https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem (出現数1の種類数)
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
    N(N), Q(Q), index(0), width(sqrt(N)), left(Q), right(Q), ord(Q), append(append), remove(remove), query(query){
  }

  // [l, r)
  inline void add(int l, int r){
    left[index] = l;
    right[index] = r;
    ord[index] = index;
    ++index;
  }

  inline void build(){
    std::sort(ord.begin(), ord.end(),
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
              });

    is_built = true;
  }

  /**
   * @attention time complexity O(N√Q)
   */
  inline void process(){
    assert(is_built);
    
    int q = 0;
    int l = left[ord[0]], r = left[ord[0]];
    
    for(int i = 0; i < Q; ++i){
      int id = ord[q++];

      while(l != left[id] or r != right[id]){
        if(l > left[id]) append(--l);
        if(l < left[id]) remove(l++);
        if(r < right[id]) append(r++);
        if(r > right[id]) remove(--r);
      }

      query(id);
    }
  }
};

template <typename F, typename G, typename H>
auto make_mo(int N, int Q, F append, G remove, H query){
  return MoAlgorithm<F, G, H>(N, Q, append, remove, query);
}
