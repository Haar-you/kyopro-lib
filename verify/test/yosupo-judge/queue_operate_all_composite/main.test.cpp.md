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


# :heavy_check_mark: test/yosupo-judge/queue_operate_all_composite/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c8d31b5139983c6742fe36acb5e1ac81">test/yosupo-judge/queue_operate_all_composite</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/queue_operate_all_composite/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 19:24:13+09:00


* see: <a href="https://judge.yosupo.jp/problem/queue_operate_all_composite">https://judge.yosupo.jp/problem/queue_operate_all_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Algorithm/SlidingWindow/sliding_window_aggregation.cpp.html">Sliding Window Aggregation</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Algorithm/SlidingWindow/sliding_window_aggregation.cpp"

using mint = ModInt<998244353>;

struct linear_function{
  mint a, b;
};

auto composite =
  [](const linear_function &q, const linear_function &p){
    return linear_function({p.a * q.a, p.a * q.b + p.b});
  };


int main(){
  int Q; std::cin >> Q;

  auto swag = SlidingWindowAggregation<linear_function, decltype(composite)>(composite);
  
  while(Q--){
    int type; std::cin >> type;

    if(type == 0){
      int a,b; std::cin >> a >> b;
      swag.push({a, b});
    }else if(type == 1){
      swag.pop();
    }else{
      int x; std::cin >> x;
      auto res = swag.fold();
      if(res){
        auto [a, b] = *res;
        std::cout << a * x + b << std::endl;
      }else{
        std::cout << x << std::endl;
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
#line 1 "test/yosupo-judge/queue_operate_all_composite/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title modint
 */
template <uint32_t M> class ModInt{
public:
  uint64_t val;
  
  constexpr ModInt(): val(0){}
  constexpr ModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  inline constexpr auto operator+(const ModInt &a) const {return ModInt(val + a.val);}
  inline constexpr auto operator-(const ModInt &a) const {return ModInt(val - a.val);}
  inline constexpr auto operator*(const ModInt &a) const {return ModInt(val * a.val);}
  inline constexpr auto operator/(const ModInt &a) const {return ModInt(val * a.inv().val);}
  
  inline constexpr auto& operator=(const ModInt &a){val = a.val; return *this;}
  inline constexpr auto& operator+=(const ModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  inline constexpr auto& operator-=(const ModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  inline constexpr auto& operator*=(const ModInt &a){(val *= a.val) %= M; return *this;}
  inline constexpr auto& operator/=(const ModInt &a){(val *= a.inv().val) %= M; return *this;}
 
  inline constexpr bool operator==(const ModInt &a) const {return val == a.val;}
  inline constexpr bool operator!=(const ModInt &a) const {return val != a.val;}
 
  inline constexpr auto& operator++(){*this += 1; return *this;}
  inline constexpr auto& operator--(){*this -= 1; return *this;}
 
  inline constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
  inline constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}
 
  inline constexpr static ModInt power(int64_t n, int64_t p){
    if(p < 0) return power(n, -p).inv();
    
    int64_t ret = 1, e = n % M;
    for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
    return ret;
  }
 
  inline constexpr static ModInt inv(int64_t a){
    int64_t b = M, u = 1, v = 0;
    
    while(b){
      int64_t t = a / b;
      a -= t * b; std::swap(a,b);
      u -= t * v; std::swap(u,v);
    }
 
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
 
  inline constexpr static auto frac(int64_t a, int64_t b){return ModInt(a) / ModInt(b);}
  
  inline constexpr auto power(int64_t p) const {return power(val, p);}
  inline constexpr auto inv() const {return inv(val);}
 
  friend inline constexpr auto operator-(const ModInt &a){return ModInt(-a.val);}
 
  friend inline constexpr auto operator+(int64_t a, const ModInt &b){return ModInt(a) + b;}
  friend inline constexpr auto operator-(int64_t a, const ModInt &b){return ModInt(a) - b;}
  friend inline constexpr auto operator*(int64_t a, const ModInt &b){return ModInt(a) * b;}
  friend inline constexpr auto operator/(int64_t a, const ModInt &b){return ModInt(a) / b;}
 
  friend std::istream& operator>>(std::istream &s, ModInt<M> &a){s >> a.val; return s;}
  friend std::ostream& operator<<(std::ostream &s, const ModInt<M> &a){s << a.val; return s;}

  template <int N>
  inline static auto div(){
    static auto value = inv(N);
    return value;
  }

  explicit operator int32_t() const noexcept {return val;}
  explicit operator int64_t() const noexcept {return val;}
};
#line 2 "Mylib/Algorithm/SlidingWindow/sliding_window_aggregation.cpp"
#include <vector>
#include <stack>
#include <optional>

/**
 * @title Sliding Window Aggregation
 * @see https://scrapbox.io/data-structures/Sliding_Window_Aggregation
 */
template <typename T, typename F>
class SlidingWindowAggregation{
  std::stack<T> front_stack, back_stack;
  std::vector<T> front_sum, back_sum;

  const F f;
  
public:
  SlidingWindowAggregation(const F &f): f(f){}
  
  std::optional<T> fold() const {
    if(front_sum.empty()){
      if(back_sum.empty()) return std::nullopt;
      return {back_sum.back()};
    }else{
      if(back_sum.empty()) return {front_sum.back()};
      return {f(front_sum.back(), back_sum.back())};
    }
  }

  void push(const T &value){
    back_stack.push(value);

    if(back_sum.empty()){
      back_sum.push_back(value);
    }else{
      const auto t = f(back_sum.back(), value);
      back_sum.push_back(t);
    }
  }

  void pop(){
    if(front_stack.empty()){
      back_sum.clear();

      while(not back_stack.empty()){
        const auto value = back_stack.top(); back_stack.pop();
        front_stack.push(value);

        if(front_sum.empty()){
          front_sum.push_back(value);
        }else{
          const auto t = f(value, front_sum.back());
          front_sum.push_back(t);
        }
      }
    }

    front_stack.pop();
    front_sum.pop_back();
  }
};
#line 6 "test/yosupo-judge/queue_operate_all_composite/main.test.cpp"

using mint = ModInt<998244353>;

struct linear_function{
  mint a, b;
};

auto composite =
  [](const linear_function &q, const linear_function &p){
    return linear_function({p.a * q.a, p.a * q.b + p.b});
  };


int main(){
  int Q; std::cin >> Q;

  auto swag = SlidingWindowAggregation<linear_function, decltype(composite)>(composite);
  
  while(Q--){
    int type; std::cin >> type;

    if(type == 0){
      int a,b; std::cin >> a >> b;
      swag.push({a, b});
    }else if(type == 1){
      swag.pop();
    }else{
      int x; std::cin >> x;
      auto res = swag.fold();
      if(res){
        auto [a, b] = *res;
        std::cout << a * x + b << std::endl;
      }else{
        std::cout << x << std::endl;
      }
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

