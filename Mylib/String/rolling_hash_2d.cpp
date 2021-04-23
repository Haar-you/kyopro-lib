#pragma once
#include <random>
#include <vector>

namespace haar_lib {
  class rolling_hash_2d {
    std::vector<int64_t> pow_w_, pow_h_;
    int64_t MOD_, BASEW_, BASEH_;

  public:
    rolling_hash_2d() {}
    rolling_hash_2d(int width, int height, int MOD, int BASEW, int BASEH) : MOD_(MOD), BASEW_(BASEW), BASEH_(BASEH) {
      pow_w_.resize(width + 1);
      pow_h_.resize(height + 1);
      pow_w_[0] = pow_h_[0] = 1;
      for (int i = 1; i <= width; ++i) pow_w_[i] = pow_w_[i - 1] * BASEW_ % MOD_;
      for (int i = 1; i <= height; ++i) pow_h_[i] = pow_h_[i - 1] * BASEH_ % MOD_;
    }

    template <typename T>
    auto gen_hash_table(const T &s) const {
      const int n = s.size(), m = s[0].size();
      std::vector<std::vector<int64_t>> ret(n + 1, std::vector<int64_t>(m + 1));

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          ret[i + 1][j + 1] = (ret[i + 1][j] * BASEW_ + s[i][j]) % MOD_;
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          ret[i + 1][j + 1] = (ret[i][j + 1] * BASEH_ + ret[i + 1][j + 1]) % MOD_;
        }
      }

      return ret;
    }

    template <typename T>
    auto gen_hash(const T &s) const {
      const int n = s.size(), m = s[0].size();
      int64_t ret = 0;
      for (int i = 0; i < n; ++i) {
        int64_t temp = 0;
        for (int j = 0; j < m; ++j) {
          temp = (temp * BASEW_ + s[i][j]) % MOD_;
        }
        ret = (ret * BASEH_ + temp) % MOD_;
      }
      return ret;
    }

    /**
     * @attention [i1, i2), [j1, j2)
     */
    int64_t get(const std::vector<std::vector<int64_t>> &table, int i1, int j1, int i2, int j2) const {
      const auto a = table[i2][j2];
      const auto b = table[i1][j2] * pow_h_[i2 - i1] % MOD_;
      const auto c = table[i2][j1] * pow_w_[j2 - j1] % MOD_;
      const auto d = table[i1][j1] * pow_h_[i2 - i1] % MOD_ * pow_w_[j2 - j1] % MOD_;

      return (((a - b + MOD_) % MOD_ - c + MOD_) % MOD_ + d + MOD_) % MOD_;
    }

    template <typename T>
    std::vector<std::pair<int, int>> find(const T &s, const T &pattern) const {
      auto hp = gen_hash(pattern);
      auto hs = gen_hash_table(s);

      const int H = s.size();
      const int W = s[0].size();
      const int R = pattern.size();
      const int C = pattern[0].size();

      std::vector<std::pair<int, int>> ret;

      for (int i = 0; i <= H - R; ++i) {
        for (int j = 0; j <= W - C; ++j) {
          if (hp == get(hs, i, j, i + R, j + C)) ret.emplace_back(i, j);
        }
      }

      return ret;
    }
  };

  auto make_rh_2d(int width, int height, int MOD, int seed = 0) {
    std::mt19937 rnd(seed);
    std::uniform_int_distribution<> dist(2, MOD - 2);
    return rolling_hash_2d(width, height, MOD, dist(rnd), dist(rnd));
  }
}  // namespace haar_lib
