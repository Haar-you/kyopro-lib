#pragma once

/**
 * @title Gray code
 * @docs gray_code.md
 */
template <typename Func>
void gray_code(int n, const Func &f){
  for(int i = 0; i < (1 << n); ++i){
    if(not f(i ^ (i >> 1))) break;
  }
}
