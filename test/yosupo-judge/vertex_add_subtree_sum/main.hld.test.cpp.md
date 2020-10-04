---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
    title: Heavy-light decomposition
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp\"\
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
    \ };\n}\n#line 4 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include\
    \ <functional>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  class\
    \ segment_tree {\n  public:\n    using value_type = typename Monoid::value_type;\n\
    \n  private:\n    Monoid M_;\n    int depth_, size_, hsize_;\n    std::vector<value_type>\
    \ data_;\n\n  public:\n    segment_tree(){}\n    segment_tree(int n):\n      depth_(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_), hsize_(size_\
    \ / 2),\n      data_(size_, M_())\n    {}\n\n    auto operator[](int i) const\
    \ {return data_[hsize_ + i];}\n\n    auto fold(int x, int y) const {\n      value_type\
    \ ret_left = M_();\n      value_type ret_right = M_();\n\n      int l = x + hsize_,\
    \ r = y + hsize_;\n      while(l < r){\n        if(r & 1) ret_right = M_(data_[--r],\
    \ ret_right);\n        if(l & 1) ret_left = M_(ret_left, data_[l++]);\n      \
    \  l >>= 1, r >>= 1;\n      }\n\n      return M_(ret_left, ret_right);\n    }\n\
    \n    auto fold_all() const {\n      return data_[1];\n    }\n\n    void set(int\
    \ i, const value_type &x){\n      i += hsize_;\n      data_[i] = x;\n      while(i\
    \ > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n\
    \    void update(int i, const value_type &x){\n      i += hsize_;\n      data_[i]\
    \ = M_(data_[i], x);\n      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 |\
    \ 0], data_[i << 1 | 1]);\n    }\n\n    template <typename T>\n    void init_with_vector(const\
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
    }\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  struct sum_monoid {\n    using value_type = T;\n \
    \   value_type operator()() const {return 0;}\n    value_type operator()(value_type\
    \ a, value_type b) const {return a + b;}\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t ... I>\n  static void input_tuple_helper(std::istream\
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
    \ 11 \"test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto a = hl::input_vector<int64_t>(N);\n\
    \n  hl::tree<int> tree(N);\n  for(int i = 1; i < N; ++i){\n    int p; std::cin\
    \ >> p;\n    tree.add_edge(p, i, 1);\n  }\n\n  auto seg = hl::segment_tree<hl::sum_monoid<int64_t>>(N);\n\
    \  auto hld = hl::hl_decomposition(tree, 0);\n\n  for(int i = 0; i < N; ++i){\n\
    \    seg.set(hld.get_id(i), a[i]);\n  }\n\n  for(auto [t, u] : hl::input_tuples<int,\
    \ int>(Q)){\n    if(t == 0){\n      int x; std::cin >> x;\n\n      int i = hld.get_id(u);\n\
    \      seg.update(i, x);\n    }else{\n      int64_t ans = 0;\n      auto [l, r]\
    \ = hld.subtree_query_vertex(u);\n      ans += seg.fold(l, r);\n\n      std::cout\
    \ << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n#include \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\n#include \"\
    Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto a = hl::input_vector<int64_t>(N);\n\
    \n  hl::tree<int> tree(N);\n  for(int i = 1; i < N; ++i){\n    int p; std::cin\
    \ >> p;\n    tree.add_edge(p, i, 1);\n  }\n\n  auto seg = hl::segment_tree<hl::sum_monoid<int64_t>>(N);\n\
    \  auto hld = hl::hl_decomposition(tree, 0);\n\n  for(int i = 0; i < N; ++i){\n\
    \    seg.set(hld.get_id(i), a[i]);\n  }\n\n  for(auto [t, u] : hl::input_tuples<int,\
    \ int>(Q)){\n    if(t == 0){\n      int x; std::cin >> x;\n\n      int i = hld.get_id(u);\n\
    \      seg.update(i, x);\n    }else{\n      int64_t ans = 0;\n      auto [l, r]\
    \ = hld.subtree_query_vertex(u);\n      ans += seg.fold(l, r);\n\n      std::cout\
    \ << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 13:26:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
- /verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp.html
title: test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp
---
