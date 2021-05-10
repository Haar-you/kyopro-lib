---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/enumerate_triangles.cpp
    title: Enumerate triangles
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_triangles
    links:
    - https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "#line 1 \"test/yosupo-judge/enumerate_triangles/main.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\n#include\
    \ <iostream>\n\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge() {}\n    edge(int from, int\
    \ to, T cost) : from(from), to(to), cost(cost) {}\n    edge(int from, int to,\
    \ T cost, int index) : from(from), to(to), cost(cost), index(index) {}\n  };\n\
    \n  template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n  \
    \  auto& operator[](size_t i) { return data[i]; }\n    const auto& operator[](size_t\
    \ i) const { return data[i]; }\n\n    auto begin() const { return data.begin();\
    \ }\n    auto end() const { return data.end(); }\n\n    graph() {}\n    graph(int\
    \ N) : data(N) {}\n\n    bool empty() const { return data.empty(); }\n    int\
    \ size() const { return data.size(); }\n\n    void add_edge(int i, int j, T w,\
    \ int index = -1) {\n      data[i].emplace_back(i, j, w, index);\n    }\n\n  \
    \  void add_undirected(int i, int j, T w, int index = -1) {\n      add_edge(i,\
    \ j, w, index);\n      add_edge(j, i, w, index);\n    }\n\n    template <size_t\
    \ I, bool DIRECTED = true, bool WEIGHTED = true>\n    void read(int M) {\n   \
    \   for (int i = 0; i < M; ++i) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n        u -= I;\n        v -= I;\n        T w = 1;\n        if (WEIGHTED)\
    \ std::cin >> w;\n        if (DIRECTED)\n          add_edge(u, v, w, i);\n   \
    \     else\n          add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 2 \"\
    Mylib/Graph/enumerate_triangles.cpp\"\n#include <tuple>\n#include <unordered_set>\n\
    #line 6 \"Mylib/Graph/enumerate_triangles.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<std::tuple<int, int, int>> enumerate_triangles(const\
    \ graph<T> &g) {\n    const int N = g.size();\n    std::vector<std::tuple<int,\
    \ int, int>> ret;\n\n    std::vector<std::unordered_set<int>> adjacent(N);\n\n\
    \    for (int i = 0; i < N; ++i) {\n      for (auto &e : g[i]) {\n        if (g[e.from].size()\
    \ < g[e.to].size()) {\n          adjacent[e.from].insert(e.to);\n        } else\
    \ if (g[e.from].size() == g[e.to].size()) {\n          if (e.from < e.to) {\n\
    \            adjacent[e.from].insert(e.to);\n          }\n        }\n      }\n\
    \    }\n\n    for (int i = 0; i < N; ++i) {\n      for (int j : adjacent[i]) {\n\
    \        for (int k : adjacent[j]) {\n          if (adjacent[i].find(k) != adjacent[i].end())\
    \ {\n            ret.emplace_back(i, j, k);\n          }\n        }\n      }\n\
    \    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N) {\n    std::vector<T> ret(N);\n    for (int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for\
    \ (int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <int32_t M>\n  class modint {\n    uint32_t\
    \ val_;\n\n  public:\n    constexpr static auto mod() { return M; }\n\n    constexpr\
    \ modint() : val_(0) {}\n    constexpr modint(int64_t n) {\n      if (n >= M)\n\
    \        val_ = n % M;\n      else if (n < 0)\n        val_ = n % M + M;\n   \
    \   else\n        val_ = n;\n    }\n\n    constexpr auto &operator=(const modint\
    \ &a) {\n      val_ = a.val_;\n      return *this;\n    }\n    constexpr auto\
    \ &operator+=(const modint &a) {\n      if (val_ + a.val_ >= M)\n        val_\
    \ = (uint64_t) val_ + a.val_ - M;\n      else\n        val_ += a.val_;\n     \
    \ return *this;\n    }\n    constexpr auto &operator-=(const modint &a) {\n  \
    \    if (val_ < a.val_) val_ += M;\n      val_ -= a.val_;\n      return *this;\n\
    \    }\n    constexpr auto &operator*=(const modint &a) {\n      val_ = (uint64_t)\
    \ val_ * a.val_ % M;\n      return *this;\n    }\n    constexpr auto &operator/=(const\
    \ modint &a) {\n      val_ = (uint64_t) val_ * a.inv().val_ % M;\n      return\
    \ *this;\n    }\n\n    constexpr auto operator+(const modint &a) const { return\
    \ modint(*this) += a; }\n    constexpr auto operator-(const modint &a) const {\
    \ return modint(*this) -= a; }\n    constexpr auto operator*(const modint &a)\
    \ const { return modint(*this) *= a; }\n    constexpr auto operator/(const modint\
    \ &a) const { return modint(*this) /= a; }\n\n    constexpr bool operator==(const\
    \ modint &a) const { return val_ == a.val_; }\n    constexpr bool operator!=(const\
    \ modint &a) const { return val_ != a.val_; }\n\n    constexpr auto &operator++()\
    \ {\n      *this += 1;\n      return *this;\n    }\n    constexpr auto &operator--()\
    \ {\n      *this -= 1;\n      return *this;\n    }\n\n    constexpr auto operator++(int)\
    \ {\n      auto t = *this;\n      *this += 1;\n      return t;\n    }\n    constexpr\
    \ auto operator--(int) {\n      auto t = *this;\n      *this -= 1;\n      return\
    \ t;\n    }\n\n    constexpr static modint pow(int64_t n, int64_t p) {\n     \
    \ if (p < 0) return pow(n, -p).inv();\n\n      int64_t ret = 1, e = n % M;\n \
    \     for (; p; (e *= e) %= M, p >>= 1)\n        if (p & 1) (ret *= e) %= M;\n\
    \      return ret;\n    }\n\n    constexpr static modint inv(int64_t a) {\n  \
    \    int64_t b = M, u = 1, v = 0;\n\n      while (b) {\n        int64_t t = a\
    \ / b;\n        a -= t * b;\n        std::swap(a, b);\n        u -= t * v;\n \
    \       std::swap(u, v);\n      }\n\n      u %= M;\n      if (u < 0) u += M;\n\
    \n      return u;\n    }\n\n    constexpr static auto frac(int64_t a, int64_t\
    \ b) { return modint(a) / modint(b); }\n\n    constexpr auto pow(int64_t p) const\
    \ { return pow(val_, p); }\n    constexpr auto inv() const { return inv(val_);\
    \ }\n\n    friend constexpr auto operator-(const modint &a) { return modint(M\
    \ - a.val_); }\n\n    friend constexpr auto operator+(int64_t a, const modint\
    \ &b) { return modint(a) + b; }\n    friend constexpr auto operator-(int64_t a,\
    \ const modint &b) { return modint(a) - b; }\n    friend constexpr auto operator*(int64_t\
    \ a, const modint &b) { return modint(a) * b; }\n    friend constexpr auto operator/(int64_t\
    \ a, const modint &b) { return modint(a) / b; }\n\n    friend std::istream &operator>>(std::istream\
    \ &s, modint &a) {\n      s >> a.val_;\n      return s;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &s, const modint &a) {\n      s << a.val_;\n      return\
    \ s;\n    }\n\n    template <int N>\n    static auto div() {\n      static auto\
    \ value = inv(N);\n      return value;\n    }\n\n    explicit operator int32_t()\
    \ const noexcept { return val_; }\n    explicit operator int64_t() const noexcept\
    \ { return val_; }\n  };\n}  // namespace haar_lib\n#line 9 \"test/yosupo-judge/enumerate_triangles/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, M;\n\
    \  std::cin >> N >> M;\n  auto x = hl::input_vector<mint>(N);\n\n  hl::graph<int>\
    \ g(N);\n  g.read<0, false, false>(M);\n\n  auto res = hl::enumerate_triangles(g);\n\
    \  mint ans = 0;\n  for (auto [i, j, k] : res) ans += x[i] * x[j] * x[k];\n\n\
    \  std::cout << ans << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    \n#include <iostream>\n\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/enumerate_triangles.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n#include \"Mylib/Number/Mint/mint.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ mint = hl::modint<998244353>;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, M;\n  std::cin >> N >> M;\n  auto x = hl::input_vector<mint>(N);\n\n\
    \  hl::graph<int> g(N);\n  g.read<0, false, false>(M);\n\n  auto res = hl::enumerate_triangles(g);\n\
    \  mint ans = 0;\n  for (auto [i, j, k] : res) ans += x[i] * x[j] * x[k];\n\n\
    \  std::cout << ans << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/enumerate_triangles.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/Number/Mint/mint.cpp
  isVerificationFile: true
  path: test/yosupo-judge/enumerate_triangles/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/enumerate_triangles/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/enumerate_triangles/main.test.cpp
- /verify/test/yosupo-judge/enumerate_triangles/main.test.cpp.html
title: test/yosupo-judge/enumerate_triangles/main.test.cpp
---