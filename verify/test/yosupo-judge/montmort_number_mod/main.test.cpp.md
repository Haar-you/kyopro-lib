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


# :x: test/yosupo-judge/montmort_number_mod/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#910a463805ae5ab8a646512f693c1fa3">test/yosupo-judge/montmort_number_mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/montmort_number_mod/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/montmort_number_mod">https://judge.yosupo.jp/problem/montmort_number_mod</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Combinatorics/montmort_number.cpp.html">Montmort number</a>
* :question: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>
* :question: <a href="../../../../library/Mylib/Number/Mint/runtime_mint.cpp.html">Modint (Runtime mod)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include <iostream>
#include "Mylib/Number/Mint/runtime_mint.cpp"
#include "Mylib/Combinatorics/montmort_number.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

struct tag {};
using mint = hl::runtime_modint<tag>;

int main(){
  int N, M; std::cin >> N >> M;

  mint::init(M);

  auto ans = hl::montmort_number<mint>(1000000);

  std::cout << hl::join(ans.begin() + 1, ans.begin() + N + 1) << "\n";

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
 * @title Modint (Runtime mod)
 * @docs runtime_mint.md
 */
namespace haar_lib {
  template <typename Tag>
  class runtime_modint {
  public:
    static uint32_t M;

    uint64_t val;
    runtime_modint(): val(0){}
    runtime_modint(int64_t n){
      if(n >= M) val = n % M;
      else if(n < 0) val = n % M + M;
      else val = n;
    }

    auto operator+(const runtime_modint &a) const {return runtime_modint(val + a.val);}
    auto operator-(const runtime_modint &a) const {return runtime_modint(val - a.val);}
    auto operator*(const runtime_modint &a) const {return runtime_modint(val * a.val);}
    auto operator/(const runtime_modint &a) const {return runtime_modint(val * a.inv().val);}

    const auto& operator=(const runtime_modint &a){val = a.val; return *this;}
    const auto& operator+=(const runtime_modint &a){if((val += a.val) >= M) val -= M; return *this;}
    const auto& operator-=(const runtime_modint &a){if(val < a.val) val += M; val -= a.val; return *this;}
    const auto& operator*=(const runtime_modint &a){(val *= a.val) %= M; return *this;}
    const auto& operator/=(const runtime_modint &a){(val *= a.inv().val) %= M; return *this;}

    bool operator==(const runtime_modint &a) const {return val == a.val;}
    bool operator!=(const runtime_modint &a) const {return val != a.val;}

    static auto power(int64_t n, int64_t p){
      runtime_modint ret = 1, e = n;
      for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
      return ret;
    }

    auto power(int64_t p) const {
      runtime_modint ret = 1, e = val;
      for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
      return ret;
    }

    runtime_modint inv() const {
      int64_t a = val, b = M, u = 1, v = 0;

      while(b){
        int64_t t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
      }
      u %= M;
      if(u < 0) u += M;

      return u;
    }

    explicit operator int32_t() const noexcept {return val;}
    explicit operator int64_t() const noexcept {return val;}

    static void init(uint32_t m){M = m;}
  };

  template <typename Tag> auto operator-(const runtime_modint<Tag> &a){return runtime_modint(-a.val);}

  template <typename Tag> auto operator+(int64_t a, const runtime_modint<Tag> &b){return runtime_modint(a) + b;}
  template <typename Tag> auto operator-(int64_t a, const runtime_modint<Tag> &b){return runtime_modint(a) - b;}
  template <typename Tag> auto operator*(int64_t a, const runtime_modint<Tag> &b){return runtime_modint(a) * b;}
  template <typename Tag> auto operator/(int64_t a, const runtime_modint<Tag> &b){return runtime_modint(a) / b;}

  template <typename Tag> uint32_t runtime_modint<Tag>::M;

  template <typename Tag> std::istream& operator>>(std::istream &is, runtime_modint<Tag> &a){is >> a.val; return is;}
  template <typename Tag> std::ostream& operator<<(std::ostream &os, const runtime_modint<Tag> &a){os << a.val; return os;}
}
#line 2 "Mylib/Combinatorics/montmort_number.cpp"
#include <vector>

/**
 * @title Montmort number
 * @docs montmort_number.md
 */
namespace haar_lib {
  template <typename T>
  auto montmort_number(int n){
    std::vector<T> ret(n + 1);

    ret[0] = 1;
    ret[1] = 0;
    ret[2] = 1;

    for(int i = 3; i <= n; ++i){
      ret[i] = (ret[i - 1] + ret[i - 2]) * (i - 1);
    }

    return ret;
  }
}
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
namespace haar_lib {
  template <typename Iter>
  std::string join(Iter first, Iter last, std::string delim = " "){
    std::stringstream s;

    for(auto it = first; it != last; ++it){
      if(it != first) s << delim;
      s << *it;
    }

    return s.str();
  }
}
#line 7 "test/yosupo-judge/montmort_number_mod/main.test.cpp"

namespace hl = haar_lib;

struct tag {};
using mint = hl::runtime_modint<tag>;

int main(){
  int N, M; std::cin >> N >> M;

  mint::init(M);

  auto ans = hl::montmort_number<mint>(1000000);

  std::cout << hl::join(ans.begin() + 1, ans.begin() + N + 1) << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
