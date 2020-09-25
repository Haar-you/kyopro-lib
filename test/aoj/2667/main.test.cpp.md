---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
    title: Heavy-light decomposition
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
    title: Lazy segment tree
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp
    title: Range add / Range sum
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
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
    \    int n;\n\n    std::vector<int> sub, // subtree size\n      par, // parent\
    \ id\n      head, // chain head id\n      id, // id[original id] = hld id\n  \
    \    rid, // rid[hld id] = original id\n      next, // next node in a chain\n\
    \      end; //\n\n    int dfs_sub(tree<T> &tr, int cur, int p){\n      par[cur]\
    \ = p;\n      int t = 0;\n      for(auto &e : tr[cur]){\n        if(e.to == p)\
    \ continue;\n        sub[cur] += dfs_sub(tr, e.to, cur);\n        if(sub[e.to]\
    \ > t){\n          t = sub[e.to];\n          next[cur] = e.to;\n          std::swap(e,\
    \ tr[cur][0]);\n        }\n      }\n      return sub[cur];\n    }\n\n    void\
    \ dfs_build(const tree<T> &tr, int cur, int &i){\n      id[cur] = i;\n      rid[i]\
    \ = cur;\n      ++i;\n\n      for(auto &e : tr[cur]){\n        if(e.to == par[cur])\
    \ continue;\n        head[e.to] = (e.to == tr[cur][0].to ? head[cur] : e.to);\n\
    \        dfs_build(tr, e.to, i);\n      }\n\n      end[cur] = i;\n    }\n\n  public:\n\
    \    hl_decomposition(tree<T> tr, int root):\n      n(tr.size()), sub(n, 1), par(n,\
    \ -1), head(n), id(n), rid(n), next(n, -1), end(n, -1){\n      dfs_sub(tr, root,\
    \ -1);\n      int i = 0;\n      dfs_build(tr, root, i);\n    }\n\n    std::vector<std::tuple<int,\
    \ int, bool>> path_query_vertex(int x, int y) const {\n      std::vector<std::tuple<int,\
    \ int, bool>> ret;\n      const int w = lca(x, y);\n\n      {\n        int y =\
    \ w;\n        bool d = true;\n        while(1){\n          if(id[x] > id[y]) std::swap(x,\
    \ y), d = not d;\n          int l = std::max(id[head[y]], id[x]), r = id[y] +\
    \ 1;\n          if(l != r) ret.emplace_back(l, r, d);\n          if(head[x] ==\
    \ head[y]) break;\n          y = par[head[y]];\n        }\n      }\n\n      x\
    \ = y;\n      y = w;\n\n      {\n        std::vector<std::tuple<int, int, bool>>\
    \ temp;\n        bool d = false;\n        while(1){\n          if(id[x] > id[y])\
    \ std::swap(x, y), d = not d;\n          int l = std::max({id[head[y]], id[x],\
    \ id[w] + 1}), r = id[y] + 1;\n          if(l != r) temp.emplace_back(l, r, d);\n\
    \          if(head[x] == head[y]) break;\n          y = par[head[y]];\n      \
    \  }\n\n        std::reverse(temp.begin(), temp.end());\n        ret.insert(ret.end(),\
    \ temp.begin(), temp.end());\n      }\n\n      return ret;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> path_query_edge(int x, int y) const {\n      std::vector<std::pair<int,\
    \ int>> ret;\n      while(1){\n        if(id[x] > id[y]) std::swap(x, y);\n  \
    \      if(head[x] == head[y]){\n          if(x != y) ret.emplace_back(id[x] +\
    \ 1, id[y] + 1);\n          break;\n        }\n        ret.emplace_back(id[head[y]],\
    \ id[y] + 1);\n        y = par[head[y]];\n      }\n      return ret;\n    }\n\n\
    \    std::pair<int, int> subtree_query_edge(int x) const {\n      return {id[x]\
    \ + 1, end[x]};\n    }\n\n    std::pair<int, int> subtree_query_vertex(int x)\
    \ const {\n      return {id[x], end[x]};\n    }\n\n    int get_edge_id(int u,\
    \ int v) const { // \u8FBA\u306B\u5BFE\u5FDC\u3059\u308Bid\n      if(par[u] ==\
    \ v) return id[u];\n      if(par[v] == u) return id[v];\n      return -1;\n  \
    \  }\n\n    int parent(int x) const {return par[x];};\n\n    int lca(int u, int\
    \ v) const {\n      while(1){\n        if(id[u] > id[v]) std::swap(u, v);\n  \
    \      if(head[u] == head[v]) return u;\n        v = par[head[v]];\n      }\n\
    \    }\n\n    int get_id(int x) const {\n      return id[x];\n    }\n  };\n}\n\
    #line 3 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate, template\
    \ <typename, typename> typename Connector>\n  class lazy_segment_tree {\n    using\
    \ value_type_get = typename MonoidGet::value_type;\n    using value_type_update\
    \ = typename MonoidUpdate::value_type;\n    Connector<MonoidGet, MonoidUpdate>\
    \ M;\n    MonoidGet M_get;\n    MonoidUpdate M_update;\n\n    const int depth,\
    \ size, hsize;\n    std::vector<value_type_get> data;\n    std::vector<value_type_update>\
    \ lazy;\n\n    void propagate(int i){\n      if(lazy[i] == M_update()) return;\n\
    \      if(i < hsize){\n        lazy[i << 1 | 0] = M_update(lazy[i], lazy[i <<\
    \ 1 | 0]);\n        lazy[i << 1 | 1] = M_update(lazy[i], lazy[i << 1 | 1]);\n\
    \      }\n      int len = hsize >> (31 - __builtin_clz(i));\n      data[i] = M(data[i],\
    \ lazy[i], len);\n      lazy[i] = M_update();\n    }\n\n    void propagate_top_down(int\
    \ i){\n      std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for(auto it = temp.rbegin(); it !=\
    \ temp.rend(); ++it) propagate(*it);\n    }\n\n    void bottom_up(int i){\n  \
    \    while(i > 1){\n        i >>= 1;\n        propagate(i << 1 | 0);\n       \
    \ propagate(i << 1 | 1);\n        data[i] = M_get(data[i << 1 | 0], data[i <<\
    \ 1 | 1]);\n      }\n    }\n\n  public:\n    lazy_segment_tree(){}\n    lazy_segment_tree(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth),\n      hsize(size / 2),\n      data(size, M_get()),\n      lazy(size,\
    \ M_update())\n    {}\n\n    void update(int l, int r, const value_type_update\
    \ &x){\n      propagate_top_down(l + hsize);\n      if(r < hsize) propagate_top_down(r\
    \ + hsize);\n\n      int L = l + hsize, R = r + hsize;\n\n      while(L < R){\n\
    \        if(R & 1){\n          --R;\n          lazy[R] = M_update(x, lazy[R]);\n\
    \          propagate(R);\n        }\n        if(L & 1){\n          lazy[L] = M_update(x,\
    \ lazy[L]);\n          propagate(L);\n          ++L;\n        }\n        L >>=\
    \ 1;\n        R >>= 1;\n      }\n\n      bottom_up(l + hsize);\n      if(r < hsize)\
    \ bottom_up(r + hsize);\n    }\n\n    void update(int i, const value_type_update\
    \ &x){update(i, i + 1, x);}\n\n    value_type_get fold(int l, int r){\n      propagate_top_down(l\
    \ + hsize);\n      if(r < hsize) propagate_top_down(r + hsize);\n\n      value_type_get\
    \ ret_left = M_get(), ret_right = M_get();\n\n      int L = l + hsize, R = r +\
    \ hsize;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n        \
    \  propagate(R);\n          ret_right = M_get(data[R], ret_right);\n        }\n\
    \        if(L & 1){\n          propagate(L);\n          ret_left = M_get(ret_left,\
    \ data[L]);\n          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n \
    \     }\n\n      return M_get(ret_left, ret_right);\n    }\n\n    value_type_get\
    \ operator[](int i){return fold(i, i + 1);}\n\n    template <typename T>\n   \
    \ void init(const T &val){\n      init_with_vector(std::vector<T>(hsize, val));\n\
    \    }\n\n    template <typename T>\n    void init_with_vector(const std::vector<T>\
    \ &val){\n      data.assign(size, M_get());\n      lazy.assign(size, M_update());\n\
    \      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = (value_type_get)val[i];\n\
    \      for(int i = hsize - 1; i > 0; --i) data[i] = M_get(data[i << 1 | 0], data[i\
    \ << 1 | 1]);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 2 \"Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename MonoidGet, typename MonoidUpdate>\n  struct add_sum\
    \ {\n    using value_type_get = typename MonoidGet::value_type;\n    using value_type_update\
    \ = typename MonoidUpdate::value_type;\n\n    value_type_get operator()(value_type_get\
    \ a, value_type_update b, int len) const {\n      return a + b * len;\n    }\n\
    \  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#line 6 \"\
    Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 10 \"test/aoj/2667/main.test.cpp\"\n\nnamespace hl =\
    \ haar_lib;\n\nint main(){\n  int N, Q; std::cin >> N >> Q;\n\n  hl::tree<int>\
    \ tree(N);\n  tree.read<0, false, false>(N - 1);\n\n  auto hld = hl::hl_decomposition(tree,\
    \ 0);\n  hl::lazy_segment_tree<hl::sum_monoid<int64_t>, hl::sum_monoid<int64_t>,\
    \ hl::add_sum> seg(N);\n\n  for(auto [c] : hl::input_tuples<int>(Q)){\n    if(c\
    \ == 0){\n      int u, v; std::cin >> u >> v;\n\n      int64_t ans = 0;\n    \
    \  for(auto [l, r] : hld.path_query_edge(u, v)){\n        ans += seg.fold(l, r);\n\
    \      }\n      std::cout << ans << std::endl;\n    }else{\n      int v, x; std::cin\
    \ >> v >> x;\n\n      auto [l, r] = hld.subtree_query_edge(v);\n      seg.update(l,\
    \ r, x);\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\
    \n\n#include <iostream>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\n#include \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N, Q; std::cin >> N >> Q;\n\n  hl::tree<int> tree(N);\n  tree.read<0, false,\
    \ false>(N - 1);\n\n  auto hld = hl::hl_decomposition(tree, 0);\n  hl::lazy_segment_tree<hl::sum_monoid<int64_t>,\
    \ hl::sum_monoid<int64_t>, hl::add_sum> seg(N);\n\n  for(auto [c] : hl::input_tuples<int>(Q)){\n\
    \    if(c == 0){\n      int u, v; std::cin >> u >> v;\n\n      int64_t ans = 0;\n\
    \      for(auto [l, r] : hld.path_query_edge(u, v)){\n        ans += seg.fold(l,\
    \ r);\n      }\n      std::cout << ans << std::endl;\n    }else{\n      int v,\
    \ x; std::cin >> v >> x;\n\n      auto [l, r] = hld.subtree_query_edge(v);\n \
    \     seg.update(l, r, x);\n    }\n  }\n\n  return 0;\n}\n"
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
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2667/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2667/main.test.cpp
- /verify/test/aoj/2667/main.test.cpp.html
title: test/aoj/2667/main.test.cpp
---
