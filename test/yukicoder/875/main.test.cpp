#define PROBLEM "https://yukicoder.me/problems/no/875"

#include <iostream>
#include <vector>
#include <utility>

#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/AlgebraicStructure/Monoid/with_min_index.cpp"
#include "Mylib/IO/input_tuples.cpp"

using Mon = WithMinIndex<MinMonoid<int>>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  SegmentTree<Mon> seg(N);

  std::vector<Mon::value_type> a(N);
  for(int i = 0; i < N; ++i){
    int x; std::cin >> x;
    a[i] = std::make_pair(x, i);
  }

  seg.init_with_vector(a);

  for(auto [type, l, r] : input_tuples<int, int, int>(Q)){
    switch(type){
    case 1: {
      --l, --r;

      auto x = seg[l].first;
      auto y = seg[r].first;

      seg.update(l, std::make_pair(y, l));
      seg.update(r, std::make_pair(x, r));

      break;
    }
    case 2: {
      --l, --r;

      std::cout << seg.get(l, r+1).second + 1 << "\n";

      break;
    }
    }
  }

  return 0;
}
