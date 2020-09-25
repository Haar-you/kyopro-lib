---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':x:'
    path: Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp
    title: Square matrix (Const size)
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/product_matrix.cpp
    title: Product matrix monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/dual.cpp
    title: Dual monoid
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/510
    links:
    - https://yukicoder.me/problems/no/510
  bundledCode: "#line 1 \"test/yukicoder/510/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/510\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <int32_t M>\n  class\
    \ modint {\n    uint32_t val;\n\n  public:\n    constexpr static auto mod(){return\
    \ M;}\n\n    constexpr modint(): val(0){}\n    constexpr modint(int64_t n){\n\
    \      if(n >= M) val = n % M;\n      else if(n < 0) val = n % M + M;\n      else\
    \ val = n;\n    }\n\n    constexpr auto& operator=(const modint &a){val = a.val;\
    \ return *this;}\n    constexpr auto& operator+=(const modint &a){\n      if(val\
    \ + a.val >= M) val = (uint64_t)val + a.val - M;\n      else val += a.val;\n \
    \     return *this;\n    }\n    constexpr auto& operator-=(const modint &a){\n\
    \      if(val < a.val) val += M;\n      val -= a.val;\n      return *this;\n \
    \   }\n    constexpr auto& operator*=(const modint &a){\n      val = (uint64_t)val\
    \ * a.val % M;\n      return *this;\n    }\n    constexpr auto& operator/=(const\
    \ modint &a){\n      val = (uint64_t)val * a.inv().val % M;\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const modint &a) const {return modint(*this)\
    \ += a;}\n    constexpr auto operator-(const modint &a) const {return modint(*this)\
    \ -= a;}\n    constexpr auto operator*(const modint &a) const {return modint(*this)\
    \ *= a;}\n    constexpr auto operator/(const modint &a) const {return modint(*this)\
    \ /= a;}\n\n    constexpr bool operator==(const modint &a) const {return val ==\
    \ a.val;}\n    constexpr bool operator!=(const modint &a) const {return val !=\
    \ a.val;}\n\n    constexpr auto& operator++(){*this += 1; return *this;}\n   \
    \ constexpr auto& operator--(){*this -= 1; return *this;}\n\n    constexpr auto\
    \ operator++(int){auto t = *this; *this += 1; return t;}\n    constexpr auto operator--(int){auto\
    \ t = *this; *this -= 1; return t;}\n\n    constexpr static modint pow(int64_t\
    \ n, int64_t p){\n      if(p < 0) return pow(n, -p).inv();\n\n      int64_t ret\
    \ = 1, e = n % M;\n      for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e)\
    \ %= M;\n      return ret;\n    }\n\n    constexpr static modint inv(int64_t a){\n\
    \      int64_t b = M, u = 1, v = 0;\n\n      while(b){\n        int64_t t = a\
    \ / b;\n        a -= t * b; std::swap(a, b);\n        u -= t * v; std::swap(u,\
    \ v);\n      }\n\n      u %= M;\n      if(u < 0) u += M;\n\n      return u;\n\
    \    }\n\n    constexpr static auto frac(int64_t a, int64_t b){return modint(a)\
    \ / modint(b);}\n\n    constexpr auto pow(int64_t p) const {return pow(val, p);}\n\
    \    constexpr auto inv() const {return inv(val);}\n\n    friend constexpr auto\
    \ operator-(const modint &a){return modint(M - a.val);}\n\n    friend constexpr\
    \ auto operator+(int64_t a, const modint &b){return modint(a) + b;}\n    friend\
    \ constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}\n\
    \    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a)\
    \ * b;}\n    friend constexpr auto operator/(int64_t a, const modint &b){return\
    \ modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream &s, modint<M>\
    \ &a){s >> a.val; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint<M> &a){s << a.val; return s;}\n\n    template <int N>\n   \
    \ static auto div(){\n      static auto value = inv(N);\n      return value;\n\
    \    }\n\n    explicit operator int32_t() const noexcept {return val;}\n    explicit\
    \ operator int64_t() const noexcept {return val;}\n  };\n}\n#line 2 \"Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp\"\
    \n#include <array>\n#include <initializer_list>\n#line 5 \"Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, int N>\n  struct square_matrix_const\
    \ {\n    using value_type = T;\n\n    std::array<std::array<T, N>, N> matrix;\n\
    \n    square_matrix_const(){\n      for(size_t i = 0; i < N; ++i) for(size_t j\
    \ = 0; j < N; ++j) matrix[i][j] = 0;\n    }\n    square_matrix_const(const T &val){\n\
    \      for(size_t i = 0; i < N; ++i) matrix[i].fill(val);\n    }\n    square_matrix_const(std::initializer_list<std::initializer_list<T>>\
    \ list){\n      int i = 0;\n      for(auto it1 = list.begin(); it1 != list.end();\
    \ ++it1, ++i){\n        int j = 0;\n        for(auto it2 = it1->begin(); it2 !=\
    \ it1->end(); ++it2, ++j){\n          matrix[i][j] = *it2;\n        }\n      }\n\
    \    }\n\n    bool operator==(const square_matrix_const &val) const {return matrix\
    \ == val.matrix;}\n    bool operator!=(const square_matrix_const &val) const {return\
    \ !(*this == val);}\n\n    auto& operator=(const square_matrix_const &val){\n\
    \      this->matrix = val.matrix;\n      return *this;\n    }\n\n    auto& operator+=(const\
    \ square_matrix_const &val){\n      for(int i = 0; i < N; ++i)\n        for(int\
    \ j = 0; j < N; ++j)\n          matrix[i][j] = matrix[i][j] + val[i][j];\n   \
    \   return *this;\n    }\n\n    auto& operator-=(const square_matrix_const &val){\n\
    \      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n      \
    \    matrix[i][j] = matrix[i][j] - val[i][j];\n      return *this;\n    }\n\n\
    \    auto& operator*=(const square_matrix_const &val){\n      std::array<std::array<T,\
    \ N>, N> temp = {};\n      for(int i = 0; i < N; ++i)\n        for(int j = 0;\
    \ j < N; ++j)\n          for(int k = 0; k < N; ++k)\n            temp[i][j] +=\
    \ matrix[i][k] * val[k][j];\n      std::swap(matrix, temp);\n      return *this;\n\
    \    }\n\n    const auto& operator[](size_t i) const {return matrix[i];}\n   \
    \ auto& operator[](size_t i){return matrix[i];}\n    int size() const {return\
    \ N;}\n\n    static auto unit(){\n      square_matrix_const ret;\n      for(size_t\
    \ i = 0; i < N; ++i) ret[i][i] = 1;\n      return ret;\n    }\n\n    friend auto\
    \ operator+(const square_matrix_const &a, const square_matrix_const &b){\n   \
    \   auto ret = a; return ret += b;\n    }\n    friend auto operator-(const square_matrix_const\
    \ &a, const square_matrix_const &b){\n      auto ret = a; return ret -= b;\n \
    \   }\n    friend auto operator*(const square_matrix_const &a, const square_matrix_const\
    \ &b){\n      auto ret = a; return ret *= b;\n    }\n\n    auto pow(uint64_t p)\
    \ const {\n      auto ret = unit();\n      auto a = *this;\n\n      while(p >\
    \ 0){\n        if(p & 1) ret *= a;\n        a *= a;\n        p >>= 1;\n      }\n\
    \n      return ret;\n    }\n  };\n}\n#line 3 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <algorithm>\n#include <functional>\n\nnamespace haar_lib {\n  template\
    \ <typename Monoid>\n  class segment_tree {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    int depth, size, hsize;\n    std::vector<value_type>\
    \ data;\n\n  public:\n    segment_tree(){}\n    segment_tree(int n):\n      depth(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 << depth), hsize(size\
    \ / 2),\n      data(size, M())\n    {}\n\n    auto operator[](int i) const {return\
    \ data[hsize + i];}\n\n    auto fold(int x, int y) const {\n      value_type ret_left\
    \ = M();\n      value_type ret_right = M();\n\n      int l = x + hsize, r = y\
    \ + hsize;\n      while(l < r){\n        if(r & 1) ret_right = M(data[--r], ret_right);\n\
    \        if(l & 1) ret_left = M(ret_left, data[l++]);\n        l >>= 1, r >>=\
    \ 1;\n      }\n\n      return M(ret_left, ret_right);\n    }\n\n    void set(int\
    \ i, const value_type &x){\n      i += hsize;\n      data[i] = x;\n      while(i\
    \ > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n  \
    \  void update(int i, const value_type &x){\n      i += hsize;\n      data[i]\
    \ = M(data[i], x);\n      while(i > 1) i >>= 1, data[i] = M(data[i << 1 | 0],\
    \ data[i << 1 | 1]);\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val){\n      data.assign(size, M());\n      for(int i = 0; i\
    \ < (int)val.size(); ++i) data[hsize + i] = val[i];\n      for(int i = hsize -\
    \ 1; i >= 1; --i) data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n\
    \    template <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize,\
    \ val));\n    }\n\n  private:\n    template <bool Lower, typename F>\n    int\
    \ bound(const int l, const int r, value_type x, F f) const {\n      std::vector<int>\
    \ pl, pr;\n      int L = l + hsize;\n      int R = r + hsize;\n      while(L <\
    \ R){\n        if(R & 1) pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n\
    \        L >>= 1, R >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n\
    \      pl.insert(pl.end(), pr.begin(), pr.end());\n\n      value_type a = M();\n\
    \n      for(int i : pl){\n        auto b = M(a, data[i]);\n\n        if((Lower\
    \ and not f(b, x)) or (not Lower and f(x, b))){\n          while(i < hsize){\n\
    \            if(auto c = M(a, data[i << 1 | 0]); (Lower and not f(c, x)) or (not\
    \ Lower and f(x, c))){\n              i = i << 1 | 0;\n            }else{\n  \
    \            a = c;\n              i = i << 1 | 1;\n            }\n          }\n\
    \n          return i - hsize;\n        }\n\n        a = b;\n      }\n\n      return\
    \ r;\n    }\n\n  public:\n    template <typename F = std::less<value_type>>\n\
    \    int lower_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<true>(l, r, x, f);\n    }\n\n    template <typename F = std::less<value_type>>\n\
    \    int upper_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<false>(l, r, x, f);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/product_matrix.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct product_matrix_monoid\
    \ {\n    using value_type = T;\n    value_type operator()() const {return T::unit();}\n\
    \    value_type operator()(const value_type &a, const value_type &b) const {return\
    \ a * b;}\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/dual.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename Monoid>\n  struct dual_monoid {\n    using\
    \ value_type = typename Monoid::value_type;\n    const static Monoid M;\n    value_type\
    \ operator()() const {return M();}\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const {return M(b, a);}\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t ... I>\n  static void input_tuple_helper(std::istream\
    \ &s, T &val, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s\
    \ >> std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n\
    \  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){\n    s >>\
    \ value.first >> value.second;\n    return s;\n  }\n\n  template <typename ...\
    \ Args>\n  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){\n\
    \    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename ... Args>\n  class InputTuples {\n    struct iter {\n\
    \      using value_type = std::tuple<Args ...>;\n      value_type value;\n   \
    \   bool fetched = false;\n      int N, c = 0;\n\n      value_type operator*(){\n\
    \        if(not fetched){\n          std::cin >> value;\n        }\n        return\
    \ value;\n      }\n\n      void operator++(){\n        ++c;\n        fetched =\
    \ false;\n      }\n\n      bool operator!=(iter &) const {\n        return c <\
    \ N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n\
    \    InputTuples(int N): N(N){}\n\n    iter begin() const {return iter(N);}\n\
    \    iter end() const {return iter(N);}\n  };\n\n  template <typename ... Args>\n\
    \  auto input_tuples(int N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line\
    \ 11 \"test/yukicoder/510/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ mint = hl::modint<1000000007>;\nusing Mat = hl::square_matrix_const<mint, 4>;\n\
    using Monoid = hl::dual_monoid<hl::product_matrix_monoid<Mat>>;\n\nauto f(mint\
    \ x, mint y){\n  Mat ret = {\n             {1, 0, x, 0},\n             {0, y,\
    \ 0, 1},\n             {0, 2 * y, y * y, 1},\n             {0, 0, 0, 1}\n  };\n\
    \  return ret;\n}\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\n  hl::segment_tree<Monoid>\
    \ seg(n);\n  std::vector<mint> x(n), y(n);\n\n  for(int i = 0; i < n; ++i){\n\
    \    seg.set(i, f(x[i], y[i]));\n  }\n\n  for(auto [c, i] : hl::input_tuples<char,\
    \ int>(q)){\n    if(c == 'x'){\n      int v; std::cin >> v;\n      x[i] = v;\n\
    \n      seg.set(i, f(x[i], y[i]));\n    }else if(c == 'y'){\n      int v; std::cin\
    \ >> v;\n      y[i] = v;\n\n      seg.set(i, f(x[i], y[i]));\n    }else{\n   \
    \   auto m = seg.fold(0, i);\n      auto ans = m[0][0] + m[0][1] + m[0][2] + m[0][3];\n\
    \      std::cout << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/510\"\n\n#include <iostream>\n\
    #include <vector>\n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/product_matrix.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/dual.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\nusing Mat\
    \ = hl::square_matrix_const<mint, 4>;\nusing Monoid = hl::dual_monoid<hl::product_matrix_monoid<Mat>>;\n\
    \nauto f(mint x, mint y){\n  Mat ret = {\n             {1, 0, x, 0},\n       \
    \      {0, y, 0, 1},\n             {0, 2 * y, y * y, 1},\n             {0, 0,\
    \ 0, 1}\n  };\n  return ret;\n}\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\
    \n  hl::segment_tree<Monoid> seg(n);\n  std::vector<mint> x(n), y(n);\n\n  for(int\
    \ i = 0; i < n; ++i){\n    seg.set(i, f(x[i], y[i]));\n  }\n\n  for(auto [c, i]\
    \ : hl::input_tuples<char, int>(q)){\n    if(c == 'x'){\n      int v; std::cin\
    \ >> v;\n      x[i] = v;\n\n      seg.set(i, f(x[i], y[i]));\n    }else if(c ==\
    \ 'y'){\n      int v; std::cin >> v;\n      y[i] = v;\n\n      seg.set(i, f(x[i],\
    \ y[i]));\n    }else{\n      auto m = seg.fold(0, i);\n      auto ans = m[0][0]\
    \ + m[0][1] + m[0][2] + m[0][3];\n      std::cout << ans << \"\\n\";\n    }\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/product_matrix.cpp
  - Mylib/AlgebraicStructure/Monoid/dual.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/510/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/510/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/510/main.test.cpp
- /verify/test/yukicoder/510/main.test.cpp.html
title: test/yukicoder/510/main.test.cpp
---
