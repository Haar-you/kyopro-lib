---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: Rolling hash (2D)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/rolling_hash_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/ALDS1_14_C/main.test.cpp.html">test/aoj/ALDS1_14_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <random>

/**
 * @title Rolling hash (2D)
 * @docs rolling_hash_2d.md
 */
class RollingHash2D {
  std::vector<int64_t> pow_w, pow_h;
  int64_t MOD, BASEW, BASEH;

public:
  RollingHash2D(int width, int height, int MOD, int BASEW, int BASEH): MOD(MOD), BASEW(BASEW), BASEH(BASEH){
    pow_w.resize(width + 1);
    pow_h.resize(height + 1);
    pow_w[0] = pow_h[0] = 1;
    for(int i = 1; i <= width; ++i) pow_w[i] = pow_w[i - 1] * BASEW % MOD;
    for(int i = 1; i <= height; ++i) pow_h[i] = pow_h[i - 1] * BASEH % MOD;
  }

  template <typename T>
  auto gen_hash_table(const T &s) const {
    const int n = s.size(), m = s[0].size();
    std::vector<std::vector<int64_t>> ret(n + 1, std::vector<int64_t>(m + 1));

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        ret[i + 1][j + 1] = (ret[i + 1][j] * BASEW + s[i][j]) % MOD;
      }
    }
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        ret[i + 1][j + 1] = (ret[i][j + 1] * BASEH + ret[i + 1][j + 1]) % MOD;
      }
    }

    return ret;
  }

  template <typename T>
  auto gen_hash(const T &s) const {
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
  int64_t get(const std::vector<std::vector<int64_t>> &table, int i1, int j1, int i2, int j2) const {
    const auto a = table[i2][j2];
    const auto b = table[i1][j2] * pow_h[i2 - i1] % MOD;
    const auto c = table[i2][j1] * pow_w[j2 - j1] % MOD;
    const auto d = table[i1][j1] * pow_h[i2 - i1] % MOD * pow_w[j2 - j1] % MOD;

    return (((a - b + MOD) % MOD - c + MOD) % MOD + d + MOD) % MOD;
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

    for(int i = 0; i <= H - R; ++i){
      for(int j = 0; j <= W - C; ++j){
        if(hp == get(hs, i, j, i + R, j + C)) ret.emplace_back(i, j);
      }
    }

    return ret;
  }
};

auto make_rh_2d(int width, int height, int MOD, int seed = 0){
  std::mt19937 rnd(seed);
  std::uniform_int_distribution<> dist(2, MOD - 2);
  return RollingHash2D(width, height, dist(rnd), dist(rnd), MOD);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/rolling_hash_2d.cpp"
#include <vector>
#include <random>

/**
 * @title Rolling hash (2D)
 * @docs rolling_hash_2d.md
 */
class RollingHash2D {
  std::vector<int64_t> pow_w, pow_h;
  int64_t MOD, BASEW, BASEH;

public:
  RollingHash2D(int width, int height, int MOD, int BASEW, int BASEH): MOD(MOD), BASEW(BASEW), BASEH(BASEH){
    pow_w.resize(width + 1);
    pow_h.resize(height + 1);
    pow_w[0] = pow_h[0] = 1;
    for(int i = 1; i <= width; ++i) pow_w[i] = pow_w[i - 1] * BASEW % MOD;
    for(int i = 1; i <= height; ++i) pow_h[i] = pow_h[i - 1] * BASEH % MOD;
  }

  template <typename T>
  auto gen_hash_table(const T &s) const {
    const int n = s.size(), m = s[0].size();
    std::vector<std::vector<int64_t>> ret(n + 1, std::vector<int64_t>(m + 1));

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        ret[i + 1][j + 1] = (ret[i + 1][j] * BASEW + s[i][j]) % MOD;
      }
    }
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        ret[i + 1][j + 1] = (ret[i][j + 1] * BASEH + ret[i + 1][j + 1]) % MOD;
      }
    }

    return ret;
  }

  template <typename T>
  auto gen_hash(const T &s) const {
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
  int64_t get(const std::vector<std::vector<int64_t>> &table, int i1, int j1, int i2, int j2) const {
    const auto a = table[i2][j2];
    const auto b = table[i1][j2] * pow_h[i2 - i1] % MOD;
    const auto c = table[i2][j1] * pow_w[j2 - j1] % MOD;
    const auto d = table[i1][j1] * pow_h[i2 - i1] % MOD * pow_w[j2 - j1] % MOD;

    return (((a - b + MOD) % MOD - c + MOD) % MOD + d + MOD) % MOD;
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

    for(int i = 0; i <= H - R; ++i){
      for(int j = 0; j <= W - C; ++j){
        if(hp == get(hs, i, j, i + R, j + C)) ret.emplace_back(i, j);
      }
    }

    return ret;
  }
};

auto make_rh_2d(int width, int height, int MOD, int seed = 0){
  std::mt19937 rnd(seed);
  std::uniform_int_distribution<> dist(2, MOD - 2);
  return RollingHash2D(width, height, dist(rnd), dist(rnd), MOD);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

