#pragma once
#include "Mylib/Math/formal_power_series.cpp"
#include "Mylib/Number/Mod/mod_sqrt.cpp"

namespace haar_lib {
  template <typename T, const auto &convolve>
  auto formal_power_series<T, convolve>::sqrt() const ->
    std::optional<formal_power_series<T, convolve>> {
    constexpr int mod = value_type::mod();

    const int n = data_.size();
    int k = 0;
    for(; k < n; ++k) if(data_[k] != 0) break;

    if(k >= n) return *this;
    if(k % 2 != 0) return {};

    auto x = mod_sqrt((int64_t)data_[k], mod);

    if(not x) return {};

    const int m = n - k;

    auto it = data_.begin() + k;
    formal_power_series ret({*x});

    int t = 1;
    while(t <= m * 2){
      formal_power_series f(std::vector<T>(it, it + std::min(t, m)));
      ret.resize(t);
      f.resize(t);
      ret = (ret + f * ret.inv()) * T(2).inv();
      t <<= 1;
    }

    ret.resize(n);
    ret = ret.shift(k / 2);

    return ret;
  }
}
