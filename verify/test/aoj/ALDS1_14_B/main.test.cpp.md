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
    - Last commit date: 2020-04-01 12:42:55+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/String/rolling_hash.cpp.html">Mylib/String/rolling_hash.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "Mylib/String/rolling_hash.cpp"

using RH = RollingHash<std::string, 30, 1000000007>;

int main(){
  RH::init(1000000);
  
  std::string t, p; std::cin >> t >> p;
  
  auto t_hashs = RH::gen_hash_table(t);
  auto p_hash = RH::gen_hash(p);

  for(int i = 0; i < (int)t.size(); ++i){
    if(i + p.size() <= t.size() and t_hashs.get(i, i + p.size()) == p_hash){
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

/**
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
#line 6 "test/aoj/ALDS1_14_B/main.test.cpp"

using RH = RollingHash<std::string, 30, 1000000007>;

int main(){
  RH::init(1000000);
  
  std::string t, p; std::cin >> t >> p;
  
  auto t_hashs = RH::gen_hash_table(t);
  auto p_hash = RH::gen_hash(p);

  for(int i = 0; i < (int)t.size(); ++i){
    if(i + p.size() <= t.size() and t_hashs.get(i, i + p.size()) == p_hash){
      std::cout << i << std::endl;
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

