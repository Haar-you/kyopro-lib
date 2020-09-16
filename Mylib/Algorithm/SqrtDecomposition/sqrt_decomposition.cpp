#pragma once
#include <algorithm>
#include <cmath>

namespace haar_lib {
  struct sqrt_decomposition {
    const int N;
    const int BLOCK_SIZE;
    const int BLOCK_NUM;

    sqrt_decomposition(int N):
      N(N), BLOCK_SIZE((int)std::sqrt(N)), BLOCK_NUM((N + BLOCK_SIZE - 1) / BLOCK_SIZE)
    {
    }

    template <typename Func>
    void init(const Func &f){
      for(int i = 0; i < BLOCK_NUM; ++i){
        const int L = i * BLOCK_SIZE;
        const int R = std::min<int>(N, (i + 1) * BLOCK_SIZE);
        f(i, L, R);
      }
    }

    template <typename FuncBlock, typename FuncRange>
    void query(int l, int r, const FuncBlock &func_block, const FuncRange &func_range){ // [l, r)
      for(int i = 0; i < BLOCK_NUM; ++i){
        const int L = i * BLOCK_SIZE;
        const int R = std::min<int>(N, (i + 1) * BLOCK_SIZE);

        if(l <= L and R <= r){
          func_block(i, L, R);
        }else if((L <= l and l < R) or (L < r and r <= R)){
          func_range(i, L, R, std::max(l, L), std::min(r, R));
        }
      }
    }
  };
}
