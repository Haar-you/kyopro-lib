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


# :heavy_check_mark: test/aoj/ALDS1_14_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6ed7f5103dd44c87e247853bfe87329e">test/aoj/ALDS1_14_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_14_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/String/rolling_hash.cpp.html">Rolling hash</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "Mylib/String/rolling_hash.cpp"

int main(){
  auto rh = make_rh(1000000, 1000000007);
  
  std::string t, p; std::cin >> t >> p;
  
  auto t_hashes = rh.gen_hash_table(t);
  auto p_hash = rh.gen_hash(p);

  for(int i = 0; i < (int)t.size(); ++i){
    if(i + p.size() <= t.size() and rh.get(t_hashes, i, i + p.size()) == p_hash){
      std::cout << i << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_14_B/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#line 2 "Mylib/String/rolling_hash.cpp"
#include <vector>
#include <random>

/**
 * @title Rolling hash
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
#line 6 "test/aoj/ALDS1_14_B/main.test.cpp"

int main(){
  auto rh = make_rh(1000000, 1000000007);
  
  std::string t, p; std::cin >> t >> p;
  
  auto t_hashes = rh.gen_hash_table(t);
  auto p_hash = rh.gen_hash(p);

  for(int i = 0; i < (int)t.size(); ++i){
    if(i + p.size() <= t.size() and rh.get(t_hashes, i, i + p.size()) == p_hash){
      std::cout << i << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

