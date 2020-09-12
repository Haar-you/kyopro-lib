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


# :x: Rolling hash

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/rolling_hash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/ALDS1_14_B/main.test.cpp.html">test/aoj/ALDS1_14_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <random>

/**
 * @title Rolling hash
 * @docs rolling_hash.md
 */
namespace haar_lib {
  class rolling_hash {
    std::vector<int64_t> pow;
    int64_t MOD, BASE;

  public:
    rolling_hash(int size, int MOD, int BASE): MOD(MOD), BASE(BASE){
      pow.resize(size + 1);
      pow[0] = 1;
      for(int i = 1; i <= size; ++i) pow[i] = pow[i - 1] * BASE % MOD;
    }

    template <typename T>
    auto gen_hash_table(const T &s) const {
      std::vector<int64_t> ret(s.size() + 1);
      for(int i = 0; i < (int)s.size(); ++i) ret[i + 1] = (ret[i] * BASE + s[i]) % MOD;
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
      return (table[r] - table[l] * pow[r - l] % MOD + MOD * MOD) % MOD;
    }

    template <typename T>
    std::vector<int> find(const T &s, const T &pattern) const {
      auto hp = gen_hash(pattern);
      auto hs = gen_hash_table(s);
      std::vector<int> ret;
      for(int i = 0; i <= ((int)s.size() - (int)pattern.size()); ++i){
        if(hp == get(hs, i, i + pattern.size())) ret.push_back(i);
      }

      return ret;
    }
  };

  auto make_rh(int size, int MOD, int seed = 0){
    std::mt19937 rnd(seed);
    std::uniform_int_distribution<> dist(2, MOD - 2);
    return rolling_hash(size, dist(rnd), MOD);
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/rolling_hash.cpp"
#include <vector>
#include <random>

/**
 * @title Rolling hash
 * @docs rolling_hash.md
 */
namespace haar_lib {
  class rolling_hash {
    std::vector<int64_t> pow;
    int64_t MOD, BASE;

  public:
    rolling_hash(int size, int MOD, int BASE): MOD(MOD), BASE(BASE){
      pow.resize(size + 1);
      pow[0] = 1;
      for(int i = 1; i <= size; ++i) pow[i] = pow[i - 1] * BASE % MOD;
    }

    template <typename T>
    auto gen_hash_table(const T &s) const {
      std::vector<int64_t> ret(s.size() + 1);
      for(int i = 0; i < (int)s.size(); ++i) ret[i + 1] = (ret[i] * BASE + s[i]) % MOD;
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
      return (table[r] - table[l] * pow[r - l] % MOD + MOD * MOD) % MOD;
    }

    template <typename T>
    std::vector<int> find(const T &s, const T &pattern) const {
      auto hp = gen_hash(pattern);
      auto hs = gen_hash_table(s);
      std::vector<int> ret;
      for(int i = 0; i <= ((int)s.size() - (int)pattern.size()); ++i){
        if(hp == get(hs, i, i + pattern.size())) ret.push_back(i);
      }

      return ret;
    }
  };

  auto make_rh(int size, int MOD, int seed = 0){
    std::mt19937 rnd(seed);
    std::uniform_int_distribution<> dist(2, MOD - 2);
    return rolling_hash(size, dist(rnd), MOD);
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

