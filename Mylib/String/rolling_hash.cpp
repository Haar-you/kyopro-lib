#pragma once
#include <random>
#include <vector>

namespace haar_lib {
  class rolling_hash {
    std::vector<int64_t> pow_;
    int64_t MOD_, BASE_;

  public:
    rolling_hash() {}
    rolling_hash(int size, int MOD, int BASE) : MOD_(MOD), BASE_(BASE) {
      pow_.assign(size + 1, 1);
      for (int i = 1; i <= size; ++i) pow_[i] = pow_[i - 1] * BASE_ % MOD_;
    }

    template <typename T>
    auto gen_hash_table(const T &s) const {
      std::vector<int64_t> ret(s.size() + 1);
      for (int i = 0; i < (int) s.size(); ++i) ret[i + 1] = (ret[i] * BASE_ + s[i]) % MOD_;
      return ret;
    }

    template <typename T>
    auto gen_hash(const T &s) const {
      int64_t ret = 0;
      for (int i = 0; i < (int) s.size(); ++i) ret = (ret * BASE_ + s[i]) % MOD_;
      return ret;
    }

    /**
     * @attention [l, r)
     */
    int64_t get(const std::vector<int64_t> &table, int l, int r) const {
      return (table[r] - table[l] * pow_[r - l] % MOD_ + MOD_ * MOD_) % MOD_;
    }

    template <typename T>
    std::vector<int> find(const T &s, const T &pattern) const {
      auto hp = gen_hash(pattern);
      auto hs = gen_hash_table(s);
      std::vector<int> ret;
      for (int i = 0; i <= ((int) s.size() - (int) pattern.size()); ++i) {
        if (hp == get(hs, i, i + pattern.size())) ret.push_back(i);
      }

      return ret;
    }
  };

  auto make_rh(int size, int MOD, int seed = 0) {
    std::mt19937 rnd(seed);
    std::uniform_int_distribution<> dist(2, MOD - 2);
    return rolling_hash(size, MOD, dist(rnd));
  }
}  // namespace haar_lib
