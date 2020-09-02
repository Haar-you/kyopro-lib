#pragma once
#include <chrono>
#include <cmath>

/**
 * @title Simulated annealing
 * @docs simulated_annealing.md
 */
template <typename Func>
void simulated_annealing(int duration, double T0, double T1, Func f){
  using namespace std::chrono;

  auto s = system_clock::now();

  while(true){
    auto t = system_clock::now();
    int d = duration_cast<milliseconds>(t - s).count();
    if(d >= duration) break;

    double now = (double)d / duration;

    double T = std::pow(T0, 1.0 - now) * std::pow(T1, now);

    f(d, T);
  }
}
