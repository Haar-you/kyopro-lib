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


# :heavy_check_mark: test/yosupo-judge/montmort_number_mod/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#910a463805ae5ab8a646512f693c1fa3">test/yosupo-judge/montmort_number_mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/montmort_number_mod/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 15:31:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/montmort_number_mod">https://judge.yosupo.jp/problem/montmort_number_mod</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Combinatorics/montmort_number.cpp.html">Mylib/Combinatorics/montmort_number.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mint/runtime_mint.cpp.html">Mylib/Number/Mint/runtime_mint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include <iostream>
#include "Mylib/Number/Mint/runtime_mint.cpp"
#include "Mylib/Combinatorics/montmort_number.cpp"

using mint = RuntimeModInt;

int main(){
  int N, M; std::cin >> N >> M;

  mint::M = M;

  auto ans = montmort_number<mint>(1000000);

  for(int i = 1; i <= N; ++i){
    std::cout << ans[i] << " ";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/montmort_number_mod/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include <iostream>
#line 3 "Mylib/Number/Mint/runtime_mint.cpp"
#include <utility>

/**
 * @attention 使用前にstatic変数Mを設定する。
 */
class RuntimeModInt{
public:
  static uint32_t M;
  
  uint64_t val;
  RuntimeModInt(): val(0){}
  RuntimeModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  const auto operator+(const RuntimeModInt &a) const {return RuntimeModInt(val + a.val);}
  const auto operator-(const RuntimeModInt &a) const {return RuntimeModInt(val - a.val);}
  const auto operator*(const RuntimeModInt &a) const {return RuntimeModInt(val * a.val);}
  const auto operator/(const RuntimeModInt &a) const {return RuntimeModInt(val * a.inv().val);}
  
  const auto& operator=(const RuntimeModInt &a){val = a.val; return *this;}
  const auto& operator+=(const RuntimeModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  const auto& operator-=(const RuntimeModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  const auto& operator*=(const RuntimeModInt &a){(val *= a.val) %= M; return *this;}
  const auto& operator/=(const RuntimeModInt &a){(val *= a.inv().val) %= M; return *this;}

  const bool operator==(const RuntimeModInt &a) const {return val == a.val;}
  const bool operator!=(const RuntimeModInt &a) const {return val != a.val;}

  const static auto power(int64_t n, int64_t p){
    RuntimeModInt ret = 1, e = n;
    for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
    return ret;
  }

  const auto power(int64_t p) const {
    RuntimeModInt ret = 1, e = val;
    for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
    return ret;
  }
  
  const RuntimeModInt inv() const {
    int64_t a = val, b = M, u = 1, v = 0;

    while(b){
      int64_t t = a/b;
      a -= t*b; std::swap(a,b);
      u -= t*v; std::swap(u,v);
    }
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
};

auto operator-(const RuntimeModInt &a){return RuntimeModInt(-a.val);}

auto operator+(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) + b;}
auto operator-(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) - b;}
auto operator*(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) * b;}
auto operator/(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) / b;}

uint32_t RuntimeModInt::M;

std::istream& operator>>(std::istream &is, RuntimeModInt &a){is >> a.val; return is;}
std::ostream& operator<<(std::ostream &os, const RuntimeModInt &a){os << a.val; return os;}
#line 2 "Mylib/Combinatorics/montmort_number.cpp"
#include <vector>

/**
 * @see https://atcoder.jp/contests/arc009/tasks/arc009_3
 * @note 完全順列,撹乱順列の個数
 * @note 1..nの順列を並び変えた時にどの要素も元の要素と異なるような並び替えの総数。
 */
template <typename T>
auto montmort_number(int n){
  std::vector<T> ret(n+1);

  ret[0] = 1;
  ret[1] = 0;
  ret[2] = 1;

  for(int i = 3; i <= n; ++i){
    ret[i] = (ret[i-1] + ret[i-2]) * (i-1);
  }

  return ret;
}
#line 6 "test/yosupo-judge/montmort_number_mod/main.test.cpp"

using mint = RuntimeModInt;

int main(){
  int N, M; std::cin >> N >> M;

  mint::M = M;

  auto ans = montmort_number<mint>(1000000);

  for(int i = 1; i <= N; ++i){
    std::cout << ans[i] << " ";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

