#define PROBLEM "https://yukicoder.me/problems/no/755"

#include <iostream>
#include <vector>

#include "Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;

  std::vector<std::vector<int64_t>> A(M, std::vector<int64_t>(M));
  for(int i = 0; i < M; ++i){
    for(int j = 0; j < M; ++j){
      std::cin >> A[i][j];
    }
  }

  auto c = CumulativeSum2D(A).build();

  while(N--){
    int x, y; std::cin >> x >> y;
    --x, --y;

    int ans = 0;
    
    for(int x1 = 0; x1 <= x; ++x1){
      for(int y1 = 0; y1 <= y; ++y1){
        for(int x2 = x; x2 < M; ++x2){
          for(int y2 = y; y2 < M; ++y2){
            if(c.get(x1, y1, x2 + 1, y2 + 1) == 0) ++ans;
          }
        }
      }  
    }

    std::cout << ans << std::endl;
  }
  
  return 0;
}
