#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

/**
 * @title Mo's algorithm
 * @docs mo_algorithm.md
 */
namespace haar_lib {
  template <typename AppendLeft, typename AppendRight, typename RemoveLeft, typename RemoveRight, typename Query>
  class MoAlgorithm {
    int N, Q, index, width;
    std::vector<int> left, right, ord;

    const AppendLeft append_left;
    const AppendRight append_right;
    const RemoveLeft remove_left;
    const RemoveRight remove_right;
    const Query query;

    bool is_built = false;

  public:
    MoAlgorithm(
      int N, int Q,
      const AppendLeft &append_left, const AppendRight &append_right,
      const RemoveLeft &remove_left, const RemoveRight &remove_right,
      const Query &query
    ):
      N(N), Q(Q), index(0), width(sqrt(N)),
      left(Q), right(Q), ord(Q),
      append_left(append_left), append_right(append_right),
      remove_left(remove_left), remove_right(remove_right),
      query(query)
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
          if(l > left[id]) append_left(--l);
          if(l < left[id]) remove_left(l++);
          if(r < right[id]) append_right(r++);
          if(r > right[id]) remove_right(--r);
        }

        query(id);
      }
    }
  };
}
