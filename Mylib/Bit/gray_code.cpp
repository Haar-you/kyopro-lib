#pragma once

/**
 * @title Grayコード
 * @docs gray_code.md
 */
template <typename Func>
void gray_code(int n, const Func &f){
  for(int i = 0; i < (1 << n); ++i){
    f(i ^ (i >> 1));
  }
}