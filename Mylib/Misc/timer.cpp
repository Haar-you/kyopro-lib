#pragma once
#include <chrono>
#include <iostream>

namespace haar_lib {
  class timer {
    std::chrono::system_clock::time_point s_, last_;

  public:
    timer() {}

    void set() {
      s_ = last_ = std::chrono::system_clock::now();
    }

    void time() {
#ifdef DEBUG
      auto t = std::chrono::system_clock::now();
      auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t - last_).count();
      std::cerr << "\e[1;33m" << d << "ms\e[m\n";
      last_ = t;
#endif
    }
  };
}  // namespace haar_lib
