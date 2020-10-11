---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/update.cpp
    title: Update monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp
    title: Range update / Range sum
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
    title: Lazy segment tree
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/TreeUtils/euler_tour_bfs.cpp
    title: Euler tour (BFS)
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/899
    links:
    - https://yukicoder.me/problems/no/899
  bundledCode: "#line 1 \"test/yukicoder/899/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/899\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ <vector>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n  \
    \  int index = -1;\n    edge(){}\n    edge(int from, int to, T cost): from(from),\
    \ to(to), cost(cost){}\n    edge(int from, int to, T cost, int index): from(from),\
    \ to(to), cost(cost), index(index){}\n  };\n\n  template <typename T>\n  struct\
    \ graph {\n    using weight_type = T;\n    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/TreeUtils/euler_tour_bfs.cpp\"\
    \n#include <queue>\n#line 5 \"Mylib/Graph/TreeUtils/euler_tour_bfs.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class euler_tour_bfs {\n    int N_;\n\
    \    std::vector<int> parent_, depth_, left_, right_;\n    std::vector<std::vector<int>>\
    \ bfs_order_, dfs_order_;\n\n  public:\n    euler_tour_bfs(){}\n    euler_tour_bfs(const\
    \ tree<T> &tr, int root):\n      N_(tr.size()), parent_(N_), depth_(N_), left_(N_),\
    \ right_(N_)\n    {\n      {\n        int ord = 0;\n        dfs(tr, root, -1,\
    \ 0, ord);\n      }\n\n      {\n        std::queue<std::pair<int, int>> q;\n \
    \       q.emplace(root, 0);\n        int ord = 0;\n\n        while(not q.empty()){\n\
    \          auto [i, d] = q.front(); q.pop();\n\n          if((int)bfs_order_.size()\
    \ <= d) bfs_order_.emplace_back();\n          bfs_order_[d].push_back(ord);\n\
    \          ++ord;\n\n          for(auto &e : tr[i]){\n            if(e.to == parent_[i])\
    \ continue;\n            q.emplace(e.to, d + 1);\n          }\n        }\n   \
    \   }\n    }\n\n  private:\n    void dfs(const tree<T> &tr, int cur, int par,\
    \ int d, int &ord){\n      parent_[cur] = par;\n      depth_[cur] = d;\n\n   \
    \   if((int)dfs_order_.size() <= d) dfs_order_.emplace_back();\n      dfs_order_[d].push_back(ord);\n\
    \      left_[cur] = ord;\n      ++ord;\n\n      for(auto &e : tr[cur]){\n    \
    \    if(e.to == par) continue;\n        dfs(tr, e.to, cur, d + 1, ord);\n    \
    \  }\n\n      right_[cur] = ord;\n    }\n\n  public:\n    template <typename Func>\n\
    \    void query_children(int i, int d, const Func &f) const {\n      if(i != -1){\n\
    \        d += depth_[i];\n        if((int)bfs_order_.size() > d){\n          int\
    \ l = std::lower_bound(dfs_order_[d].begin(), dfs_order_[d].end(), left_[i]) -\
    \ dfs_order_[d].begin();\n          int r = std::lower_bound(dfs_order_[d].begin(),\
    \ dfs_order_[d].end(), right_[i]) - dfs_order_[d].begin();\n\n          if(l >=\
    \ (int)bfs_order_[d].size()) return;\n          if(r == l) return;\n\n       \
    \   f(bfs_order_[d][l], bfs_order_[d][r - 1] + 1);\n        }\n      }\n    }\n\
    \n    template <typename Func>\n    void query_at(int i, const Func &f) const\
    \ {\n      query_children(i, 0, f);\n    }\n\n    int get_parent(int i) const\
    \ {\n      if(i == -1) return -1;\n      return parent_[i];\n    }\n\n    int\
    \ get_ancestor(int i, int k) const {\n      int ret = i;\n      for(int i = 0;\
    \ i < k; ++i){\n        ret = get_parent(ret);\n        if(ret == -1) break;\n\
    \      }\n      return ret;\n    }\n  };\n}\n#line 3 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  class lazy_segment_tree\
    \ {\n  public:\n    using monoid_get = typename Monoid::monoid_get;\n    using\
    \ monoid_update = typename Monoid::monoid_update;\n    using value_type_get =\
    \ typename monoid_get::value_type;\n    using value_type_update = typename monoid_update::value_type;\n\
    \n  private:\n    Monoid M_;\n    monoid_get M_get_;\n    monoid_update M_update_;\n\
    \n    int depth_, size_, hsize_;\n    std::vector<value_type_get> data_;\n   \
    \ std::vector<value_type_update> lazy_;\n\n    void propagate(int i){\n      if(lazy_[i]\
    \ == M_update_()) return;\n      if(i < hsize_){\n        lazy_[i << 1 | 0] =\
    \ M_update_(lazy_[i], lazy_[i << 1 | 0]);\n        lazy_[i << 1 | 1] = M_update_(lazy_[i],\
    \ lazy_[i << 1 | 1]);\n      }\n      const int len = hsize_ >> (31 - __builtin_clz(i));\n\
    \      data_[i] = M_(data_[i], lazy_[i], len);\n      lazy_[i] = M_update_();\n\
    \    }\n\n    void propagate_top_down(int i){\n      std::vector<int> temp;\n\
    \      while(i > 1){\n        i >>= 1;\n        temp.push_back(i);\n      }\n\n\
    \      for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);\n\
    \    }\n\n    void bottom_up(int i){\n      while(i > 1){\n        i >>= 1;\n\
    \        propagate(i << 1 | 0);\n        propagate(i << 1 | 1);\n        data_[i]\
    \ = M_get_(data_[i << 1 | 0], data_[i << 1 | 1]);\n      }\n    }\n\n  public:\n\
    \    lazy_segment_tree(){}\n    lazy_segment_tree(int n):\n      depth_(n > 1\
    \ ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_),\n      hsize_(size_\
    \ / 2),\n      data_(size_, M_get_()),\n      lazy_(size_, M_update_())\n    {}\n\
    \n    void update(int l, int r, const value_type_update &x){\n      propagate_top_down(l\
    \ + hsize_);\n      if(r < hsize_) propagate_top_down(r + hsize_);\n\n      int\
    \ L = l + hsize_, R = r + hsize_;\n\n      while(L < R){\n        if(R & 1){\n\
    \          --R;\n          lazy_[R] = M_update_(x, lazy_[R]);\n          propagate(R);\n\
    \        }\n        if(L & 1){\n          lazy_[L] = M_update_(x, lazy_[L]);\n\
    \          propagate(L);\n          ++L;\n        }\n        L >>= 1;\n      \
    \  R >>= 1;\n      }\n\n      bottom_up(l + hsize_);\n      if(r < hsize_) bottom_up(r\
    \ + hsize_);\n    }\n\n    void update(int i, const value_type_update &x){update(i,\
    \ i + 1, x);}\n\n    value_type_get fold(int l, int r){\n      propagate_top_down(l\
    \ + hsize_);\n      if(r < hsize_) propagate_top_down(r + hsize_);\n\n      value_type_get\
    \ ret_left = M_get_(), ret_right = M_get_();\n\n      int L = l + hsize_, R =\
    \ r + hsize_;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n   \
    \       propagate(R);\n          ret_right = M_get_(data_[R], ret_right);\n  \
    \      }\n        if(L & 1){\n          propagate(L);\n          ret_left = M_get_(ret_left,\
    \ data_[L]);\n          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n\
    \      }\n\n      return M_get_(ret_left, ret_right);\n    }\n\n    value_type_get\
    \ fold_all(){\n      return fold(0, hsize_);\n    }\n\n    value_type_get operator[](int\
    \ i){return fold(i, i + 1);}\n\n    template <typename T>\n    void init(const\
    \ T &val){\n      init_with_vector(std::vector<T>(hsize_, val));\n    }\n\n  \
    \  template <typename T>\n    void init_with_vector(const std::vector<T> &val){\n\
    \      data_.assign(size_, M_get_());\n      lazy_.assign(size_, M_update_());\n\
    \      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = (value_type_get)val[i];\n\
    \      for(int i = hsize_; --i > 0;) data_[i] = M_get_(data_[i << 1 | 0], data_[i\
    \ << 1 | 1]);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/update.cpp\"\
    \n#include <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ update_monoid {\n    using value_type = std::optional<T>;\n    value_type operator()()\
    \ const {return std::nullopt;}\n    value_type operator()(const value_type &a,\
    \ const value_type &b) const {return (a ? a : b);}\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 2 \"Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename MonoidUpdate, typename MonoidGet>\n  struct update_sum\
    \ {\n    using monoid_get = MonoidGet;\n    using monoid_update = MonoidUpdate;\n\
    \    using value_type_get = typename MonoidGet::value_type;\n    using value_type_update\
    \ = typename MonoidUpdate::value_type;\n\n    value_type_get operator()(value_type_get\
    \ a, value_type_update b, int len) const {\n      return b ? *b * len : a;\n \
    \   }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n\
    \  }\n\n  template <typename T>\n  std::vector<std::vector<T>> input_vector(int\
    \ N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i <\
    \ N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#include <utility>\n#include <initializer_list>\n#line 6 \"\
    Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename T, size_t\
    \ ... I>\n  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)\
    \ ...};\n  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
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
    \ ...>(N);\n  }\n}\n#line 12 \"test/yukicoder/899/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing update = hl::update_monoid<int64_t>;\nusing sum = hl::sum_monoid<int64_t>;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N; std::cin >> N;\n\n  hl::tree<int> tree(N);\n  tree.read<0, false, false>(N\
    \ - 1);\n\n  auto res = hl::euler_tour_bfs<int>(tree, 0);\n\n  auto A = hl::input_vector<int64_t>(N);\n\
    \  hl::lazy_segment_tree<hl::update_sum<update, sum>> seg(N);\n\n  for(int i =\
    \ 0; i < N; ++i){\n    res.query_at(i, [&](int l, int r){seg.update(l, r, A[i]);});\n\
    \  }\n\n  int Q; std::cin >> Q;\n\n  for(auto [x] : hl::input_tuples<int>(Q)){\n\
    \    int64_t ans = 0;\n\n    auto f =\n      [&](int l, int r){\n        ans +=\
    \ seg.fold(l, r);\n        seg.update(l, r, 0);\n      };\n\n    // \u89AA\u306E\
    \u89AA\n    res.query_at(res.get_ancestor(x, 2), f);\n\n    // \u89AA\n    res.query_at(res.get_ancestor(x,\
    \ 1), f);\n\n    // \u89AA\u306E\u5B50\n    res.query_children(res.get_parent(x),\
    \ 1, f);\n\n    // \u81EA\u5206\n    res.query_at(x, f);\n\n    // \u5B50\n  \
    \  res.query_children(x, 1, f);\n\n    // \u5B50\u306E\u5B50\n    res.query_children(x,\
    \ 2, f);\n\n    res.query_at(\n      x,\n      [&](int l, int r){\n        seg.update(l,\
    \ r, ans);\n      }\n    );\n\n    std::cout << ans << std::endl;\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/899\"\n\n#include <iostream>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Graph/TreeUtils/euler_tour_bfs.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n#include\
    \ \"Mylib/AlgebraicStructure/Monoid/update.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp\"\n#include\
    \ \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing update = hl::update_monoid<int64_t>;\nusing sum = hl::sum_monoid<int64_t>;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N; std::cin >> N;\n\n  hl::tree<int> tree(N);\n  tree.read<0, false, false>(N\
    \ - 1);\n\n  auto res = hl::euler_tour_bfs<int>(tree, 0);\n\n  auto A = hl::input_vector<int64_t>(N);\n\
    \  hl::lazy_segment_tree<hl::update_sum<update, sum>> seg(N);\n\n  for(int i =\
    \ 0; i < N; ++i){\n    res.query_at(i, [&](int l, int r){seg.update(l, r, A[i]);});\n\
    \  }\n\n  int Q; std::cin >> Q;\n\n  for(auto [x] : hl::input_tuples<int>(Q)){\n\
    \    int64_t ans = 0;\n\n    auto f =\n      [&](int l, int r){\n        ans +=\
    \ seg.fold(l, r);\n        seg.update(l, r, 0);\n      };\n\n    // \u89AA\u306E\
    \u89AA\n    res.query_at(res.get_ancestor(x, 2), f);\n\n    // \u89AA\n    res.query_at(res.get_ancestor(x,\
    \ 1), f);\n\n    // \u89AA\u306E\u5B50\n    res.query_children(res.get_parent(x),\
    \ 1, f);\n\n    // \u81EA\u5206\n    res.query_at(x, f);\n\n    // \u5B50\n  \
    \  res.query_children(x, 1, f);\n\n    // \u5B50\u306E\u5B50\n    res.query_children(x,\
    \ 2, f);\n\n    res.query_at(\n      x,\n      [&](int l, int r){\n        seg.update(l,\
    \ r, ans);\n      }\n    );\n\n    std::cout << ans << std::endl;\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/euler_tour_bfs.cpp
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/update.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/899/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-02 17:13:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/899/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/899/main.test.cpp
- /verify/test/yukicoder/899/main.test.cpp.html
title: test/yukicoder/899/main.test.cpp
---
