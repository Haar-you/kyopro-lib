#pragma once

namespace haar_lib {
  template <typename T>
  constexpr int sign(T n) {
    return (n > 0) - (n < 0);
  }
}  // namespace haar_lib
