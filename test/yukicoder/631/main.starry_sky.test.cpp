#define PROBLEM "https://yukicoder.me/problems/no/631"

#include <iostream>
#include <vector>
#include <functional>
#include "Mylib/DataStructure/SegmentTree/starry_sky_tree.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto seg = hl::starry_sky_tree<int64_t, std::greater<>>(N - 1);

  auto T = hl::input_vector<int64_t>(N - 1);

  for(int i = 0; i < N - 1; ++i){
    T[i] += 3 * (N - 1 - i);
  }

  seg.init_with_vector(T);

  int M; std::cin >> M;

  for(auto [L, R, D] : hl::input_tuples<int, int, int>(M)){
    --L, --R;

    seg.update(L, R + 1, D);

    auto ans = seg.fold_all();
    std::cout << ans << std::endl;
  }

  return 0;
}
