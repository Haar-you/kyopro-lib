#pragma once
#include <cassert>
#include <functional>
#include <initializer_list>
#include <vector>

namespace haar_lib {
  template <typename T, const auto &convolve>
  class formal_power_series {
  public:
    using value_type = T;

  private:
    std::vector<T> data_;

  public:
    formal_power_series() {}
    explicit formal_power_series(int N) : data_(N) {}
    formal_power_series(const std::vector<T> &data_) : data_(data_) {}
    formal_power_series(std::initializer_list<T> init) : data_(init.begin(), init.end()) {}
    formal_power_series(const formal_power_series &a) : data_(a.data_) {}
    formal_power_series(formal_power_series &&a) noexcept { *this = std::move(a); }

    size_t size() const {
      return data_.size();
    }

    const T &operator[](int i) const {
      return data_[i];
    }

    T &operator[](int i) {
      return data_[i];
    }

    auto begin() { return data_.begin(); }
    auto end() { return data_.end(); }

    const auto &data() const { return data_; }

    void resize(int n) {
      data_.resize(n);
    }

    auto &operator=(formal_power_series &&rhs) noexcept {
      if (this != &rhs) {
        data_ = std::move(rhs.data_);
      }
      return *this;
    }

    auto &operator+=(const formal_power_series &rhs) {
      if (data_.size() < rhs.size()) data_.resize(rhs.size());
      for (int i = 0; i < rhs.size(); ++i) data_[i] += rhs[i];
      return *this;
    }

    auto &operator+=(T rhs) {
      data_[0] += rhs;
      return *this;
    }

    auto operator+(T rhs) const {
      auto ret = *this;
      return ret += rhs;
    }

    auto operator+(const formal_power_series &rhs) const {
      auto ret = *this;
      return ret += rhs;
    }

    auto &operator-=(const formal_power_series &rhs) {
      if (data_.size() < rhs.size()) data_.resize(rhs.size());
      for (int i = 0; i < rhs.size(); ++i) data_[i] -= rhs[i];
      return *this;
    }

    auto &operator-=(T rhs) {
      data_[0] -= rhs;
      return *this;
    }

    auto operator-(T rhs) const {
      auto ret = *this;
      return ret -= rhs;
    }

    auto operator-(const formal_power_series &rhs) const {
      auto ret = *this;
      return ret -= rhs;
    }

    auto operator-() const {
      auto ret = *this;
      for (auto &x : ret) x = -x;
      return ret;
    }

    auto &operator*=(const formal_power_series &rhs) {
      data_ = convolve(data_, rhs.data_);
      return *this;
    }

    auto operator*(const formal_power_series &rhs) const {
      auto ret = convolve(data_, rhs.data_);
      return formal_power_series(ret);
    }

    auto &operator*=(T rhs) {
      for (auto &x : data_) x *= rhs;
      return *this;
    }

    auto operator*(T rhs) const {
      auto ret = *this;
      return ret *= rhs;
    }

    auto differentiate() const {
      const int n = data_.size();
      std::vector<T> ret(n - 1);
      for (int i = 0; i < n - 1; ++i) {
        ret[i] = data_[i + 1] * (i + 1);
      }

      return formal_power_series(ret);
    }

    auto integrate() const {
      const int n = data_.size();
      std::vector<T> ret(n + 1), invs(n + 1, 1);
      const int p = T::mod();
      for (int i = 2; i <= n; ++i) invs[i] = -invs[p % i] * (p / i);
      for (int i = 0; i < n; ++i) {
        ret[i + 1] = data_[i] * invs[i + 1];
      }

      return formal_power_series(ret);
    }

    auto inv() const {
      assert(data_[0] != 0);
      const int n = data_.size();

      int t              = 1;
      std::vector<T> ret = {data_[0].inv()};
      ret.reserve(n * 2);

      while (t <= n * 2) {
        std::vector<T> c(data_.begin(), data_.begin() + std::min(t, n));
        auto a = convolve(ret, ret, true);
        if ((int) a.size() > t) a.resize(t);

        c = convolve(c, a);

        if ((int) c.size() > t) c.resize(t);
        if ((int) ret.size() > t) ret.resize(t);

        for (int i = 0; i < (int) ret.size(); ++i) ret[i] = ret[i] * 2;

        if (ret.size() < c.size()) ret.resize(std::min<int>(c.size(), t));

        for (int i = 0; i < (int) c.size(); ++i) {
          ret[i] -= c[i];
        }

        t <<= 1;
      }

      ret.resize(n);

      return formal_power_series(ret);
    }

    auto log() const {
      assert(data_[0] == 1);
      const int n = data_.size();
      auto ret    = (differentiate() * inv()).integrate();
      ret.resize(n);
      return ret;
    }

    auto exp() const {
      const int n = data_.size();

      int t = 1;
      formal_power_series b({1});

      while (t <= n * 2) {
        t <<= 1;
        auto temp = b.log();
        temp.resize(t);

        for (int i = 0; i < t; ++i) temp[i] = -temp[i];
        temp[0] += 1;
        for (int i = 0; i < std::min(t, n); ++i) temp[i] += data_[i];

        b = b * temp;
        b.resize(t);
      }

      b.resize(n);

      return b;
    }

    auto shift(int64_t k) const {
      const int64_t n = data_.size();
      formal_power_series ret(n);

      if (k >= 0) {
        for (int64_t i = k; i < n; ++i) {
          ret[i] = data_[i - k];
        }
      } else {
        for (int64_t i = 0; i < n + k; ++i) {
          ret[i] = data_[i - k];
        }
      }

      return ret;
    }

    auto pow(int64_t M) const {
      assert(M >= 0);

      const int n = data_.size();
      int k       = 0;
      for (; k < n; ++k) {
        if (data_[k] != 0) {
          break;
        }
      }

      if (k >= n) return *this;

      T a = data_[k];

      formal_power_series ret = *this;
      ret                     = (ret.shift(-k)) * a.inv();
      ret                     = (ret.log() * (T) M).exp();
      ret                     = (ret * a.pow(M)).shift(M * k);

      return ret;
    }

    std::optional<formal_power_series> sqrt() const;
  };
}  // namespace haar_lib
