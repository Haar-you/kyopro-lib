#pragma once

namespace haar_lib {
  template <typename T>
  constexpr bool is_square(T n){
    T rt = sqrt(n);
    return rt * rt == n;
  }
}
