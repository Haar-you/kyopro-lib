#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390"

#include <iostream>
#include <variant>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/AlgebraicStructure/Group/dihedral.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"

struct tag {};
using M = DihedralGroup<tag>;

int main(){
  int K, N, Q; std::cin >> K >> N >> Q;
  auto A = input_vector<int>(N);

  M::K = K;

  SegmentTree<M> seg(N);

  for(int i = 0; i < N; ++i){
    if(A[i] > 0){
      seg.update(i, M::R({A[i] % K}));
    }else if(A[i] < 0){
      seg.update(i, M::R({A[i] % K + K}));
    }else{
      seg.update(i, M::S({0}));
    }
  }

  for(auto [L, R] : input_tuples<int, int>(Q)){
    --L, --R;

    auto x = seg[L];
    auto y = seg[R];
    seg.update(L, y);
    seg.update(R, x);

    auto res = seg.get(0, N);

    if(std::holds_alternative<M::R>(res)){
      int ans = (K - std::get<M::R>(res).value) % K + 1;
      std::cout << ans << "\n";
    }else{
      int ans = -(std::get<M::S>(res).value + 1);
      std::cout << ans << "\n";
    }
  }

  return 0;
}
