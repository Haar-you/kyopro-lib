---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/kruskal.cpp
    title: Kruskal algorithm
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
    title: Manhattan distance MST
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"test/yosupo-judge/manhattanmst/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include <iostream>\n\
    #line 3 \"Mylib/IO/input_tuple_vector.cpp\"\n#include <vector>\n#include <tuple>\n\
    #include <utility>\n#include <initializer_list>\n\nnamespace haar_lib {\n  template\
    \ <typename T, size_t ... I>\n  void input_tuple_vector_init(T &val, int N, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 4 \"Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp\"\
    \n#include <algorithm>\n#include <numeric>\n#include <cmath>\n#line 3 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\
    \n#include <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ min_monoid {\n    using value_type = std::optional<T>;\n\n    value_type operator()()\
    \ const {return {};}\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if(not a) return b;\n      if(not b) return a;\n      return\
    \ {std::min(*a, *b)};\n    }\n  };\n}\n#line 4 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <functional>\n#include <cassert>\n\nnamespace haar_lib {\n  template\
    \ <typename Monoid>\n  class segment_tree {\n  public:\n    using value_type =\
    \ typename Monoid::value_type;\n\n  private:\n    Monoid M_;\n    int depth_,\
    \ size_, hsize_;\n    std::vector<value_type> data_;\n\n  public:\n    segment_tree(){}\n\
    \    segment_tree(int n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1\
    \ : 1),\n      size_(1 << depth_), hsize_(size_ / 2),\n      data_(size_, M_())\n\
    \    {}\n\n    auto operator[](int i) const {\n      assert(0 <= i and i < hsize_);\n\
    \      return data_[hsize_ + i];\n    }\n\n    auto fold(int l, int r) const {\n\
    \      assert(0 <= l and l <= r and r <= hsize_);\n      value_type ret_left =\
    \ M_();\n      value_type ret_right = M_();\n\n      int L = l + hsize_, R = r\
    \ + hsize_;\n      while(L < R){\n        if(R & 1) ret_right = M_(data_[--R],\
    \ ret_right);\n        if(L & 1) ret_left = M_(ret_left, data_[L++]);\n      \
    \  L >>= 1, R >>= 1;\n      }\n\n      return M_(ret_left, ret_right);\n    }\n\
    \n    auto fold_all() const {\n      return data_[1];\n    }\n\n    void set(int\
    \ i, const value_type &x){\n      assert(0 <= i and i < hsize_);\n      i += hsize_;\n\
    \      data_[i] = x;\n      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 |\
    \ 0], data_[i << 1 | 1]);\n    }\n\n    void update(int i, const value_type &x){\n\
    \      assert(0 <= i and i < hsize_);\n      i += hsize_;\n      data_[i] = M_(data_[i],\
    \ x);\n      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i <<\
    \ 1 | 1]);\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val){\n      data_.assign(size_, M_());\n      for(int i = 0;\
    \ i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n      for(int i = hsize_;\
    \ --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n \
    \   template <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize_,\
    \ val));\n    }\n\n  private:\n    template <bool Lower, typename F>\n    int\
    \ bound(const int l, const int r, value_type x, F f) const {\n      std::vector<int>\
    \ pl, pr;\n      int L = l + hsize_;\n      int R = r + hsize_;\n      while(L\
    \ < R){\n        if(R & 1) pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n\
    \        L >>= 1, R >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n\
    \      pl.insert(pl.end(), pr.begin(), pr.end());\n\n      value_type a = M_();\n\
    \n      for(int i : pl){\n        auto b = M_(a, data_[i]);\n\n        if((Lower\
    \ and not f(b, x)) or (not Lower and f(x, b))){\n          while(i < hsize_){\n\
    \            const auto c = M_(a, data_[i << 1 | 0]);\n            if((Lower and\
    \ not f(c, x)) or (not Lower and f(x, c))){\n              i = i << 1 | 0;\n \
    \           }else{\n              a = c;\n              i = i << 1 | 1;\n    \
    \        }\n          }\n\n          return i - hsize_;\n        }\n\n       \
    \ a = b;\n      }\n\n      return r;\n    }\n\n  public:\n    template <typename\
    \ F = std::less<value_type>>\n    int lower_bound(int l, int r, value_type x,\
    \ F f = F()) const {\n      return bound<true>(l, r, x, f);\n    }\n\n    template\
    \ <typename F = std::less<value_type>>\n    int upper_bound(int l, int r, value_type\
    \ x, F f = F()) const {\n      return bound<false>(l, r, x, f);\n    }\n  };\n\
    }\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n    int index\
    \ = -1;\n    edge(){}\n    edge(int from, int to, T cost): from(from), to(to),\
    \ cost(cost){}\n    edge(int from, int to, T cost, int index): from(from), to(to),\
    \ cost(cost), index(index){}\n  };\n\n  template <typename T>\n  struct graph\
    \ {\n    using weight_type = T;\n    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
    \ data;\n\n    auto& operator[](size_t i){return data[i];}\n    const auto& operator[](size_t\
    \ i) const {return data[i];}\n\n    auto begin() const {return data.begin();}\n\
    \    auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 10 \"Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, typename MST>\n  std::vector<edge<T>>\
    \ manhattan_minimum_spanning_tree(std::vector<T> x, std::vector<T> y, MST mst){\n\
    \    const int N = x.size();\n    graph<T> g(N);\n    segment_tree<min_monoid<std::pair<T,\
    \ int>>> seg(N);\n\n    auto f =\n      [&](){\n        std::vector<T> Y(y);\n\
    \        std::sort(Y.begin(), Y.end());\n        Y.erase(std::unique(Y.begin(),\
    \ Y.end()), Y.end());\n\n        seg.init(std::nullopt);\n\n        std::vector<int>\
    \ ord(N);\n        std::iota(ord.begin(), ord.end(), 0);\n        std::sort(\n\
    \          ord.begin(), ord.end(),\n          [&](int i, int j){\n           \
    \ if(y[i] - x[i] == y[j] - x[j]) return x[i] > x[j];\n            return y[i]\
    \ - x[i] < y[j] - x[j];\n          }\n        );\n\n        for(int i : ord){\n\
    \          int lb = std::lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();\n\n\
    \          if(auto res = seg.fold(lb, N); res){\n            auto j = res->second;\n\
    \            T c = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);\n          \
    \  g.add_edge(i, j, c);\n          }\n\n          if(auto res = seg[lb]; not res\
    \ or x[i] + y[i] < res->first){\n            seg.set(lb, {{x[i] + y[i], i}});\n\
    \          }\n        }\n      };\n\n    for(int i = 0; i < 2; ++i){\n      for(int\
    \ j = 0; j < 2; ++j){\n        for(int k = 0; k < 2; ++k){\n          f();\n \
    \         for(int l = 0; l < N; ++l) std::swap(x[l], y[l]);\n        }\n     \
    \   for(int l = 0; l < N; ++l) x[l] = -x[l];\n      }\n      for(int l = 0; l\
    \ < N; ++l) y[l] = -y[l];\n    }\n\n    return mst(g);\n  }\n}\n#line 5 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
    \n\nnamespace haar_lib {\n  class unionfind {\n    int n_, count_;\n    mutable\
    \ std::vector<int> parent_;\n    std::vector<int> depth_, size_;\n\n  public:\n\
    \    unionfind(){}\n    unionfind(int n): n_(n), count_(n), parent_(n), depth_(n,\
    \ 1), size_(n, 1){\n      std::iota(parent_.begin(), parent_.end(), 0);\n    }\n\
    \n    int root_of(int i) const {\n      if(parent_[i] == i) return i;\n      else\
    \ return parent_[i] = root_of(parent_[i]);\n    }\n\n    bool is_same(int i, int\
    \ j) const {return root_of(i) == root_of(j);}\n\n    int merge(int i, int j){\n\
    \      const int ri = root_of(i), rj = root_of(j);\n      if(ri == rj) return\
    \ ri;\n      else{\n        --count_;\n        if(depth_[ri] < depth_[rj]){\n\
    \          parent_[ri] = rj;\n          size_[rj] += size_[ri];\n          return\
    \ rj;\n        }else{\n          parent_[rj] = ri;\n          size_[ri] += size_[rj];\n\
    \          if(depth_[ri] == depth_[rj]) ++depth_[ri];\n          return ri;\n\
    \        }\n      }\n    }\n\n    int size_of(int i) const {return size_[root_of(i)];}\n\
    \n    int count_groups() const {return count_;}\n\n    auto get_groups() const\
    \ {\n      std::vector<std::vector<int>> ret(n_);\n\n      for(int i = 0; i <\
    \ n_; ++i){\n        ret[root_of(i)].push_back(i);\n      }\n\n      ret.erase(\n\
    \        std::remove_if(\n          ret.begin(), ret.end(),\n          [](const\
    \ auto &a){return a.empty();}\n        ),\n        ret.end()\n      );\n\n   \
    \   return ret;\n    }\n  };\n}\n#line 6 \"Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<edge<T>> kruskal(const\
    \ graph<T> &graph){\n    const int n = graph.size();\n    std::vector<edge<T>>\
    \ edges;\n    for(auto &v : graph){\n      for(auto &e : v){\n        edges.push_back(e);\n\
    \      }\n    }\n\n    std::sort(\n      edges.begin(), edges.end(),\n      [](const\
    \ auto &a, const auto &b){return a.cost < b.cost;}\n    );\n\n    unionfind uf(n);\n\
    \n    std::vector<edge<T>> ret;\n\n    for(auto &e : edges){\n      if(not uf.is_same(e.from,\
    \ e.to)){\n        uf.merge(e.from, e.to);\n        ret.push_back(e);\n      }\n\
    \    }\n\n    return ret;\n  }\n}\n#line 7 \"test/yosupo-judge/manhattanmst/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  auto [x, y] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\
    \n  auto res = hl::manhattan_minimum_spanning_tree(x, y, hl::kruskal<int64_t>);\n\
    \n  int64_t ans = 0;\n\n  for(auto &e : res){\n    ans += e.cost;\n  }\n\n  std::cout\
    \ << ans << \"\\n\";\n  for(auto &e : res){\n    std::cout << e.from << \" \"\
    \ << e.to << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include\
    \ <iostream>\n#include \"Mylib/IO/input_tuple_vector.cpp\"\n#include \"Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp\"\
    \n#include \"Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N; std::cin >> N;\n\n  auto [x, y] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\
    \n  auto res = hl::manhattan_minimum_spanning_tree(x, y, hl::kruskal<int64_t>);\n\
    \n  int64_t ans = 0;\n\n  for(auto &e : res){\n    ans += e.cost;\n  }\n\n  std::cout\
    \ << ans << \"\\n\";\n  for(auto &e : res){\n    std::cout << e.from << \" \"\
    \ << e.to << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/MinimumSpanningTree/kruskal.cpp
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  isVerificationFile: true
  path: test/yosupo-judge/manhattanmst/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/manhattanmst/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/manhattanmst/main.test.cpp
- /verify/test/yosupo-judge/manhattanmst/main.test.cpp.html
title: test/yosupo-judge/manhattanmst/main.test.cpp
---
