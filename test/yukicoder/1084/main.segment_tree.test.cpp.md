---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp
    title: Segment tree (Add $ai + b$)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1084
    links:
    - https://yukicoder.me/problems/no/1084
  bundledCode: "#line 1 \"test/yukicoder/1084/main.segment_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1084\"\n\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int N){\n\
    \    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n\
    \    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\nnamespace haar_lib {\n\
    \  template <int32_t M>\n  class modint {\n    uint32_t val;\n\n  public:\n  \
    \  constexpr static auto mod(){return M;}\n\n    constexpr modint(): val(0){}\n\
    \    constexpr modint(int64_t n){\n      if(n >= M) val = n % M;\n      else if(n\
    \ < 0) val = n % M + M;\n      else val = n;\n    }\n\n    constexpr auto& operator=(const\
    \ modint &a){val = a.val; return *this;}\n    constexpr auto& operator+=(const\
    \ modint &a){\n      if(val + a.val >= M) val = (uint64_t)val + a.val - M;\n \
    \     else val += a.val;\n      return *this;\n    }\n    constexpr auto& operator-=(const\
    \ modint &a){\n      if(val < a.val) val += M;\n      val -= a.val;\n      return\
    \ *this;\n    }\n    constexpr auto& operator*=(const modint &a){\n      val =\
    \ (uint64_t)val * a.val % M;\n      return *this;\n    }\n    constexpr auto&\
    \ operator/=(const modint &a){\n      val = (uint64_t)val * a.inv().val % M;\n\
    \      return *this;\n    }\n\n    constexpr auto operator+(const modint &a) const\
    \ {return modint(*this) += a;}\n    constexpr auto operator-(const modint &a)\
    \ const {return modint(*this) -= a;}\n    constexpr auto operator*(const modint\
    \ &a) const {return modint(*this) *= a;}\n    constexpr auto operator/(const modint\
    \ &a) const {return modint(*this) /= a;}\n\n    constexpr bool operator==(const\
    \ modint &a) const {return val == a.val;}\n    constexpr bool operator!=(const\
    \ modint &a) const {return val != a.val;}\n\n    constexpr auto& operator++(){*this\
    \ += 1; return *this;}\n    constexpr auto& operator--(){*this -= 1; return *this;}\n\
    \n    constexpr auto operator++(int){auto t = *this; *this += 1; return t;}\n\
    \    constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}\n\n\
    \    constexpr static modint pow(int64_t n, int64_t p){\n      if(p < 0) return\
    \ pow(n, -p).inv();\n\n      int64_t ret = 1, e = n % M;\n      for(; p; (e *=\
    \ e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;\n      return ret;\n    }\n\n \
    \   constexpr static modint inv(int64_t a){\n      int64_t b = M, u = 1, v = 0;\n\
    \n      while(b){\n        int64_t t = a / b;\n        a -= t * b; std::swap(a,\
    \ b);\n        u -= t * v; std::swap(u, v);\n      }\n\n      u %= M;\n      if(u\
    \ < 0) u += M;\n\n      return u;\n    }\n\n    constexpr static auto frac(int64_t\
    \ a, int64_t b){return modint(a) / modint(b);}\n\n    constexpr auto pow(int64_t\
    \ p) const {return pow(val, p);}\n    constexpr auto inv() const {return inv(val);}\n\
    \n    friend constexpr auto operator-(const modint &a){return modint(M - a.val);}\n\
    \n    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a)\
    \ + b;}\n    friend constexpr auto operator-(int64_t a, const modint &b){return\
    \ modint(a) - b;}\n    friend constexpr auto operator*(int64_t a, const modint\
    \ &b){return modint(a) * b;}\n    friend constexpr auto operator/(int64_t a, const\
    \ modint &b){return modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream\
    \ &s, modint<M> &a){s >> a.val; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint<M> &a){s << a.val; return s;}\n\n    template <int N>\n   \
    \ static auto div(){\n      static auto value = inv(N);\n      return value;\n\
    \    }\n\n    explicit operator int32_t() const noexcept {return val;}\n    explicit\
    \ operator int64_t() const noexcept {return val;}\n  };\n}\n#line 4 \"Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class segment_tree_linear_add\
    \ {\n    using value_type = T;\n    using P = std::pair<T, T>;\n\n    int depth,\
    \ size, hsize;\n\n    std::vector<P> data;\n    std::vector<int> from;\n\n   \
    \ P add(P a, P b){\n      return {a.first + b.first, a.second + b.second};\n \
    \   }\n\n    void propagate(int i){\n      if(i < hsize){\n        data[i << 1\
    \ | 0] = add(data[i << 1 | 0], data[i]);\n\n        int len = hsize >> (31 - __builtin_clz(i)\
    \ + 1);\n        data[i].first += data[i].second * len;\n        data[i << 1 |\
    \ 1] = add(data[i << 1 | 1], data[i]);\n\n        data[i] = P();\n      }\n  \
    \  }\n\n    void propagate_top_down(int i){\n      std::vector<int> temp;\n  \
    \    while(i > 1){\n        i >>= 1;\n        temp.push_back(i);\n      }\n\n\
    \      for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);\n\
    \    }\n\n  public:\n    segment_tree_linear_add(){}\n    segment_tree_linear_add(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth), hsize(size / 2),\n      data(size, P()),\n      from(size)\n    {\n\
    \      int s = 0;\n      for(int i = 1; i < size; ++i){\n        from[i] = s;\n\
    \        int l = hsize >> (31 - __builtin_clz(i));\n        s += l;\n        if(s\
    \ == hsize) s = 0;\n      }\n    }\n\n    void update(int l, int r, T a, T b){\n\
    \      int L = l + hsize;\n      int R = r + hsize;\n\n      while(L < R){\n \
    \       if(R & 1){\n          --R;\n          data[R] = add(std::make_pair(b +\
    \ a * (from[R] - l), a), data[R]);\n        }\n        if(L & 1){\n          data[L]\
    \ = add(std::make_pair(b + a * (from[L] - l), a), data[L]);\n          ++L;\n\
    \        }\n        L >>= 1;\n        R >>= 1;\n      }\n    }\n\n    T operator[](int\
    \ i){\n      propagate_top_down(i + hsize);\n      return data[i + hsize].first;\n\
    \    }\n\n    std::vector<T> get_all(int n){\n      std::vector<T> ret(n);\n \
    \     for(int i = 1; i < hsize; ++i) propagate(i);\n      for(int i = hsize; i\
    \ < hsize + n; ++i) ret[i - hsize] = data[i].first;\n      return ret;\n    }\n\
    \  };\n}\n#line 9 \"test/yukicoder/1084/main.segment_tree.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\nconst int MAX = 1000000000;\n\
    \nint main(){\n  int N; std::cin >> N;\n  auto A = hl::input_vector<int64_t>(N);\n\
    \n  mint ans = 0;\n\n  if(std::count(A.begin(), A.end(), 0) == 0){\n    hl::segment_tree_linear_add<int64_t>\
    \ seg(N);\n\n    std::vector<int> next(N);\n    for(int i = N; --i >= 0;){\n \
    \     if(A[i] == 1){\n        if(i == N - 1) next[i] = N;\n        else{\n   \
    \       if(A[i + 1] == 1){\n            next[i] = next[i + 1];\n          }else{\n\
    \            next[i] = i + 1;\n          }\n        }\n      }else{\n        next[i]\
    \ = i + 1;\n      }\n    }\n\n    for(int l = 0; l < N; ++l){\n      int64_t prod\
    \ = 1;\n\n      int r = l;\n\n      for(int i = 0; i < 100; ++i){\n        if(r\
    \ == N or prod * A[r] >= MAX) break;\n        prod *= A[r];\n        r = next[r];\n\
    \      }\n\n      seg.update(l, r, -1, r - l);\n    }\n\n    ans = 1;\n    for(int\
    \ i = 0; i < N; ++i){\n      ans *= mint::pow(A[i], seg[i]);\n    }\n  }\n\n \
    \ std::cout << ans << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1084\"\n\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include \"Mylib/IO/input_vector.cpp\"\
    \n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\nconst int\
    \ MAX = 1000000000;\n\nint main(){\n  int N; std::cin >> N;\n  auto A = hl::input_vector<int64_t>(N);\n\
    \n  mint ans = 0;\n\n  if(std::count(A.begin(), A.end(), 0) == 0){\n    hl::segment_tree_linear_add<int64_t>\
    \ seg(N);\n\n    std::vector<int> next(N);\n    for(int i = N; --i >= 0;){\n \
    \     if(A[i] == 1){\n        if(i == N - 1) next[i] = N;\n        else{\n   \
    \       if(A[i + 1] == 1){\n            next[i] = next[i + 1];\n          }else{\n\
    \            next[i] = i + 1;\n          }\n        }\n      }else{\n        next[i]\
    \ = i + 1;\n      }\n    }\n\n    for(int l = 0; l < N; ++l){\n      int64_t prod\
    \ = 1;\n\n      int r = l;\n\n      for(int i = 0; i < 100; ++i){\n        if(r\
    \ == N or prod * A[r] >= MAX) break;\n        prod *= A[r];\n        r = next[r];\n\
    \      }\n\n      seg.update(l, r, -1, r - l);\n    }\n\n    ans = 1;\n    for(int\
    \ i = 0; i < N; ++i){\n      ans *= mint::pow(A[i], seg[i]);\n    }\n  }\n\n \
    \ std::cout << ans << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/Number/Mint/mint.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp
  isVerificationFile: true
  path: test/yukicoder/1084/main.segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/1084/main.segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1084/main.segment_tree.test.cpp
- /verify/test/yukicoder/1084/main.segment_tree.test.cpp.html
title: test/yukicoder/1084/main.segment_tree.test.cpp
---
