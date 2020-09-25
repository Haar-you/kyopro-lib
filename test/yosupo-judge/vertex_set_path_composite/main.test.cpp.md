---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
    title: Heavy-light decomposition
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp
    title: Segment tree (Both foldable)
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/affine.cpp
    title: Affine monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/dual.cpp
    title: Dual monoid
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo-judge/vertex_set_path_composite/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#line 4 \"Mylib/Number/Mint/mint.cpp\"\
    \n\nnamespace haar_lib {\n  template <int32_t M>\n  class modint {\n    uint32_t\
    \ val;\n\n  public:\n    constexpr static auto mod(){return M;}\n\n    constexpr\
    \ modint(): val(0){}\n    constexpr modint(int64_t n){\n      if(n >= M) val =\
    \ n % M;\n      else if(n < 0) val = n % M + M;\n      else val = n;\n    }\n\n\
    \    constexpr auto& operator=(const modint &a){val = a.val; return *this;}\n\
    \    constexpr auto& operator+=(const modint &a){\n      if(val + a.val >= M)\
    \ val = (uint64_t)val + a.val - M;\n      else val += a.val;\n      return *this;\n\
    \    }\n    constexpr auto& operator-=(const modint &a){\n      if(val < a.val)\
    \ val += M;\n      val -= a.val;\n      return *this;\n    }\n    constexpr auto&\
    \ operator*=(const modint &a){\n      val = (uint64_t)val * a.val % M;\n     \
    \ return *this;\n    }\n    constexpr auto& operator/=(const modint &a){\n   \
    \   val = (uint64_t)val * a.inv().val % M;\n      return *this;\n    }\n\n   \
    \ constexpr auto operator+(const modint &a) const {return modint(*this) += a;}\n\
    \    constexpr auto operator-(const modint &a) const {return modint(*this) -=\
    \ a;}\n    constexpr auto operator*(const modint &a) const {return modint(*this)\
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
    \ operator int64_t() const noexcept {return val;}\n  };\n}\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 4 \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\
    \n#include <algorithm>\n#line 6 \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\
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
    #line 3 \"Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp\"\n\n\
    namespace haar_lib {\n  template <typename Monoid>\n  class segment_tree_both_foldable\
    \ {\n    using value_type = typename Monoid::value_type;\n    const static Monoid\
    \ M;\n\n    const int depth, size, hsize;\n    std::vector<value_type> data_left,\
    \ data_right;\n\n  public:\n    segment_tree_both_foldable(int n):\n      depth(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 << depth),\n      hsize(size\
    \ / 2),\n      data_left(size, M()),\n      data_right(size, M())\n    {}\n\n\
    \    auto operator[](int i) const {return data_left[hsize + i];}\n\n    auto fold_left(int\
    \ x, int y) const {\n      value_type ret_left = M();\n      value_type ret_right\
    \ = M();\n\n      int l = x + hsize, r = y + hsize;\n      while(l < r){\n   \
    \     if(r & 1) ret_right = M(data_left[--r], ret_right);\n        if(l & 1) ret_left\
    \ = M(ret_left, data_left[l++]);\n        l >>= 1, r >>= 1;\n      }\n\n     \
    \ return M(ret_left, ret_right);\n    }\n\n    auto fold_right(int x, int y) const\
    \ {\n      value_type ret_left = M();\n      value_type ret_right = M();\n\n \
    \     int l = x + hsize, r = y + hsize;\n      while(l < r){\n        if(r & 1)\
    \ ret_right = M(ret_right, data_right[--r]);\n        if(l & 1) ret_left = M(data_right[l++],\
    \ ret_left);\n        l >>= 1, r >>= 1;\n      }\n\n      return M(ret_right,\
    \ ret_left);\n    }\n\n    void set(int i, const value_type &x){\n      i += hsize;\n\
    \      data_left[i] = data_right[i] = x;\n      while(i > 1){\n        i >>= 1;\n\
    \        data_left[i] = M(data_left[i << 1 | 0], data_left[i << 1 | 1]);\n   \
    \     data_right[i] = M(data_right[i << 1 | 1], data_right[i << 1 | 0]);\n   \
    \   }\n    }\n\n    template <typename T>\n    void init_with_vector(const std::vector<T>\
    \ &val){\n      data_left.assign(size, M());\n      data_right.assign(size, M());\n\
    \n      for(int i = 0; i < (int)val.size(); ++i){\n        data_left[hsize + i]\
    \ = val[i];\n        data_right[hsize + i] = val[i];\n      }\n      for(int i\
    \ = hsize - 1; i >= 1; --i){\n        data_left[i] = M(data_left[i << 1 | 0],\
    \ data_left[i << 1 | 1]);\n        data_right[i] = M(data_right[i << 1 | 1], data_right[i\
    \ << 1 | 0]);\n      }\n    }\n\n    template <typename T>\n    void init(const\
    \ T &val){\n      init_with_vector(std::vector<value_type>(hsize, val));\n   \
    \ }\n  };\n}\n#line 3 \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct affine_monoid {\n    using value_type\
    \ = std::pair<T, T>;\n    value_type operator()() const {return std::make_pair(1,\
    \ 0);}\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ {\n      return std::make_pair(a.first * b.first, a.first * b.second + a.second);\n\
    \    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/dual.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename Monoid>\n  struct dual_monoid {\n    using\
    \ value_type = typename Monoid::value_type;\n    const static Monoid M;\n    value_type\
    \ operator()() const {return M();}\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const {return M(b, a);}\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 14 \"test/yosupo-judge/vertex_set_path_composite/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\nusing Monoid = hl::dual_monoid<hl::affine_monoid<mint>>;\n\
    const Monoid M;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto f = hl::input_vector<std::pair<mint,\
    \ mint>>(N);\n  hl::tree<int> tree(N);\n  tree.read<0, false, false>(N - 1);\n\
    \n  hl::hl_decomposition<int> hld(tree, 0);\n  hl::segment_tree_both_foldable<Monoid>\
    \ seg(N);\n\n  for(int i = 0; i < N; ++i){\n    seg.set(hld.get_id(i), f[i]);\n\
    \  }\n\n  for(auto [type] : hl::input_tuples<int>(Q)){\n    if(type == 0){\n \
    \     int64_t p, c, d; std::cin >> p >> c >> d;\n\n      seg.set(hld.get_id(p),\
    \ std::make_pair(c, d));\n    }else{\n      int64_t u, v, x; std::cin >> u >>\
    \ v >> x;\n\n      auto res = M();\n      for(auto [l, r, d] : hld.path_query_vertex(u,\
    \ v)){\n        if(d) res = M(res, seg.fold_left(l, r));\n        else res = M(res,\
    \ seg.fold_right(l, r));\n      }\n\n      mint ans = res.first * x + res.second;\n\
    \      std::cout << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#include \"Mylib/Number/Mint/mint.cpp\"\
    \n#include \"Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp\"\n\
    #include \"Mylib/AlgebraicStructure/Monoid/affine.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/dual.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\nusing Monoid\
    \ = hl::dual_monoid<hl::affine_monoid<mint>>;\nconst Monoid M;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, Q; std::cin\
    \ >> N >> Q;\n\n  auto f = hl::input_vector<std::pair<mint, mint>>(N);\n  hl::tree<int>\
    \ tree(N);\n  tree.read<0, false, false>(N - 1);\n\n  hl::hl_decomposition<int>\
    \ hld(tree, 0);\n  hl::segment_tree_both_foldable<Monoid> seg(N);\n\n  for(int\
    \ i = 0; i < N; ++i){\n    seg.set(hld.get_id(i), f[i]);\n  }\n\n  for(auto [type]\
    \ : hl::input_tuples<int>(Q)){\n    if(type == 0){\n      int64_t p, c, d; std::cin\
    \ >> p >> c >> d;\n\n      seg.set(hld.get_id(p), std::make_pair(c, d));\n   \
    \ }else{\n      int64_t u, v, x; std::cin >> u >> v >> x;\n\n      auto res =\
    \ M();\n      for(auto [l, r, d] : hld.path_query_vertex(u, v)){\n        if(d)\
    \ res = M(res, seg.fold_left(l, r));\n        else res = M(res, seg.fold_right(l,\
    \ r));\n      }\n\n      mint ans = res.first * x + res.second;\n      std::cout\
    \ << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree_both_foldable.cpp
  - Mylib/AlgebraicStructure/Monoid/affine.cpp
  - Mylib/AlgebraicStructure/Monoid/dual.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp
- /verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html
title: test/yosupo-judge/vertex_set_path_composite/main.test.cpp
---
