#pragma once

namespace haar_lib {
  template <typename T>
  bool is_square(T n){
    T rt = sqrt(n);
    return rt * rt == n;
  }
}
