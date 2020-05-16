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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/ALDS1_14_C/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4663ce58de854a9b7b2acb9ce1fd08fb">test/aoj/ALDS1_14_C</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_14_C/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 14:34:19+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/String/rolling_hash_2d.cpp.html">RollingHash (2D)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include <iostream>
#include <string>
#include <vector>
#include "Mylib/String/rolling_hash_2d.cpp"

int main(){
  auto rh = make_rh_2d(1000, 1000, 1000000007);
  
  int H, W; std::cin >> H >> W;
  std::vector<std::string> s(H);
  for(int i = 0; i < H; ++i) std::cin >> s[i];

  int R, C; std::cin >> R >> C;
  std::vector<std::string> t(R);
  for(int i = 0; i < R; ++i) std::cin >> t[i];

  auto table = rh.gen_hash_table(s);
  auto hash = rh.gen_hash(t);
  
  for(int i = 0; i <= H-R; ++i){
    for(int j = 0; j <= W-C; ++j){
      if(rh.get(table, i, j, i + R, j + C) == hash){
        std::cout << i << " " << j << std::endl;
      }
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_14_C/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include <iostream>
#include <string>
#include <vector>
#line 3 "Mylib/String/rolling_hash_2d.cpp"
#include <random>

/**
 * @title RollingHash (2D)
 * @docs rolling_hash_2d.md
 */
class RollingHash2D{
  std::vector<int64_t> pow_w, pow_h;
  int64_t MOD, BASEW, BASEH;

public:
  RollingHash2D(int width, int height, int MOD, int BASEW, int BASEH): MOD(MOD), BASEW(BASEW), BASEH(BASEH){
    pow_w.resize(width + 1);
    pow_h.resize(height + 1);
    pow_w[0] = pow_h[0] = 1;
    for(int i = 1; i <= width; ++i) pow_w[i] = pow_w[i-1] * BASEW % MOD;
    for(int i = 1; i <= height; ++i) pow_h[i] = pow_h[i-1] * BASEH % MOD;
  }

  template <typename T>
  auto gen_hash_table(const T &s){
    const int n = s.size(), m = s[0].size();
    std::vector<std::vector<int64_t>> ret(n+1, std::vector<int64_t>(m+1));

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        ret[i+1][j+1] = (ret[i+1][j] * BASEW + s[i][j]) % MOD;
      }
    }
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        ret[i+1][j+1] = (ret[i][j+1] * BASEH + ret[i+1][j+1]) % MOD;
      }
    }
    
    return ret;
  }

  template <typename T>
  auto gen_hash(const T &s){
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
    const auto b = table[i1][j2] * pow_h[i2-i1] % MOD;
    const auto c = table[i2][j1] * pow_w[j2-j1] % MOD;
    const auto d = table[i1][j1] * pow_h[i2-i1] % MOD * pow_w[j2-j1] % MOD;
    
    return (((a - b + MOD) % MOD - c + MOD) % MOD + d + MOD) % MOD;
  }
};

auto make_rh_2d(int width, int height, int MOD, int seed = 0){
  std::mt19937 rnd(seed);
  std::uniform_int_distribution<> dist(2, MOD-2);
  return RollingHash2D(width, height, dist(rnd), dist(rnd), MOD);
}
#line 7 "test/aoj/ALDS1_14_C/main.test.cpp"

int main(){
  auto rh = make_rh_2d(1000, 1000, 1000000007);
  
  int H, W; std::cin >> H >> W;
  std::vector<std::string> s(H);
  for(int i = 0; i < H; ++i) std::cin >> s[i];

  int R, C; std::cin >> R >> C;
  std::vector<std::string> t(R);
  for(int i = 0; i < R; ++i) std::cin >> t[i];

  auto table = rh.gen_hash_table(s);
  auto hash = rh.gen_hash(t);
  
  for(int i = 0; i <= H-R; ++i){
    for(int j = 0; j <= W-C; ++j){
      if(rh.get(table, i, j, i + R, j + C) == hash){
        std::cout << i << " " << j << std::endl;
      }
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

