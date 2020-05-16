#define PROBLEM "https://yukicoder.me/problems/no/631"

#include <iostream>
#include <vector>

#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_max.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N;
  while(std::cin >> N){
    auto seg = LazySegmentTree<AddMax<int64_t,int64_t>>(N-1);
        
    std::vector<int64_t> T(N-1);
    for(auto &x : T) std::cin >> x;
    
    for(int i = 0; i < N-1; ++i){
      T[i] += 3 * (N-1-i);
    }

    seg.init_with_vector(T);
    
    int M; std::cin >> M;

    for(int i = 0; i < M; ++i){
      int L, R, D; std::cin >> L >> R >> D;
      --L, --R;

      seg.update(L, R+1, D);
      
      auto ans = seg.get(0, N-1);
      std::cout << ans << std::endl;
    }
  }

  return 0;
}
