#pragma once
#include <vector>

/**
 * @title Rolling Hash
 * @see https://yukicoder.me/submissions/347187
 */
template <typename T, int64_t BASE, int64_t MOD>
class RollingHash{
  static std::vector<int64_t> pow;

public:
  std::vector<int64_t> table;

  static void init(int size){
    pow.resize(size + 1);
    pow[0] = 1;
    for(int i = 1; i <= size; ++i) pow[i] = pow[i-1] * BASE % MOD;
  }

  static auto gen_hash_table(const T &s){
    RollingHash ret;
    ret.table.resize(s.size() + 1, 0);
    for(int i = 1; i <= (int)s.size(); ++i) ret.table[i] = (ret.table[i-1] * BASE + s[i-1]) % MOD;
    return ret;
  }

  static auto gen_hash(const T &s){
    int64_t ret = 0;
    for(int i = 0; i < (int)s.size(); ++i) ret = (ret * BASE + s[i]) % MOD;
    return ret;
  }

  /**
   * @attention [l, r)
   */
  int64_t get(int l, int r) const {
    return (table[r] - table[l] * pow[r-l] + MOD * MOD) % MOD;
  }
};

template <typename T, int64_t BASE, int64_t MOD>
std::vector<int64_t> RollingHash<T,BASE,MOD>::pow;
