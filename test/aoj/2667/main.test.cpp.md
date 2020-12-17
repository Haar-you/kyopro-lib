---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp
    title: Range add / Range sum
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
    title: Lazy segment tree
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
    title: Heavy-light decomposition
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
  bundledCode: "#line 1 \"test/aoj/2667/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\
    \n#include <utility>\n#include <algorithm>\n#line 6 \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class hl_decomposition {\n\
    \    int n_;\n\n    std::vector<int> sub_, // subtree size\n      par_, // parent\
    \ id\n      head_, // chain head id\n      id_, // id[original id] = hld id\n\
    \      rid_, // rid[hld id] = original id\n      next_, // next node in a chain\n\
    \      end_; //\n\n    int dfs_sub(tree<T> &tr, int cur, int p){\n      par_[cur]\
    \ = p;\n      int t = 0;\n      for(auto &e : tr[cur]){\n        if(e.to == p)\
    \ continue;\n        sub_[cur] += dfs_sub(tr, e.to, cur);\n        if(sub_[e.to]\
    \ > t){\n          t = sub_[e.to];\n          next_[cur] = e.to;\n          std::swap(e,\
    \ tr[cur][0]);\n        }\n      }\n      return sub_[cur];\n    }\n\n    void\
    \ dfs_build(const tree<T> &tr, int cur, int &i){\n      id_[cur] = i;\n      rid_[i]\
    \ = cur;\n      ++i;\n\n      for(auto &e : tr[cur]){\n        if(e.to == par_[cur])\
    \ continue;\n        head_[e.to] = (e.to == tr[cur][0].to ? head_[cur] : e.to);\n\
    \        dfs_build(tr, e.to, i);\n      }\n\n      end_[cur] = i;\n    }\n\n \
    \ public:\n    hl_decomposition(){}\n    hl_decomposition(tree<T> tr, int root):\n\
    \      n_(tr.size()), sub_(n_, 1), par_(n_, -1), head_(n_), id_(n_), rid_(n_),\
    \ next_(n_, -1), end_(n_, -1){\n      dfs_sub(tr, root, -1);\n      int i = 0;\n\
    \      dfs_build(tr, root, i);\n    }\n\n    std::vector<std::tuple<int, int,\
    \ bool>> path_query_vertex(int x, int y) const {\n      std::vector<std::tuple<int,\
    \ int, bool>> ret;\n      const int w = lca(x, y);\n\n      {\n        int y =\
    \ w;\n        bool d = true;\n        while(1){\n          if(id_[x] > id_[y])\
    \ std::swap(x, y), d = not d;\n          int l = std::max(id_[head_[y]], id_[x]),\
    \ r = id_[y] + 1;\n          if(l != r) ret.emplace_back(l, r, d);\n         \
    \ if(head_[x] == head_[y]) break;\n          y = par_[head_[y]];\n        }\n\
    \      }\n\n      x = y;\n      y = w;\n\n      {\n        std::vector<std::tuple<int,\
    \ int, bool>> temp;\n        bool d = false;\n        while(1){\n          if(id_[x]\
    \ > id_[y]) std::swap(x, y), d = not d;\n          int l = std::max({id_[head_[y]],\
    \ id_[x], id_[w] + 1}), r = id_[y] + 1;\n          if(l != r) temp.emplace_back(l,\
    \ r, d);\n          if(head_[x] == head_[y]) break;\n          y = par_[head_[y]];\n\
    \        }\n\n        std::reverse(temp.begin(), temp.end());\n        ret.insert(ret.end(),\
    \ temp.begin(), temp.end());\n      }\n\n      return ret;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> path_query_edge(int x, int y) const {\n      std::vector<std::pair<int,\
    \ int>> ret;\n      while(1){\n        if(id_[x] > id_[y]) std::swap(x, y);\n\
    \        if(head_[x] == head_[y]){\n          if(x != y) ret.emplace_back(id_[x]\
    \ + 1, id_[y] + 1);\n          break;\n        }\n        ret.emplace_back(id_[head_[y]],\
    \ id_[y] + 1);\n        y = par_[head_[y]];\n      }\n      return ret;\n    }\n\
    \n    std::pair<int, int> subtree_query_edge(int x) const {\n      return {id_[x]\
    \ + 1, end_[x]};\n    }\n\n    std::pair<int, int> subtree_query_vertex(int x)\
    \ const {\n      return {id_[x], end_[x]};\n    }\n\n    int get_edge_id(int u,\
    \ int v) const { // \u8FBA\u306B\u5BFE\u5FDC\u3059\u308Bid\n      if(par_[u] ==\
    \ v) return id_[u];\n      if(par_[v] == u) return id_[v];\n      return -1;\n\
    \    }\n\n    int parent(int x) const {return par_[x];};\n\n    int lca(int u,\
    \ int v) const {\n      while(1){\n        if(id_[u] > id_[v]) std::swap(u, v);\n\
    \        if(head_[u] == head_[v]) return u;\n        v = par_[head_[v]];\n   \
    \   }\n    }\n\n    int get_id(int x) const {\n      return id_[x];\n    }\n \
    \ };\n}\n#line 3 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n#include\
    \ <cassert>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  class lazy_segment_tree\
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
    \n    void update(int l, int r, const value_type_update &x){\n      assert(0 <=\
    \ l and l <= r and r <= hsize_);\n      propagate_top_down(l + hsize_);\n    \
    \  if(r < hsize_) propagate_top_down(r + hsize_);\n\n      int L = l + hsize_,\
    \ R = r + hsize_;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n\
    \          lazy_[R] = M_update_(x, lazy_[R]);\n          propagate(R);\n     \
    \   }\n        if(L & 1){\n          lazy_[L] = M_update_(x, lazy_[L]);\n    \
    \      propagate(L);\n          ++L;\n        }\n        L >>= 1;\n        R >>=\
    \ 1;\n      }\n\n      bottom_up(l + hsize_);\n      if(r < hsize_) bottom_up(r\
    \ + hsize_);\n    }\n\n    void update(int i, const value_type_update &x){update(i,\
    \ i + 1, x);}\n\n    value_type_get fold(int l, int r){\n      assert(0 <= l and\
    \ l <= r and r <= hsize_);\n      propagate_top_down(l + hsize_);\n      if(r\
    \ < hsize_) propagate_top_down(r + hsize_);\n\n      value_type_get ret_left =\
    \ M_get_(), ret_right = M_get_();\n\n      int L = l + hsize_, R = r + hsize_;\n\
    \n      while(L < R){\n        if(R & 1){\n          --R;\n          propagate(R);\n\
    \          ret_right = M_get_(data_[R], ret_right);\n        }\n        if(L &\
    \ 1){\n          propagate(L);\n          ret_left = M_get_(ret_left, data_[L]);\n\
    \          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n      }\n\n  \
    \    return M_get_(ret_left, ret_right);\n    }\n\n    value_type_get fold_all(){\n\
    \      return fold(0, hsize_);\n    }\n\n    value_type_get operator[](int i){return\
    \ fold(i, i + 1);}\n\n    template <typename T>\n    void init(const T &val){\n\
    \      init_with_vector(std::vector<T>(hsize_, val));\n    }\n\n    template <typename\
    \ T>\n    void init_with_vector(const std::vector<T> &val){\n      data_.assign(size_,\
    \ M_get_());\n      lazy_.assign(size_, M_update_());\n      for(int i = 0; i\
    \ < (int)val.size(); ++i) data_[hsize_ + i] = (value_type_get)val[i];\n      for(int\
    \ i = hsize_; --i > 0;) data_[i] = M_get_(data_[i << 1 | 0], data_[i << 1 | 1]);\n\
    \    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct sum_monoid {\n    using value_type\
    \ = T;\n    value_type operator()() const {return 0;}\n    value_type operator()(value_type\
    \ a, value_type b) const {return a + b;}\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct add_sum {\n    using monoid_get = MonoidGet;\n    using monoid_update\
    \ = MonoidUpdate;\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int len) const {\n      return\
    \ a + b * len;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include\
    \ <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
    #line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t ... I>\n  static void input_tuple_helper(std::istream &s, T &val,\
    \ std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s >>\
    \ std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n  std::istream&\
    \ operator>>(std::istream &s, std::pair<T, U> &value){\n    s >> value.first >>\
    \ value.second;\n    return s;\n  }\n\n  template <typename ... Args>\n  std::istream&\
    \ operator>>(std::istream &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s,\
    \ value, std::make_index_sequence<sizeof ... (Args)>());\n    return s;\n  }\n\
    }\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ ... Args>\n  class InputTuples {\n    struct iter {\n      using value_type\
    \ = std::tuple<Args ...>;\n      value_type value;\n      bool fetched = false;\n\
    \      int N, c = 0;\n\n      value_type operator*(){\n        if(not fetched){\n\
    \          std::cin >> value;\n        }\n        return value;\n      }\n\n \
    \     void operator++(){\n        ++c;\n        fetched = false;\n      }\n\n\
    \      bool operator!=(iter &) const {\n        return c < N;\n      }\n\n   \
    \   iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n    InputTuples(int\
    \ N): N(N){}\n\n    iter begin() const {return iter(N);}\n    iter end() const\
    \ {return iter(N);}\n  };\n\n  template <typename ... Args>\n  auto input_tuples(int\
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 10 \"test/aoj/2667/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing sum = hl::sum_monoid<int64_t>;\n\nint main(){\n\
    \  int N, Q; std::cin >> N >> Q;\n\n  hl::tree<int> tree(N);\n  tree.read<0, false,\
    \ false>(N - 1);\n\n  auto hld = hl::hl_decomposition(tree, 0);\n  hl::lazy_segment_tree<hl::add_sum<sum,\
    \ sum>> seg(N);\n\n  for(auto [c] : hl::input_tuples<int>(Q)){\n    if(c == 0){\n\
    \      int u, v; std::cin >> u >> v;\n\n      int64_t ans = 0;\n      for(auto\
    \ [l, r] : hld.path_query_edge(u, v)){\n        ans += seg.fold(l, r);\n     \
    \ }\n      std::cout << ans << std::endl;\n    }else{\n      int v, x; std::cin\
    \ >> v >> x;\n\n      auto [l, r] = hld.subtree_query_edge(v);\n      seg.update(l,\
    \ r, x);\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\n#include \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ sum = hl::sum_monoid<int64_t>;\n\nint main(){\n  int N, Q; std::cin >> N >>\
    \ Q;\n\n  hl::tree<int> tree(N);\n  tree.read<0, false, false>(N - 1);\n\n  auto\
    \ hld = hl::hl_decomposition(tree, 0);\n  hl::lazy_segment_tree<hl::add_sum<sum,\
    \ sum>> seg(N);\n\n  for(auto [c] : hl::input_tuples<int>(Q)){\n    if(c == 0){\n\
    \      int u, v; std::cin >> u >> v;\n\n      int64_t ans = 0;\n      for(auto\
    \ [l, r] : hld.path_query_edge(u, v)){\n        ans += seg.fold(l, r);\n     \
    \ }\n      std::cout << ans << std::endl;\n    }else{\n      int v, x; std::cin\
    \ >> v >> x;\n\n      auto [l, r] = hld.subtree_query_edge(v);\n      seg.update(l,\
    \ r, x);\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/2667/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2667/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2667/main.test.cpp
- /verify/test/aoj/2667/main.test.cpp.html
title: test/aoj/2667/main.test.cpp
---
