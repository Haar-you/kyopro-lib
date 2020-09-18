#define PROBLEM "https://yukicoder.me/problems/no/1099"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/array.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto A = hl::input_vector<int64_t>(N);

  hl::lazy_segment_tree<
    hl::array_monoid<hl::sum_monoid<int64_t>, 2>,
    hl::sum_monoid<int64_t>,
    hl::add_square_sum> seg(N);

  for(int i = 0; i < N; ++i) seg.update_at(i, A[i]);

  int Q; std::cin >> Q;

  for(auto [type] : hl::input_tuples<int>(Q)){
    if(type == 1){
      int l, r, x; std::cin >> l >> r >> x;
      seg.update(l - 1, r, x);
    }else{
      int l, r; std::cin >> l >> r;
      std::cout << std::get<1>(seg.get(l - 1, r)) << "\n";
    }
  }

  return 0;
}
