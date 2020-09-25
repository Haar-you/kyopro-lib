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
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/max.cpp
    title: Max monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/maybe.cpp
    title: Maybe monoid
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
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
    PROBLEM: https://yukicoder.me/problems/no/1030
    links:
    - https://yukicoder.me/problems/no/1030
  bundledCode: "#line 1 \"test/yukicoder/1030/main.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1030\"\n\n#include <iostream>\n#include <functional>\n\
    #include <algorithm>\n#include <vector>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
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
    \n#include <utility>\n#line 6 \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\
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
    #line 5 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename Monoid>\n  class segment_tree {\n    using value_type\
    \ = typename Monoid::value_type;\n    const static Monoid M;\n\n    int depth,\
    \ size, hsize;\n    std::vector<value_type> data;\n\n  public:\n    segment_tree(){}\n\
    \    segment_tree(int n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 :\
    \ 1),\n      size(1 << depth), hsize(size / 2),\n      data(size, M())\n    {}\n\
    \n    auto operator[](int i) const {return data[hsize + i];}\n\n    auto fold(int\
    \ x, int y) const {\n      value_type ret_left = M();\n      value_type ret_right\
    \ = M();\n\n      int l = x + hsize, r = y + hsize;\n      while(l < r){\n   \
    \     if(r & 1) ret_right = M(data[--r], ret_right);\n        if(l & 1) ret_left\
    \ = M(ret_left, data[l++]);\n        l >>= 1, r >>= 1;\n      }\n\n      return\
    \ M(ret_left, ret_right);\n    }\n\n    void set(int i, const value_type &x){\n\
    \      i += hsize;\n      data[i] = x;\n      while(i > 1) i >>= 1, data[i] =\
    \ M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n    void update(int i, const\
    \ value_type &x){\n      i += hsize;\n      data[i] = M(data[i], x);\n      while(i\
    \ > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n  \
    \  template <typename T>\n    void init_with_vector(const std::vector<T> &val){\n\
    \      data.assign(size, M());\n      for(int i = 0; i < (int)val.size(); ++i)\
    \ data[hsize + i] = val[i];\n      for(int i = hsize - 1; i >= 1; --i) data[i]\
    \ = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n    template <typename T>\n\
    \    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize,\
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
    \ bound<false>(l, r, x, f);\n    }\n  };\n}\n#line 3 \"Mylib/AlgebraicStructure/Monoid/max.cpp\"\
    \n#include <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ max_monoid {\n    using value_type = std::optional<T>;\n\n    value_type operator()()\
    \ const {return {};}\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if(not a) return b;\n      if(not b) return a;\n      return\
    \ {std::max(*a, *b)};\n    }\n  };\n}\n#line 3 \"Mylib/AlgebraicStructure/Monoid/maybe.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Semigroup>\n  struct maybe_monoid\
    \ {\n    using value_type = std::optional<typename Semigroup::value_type>;\n \
    \   const static Semigroup S;\n\n    value_type operator()() const {return std::nullopt;}\n\
    \    value_type operator()(const value_type &a, const value_type &b) const {\n\
    \      if(not a) return b;\n      if(not b) return a;\n      return {S(*a, *b)};\n\
    \    }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n\
    \  }\n\n  template <typename T>\n  std::vector<std::vector<T>> input_vector(int\
    \ N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i <\
    \ N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
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
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 14 \"test/yukicoder/1030/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nstruct lca_semigroup {\n  using value_type = int;\n\
    \  static std::function<int(int, int)> lca;\n  value_type operator()(value_type\
    \ a, value_type b) const {\n    return lca(a, b);\n  }\n};\n\nstd::function<int(int,\
    \ int)> lca_semigroup::lca;\n\nint main(){\n  int N, K, Q; std::cin >> N >> K\
    \ >> Q;\n\n  auto C = hl::input_vector<int>(N);\n  auto A = hl::input_vector<int>(K);\n\
    \  for(auto &x : A) --x;\n\n  hl::tree<int> tree(N);\n  tree.read<1, false, false>(N\
    \ - 1);\n\n  hl::hl_decomposition<int> hld(tree, 0);\n  lca_semigroup::lca = [&](int\
    \ a, int b){return hld.lca(a, b);};\n\n  hl::segment_tree<hl::max_monoid<int>>\
    \ seg1(N);\n  for(int i = 0; i < N; ++i){\n    seg1.set(hld.get_id(i), {C[i]});\n\
    \  }\n\n  hl::segment_tree<hl::maybe_monoid<lca_semigroup>> seg2(K);\n  seg2.init_with_vector(A);\n\
    \n  for(auto [T] : hl::input_tuples<int>(Q)){\n    if(T == 1){\n      int X, Y;\
    \ std::cin >> X >> Y;\n      --X; --Y;\n\n      seg2.set(X, Y);\n    }else{\n\
    \      int L, R; std::cin >> L >> R;\n\n      int lca = *seg2.fold(L - 1, R);\n\
    \      int ans = 0;\n\n      for(auto [l, r, d] : hld.path_query_vertex(0, lca)){\n\
    \        ans = std::max(ans, seg1.fold(l, r).value());\n      }\n\n      std::cout\
    \ << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1030\"\n\n#include <iostream>\n\
    #include <functional>\n#include <algorithm>\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n#include \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\n#include \"\
    Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/max.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/maybe.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nstruct\
    \ lca_semigroup {\n  using value_type = int;\n  static std::function<int(int,\
    \ int)> lca;\n  value_type operator()(value_type a, value_type b) const {\n  \
    \  return lca(a, b);\n  }\n};\n\nstd::function<int(int, int)> lca_semigroup::lca;\n\
    \nint main(){\n  int N, K, Q; std::cin >> N >> K >> Q;\n\n  auto C = hl::input_vector<int>(N);\n\
    \  auto A = hl::input_vector<int>(K);\n  for(auto &x : A) --x;\n\n  hl::tree<int>\
    \ tree(N);\n  tree.read<1, false, false>(N - 1);\n\n  hl::hl_decomposition<int>\
    \ hld(tree, 0);\n  lca_semigroup::lca = [&](int a, int b){return hld.lca(a, b);};\n\
    \n  hl::segment_tree<hl::max_monoid<int>> seg1(N);\n  for(int i = 0; i < N; ++i){\n\
    \    seg1.set(hld.get_id(i), {C[i]});\n  }\n\n  hl::segment_tree<hl::maybe_monoid<lca_semigroup>>\
    \ seg2(K);\n  seg2.init_with_vector(A);\n\n  for(auto [T] : hl::input_tuples<int>(Q)){\n\
    \    if(T == 1){\n      int X, Y; std::cin >> X >> Y;\n      --X; --Y;\n\n   \
    \   seg2.set(X, Y);\n    }else{\n      int L, R; std::cin >> L >> R;\n\n     \
    \ int lca = *seg2.fold(L - 1, R);\n      int ans = 0;\n\n      for(auto [l, r,\
    \ d] : hld.path_query_vertex(0, lca)){\n        ans = std::max(ans, seg1.fold(l,\
    \ r).value());\n      }\n\n      std::cout << ans << \"\\n\";\n    }\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/max.cpp
  - Mylib/AlgebraicStructure/Monoid/maybe.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/1030/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/1030/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1030/main.test.cpp
- /verify/test/yukicoder/1030/main.test.cpp.html
title: test/yukicoder/1030/main.test.cpp
---
