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


# :heavy_check_mark: test/yukicoder/1084/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f3418e7f5c6444b91848f405b9401880">test/yukicoder/1084</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/1084/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-24 11:07:08+09:00


* see: <a href="https://yukicoder.me/problems/no/1084">https://yukicoder.me/problems/no/1084</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Algorithm/Imos/linear_imos_1d.cpp.html">1D Imos algorithm (Linear addition)</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/1084"

#include <iostream>
#include <vector>
#include <algorithm>

#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Algorithm/Imos/linear_imos_1d.cpp"

using mint = ModInt<1000000007>;
const int MAX = 1000000000;

int main(){
  int N; std::cin >> N;
  auto A = input_vector<int64_t>(N);

  mint ans = 0;

  if(std::count(A.begin(), A.end(), 0) == 0){
    LinearImos1D<int64_t> p(N);
    
    std::vector<int> next(N);
    for(int i = N-1; i >= 0; --i){
      if(A[i] == 1){
        if(i == N-1) next[i] = N;
        else{
          if(A[i + 1] == 1){
            next[i] = next[i + 1];
          }else{
            next[i] = i + 1;
          }
        }
      }else{
        next[i] = i + 1;
      }
    }

    for(int l = 0; l < N; ++l){
      int64_t prod = 1;

      int r = l;

      for(int i = 0; i < 100; ++i){
        if(r == N or prod * A[r] >= MAX) break;
        prod *= A[r];
        r = next[r];
      }
        
      p.add(l, r, -1, r);
    }

    p.build();
      
    ans = 1;
    for(int i = 0; i < N; ++i){
      ans *= mint::power(A[i], p[i]);
    }
  }

  std::cout << ans << "\n";
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/1084/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/1084"

#include <iostream>
#include <vector>
#include <algorithm>

#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}
#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title Modint
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
#line 3 "Mylib/Algorithm/Imos/linear_imos_1d.cpp"

/**
 * @title 1D Imos algorithm (Linear addition)
 * @docs linear_imos_1d.md
 */
template <typename T> struct LinearImos1D{
  std::vector<T> vec_a, vec_a_end, vec_b, vec;
  int n;

  LinearImos1D(int n): vec_a(n+1), vec_a_end(n+1), vec_b(n+1), vec(n+1), n(n){}

  void add(int s, int t, const T &a, const T &b){ // x∈[s,t)にax+bを加算する。
    vec_a[s+1] += a;
    vec_a[t] -= a;
    
    vec_a_end[t] -= a * (t-s-1);

    vec_b[s] += a * s + b;
    vec_b[t] -= a * s + b;
  }

  void build(){
    for(int i = 0; i < n; ++i) vec_a[i+1] += vec_a[i];
    for(int i = 0; i <= n; ++i) vec_a[i] += vec_a_end[i];
    for(int i = 0; i < n; ++i) vec_a[i+1] += vec_a[i];

    for(int i = 0; i < n; ++i) vec_b[i+1] += vec_b[i];

    for(int i = 0; i <= n; ++i) vec[i] = vec_a[i] + vec_b[i];
  }

  inline const T operator[](size_t i) const {return vec[i];}
};
#line 10 "test/yukicoder/1084/main.test.cpp"

using mint = ModInt<1000000007>;
const int MAX = 1000000000;

int main(){
  int N; std::cin >> N;
  auto A = input_vector<int64_t>(N);

  mint ans = 0;

  if(std::count(A.begin(), A.end(), 0) == 0){
    LinearImos1D<int64_t> p(N);
    
    std::vector<int> next(N);
    for(int i = N-1; i >= 0; --i){
      if(A[i] == 1){
        if(i == N-1) next[i] = N;
        else{
          if(A[i + 1] == 1){
            next[i] = next[i + 1];
          }else{
            next[i] = i + 1;
          }
        }
      }else{
        next[i] = i + 1;
      }
    }

    for(int l = 0; l < N; ++l){
      int64_t prod = 1;

      int r = l;

      for(int i = 0; i < 100; ++i){
        if(r == N or prod * A[r] >= MAX) break;
        prod *= A[r];
        r = next[r];
      }
        
      p.add(l, r, -1, r);
    }

    p.build();
      
    ans = 1;
    for(int i = 0; i < N; ++i){
      ans *= mint::power(A[i], p[i]);
    }
  }

  std::cout << ans << "\n";
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

