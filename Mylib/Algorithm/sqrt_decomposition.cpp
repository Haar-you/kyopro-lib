#pragma once
#include <algorithm>
#include <cmath>

namespace haar_lib {
  class sqrt_decomposition {
    int N_, BLOCK_SIZE_, BLOCK_NUM_;

  public:
    sqrt_decomposition(int N):
      N_(N), BLOCK_SIZE_((int)std::sqrt(N)), BLOCK_NUM_((N + BLOCK_SIZE_ - 1) / BLOCK_SIZE_){}

    int block_size() const {return BLOCK_SIZE_;}
    int block_num() const {return BLOCK_NUM_;}

    template <typename Func>
    void init(const Func &f){
      for(int i = 0; i < BLOCK_NUM_; ++i){
        const int L = i * BLOCK_SIZE_;
        const int R = std::min<int>(N_, (i + 1) * BLOCK_SIZE_);
        f(i, L, R);
      }
    }

    template <typename FuncBlock, typename FuncRange>
    void query(int l, int r, const FuncBlock &func_block, const FuncRange &func_range){
      for(int i = 0; i < BLOCK_NUM_; ++i){
        const int L = i * BLOCK_SIZE_;
        const int R = std::min<int>(N_, (i + 1) * BLOCK_SIZE_);

        if(l <= L and R <= r){
          func_block(i, L, R);
        }else if((L <= l and l < R) or (L < r and r <= R)){
          func_range(i, L, R, std::max(l, L), std::min(r, R));
        }
      }
    }
  };
}
