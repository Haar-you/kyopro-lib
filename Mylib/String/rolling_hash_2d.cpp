#pragma once
#include <vector>

/**
 * @title Rolling Hash 2D
 */
template <typename T, int64_t BASEW, int64_t BASEH, int64_t MOD>
class RollingHash2D{
  static std::vector<int64_t> pow_w, pow_h;

public:
  std::vector<std::vector<int64_t>> table;
  
  static void init(int width, int height){
    pow_w.resize(width + 1);
    pow_h.resize(height + 1);
    pow_w[0] = pow_h[0] = 1;
    for(int i = 1; i <= width; ++i) pow_w[i] = pow_w[i-1] * BASEW % MOD;
    for(int i = 1; i <= height; ++i) pow_h[i] = pow_h[i-1] * BASEH % MOD;
  }
  
  static auto gen_hash_table(const T &s){
    const int n = s.size(), m = s[0].size();
    RollingHash2D ret;
    ret.table = std::vector<std::vector<int64_t>>(n+1, std::vector<int64_t>(m+1));
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= m; ++j){
        ret.table[i][j] = (ret.table[i][j-1] * BASEW + s[i-1][j-1]) % MOD;
      }
    }
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= m; ++j){
        ret.table[i][j] = (ret.table[i-1][j] * BASEH + ret.table[i][j]) % MOD;
      }
    }
    return ret;
  }

  static auto gen_hash(const T &s){
    const int n = s.size(), m = s[0].size();
    int64_t ret = 0;
    for(int i = 0; i < n; ++i){
      int64_t temp = 0;
      for(int j = 0; j < m; ++j){
        temp = (temp * BASEW + s[i][j]) % MOD;
      }
      ret = (ret * BASEH + temp) % MOD;
    }
    return ret;
  }

  /**
   * @attention [i1, i2), [j1, j2)
   */
  int64_t get(int i1, int j1, int i2, int j2) const {
    const auto a = table[i2][j2];
    const auto b = table[i1][j2] * pow_h[i2-i1] % MOD;
    const auto c = table[i2][j1] * pow_w[j2-j1] % MOD;
    const auto d = table[i1][j1] * pow_h[i2-i1] % MOD * pow_w[j2-j1] % MOD;
    
    return (((a - b + MOD) % MOD - c + MOD) % MOD + d + MOD) % MOD;
  }
};

template <typename T, int64_t BASEW, int64_t BASEH, int64_t MOD>
std::vector<int64_t> RollingHash2D<T,BASEW,BASEH,MOD>::pow_w;
template <typename T, int64_t BASEW, int64_t BASEH, int64_t MOD>
std::vector<int64_t> RollingHash2D<T,BASEW,BASEH,MOD>::pow_h;
