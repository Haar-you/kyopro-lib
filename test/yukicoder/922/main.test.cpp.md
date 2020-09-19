---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/TreeUtils/lca_doubling.cpp
    title: Lowest common ancestor (Doubling)
  - icon: ':x:'
    path: Mylib/Graph/TreeUtils/forest.cpp
    title: Decompose forest
  - icon: ':question:'
    path: Mylib/Graph/TreeUtils/rerooting.cpp
    title: Rerooting DP
  - icon: ':x:'
    path: Mylib/Graph/TreeUtils/tree_distance.cpp
    title: Tree distance
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
    PROBLEM: https://yukicoder.me/problems/no/922
    links:
    - https://yukicoder.me/problems/no/922
  bundledCode: "#line 1 \"test/yukicoder/922/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/922\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/TreeUtils/lca_doubling.cpp\"\
    \n#include <cmath>\n#line 5 \"Mylib/Graph/TreeUtils/lca_doubling.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class lowest_common_ancestor_doubling\
    \ {\n  private:\n    std::vector<std::vector<int>> parent;\n    int n, log2n;\n\
    \n    void dfs(const tree<T> &tr, int cur, int par, int d){\n      parent[cur][0]\
    \ = par;\n      depth[cur] = d;\n\n      for(auto &e : tr[cur]){\n        if(e.to\
    \ != par){\n          dfs(tr, e.to, cur, d + 1);\n        }\n      }\n    }\n\n\
    \  public:\n    std::vector<int> depth;\n\n    lowest_common_ancestor_doubling(){}\n\
    \    lowest_common_ancestor_doubling(const tree<T> &tr, int root):\n      n(tr.size()),\
    \ depth(n)\n    {\n      log2n = (int)ceil(log2(n)) + 1;\n      parent = std::vector(n,\
    \ std::vector<int>(log2n, 0));\n\n      dfs(tr, root, -1, 0);\n      for(int k\
    \ = 0; k < log2n - 1; ++k){\n        for(int v = 0; v < n; ++v){\n          if(parent[v][k]\
    \ == -1) parent[v][k + 1] = -1;\n          else parent[v][k + 1] = parent[parent[v][k]][k];\n\
    \        }\n      }\n    }\n\n    int lca(int a, int b) const {\n      if(depth[a]\
    \ >= depth[b]) std::swap(a, b);\n      for(int k = 0; k < log2n; ++k){\n     \
    \   if((depth[b] - depth[a]) >> k & 1) b = parent[b][k];\n      }\n      if(a\
    \ == b) return a;\n      for(int k = log2n; --k >= 0;){\n        if(parent[a][k]\
    \ != parent[b][k]){a = parent[a][k]; b = parent[b][k];}\n      }\n      return\
    \ parent[a][0];\n    }\n\n    int operator()(int a, int b) const {return lca(a,\
    \ b);}\n\n    T distance(int u, int v, const std::vector<T> &dist) const {\n \
    \     return dist[u] + dist[v] - 2 * dist[lca(u, v)];\n    }\n  };\n}\n#line 3\
    \ \"Mylib/Graph/TreeUtils/forest.cpp\"\n#include <algorithm>\n#line 6 \"Mylib/Graph/TreeUtils/forest.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct forest {\n    std::vector<tree<T>>\
    \ trees;\n    std::vector<int> tree_id;\n    std::vector<int> vertex_id;\n   \
    \ std::vector<std::vector<int>> rid;\n\n    forest(const graph<T> &g){\n     \
    \ const int N = g.size();\n\n      tree_id.resize(N);\n      vertex_id.resize(N);\n\
    \n      std::vector<bool> check(N);\n\n      auto dfs =\n        [&](auto &dfs,\
    \ int cur, std::vector<int> &vertices, std::vector<edge<T>> &edges) -> void {\n\
    \          check[cur] = true;\n          vertices.push_back(cur);\n\n        \
    \  for(auto &e : g[cur]){\n            edges.push_back(e);\n\n            if(not\
    \ check[e.to]){\n              dfs(dfs, e.to, vertices, edges);\n            }\n\
    \          }\n        };\n\n      for(int i = 0; i < N; ++i){\n        if(not\
    \ check[i]){\n          std::vector<int> vertices;\n          std::vector<edge<T>>\
    \ edges;\n          dfs(dfs, i, vertices, edges);\n\n          const int m = vertices.size();\n\
    \          const int k = trees.size();\n\n          rid.emplace_back(m);\n\n \
    \         for(int i = 0; i < (int)vertices.size(); ++i){\n            tree_id[vertices[i]]\
    \ = k;\n            vertex_id[vertices[i]] = i;\n            rid[k][i] = vertices[i];\n\
    \          }\n\n          trees.push_back(m);\n\n          for(auto &e : edges){\n\
    \            trees[k].add_edge(vertex_id[e.from], vertex_id[e.to], e.cost);\n\
    \          }\n        }\n      }\n    }\n\n    bool in_same_tree(int i, int j)\
    \ const {\n      return tree_id[i] == tree_id[j];\n    }\n  };\n}\n#line 4 \"\
    Mylib/Graph/TreeUtils/rerooting.cpp\"\n\nnamespace haar_lib {\n  namespace rerooting_impl\
    \ {\n    template <typename T, typename U, typename Merge, typename EdgeF, typename\
    \ VertexF>\n    T rec1(\n      tree<U> &tr,\n      T id,\n      const Merge &merge,\n\
    \      const EdgeF &f,\n      const VertexF &g,\n      std::vector<std::vector<T>>\
    \ &dp,\n      int cur,\n      int par = -1\n    ){\n      T acc = id;\n\n    \
    \  for(int i = 0; i < (int)tr[cur].size(); ++i){\n        auto &e = tr[cur][i];\n\
    \        if(e.to == par) continue;\n        dp[cur][i] = rec1(tr, id, merge, f,\
    \ g, dp, e.to, cur);\n        acc = merge(acc, f(dp[cur][i], e));\n      }\n\n\
    \      return g(acc, cur);\n    }\n\n    template <typename T, typename U, typename\
    \ Merge, typename EdgeF, typename VertexF>\n    void rec2(\n      const tree<U>\
    \ &tr,\n      T id,\n      const Merge &merge,\n      const EdgeF &f,\n      const\
    \ VertexF &g,\n      std::vector<std::vector<T>> &dp,\n      int cur,\n      int\
    \ par,\n      T value\n    ){\n      const int l = tr[cur].size();\n\n      for(int\
    \ i = 0; i < l; ++i){\n        if(tr[cur][i].to == par){\n          dp[cur][i]\
    \ = value;\n        }\n      }\n\n      std::vector<T> left(l + 1, id), right(l\
    \ + 1, id);\n\n      for(int i = 0; i < l - 1; ++i){\n        const auto &e =\
    \ tr[cur][i];\n        left[i + 1] = merge(left[i], f(dp[cur][i], e));\n     \
    \ }\n\n      for(int i = l - 1; i >= 1; --i){\n        const auto &e = tr[cur][i];\n\
    \        right[i - 1] = merge(right[i], f(dp[cur][i], e));\n      }\n\n      for(int\
    \ i = 0; i < l; ++i){\n        const auto &e = tr[cur][i];\n        if(e.to ==\
    \ par) continue;\n\n        rec2(tr, id, merge, f, g, dp, e.to, cur, g(merge(left[i],\
    \ right[i]), cur));\n      }\n    }\n  }\n\n  template <typename T, typename U,\
    \ typename Merge, typename EdgeF, typename VertexF>\n  auto rerooting(tree<U>\
    \ tr, T id, Merge merge, EdgeF f, VertexF g){\n    const int N = tr.size();\n\
    \    std::vector<std::vector<T>> dp(N);\n    std::vector<T> ret(N, id);\n\n  \
    \  for(int i = 0; i < N; ++i) dp[i].assign(tr[i].size(), id);\n    rerooting_impl::rec1(tr,\
    \ id, merge, f, g, dp, 0);\n    rerooting_impl::rec2(tr, id, merge, f, g, dp,\
    \ 0, -1, id);\n    for(int i = 0; i < N; ++i){\n      for(int j = 0; j < (int)tr[i].size();\
    \ ++j){\n        ret[i] = merge(ret[i], f(dp[i][j], tr[i][j]));\n      }\n\n \
    \     ret[i] = g(ret[i], i);\n    }\n\n    return ret;\n  }\n}\n#line 3 \"Mylib/Graph/TreeUtils/tree_distance.cpp\"\
    \n#include <stack>\n#line 5 \"Mylib/Graph/TreeUtils/tree_distance.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> tree_distance(const tree<T>\
    \ &tr, int root){\n    const int n = tr.size();\n    std::vector<T> ret(n);\n\
    \    std::vector<bool> visited(n);\n\n    std::stack<int> st;\n    st.push(root);\n\
    \    ret[root] = 0;\n\n    while(not st.empty()){\n      int cur = st.top(); st.pop();\n\
    \      visited[cur] = true;\n\n      for(auto &e : tr[cur]){\n        if(not visited[e.to]){\n\
    \          ret[e.to] = ret[cur] + e.cost;\n          st.push(e.to);\n        }\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 12 \"test/yukicoder/922/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N, M, Q; std::cin >> N >> M\
    \ >> Q;\n\n  hl::graph<int64_t> g(N);\n  g.read<1, false, false>(M);\n\n  int64_t\
    \ ans = 0;\n\n  hl::forest<int64_t> forest(g);\n\n  const int tree_num = forest.trees.size();\n\
    \  std::vector<hl::lowest_common_ancestor_doubling<int64_t>> lcas(tree_num);\n\
    \  std::vector<std::vector<int64_t>> dists(tree_num);\n\n  for(int i = 0; i <\
    \ tree_num; ++i){\n    lcas[i] = hl::lowest_common_ancestor_doubling(forest.trees[i],\
    \ 0);\n    dists[i] = hl::tree_distance(forest.trees[i], 0);\n  }\n\n  std::vector<std::vector<int>>\
    \ plans(tree_num);\n  for(int i = 0; i < tree_num; ++i){\n    plans[i] = std::vector<int>(forest.trees[i].size());\n\
    \  }\n\n  for(auto [a, b] : hl::input_tuples<int, int>(Q)){\n    --a, --b;\n\n\
    \    if(forest.in_same_tree(a, b)){\n      ans += lcas[forest.tree_id[a]].distance(forest.vertex_id[a],\
    \ forest.vertex_id[b], dists[forest.tree_id[a]]);\n    }else{\n      plans[forest.tree_id[a]][forest.vertex_id[a]]\
    \ += 1;\n      plans[forest.tree_id[b]][forest.vertex_id[b]] += 1;\n    }\n  }\n\
    \n  for(int i = 0; i < tree_num; ++i){\n    const auto &tree = forest.trees[i];\n\
    \    const auto &plan = plans[i];\n\n    auto res =\n      hl::rerooting<std::pair<int,\
    \ int>>(\n        tree,\n        std::make_pair(0, 0),\n        [](const auto\
    \ &a, const auto &b){\n          return std::make_pair(a.first + b.first, a.second\
    \ + b.second);\n        },\n        [](const auto &x, const auto &e){\n      \
    \    return std::make_pair(x.first, x.second + x.first);\n        },\n       \
    \ [&](const auto &x, int v){\n          return std::make_pair(x.first + plan[v],\
    \ x.second);\n        }\n      );\n\n    ans +=\n      std::min_element(\n   \
    \     res.begin(),\n        res.end(),\n        [](const auto &a, const auto &b){\n\
    \          return a.second < b.second;\n        }\n      )->second;\n  }\n\n \
    \ std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/922\"\n\n#include <iostream>\n\
    #include <vector>\n#include <utility>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n#include \"Mylib/Graph/TreeUtils/lca_doubling.cpp\"\n#include \"Mylib/Graph/TreeUtils/forest.cpp\"\
    \n#include \"Mylib/Graph/TreeUtils/rerooting.cpp\"\n#include \"Mylib/Graph/TreeUtils/tree_distance.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N, M, Q; std::cin >> N >> M >> Q;\n\n  hl::graph<int64_t> g(N);\n  g.read<1,\
    \ false, false>(M);\n\n  int64_t ans = 0;\n\n  hl::forest<int64_t> forest(g);\n\
    \n  const int tree_num = forest.trees.size();\n  std::vector<hl::lowest_common_ancestor_doubling<int64_t>>\
    \ lcas(tree_num);\n  std::vector<std::vector<int64_t>> dists(tree_num);\n\n  for(int\
    \ i = 0; i < tree_num; ++i){\n    lcas[i] = hl::lowest_common_ancestor_doubling(forest.trees[i],\
    \ 0);\n    dists[i] = hl::tree_distance(forest.trees[i], 0);\n  }\n\n  std::vector<std::vector<int>>\
    \ plans(tree_num);\n  for(int i = 0; i < tree_num; ++i){\n    plans[i] = std::vector<int>(forest.trees[i].size());\n\
    \  }\n\n  for(auto [a, b] : hl::input_tuples<int, int>(Q)){\n    --a, --b;\n\n\
    \    if(forest.in_same_tree(a, b)){\n      ans += lcas[forest.tree_id[a]].distance(forest.vertex_id[a],\
    \ forest.vertex_id[b], dists[forest.tree_id[a]]);\n    }else{\n      plans[forest.tree_id[a]][forest.vertex_id[a]]\
    \ += 1;\n      plans[forest.tree_id[b]][forest.vertex_id[b]] += 1;\n    }\n  }\n\
    \n  for(int i = 0; i < tree_num; ++i){\n    const auto &tree = forest.trees[i];\n\
    \    const auto &plan = plans[i];\n\n    auto res =\n      hl::rerooting<std::pair<int,\
    \ int>>(\n        tree,\n        std::make_pair(0, 0),\n        [](const auto\
    \ &a, const auto &b){\n          return std::make_pair(a.first + b.first, a.second\
    \ + b.second);\n        },\n        [](const auto &x, const auto &e){\n      \
    \    return std::make_pair(x.first, x.second + x.first);\n        },\n       \
    \ [&](const auto &x, int v){\n          return std::make_pair(x.first + plan[v],\
    \ x.second);\n        }\n      );\n\n    ans +=\n      std::min_element(\n   \
    \     res.begin(),\n        res.end(),\n        [](const auto &a, const auto &b){\n\
    \          return a.second < b.second;\n        }\n      )->second;\n  }\n\n \
    \ std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/TreeUtils/lca_doubling.cpp
  - Mylib/Graph/TreeUtils/forest.cpp
  - Mylib/Graph/TreeUtils/rerooting.cpp
  - Mylib/Graph/TreeUtils/tree_distance.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/922/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/922/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/922/main.test.cpp
- /verify/test/yukicoder/922/main.test.cpp.html
title: test/yukicoder/922/main.test.cpp
---
