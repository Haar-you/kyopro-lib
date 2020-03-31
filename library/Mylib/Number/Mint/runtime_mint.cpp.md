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


# :heavy_check_mark: Mylib/Number/Mint/runtime_mint.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ed8374f4a8b62e2301eb75f9564224fe">Mylib/Number/Mint</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Mint/runtime_mint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 11:59:58+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/montmort_number_mod/main.test.cpp.html">test/yosupo-judge/montmort_number_mod/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Mint/runtime_mint.cpp"
#include <iostream>
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

