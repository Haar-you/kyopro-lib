#define PROBLEM "https://yukicoder.me/problems/no/755"

#include <iostream>
#include <vector>
#include "Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;

  auto A = hl::input_vector<int64_t>(M, M);

  auto c = hl::cumulative_sum_2d(A).build();

  for(auto [x, y] : hl::input_tuples<int, int>(N)){
    --x, --y;

    int ans = 0;

    for(int x1 = 0; x1 <= x; ++x1){
      for(int y1 = 0; y1 <= y; ++y1){
        for(int x2 = x; x2 < M; ++x2){
          for(int y2 = y; y2 < M; ++y2){
            if(c.get({x1, y1}, {x2 + 1, y2 + 1}) == 0) ++ans;
          }
        }
      }
    }

    std::cout << ans << std::endl;
  }

  return 0;
}
