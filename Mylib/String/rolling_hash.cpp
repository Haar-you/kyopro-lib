#pragma once
#include <vector>
#include <random>

/**
 * @title Rolling Hash
 * @docs rolling_hash.md
 */
class RollingHash{
  std::vector<int64_t> pow;
  int64_t MOD, BASE;
  
public:
  RollingHash(int size, int MOD, int BASE): MOD(MOD), BASE(BASE){
    pow.resize(size + 1);
    pow[0] = 1;
    for(int i = 1; i <= size; ++i) pow[i] = pow[i-1] * BASE % MOD;
  }

  template <typename T>
  auto gen_hash_table(const T &s) const {
    std::vector<int64_t> ret(s.size() + 1);
    for(int i = 0; i < (int)s.size(); ++i) ret[i+1] = (ret[i] * BASE + s[i]) % MOD;
    return ret;
  }

  template <typename T>
  auto gen_hash(const T &s) const {
    int64_t ret = 0;
    for(int i = 0; i < (int)s.size(); ++i) ret = (ret * BASE + s[i]) % MOD;
    return ret;
  }

  /**
   * @attention [l, r)
   */
  int64_t get(const std::vector<int64_t> &table, int l, int r) const {
    return (table[r] - table[l] * pow[r-l] % MOD + MOD * MOD) % MOD;
  }
};

auto make_rh(int size, int MOD, int seed = 0){
  std::mt19937 rnd(seed);
  std::uniform_int_distribution<> dist(2, MOD-2);
  return RollingHash(size, dist(rnd), MOD);
}
