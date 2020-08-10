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


# :heavy_check_mark: test/yukicoder/510/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#79c44d69f4476256a05dd1926185d029">test/yukicoder/510</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/510/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-10 08:29:19+09:00


* see: <a href="https://yukicoder.me/problems/no/510">https://yukicoder.me/problems/no/510</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/dual.cpp.html">Mylib/AlgebraicStructure/Monoid/dual.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/product_matrix.cpp.html">Mylib/AlgebraicStructure/Monoid/product_matrix.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp.html">Square matrix (Const size)</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mint/mint.cpp.html">Modint</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/510"

#include <iostream>
#include <vector>

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/product_matrix.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"
#include "Mylib/IO/input_tuples.cpp"

using mint = ModInt<1000000007>;
using Mat = SquareMatrixConst<mint, 4>;
using Monoid = DualMonoid<ProductMatrixMonoid<Mat>>;

auto f(mint x, mint y){
  Mat ret = {
             {1, 0, x, 0},
             {0, y, 0, 1},
             {0, 2*y, y*y, 1},
             {0, 0, 0, 1}
  };
  return ret;
}

int main(){
  int n, q; std::cin >> n >> q;

  SegmentTree<Monoid> seg(n);
  std::vector<mint> x(n), y(n);

  for(int i = 0; i < n; ++i){
    seg.update(i, f(x[i], y[i]));
  }

  for(auto [c, i] : input_tuples<char, int>(q)){
    if(c == 'x'){
      int v; std::cin >> v;
      x[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else if(c == 'y'){
      int v; std::cin >> v;
      y[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else{
      auto m = seg.get(0, i);
      auto ans = m[0][0] + m[0][1] + m[0][2] + m[0][3];
      std::cout << ans << "\n";
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/510/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/510"

#include <iostream>
#include <vector>

#line 3 "Mylib/Number/Mint/mint.cpp"
#include <utility>

/**
 * @title Modint
 * @docs mint.md
 */
template <int32_t M> class ModInt{
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
      a -= t * b; std::swap(a,b);
      u -= t * v; std::swap(u,v);
    }
    
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
  
  constexpr static auto frac(int64_t a, int64_t b){return ModInt(a) / ModInt(b);}
  
  constexpr auto power(int64_t p) const {return power(val, p);}
  constexpr auto inv() const {return inv(val);}
  
  friend constexpr auto operator-(const ModInt &a){return ModInt(M-a.val);}
  
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
#line 2 "Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp"
#include <array>
#include <initializer_list>
#line 5 "Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp"

/**
 * @title Square matrix (Const size)
 * @docs square_matrix_const_size.md
 */
template <typename T, int N> struct SquareMatrixConst{
  using value_type = T;
  
  std::array<std::array<T,N>,N> matrix;

  SquareMatrixConst(){
    for(size_t i = 0; i < N; ++i) for(size_t j = 0; j < N; ++j) matrix[i][j] = 0;
  }
  SquareMatrixConst(const T &val){
    for(size_t i = 0; i < N; ++i) matrix[i].fill(val);
  }
  SquareMatrixConst(std::initializer_list<std::initializer_list<T>> list){
    int i = 0;
    for(auto it1 = list.begin(); it1 != list.end(); ++it1, ++i){
      int j = 0;
      for(auto it2 = it1->begin(); it2 != it1->end(); ++it2, ++j){
        matrix[i][j] = *it2;
      }
    }
  }

  bool operator==(const SquareMatrixConst &val) const {return matrix == val.matrix;}
  bool operator!=(const SquareMatrixConst &val) const {return !(*this == val);}

  auto& operator=(const SquareMatrixConst &val){
    this->matrix = val.matrix;
    return *this;
  }

  auto& operator+=(const SquareMatrixConst &val){
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];
    return *this;
  }

  auto& operator-=(const SquareMatrixConst &val){
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] - val[i][j];
    return *this;
  }

  auto& operator*=(const SquareMatrixConst &val){
    std::array<std::array<T,N>,N> temp = {};
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];
    std::swap(matrix, temp);
    return *this;
  }

  const auto& operator[](size_t i) const {return matrix[i];}
  auto& operator[](size_t i){return matrix[i];}
  int size() const {return N;}
  
  static auto make_unit(){
    SquareMatrixConst ret;
    for(size_t i = 0; i < N; ++i) ret[i][i] = 1;
    return ret;
  }

  friend auto operator+(const SquareMatrixConst &a, const SquareMatrixConst &b){auto ret = a; ret += b; return ret;}
  friend auto operator-(const SquareMatrixConst &a, const SquareMatrixConst &b){auto ret = a; ret -= b; return ret;}
  friend auto operator*(const SquareMatrixConst &a, const SquareMatrixConst &b){auto ret = a; ret *= b; return ret;}
};
#line 3 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
template <typename Monoid>
class SegmentTree{
  using value_type = typename Monoid::value_type;
  Monoid M;
  
  int depth, size, hsize;
  std::vector<value_type> data;

public:
  SegmentTree(){}
  SegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, M.id())
  {}

  auto operator[](int i) const {return at(i);}
  auto at(int i) const {return data[hsize + i];}
  
  auto get(int x, int y) const { // [x,y)
    value_type ret_left = M.id();
    value_type ret_right = M.id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = M.op(data[--r], ret_right);
      if(l & 1) ret_left = M.op(ret_left, data[l++]);
      l >>= 1, r >>= 1;
    }
    
    return M.op(ret_left, ret_right);
  }

  void update(int i, const value_type &x){
    i += hsize;
    data[i] = x;
    while(i > 1) i >>= 1, data[i] = M.op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &val){
    data.assign(size, M.id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i >= 1; --i) data[i] = M.op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }  
};
#line 2 "Mylib/AlgebraicStructure/Monoid/product_matrix.cpp"

/**
 * @docs product_matrix.md
 */
template <typename T>
struct ProductMatrixMonoid{
  using value_type = T;
  value_type id() const {return T::make_unit();}
  value_type op(const value_type &a, const value_type &b) const {return a * b;}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/dual.cpp"

/**
 * @docs dual.md
 */
template <typename Monoid>
struct DualMonoid{
  using value_type = typename Monoid::value_type;
  Monoid M;
  value_type id() const {return M.id();}
  value_type op(const value_type &a, const value_type &b) const {return M.op(b, a);}
};
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 5 "Mylib/IO/input_tuple.cpp"
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
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
#line 12 "test/yukicoder/510/main.test.cpp"

using mint = ModInt<1000000007>;
using Mat = SquareMatrixConst<mint, 4>;
using Monoid = DualMonoid<ProductMatrixMonoid<Mat>>;

auto f(mint x, mint y){
  Mat ret = {
             {1, 0, x, 0},
             {0, y, 0, 1},
             {0, 2*y, y*y, 1},
             {0, 0, 0, 1}
  };
  return ret;
}

int main(){
  int n, q; std::cin >> n >> q;

  SegmentTree<Monoid> seg(n);
  std::vector<mint> x(n), y(n);

  for(int i = 0; i < n; ++i){
    seg.update(i, f(x[i], y[i]));
  }

  for(auto [c, i] : input_tuples<char, int>(q)){
    if(c == 'x'){
      int v; std::cin >> v;
      x[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else if(c == 'y'){
      int v; std::cin >> v;
      y[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else{
      auto m = seg.get(0, i);
      auto ans = m[0][0] + m[0][1] + m[0][2] + m[0][3];
      std::cout << ans << "\n";
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

