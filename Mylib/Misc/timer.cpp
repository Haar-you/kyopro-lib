#pragma once
#include <chrono>
#include <iostream>

/**
 * @title Timer
 * @docs timer.md
 */
template <typename F>
void timer(F f){
  auto s = std::chrono::system_clock::now();
  f();
  auto t = std::chrono::system_clock::now();
  auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t - s).count();
  std::cerr << d << "ms" << "\n";
};
