---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp
    title: Lazy segment tree (Range sum, Range add, With coefficients)
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
  - icon: ':x:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':question:'
    path: Mylib/Utils/sort_simultaneously.cpp
    title: Sort simultaneously
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
    \ M>\n  class modint {\n    uint32_t val_;\n\n  public:\n    constexpr static\
    \ auto mod(){return M;}\n\n    constexpr modint(): val_(0){}\n    constexpr modint(int64_t\
    \ n){\n      if(n >= M) val_ = n % M;\n      else if(n < 0) val_ = n % M + M;\n\
    \      else val_ = n;\n    }\n\n    constexpr auto& operator=(const modint &a){val_\
    \ = a.val_; return *this;}\n    constexpr auto& operator+=(const modint &a){\n\
    \      if(val_ + a.val_ >= M) val_ = (uint64_t)val_ + a.val_ - M;\n      else\
    \ val_ += a.val_;\n      return *this;\n    }\n    constexpr auto& operator-=(const\
    \ modint &a){\n      if(val_ < a.val_) val_ += M;\n      val_ -= a.val_;\n   \
    \   return *this;\n    }\n    constexpr auto& operator*=(const modint &a){\n \
    \     val_ = (uint64_t)val_ * a.val_ % M;\n      return *this;\n    }\n    constexpr\
    \ auto& operator/=(const modint &a){\n      val_ = (uint64_t)val_ * a.inv().val_\
    \ % M;\n      return *this;\n    }\n\n    constexpr auto operator+(const modint\
    \ &a) const {return modint(*this) += a;}\n    constexpr auto operator-(const modint\
    \ &a) const {return modint(*this) -= a;}\n    constexpr auto operator*(const modint\
    \ &a) const {return modint(*this) *= a;}\n    constexpr auto operator/(const modint\
    \ &a) const {return modint(*this) /= a;}\n\n    constexpr bool operator==(const\
    \ modint &a) const {return val_ == a.val_;}\n    constexpr bool operator!=(const\
    \ modint &a) const {return val_ != a.val_;}\n\n    constexpr auto& operator++(){*this\
    \ += 1; return *this;}\n    constexpr auto& operator--(){*this -= 1; return *this;}\n\
    \n    constexpr auto operator++(int){auto t = *this; *this += 1; return t;}\n\
    \    constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}\n\n\
    \    constexpr static modint pow(int64_t n, int64_t p){\n      if(p < 0) return\
    \ pow(n, -p).inv();\n\n      int64_t ret = 1, e = n % M;\n      for(; p; (e *=\
    \ e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;\n      return ret;\n    }\n\n \
    \   constexpr static modint inv(int64_t a){\n      int64_t b = M, u = 1, v = 0;\n\
    \n      while(b){\n        int64_t t = a / b;\n        a -= t * b; std::swap(a,\
    \ b);\n        u -= t * v; std::swap(u, v);\n      }\n\n      u %= M;\n      if(u\
    \ < 0) u += M;\n\n      return u;\n    }\n\n    constexpr static auto frac(int64_t\
    \ a, int64_t b){return modint(a) / modint(b);}\n\n    constexpr auto pow(int64_t\
    \ p) const {return pow(val_, p);}\n    constexpr auto inv() const {return inv(val_);}\n\
    \n    friend constexpr auto operator-(const modint &a){return modint(M - a.val_);}\n\
    \n    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a)\
    \ + b;}\n    friend constexpr auto operator-(int64_t a, const modint &b){return\
    \ modint(a) - b;}\n    friend constexpr auto operator*(int64_t a, const modint\
    \ &b){return modint(a) * b;}\n    friend constexpr auto operator/(int64_t a, const\
    \ modint &b){return modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream\
    \ &s, modint &a){s >> a.val_; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint &a){s << a.val_; return s;}\n\n    template <int N>\n    static\
    \ auto div(){\n      static auto value = inv(N);\n      return value;\n    }\n\
    \n    explicit operator int32_t() const noexcept {return val_;}\n    explicit\
    \ operator int64_t() const noexcept {return val_;}\n  };\n}\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ };\n}\n#line 5 \"Mylib/Utils/sort_simultaneously.cpp\"\n#include <numeric>\n\
    #line 7 \"Mylib/Utils/sort_simultaneously.cpp\"\n\nnamespace haar_lib {\n  namespace\
    \ sort_simultaneously_impl {\n    template <typename T>\n    void sub(int N, const\
    \ std::vector<int> &ord, std::vector<T> &a){\n      std::vector<T> temp(N);\n\
    \      for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];\n      std::swap(temp,\
    \ a);\n    }\n  }\n\n  template <typename Compare, typename ... Args>\n  void\
    \ sort_simultaneously(const Compare &compare, std::vector<Args> &... args){\n\
    \    const int N = std::max({args.size() ...});\n    std::vector<int> ord(N);\n\
    \    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(), ord.end(),\
    \ compare);\n\n    (void)std::initializer_list<int>{\n      (void(sort_simultaneously_impl::sub(N,\
    \ ord, args)), 0) ...};\n  }\n}\n#line 3 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree_with_coefficients.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class lazy_segment_tree_with_coefficients\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    int depth_, size_,\
    \ hsize_;\n    std::vector<T> data_, lazy_, coeff_;\n\n    void propagate(int\
    \ i){\n      if(lazy_[i] == 0) return;\n      if(i < hsize_){\n        lazy_[i\
    \ << 1 | 0] = lazy_[i] + lazy_[i << 1 | 0];\n        lazy_[i << 1 | 1] = lazy_[i]\
    \ + lazy_[i << 1 | 1];\n      }\n      data_[i] = data_[i] + lazy_[i] * coeff_[i];\n\
    \      lazy_[i] = 0;\n    }\n\n    T update(int i, int l, int r, int s, int t,\
    \ const T &x){\n      propagate(i);\n      if(r <= s or t <= l) return data_[i];\n\
    \      if(s <= l and r <= t){\n        lazy_[i] += x;\n        propagate(i);\n\
    \        return data_[i];\n      }\n      return data_[i] =\n        update(i\
    \ << 1 | 0, l, (l + r) / 2, s, t, x) +\n        update(i << 1 | 1, (l + r) / 2,\
    \ r, s, t, x);\n    }\n\n    T get(int i, int l, int r, int x, int y){\n     \
    \ propagate(i);\n      if(r <= x or y <= l) return 0;\n      if(x <= l and r <=\
    \ y) return data_[i];\n      return get(i << 1 | 0, l, (l + r) / 2, x, y) + get(i\
    \ << 1 | 1, (l + r) / 2, r, x, y);\n    }\n\n  public:\n    lazy_segment_tree_with_coefficients(){}\n\
    \    lazy_segment_tree_with_coefficients(int n, std::vector<T> coeff):\n     \
    \ depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_),\n\
    \      hsize_(size_ / 2),\n      data_(size_, 0),\n      lazy_(size_, 0),\n  \
    \    coeff_(size_, 0)\n    {\n      for(int i = hsize_; i < size_; ++i) coeff_[i]\
    \ = coeff[i - hsize_];\n      for(int i = hsize_; --i >= 1;) coeff_[i] = coeff_[i\
    \ << 1 | 0] + coeff_[i << 1 | 1];\n    }\n\n    void update(int l, int r, const\
    \ T &x){update(1, 0, hsize_, l, r, x);}\n    void update(int i, const T &x){update(i,\
    \ i + 1, x);}\n    T fold(int l, int r){return get(1, 0, hsize_, l, r);}\n   \
    \ T operator[](int i){return fold(i, i + 1);}\n\n    void init(const T &val){\n\
    \      init_with_vector(std::vector<T>(hsize_, val));\n    }\n\n    void init_with_vector(const\
    \ std::vector<T> &val){\n      data_.assign(size_, 0);\n      lazy_.assign(size_,\
    \ 0);\n      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n\
    \      for(int i = hsize_; --i >= 0;) data_[i] = data_[i << 1 | 0] + data_[i <<\
    \ 1 | 1];\n    }\n  };\n}\n#line 11 \"test/yukicoder/235/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\n\nint main(){\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int N; std::cin >> N;\n  auto S = hl::input_vector<mint>(N);\n\
    \  auto C = hl::input_vector<mint>(N);\n\n  hl::tree<int> tr(N);\n  tr.read<1,\
    \ false, false>(N - 1);\n\n  auto hld = hl::hl_decomposition(tr, 0);\n\n  hl::sort_simultaneously(\n\
    \    [&](int i, int j){return hld.get_id(i) < hld.get_id(j);},\n    S, C\n  );\n\
    \n  auto seg = hl::lazy_segment_tree_with_coefficients<mint>(N, C);\n  seg.init_with_vector(S);\n\
    \n  int Q; std::cin >> Q;\n\n  for(auto [type] : hl::input_tuples<int>(Q)){\n\
    \    if(type == 0){\n      int X, Y, Z; std::cin >> X >> Y >> Z;\n      --X, --Y;\n\
    \      for(auto [l, r, d] : hld.path_query_vertex(X, Y)){\n        seg.update(l,\
    \ r, Z);\n      }\n    }else{\n      int X, Y; std::cin >> X >> Y;\n      --X,\
    \ --Y;\n      mint ans = 0;\n      for(auto [l, r, d] : hld.path_query_vertex(X,\
    \ Y)){\n        ans += seg.fold(l, r);\n      }\n      std::cout << ans << \"\\\
    n\";\n    }\n  }\n}\n"
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
    \ hld.path_query_vertex(X, Y)){\n        ans += seg.fold(l, r);\n      }\n   \
    \   std::cout << ans << \"\\n\";\n    }\n  }\n}\n"
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
  timestamp: '2020-09-30 07:57:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/235/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/235/main.test.cpp
- /verify/test/yukicoder/235/main.test.cpp.html
title: test/yukicoder/235/main.test.cpp
---
