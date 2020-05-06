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


# :x: test/yukicoder/658/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a391646de6180927bf7c3f0bfac7f3df">test/yukicoder/658</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/658/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 18:08:42+09:00


* see: <a href="https://yukicoder.me/problems/no/658">https://yukicoder.me/problems/no/658</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp.html">Kitamasa法</a>
* :question: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/658"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp"

using mint = ModInt<17>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int Q; std::cin >> Q;

  while(Q--){
    int64_t N; std::cin >> N;

    KitamasaAlgorithm<mint> ka(4, {0, 0, 0, 1}, {1, 1, 1, 1});
    std::cout << ka[N-1] << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/658/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/658"

#include <iostream>
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title modint
 * @docs mint.md
 */
template <uint32_t M> class ModInt{
public:
  constexpr static uint32_t MOD = M;
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
#line 2 "Mylib/DynamicProgramming/SpeedupTechnique/kitamasa_algorithm.cpp"
#include <vector>

/**
 * @title Kitamasa法
 * @docs kitamasa_algorithm.md
 */
template <typename T> struct KitamasaAlgorithm{
  int size;
  std::vector<T> initial_values, coeff;

  KitamasaAlgorithm(int size, const std::vector<T> &initial_values, const std::vector<T> &coeff):
    size(size), initial_values(initial_values), coeff(coeff){}

  inline std::vector<T> inc(const std::vector<T> &a) const {
    std::vector<T> ret(size);

    for(int i = 0; i < size; ++i) ret[i] += a[size-1] * coeff[i];
    for(int i = 1; i < size; ++i) ret[i] += a[i-1]; 

    return ret;
  }
  
  inline std::vector<T> dbl(const std::vector<T> &a) const {
    std::vector<T> ret(size), b(a);
    
    for(int j = 0; j < size; ++j){
      for(int i = 0; i < size; ++i){
        ret[i] += a[j] * b[i];
      }

      b = inc(b);
    }
    
    return ret;
  }
  
  inline T calc(const std::vector<T> &v) const {
    T ret = 0;
    for(int i = 0; i < size; ++i) ret += v[i] * initial_values[i];
    return ret;
  }

  inline std::vector<T> get(int64_t index) const {
    std::vector<T> ret(size);
    ret[0] = 1;

    bool check = false;
    for(int i = 63; i >= 0; --i){
      if(check) ret = dbl(ret);

      if(index & (1LL << i)){
        ret = inc(ret);
        check = true;
      }
    }
    
    return ret;
  }

  inline T operator[](int64_t index) const {
    if(index < size) return initial_values[index];
    return calc(get(index));
  }
};
#line 6 "test/yukicoder/658/main.test.cpp"

using mint = ModInt<17>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int Q; std::cin >> Q;

  while(Q--){
    int64_t N; std::cin >> N;

    KitamasaAlgorithm<mint> ka(4, {0, 0, 0, 1}, {1, 1, 1, 1});
    std::cout << ka[N-1] << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

