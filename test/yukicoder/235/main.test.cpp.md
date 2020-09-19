---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  - icon: ':x:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
    title: Heavy-light decomposition
  - icon: ':x:'
    path: Mylib/Utils/sort_simultaneously.cpp
    title: Mylib/Utils/sort_simultaneously.cpp
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp
    title: Lazy segment tree (Range sum, Range add, With coefficients)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/235
    links:
    - https://yukicoder.me/problems/no/235
  bundledCode: "#line 1 \"test/yukicoder/235/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/235\"\
    \n\n#include <iostream>\n#line 3 \"Mylib/IO/input_vector.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n#include\
    \ <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t ... I>\n  static void input_tuple_helper(std::istream\
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
    \ 4 \"Mylib/Number/Mint/mint.cpp\"\n\nnamespace haar_lib {\n  template <int32_t\
    \ M>\n  class modint {\n    uint32_t val;\n\n  public:\n    constexpr static auto\
    \ mod(){return M;}\n\n    constexpr modint(): val(0){}\n    constexpr modint(int64_t\
    \ n){\n      if(n >= M) val = n % M;\n      else if(n < 0) val = n % M + M;\n\
    \      else val = n;\n    }\n\n    constexpr auto& operator=(const modint &a){val\
    \ = a.val; return *this;}\n    constexpr auto& operator+=(const modint &a){\n\
    \      if(val + a.val >= M) val = (uint64_t)val + a.val - M;\n      else val +=\
    \ a.val;\n      return *this;\n    }\n    constexpr auto& operator-=(const modint\
    \ &a){\n      if(val < a.val) val += M;\n      val -= a.val;\n      return *this;\n\
    \    }\n    constexpr auto& operator*=(const modint &a){\n      val = (uint64_t)val\
    \ * a.val % M;\n      return *this;\n    }\n    constexpr auto& operator/=(const\
    \ modint &a){\n      val = (uint64_t)val * a.inv().val % M;\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const modint &a) const {return modint(*this)\
    \ += a;}\n    constexpr auto operator-(const modint &a) const {return modint(*this)\
    \ -= a;}\n    constexpr auto operator*(const modint &a) const {return modint(*this)\
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
    #line 5 \"Mylib/Utils/sort_simultaneously.cpp\"\n#include <numeric>\n#line 7 \"\
    Mylib/Utils/sort_simultaneously.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ Compare, typename ... Args>\n  void sort_simultaneously(const Compare &compare,\
    \ std::vector<Args> &... args){\n    const int N = std::max({args.size() ...});\n\
    \    std::vector<int> ord(N);\n    std::iota(ord.begin(), ord.end(), 0);\n   \
    \ std::sort(ord.begin(), ord.end(), compare);\n\n    (void)std::initializer_list<int>{\n\
    \      (void(\n        [&](){\n          auto temp = args;\n          for(int\
    \ i = 0; i < N; ++i) temp[i] = args[ord[i]];\n          std::swap(temp, args);\n\
    \        }()\n      ), 0) ...};\n  }\n}\n#line 3 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class lazy_segment_tree_with_coefficients\
    \ {\n    const int depth, size, hsize;\n    std::vector<T> data, lazy, coeff;\n\
    \n    void propagate(int i){\n      if(lazy[i] == 0) return;\n      if(i < hsize){\n\
    \        lazy[i << 1 | 0] = lazy[i] + lazy[i << 1 | 0];\n        lazy[i << 1 |\
    \ 1] = lazy[i] + lazy[i << 1 | 1];\n      }\n      data[i] = data[i] + lazy[i]\
    \ * coeff[i];\n      lazy[i] = 0;\n    }\n\n    T update(int i, int l, int r,\
    \ int s, int t, const T &x){\n      propagate(i);\n      if(r <= s || t <= l)\
    \ return data[i];\n      if(s <= l && r <= t){\n        lazy[i] += x;\n      \
    \  propagate(i);\n        return data[i];\n      }\n      return data[i] =\n \
    \       update(i << 1 | 0, l, (l + r) / 2, s, t, x) +\n        update(i << 1 |\
    \ 1, (l + r) / 2, r, s, t, x);\n    }\n\n    T get(int i, int l, int r, int x,\
    \ int y){\n      propagate(i);\n      if(r <= x || y <= l) return 0;\n      if(x\
    \ <= l && r <= y) return data[i];\n      return get(i << 1 | 0, l, (l + r) / 2,\
    \ x, y) + get(i << 1 | 1, (l + r) / 2, r, x, y);\n    }\n\n  public:\n    lazy_segment_tree_with_coefficients(){}\n\
    \    lazy_segment_tree_with_coefficients(int n, std::vector<T> coeff_):\n    \
    \  depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 << depth),\n\
    \      hsize(size / 2),\n      data(size, 0),\n      lazy(size, 0),\n      coeff(size,\
    \ 0)\n    {\n      for(int i = hsize; i < size; ++i) coeff[i] = coeff_[i - hsize];\n\
    \      for(int i = hsize; --i >= 1;) coeff[i] = coeff[i << 1 | 0] + coeff[i <<\
    \ 1 | 1];\n    }\n\n    void update(int l, int r, const T &x){update(1, 0, hsize,\
    \ l, r, x);}\n    void update_at(int i, const T &x){update(i, i + 1, x);}\n  \
    \  T get(int l, int r){return get(1, 0, hsize, l, r);}\n    T operator[](int i){return\
    \ get(i, i + 1);}\n\n    void init(const T &val){\n      init_with_vector(std::vector<T>(hsize,\
    \ val));\n    }\n\n    void init_with_vector(const std::vector<T> &val){\n   \
    \   data.assign(size, 0);\n      lazy.assign(size, 0);\n      for(int i = 0; i\
    \ < (int)val.size(); ++i) data[hsize + i] = val[i];\n      for(int i = hsize;\
    \ --i >= 0;) data[i] = data[i << 1 | 0] + data[i << 1 | 1];\n    }\n  };\n}\n\
    #line 11 \"test/yukicoder/235/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    using mint = hl::modint<1000000007>;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n  auto S = hl::input_vector<mint>(N);\n  auto C = hl::input_vector<mint>(N);\n\
    \n  hl::tree<int> tr(N);\n  tr.read<1, false, false>(N - 1);\n\n  auto hld = hl::hl_decomposition(tr,\
    \ 0);\n\n  hl::sort_simultaneously(\n    [&](int i, int j){return hld.get_id(i)\
    \ < hld.get_id(j);},\n    S, C\n  );\n\n  auto seg = hl::lazy_segment_tree_with_coefficients<mint>(N,\
    \ C);\n  seg.init_with_vector(S);\n\n  int Q; std::cin >> Q;\n\n  for(auto [type]\
    \ : hl::input_tuples<int>(Q)){\n    if(type == 0){\n      int X, Y, Z; std::cin\
    \ >> X >> Y >> Z;\n      --X, --Y;\n      for(auto [l, r, d] : hld.path_query_vertex(X,\
    \ Y)){\n        seg.update(l, r, Z);\n      }\n    }else{\n      int X, Y; std::cin\
    \ >> X >> Y;\n      --X, --Y;\n      mint ans = 0;\n      for(auto [l, r, d] :\
    \ hld.path_query_vertex(X, Y)){\n        ans += seg.get(l, r);\n      }\n    \
    \  std::cout << ans << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/235\"\n\n#include <iostream>\n\
    #include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n#include \"Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp\"\n#include \"\
    Mylib/Utils/sort_simultaneously.cpp\"\n#include \"Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N; std::cin\
    \ >> N;\n  auto S = hl::input_vector<mint>(N);\n  auto C = hl::input_vector<mint>(N);\n\
    \n  hl::tree<int> tr(N);\n  tr.read<1, false, false>(N - 1);\n\n  auto hld = hl::hl_decomposition(tr,\
    \ 0);\n\n  hl::sort_simultaneously(\n    [&](int i, int j){return hld.get_id(i)\
    \ < hld.get_id(j);},\n    S, C\n  );\n\n  auto seg = hl::lazy_segment_tree_with_coefficients<mint>(N,\
    \ C);\n  seg.init_with_vector(S);\n\n  int Q; std::cin >> Q;\n\n  for(auto [type]\
    \ : hl::input_tuples<int>(Q)){\n    if(type == 0){\n      int X, Y, Z; std::cin\
    \ >> X >> Y >> Z;\n      --X, --Y;\n      for(auto [l, r, d] : hld.path_query_vertex(X,\
    \ Y)){\n        seg.update(l, r, Z);\n      }\n    }else{\n      int X, Y; std::cin\
    \ >> X >> Y;\n      --X, --Y;\n      mint ans = 0;\n      for(auto [l, r, d] :\
    \ hld.path_query_vertex(X, Y)){\n        ans += seg.get(l, r);\n      }\n    \
    \  std::cout << ans << \"\\n\";\n    }\n  }\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/Number/Mint/mint.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/heavy_light_decomposition.cpp
  - Mylib/Utils/sort_simultaneously.cpp
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp
  isVerificationFile: true
  path: test/yukicoder/235/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/235/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/235/main.test.cpp
- /verify/test/yukicoder/235/main.test.cpp.html
title: test/yukicoder/235/main.test.cpp
---
