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


# :heavy_check_mark: Rolling Hash

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/rolling_hash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 01:42:28+09:00


* see: <a href="https://yukicoder.me/submissions/347187">https://yukicoder.me/submissions/347187</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_14_B/main.test.cpp.html">test/aoj/ALDS1_14_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/rolling_hash.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

