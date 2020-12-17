---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/TreeUtils/euler_tour_vertex.cpp
    title: Euler tour (Vertex)
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    \n#include <iostream>\n#include <vector>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge(){}\n    edge(int from, int\
    \ to, T cost): from(from), to(to), cost(cost){}\n    edge(int from, int to, T\
    \ cost, int index): from(from), to(to), cost(cost), index(index){}\n  };\n\n \
    \ template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n    auto&\
    \ operator[](size_t i){return data[i];}\n    const auto& operator[](size_t i)\
    \ const {return data[i];}\n\n    auto begin() const {return data.begin();}\n \
    \   auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 4 \"Mylib/Graph/TreeUtils/euler_tour_vertex.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class euler_tour_vertex {\n\
    \    int pos_ = 0;\n    std::vector<int> begin_, end_;\n\n    void dfs(int cur,\
    \ int par, const tree<T> &tr){\n      begin_[cur] = pos_++;\n\n      for(auto\
    \ &e : tr[cur]){\n        if(e.to == par) continue;\n        dfs(e.to, cur, tr);\n\
    \      }\n\n      end_[cur] = pos_;\n    }\n\n  public:\n    euler_tour_vertex(){}\n\
    \    euler_tour_vertex(const tree<T> &tr, int root):\n      begin_(tr.size()),\
    \ end_(tr.size()){\n      dfs(root, -1, tr);\n    }\n\n    template <typename\
    \ F> // F = std::function<void(int, int)>\n    void subtree_query(int i, const\
    \ F &f){\n      f(begin_[i], end_[i]);\n    }\n\n    template <typename F> //\
    \ F = std::function<void(int)>\n    void point_query(int i, const F &f){\n   \
    \   f(begin_[i]);\n    }\n  };\n}\n#line 3 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <algorithm>\n#include <functional>\n#include <cassert>\n\nnamespace\
    \ haar_lib {\n  template <typename Monoid>\n  class segment_tree {\n  public:\n\
    \    using value_type = typename Monoid::value_type;\n\n  private:\n    Monoid\
    \ M_;\n    int depth_, size_, hsize_;\n    std::vector<value_type> data_;\n\n\
    \  public:\n    segment_tree(){}\n    segment_tree(int n):\n      depth_(n > 1\
    \ ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_), hsize_(size_\
    \ / 2),\n      data_(size_, M_())\n    {}\n\n    auto operator[](int i) const\
    \ {\n      assert(0 <= i and i < hsize_);\n      return data_[hsize_ + i];\n \
    \   }\n\n    auto fold(int l, int r) const {\n      assert(0 <= l and l <= r and\
    \ r <= hsize_);\n      value_type ret_left = M_();\n      value_type ret_right\
    \ = M_();\n\n      int L = l + hsize_, R = r + hsize_;\n      while(L < R){\n\
    \        if(R & 1) ret_right = M_(data_[--R], ret_right);\n        if(L & 1) ret_left\
    \ = M_(ret_left, data_[L++]);\n        L >>= 1, R >>= 1;\n      }\n\n      return\
    \ M_(ret_left, ret_right);\n    }\n\n    auto fold_all() const {\n      return\
    \ data_[1];\n    }\n\n    void set(int i, const value_type &x){\n      assert(0\
    \ <= i and i < hsize_);\n      i += hsize_;\n      data_[i] = x;\n      while(i\
    \ > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n\
    \    void update(int i, const value_type &x){\n      assert(0 <= i and i < hsize_);\n\
    \      i += hsize_;\n      data_[i] = M_(data_[i], x);\n      while(i > 1) i >>=\
    \ 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n    template\
    \ <typename T>\n    void init_with_vector(const std::vector<T> &val){\n      data_.assign(size_,\
    \ M_());\n      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n\
    \      for(int i = hsize_; --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i\
    \ << 1 | 1]);\n    }\n\n    template <typename T>\n    void init(const T &val){\n\
    \      init_with_vector(std::vector<value_type>(hsize_, val));\n    }\n\n  private:\n\
    \    template <bool Lower, typename F>\n    int bound(const int l, const int r,\
    \ value_type x, F f) const {\n      std::vector<int> pl, pr;\n      int L = l\
    \ + hsize_;\n      int R = r + hsize_;\n      while(L < R){\n        if(R & 1)\
    \ pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n        L >>= 1, R\
    \ >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n      pl.insert(pl.end(),\
    \ pr.begin(), pr.end());\n\n      value_type a = M_();\n\n      for(int i : pl){\n\
    \        auto b = M_(a, data_[i]);\n\n        if((Lower and not f(b, x)) or (not\
    \ Lower and f(x, b))){\n          while(i < hsize_){\n            const auto c\
    \ = M_(a, data_[i << 1 | 0]);\n            if((Lower and not f(c, x)) or (not\
    \ Lower and f(x, c))){\n              i = i << 1 | 0;\n            }else{\n  \
    \            a = c;\n              i = i << 1 | 1;\n            }\n          }\n\
    \n          return i - hsize_;\n        }\n\n        a = b;\n      }\n\n     \
    \ return r;\n    }\n\n  public:\n    template <typename F = std::less<value_type>>\n\
    \    int lower_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<true>(l, r, x, f);\n    }\n\n    template <typename F = std::less<value_type>>\n\
    \    int upper_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<false>(l, r, x, f);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  std::vector<T> input_vector(int N){\n    std::vector<T> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n  template <typename\
    \ T>\n  std::vector<std::vector<T>> input_vector(int N, int M){\n    std::vector<std::vector<T>>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return\
    \ ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include\
    \ <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){\n \
    \   (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
    \ &s, std::pair<T, U> &value){\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename ... Args>\n  std::istream& operator>>(std::istream\
    \ &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuples\
    \ {\n    struct iter {\n      using value_type = std::tuple<Args ...>;\n     \
    \ value_type value;\n      bool fetched = false;\n      int N, c = 0;\n\n    \
    \  value_type operator*(){\n        if(not fetched){\n          std::cin >> value;\n\
    \        }\n        return value;\n      }\n\n      void operator++(){\n     \
    \   ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n \
    \   int N;\n\n  public:\n    InputTuples(int N): N(N){}\n\n    iter begin() const\
    \ {return iter(N);}\n    iter end() const {return iter(N);}\n  };\n\n  template\
    \ <typename ... Args>\n  auto input_tuples(int N){\n    return InputTuples<Args\
    \ ...>(N);\n  }\n}\n#line 10 \"test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto a = hl::input_vector<int64_t>(N);\n\
    \n  hl::tree<int> tree(N);\n  for(int i = 1; i < N; ++i){\n    int p; std::cin\
    \ >> p;\n    tree.add_edge(p, i, 1);\n  }\n\n  auto seg = hl::segment_tree<hl::sum_monoid<int64_t>>(N);\n\
    \  auto et = hl::euler_tour_vertex(tree, 0);\n\n  for(int i = 0; i < N; ++i){\n\
    \    et.point_query(\n      i,\n      [&](int j){\n        seg.set(j, a[i]);\n\
    \      }\n    );\n  }\n\n  for(auto [t, u] : hl::input_tuples<int, int>(Q)){\n\
    \    if(t == 0){\n      int x; std::cin >> x;\n\n      et.point_query(\n     \
    \   u,\n        [&](int j){\n          seg.update(j, x);\n        }\n      );\n\
    \    }else{\n      int64_t ans = 0;\n      et.subtree_query(\n        u,\n   \
    \     [&](int l, int r){\n          ans += seg.fold(l, r);\n        }\n      );\n\
    \n      std::cout << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Graph/TreeUtils/euler_tour_vertex.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto a = hl::input_vector<int64_t>(N);\n\
    \n  hl::tree<int> tree(N);\n  for(int i = 1; i < N; ++i){\n    int p; std::cin\
    \ >> p;\n    tree.add_edge(p, i, 1);\n  }\n\n  auto seg = hl::segment_tree<hl::sum_monoid<int64_t>>(N);\n\
    \  auto et = hl::euler_tour_vertex(tree, 0);\n\n  for(int i = 0; i < N; ++i){\n\
    \    et.point_query(\n      i,\n      [&](int j){\n        seg.set(j, a[i]);\n\
    \      }\n    );\n  }\n\n  for(auto [t, u] : hl::input_tuples<int, int>(Q)){\n\
    \    if(t == 0){\n      int x; std::cin >> x;\n\n      et.point_query(\n     \
    \   u,\n        [&](int j){\n          seg.update(j, x);\n        }\n      );\n\
    \    }else{\n      int64_t ans = 0;\n      et.subtree_query(\n        u,\n   \
    \     [&](int l, int r){\n          ans += seg.fold(l, r);\n        }\n      );\n\
    \n      std::cout << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/TreeUtils/euler_tour_vertex.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
- /verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp.html
title: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
---
