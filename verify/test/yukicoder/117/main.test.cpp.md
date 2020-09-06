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


# :x: test/yukicoder/117/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f01f019f5d83aaae637417bc3568edb5">test/yukicoder/117</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/117/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00


* see: <a href="https://yukicoder.me/problems/no/117">https://yukicoder.me/problems/no/117</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Combinatorics/factorial_table.cpp.html">Factorial table</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>
#include <string>
#include <regex>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/IO/input_tuples.cpp"

using mint = ModInt<1000000007>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  auto ft = FactorialTable<mint>(2000000);

  int T; std::cin >> T;

  std::regex re(R"((.)\((.+),(.+)\))");

  for(auto [s] : input_tuples<std::string>(T)){
    std::smatch m;
    std::regex_match(s, m, re);

    char type = m[1].str()[0];
    int N = std::stoi(m[2].str());
    int K = std::stoi(m[3].str());

    switch(type){
    case 'C': std::cout << ft.C(N, K) << "\n"; break;
    case 'P': std::cout << ft.P(N, K) << "\n"; break;
    case 'H': std::cout << ft.H(N, K) << "\n"; break;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/117/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>
#include <string>
#include <regex>
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title Modint
 * @docs mint.md
 */
template <int32_t M>
class ModInt {
public:
  constexpr static int32_t MOD = M;
  uint32_t val;

  constexpr ModInt(): val(0){}
  constexpr ModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }

  constexpr auto& operator=(const ModInt &a){val = a.val; return *this;}
  constexpr auto& operator+=(const ModInt &a){
    if(val + a.val >= M) val = (uint64_t)val + a.val - M;
    else val += a.val;
    return *this;
  }
  constexpr auto& operator-=(const ModInt &a){
    if(val < a.val) val += M;
    val -= a.val;
    return *this;
  }
  constexpr auto& operator*=(const ModInt &a){
    val = (uint64_t)val * a.val % M;
    return *this;
  }
  constexpr auto& operator/=(const ModInt &a){
    val = (uint64_t)val * a.inv().val % M;
    return *this;
  }

  constexpr auto operator+(const ModInt &a) const {return ModInt(*this) += a;}
  constexpr auto operator-(const ModInt &a) const {return ModInt(*this) -= a;}
  constexpr auto operator*(const ModInt &a) const {return ModInt(*this) *= a;}
  constexpr auto operator/(const ModInt &a) const {return ModInt(*this) /= a;}

  constexpr bool operator==(const ModInt &a) const {return val == a.val;}
  constexpr bool operator!=(const ModInt &a) const {return val != a.val;}

  constexpr auto& operator++(){*this += 1; return *this;}
  constexpr auto& operator--(){*this -= 1; return *this;}

  constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
  constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}

  constexpr static ModInt power(int64_t n, int64_t p){
    if(p < 0) return power(n, -p).inv();

    int64_t ret = 1, e = n % M;
    for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
    return ret;
  }

  constexpr static ModInt inv(int64_t a){
    int64_t b = M, u = 1, v = 0;

    while(b){
      int64_t t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }

    u %= M;
    if(u < 0) u += M;

    return u;
  }

  constexpr static auto frac(int64_t a, int64_t b){return ModInt(a) / ModInt(b);}

  constexpr auto power(int64_t p) const {return power(val, p);}
  constexpr auto inv() const {return inv(val);}

  friend constexpr auto operator-(const ModInt &a){return ModInt(M - a.val);}

  friend constexpr auto operator+(int64_t a, const ModInt &b){return ModInt(a) + b;}
  friend constexpr auto operator-(int64_t a, const ModInt &b){return ModInt(a) - b;}
  friend constexpr auto operator*(int64_t a, const ModInt &b){return ModInt(a) * b;}
  friend constexpr auto operator/(int64_t a, const ModInt &b){return ModInt(a) / b;}

  friend std::istream& operator>>(std::istream &s, ModInt<M> &a){s >> a.val; return s;}
  friend std::ostream& operator<<(std::ostream &s, const ModInt<M> &a){s << a.val; return s;}

  template <int N>
  static auto div(){
    static auto value = inv(N);
    return value;
  }

  explicit operator int32_t() const noexcept {return val;}
  explicit operator int64_t() const noexcept {return val;}
};
#line 2 "Mylib/Combinatorics/factorial_table.cpp"
#include <vector>
#include <cassert>
#include <cstdint>

/**
 * @title Factorial table
 * @docs factorial_table.md
 */
template <typename T>
class FactorialTable {
public:
  using value_type = T;

private:
  std::vector<T> f_table;
  std::vector<T> if_table;

public:
  FactorialTable(int N){
    f_table.assign(N + 1, 1);
    if_table.assign(N + 1, 1);

    for(int i = 1; i <= N; ++i){
      f_table[i] = f_table[i - 1] * i;
    }

    if_table[N] = f_table[N].inv();

    for(int i = N; --i >= 0;){
      if_table[i] = if_table[i + 1] * (i + 1);
    }
  }

  T factorial(int64_t i) const {
    assert(i < (int)f_table.size());
    return f_table[i];
  }

  T inv_factorial(int64_t i) const {
    assert(i < (int)if_table.size());
    return if_table[i];
  }

  T P(int64_t n, int64_t k) const {
    if(n < k or n < 0 or k < 0) return 0;
    return factorial(n) * inv_factorial(n - k);
  }

  T C(int64_t n, int64_t k) const {
    if(n < k or n < 0 or k < 0) return 0;
    return P(n, k) * inv_factorial(k);
  }

  T H(int64_t n, int64_t k) const {
    if(n == 0 and k == 0) return 1;
    return C(n + k - 1, k);
  }
};
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples {
  struct iter {
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool fetched = false;
    int N, c = 0;

    value_type operator*(){
      if(not fetched){
        std::cin >> value;
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 9 "test/yukicoder/117/main.test.cpp"

using mint = ModInt<1000000007>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  auto ft = FactorialTable<mint>(2000000);

  int T; std::cin >> T;

  std::regex re(R"((.)\((.+),(.+)\))");

  for(auto [s] : input_tuples<std::string>(T)){
    std::smatch m;
    std::regex_match(s, m, re);

    char type = m[1].str()[0];
    int N = std::stoi(m[2].str());
    int K = std::stoi(m[3].str());

    switch(type){
    case 'C': std::cout << ft.C(N, K) << "\n"; break;
    case 'P': std::cout << ft.P(N, K) << "\n"; break;
    case 'H': std::cout << ft.H(N, K) << "\n"; break;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

