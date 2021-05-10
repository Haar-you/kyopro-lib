---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp
    title: Check bipartite graph
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/Typical/subset_sum_limited.cpp
    title: Subset sum problem (With quantity limitations)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370
  bundledCode: "#line 1 \"test/aoj/2370/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <vector>\n\
    #line 2 \"Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp\"\n#include <optional>\n\
    #include <stack>\n#include <utility>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge() {}\n    edge(int from, int\
    \ to, T cost) : from(from), to(to), cost(cost) {}\n    edge(int from, int to,\
    \ T cost, int index) : from(from), to(to), cost(cost), index(index) {}\n  };\n\
    \n  template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n  \
    \  auto& operator[](size_t i) { return data[i]; }\n    const auto& operator[](size_t\
    \ i) const { return data[i]; }\n\n    auto begin() const { return data.begin();\
    \ }\n    auto end() const { return data.end(); }\n\n    graph() {}\n    graph(int\
    \ N) : data(N) {}\n\n    bool empty() const { return data.empty(); }\n    int\
    \ size() const { return data.size(); }\n\n    void add_edge(int i, int j, T w,\
    \ int index = -1) {\n      data[i].emplace_back(i, j, w, index);\n    }\n\n  \
    \  void add_undirected(int i, int j, T w, int index = -1) {\n      add_edge(i,\
    \ j, w, index);\n      add_edge(j, i, w, index);\n    }\n\n    template <size_t\
    \ I, bool DIRECTED = true, bool WEIGHTED = true>\n    void read(int M) {\n   \
    \   for (int i = 0; i < M; ++i) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n        u -= I;\n        v -= I;\n        T w = 1;\n        if (WEIGHTED)\
    \ std::cin >> w;\n        if (DIRECTED)\n          add_edge(u, v, w, i);\n   \
    \     else\n          add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 7 \"\
    Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  auto check_bipartite_graph(const graph<T> &g) {\n\
    \    std::vector<std::optional<std::pair<std::vector<int>, std::vector<int>>>>\
    \ ret;\n\n    const int N = g.size();\n\n    std::vector<int> check(N, -1);\n\
    \    std::vector<bool> visit(N);\n\n    for (int i = 0; i < N; ++i) {\n      if\
    \ (visit[i]) continue;\n\n      std::vector<int> a, b;\n\n      bool res =\n \
    \         [&]() {\n            std::stack<int> st;\n\n            st.push(i);\n\
    \            check[i] = 0;\n            a.push_back(i);\n\n            while (not\
    \ st.empty()) {\n              auto cur = st.top();\n              st.pop();\n\
    \              if (visit[cur]) continue;\n              visit[cur] = true;\n\n\
    \              for (auto &e : g[cur]) {\n                if (check[e.to] == check[cur])\
    \ return false;\n\n                if (check[e.to] == -1) {\n                \
    \  if (check[cur] == 0) {\n                    check[e.to] = 1;\n            \
    \        b.push_back(e.to);\n                  } else {\n                    check[e.to]\
    \ = 0;\n                    a.push_back(e.to);\n                  }\n\n      \
    \            st.push(e.to);\n                }\n              }\n            }\n\
    \n            return true;\n          }();\n\n      if (res) {\n        ret.emplace_back(std::make_pair(a,\
    \ b));\n      } else {\n        ret.emplace_back();\n      }\n    }\n\n    return\
    \ ret;\n  }\n}  // namespace haar_lib\n#line 2 \"Mylib/Typical/subset_sum_limited.cpp\"\
    \n#include <cassert>\n#line 4 \"Mylib/Typical/subset_sum_limited.cpp\"\n\nnamespace\
    \ haar_lib {\n  auto subset_sum_limited(int N, int K, const std::vector<int> &a,\
    \ const std::vector<int> &m) {\n    assert((int) a.size() == N and (int) m.size()\
    \ == N);\n    std::vector<int> dp(K + 1, -1);\n\n    dp[0] = 0;\n    for (int\
    \ i = 0; i < N; ++i) {\n      for (int j = 0; j <= K; ++j) {\n        if (dp[j]\
    \ >= 0) {\n          dp[j] = m[i];\n        } else if (j < a[i] or dp[j - a[i]]\
    \ <= 0) {\n          dp[j] = -1;\n        } else {\n          dp[j] = dp[j - a[i]]\
    \ - 1;\n        }\n      }\n    }\n\n    for (int i = 0; i <= K; ++i) dp[i] =\
    \ dp[i] >= 0;\n\n    return dp;\n  }\n}  // namespace haar_lib\n#line 10 \"test/aoj/2370/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int V, E;\n  std::cin >> V >>\
    \ E;\n\n  hl::graph<int> g(V);\n  g.read<1, false, false>(E);\n\n  auto res =\
    \ hl::check_bipartite_graph(g);\n\n  if (std::all_of(res.begin(), res.end(), [](const\
    \ auto &a) { return (bool) a; })) {\n    int k = 0;\n\n    std::map<int, int>\
    \ c;\n\n    for (auto &x : res) {\n      int a = (*x).first.size();\n      int\
    \ b = (*x).second.size();\n\n      k += std::min(a, b);\n\n      c[std::abs(a\
    \ - b)] += 1;\n    }\n\n    std::vector<int> a, m;\n    for (auto &p : c) {\n\
    \      a.push_back(p.first);\n      m.push_back(p.second);\n    }\n\n    auto\
    \ r = hl::subset_sum_limited(c.size(), V, a, m);\n\n    int64_t ans = 0;\n\n \
    \   for (int i = 0; i <= V; ++i) {\n      if (r[i]) {\n        int64_t a = k +\
    \ i;\n        ans       = std::max(ans, a * (V - a));\n      }\n    }\n\n    ans\
    \ -= E;\n    std::cout << ans << \"\\n\";\n  } else {\n    std::cout << -1 <<\
    \ \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2370\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <vector>\n\
    #include \"Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp\"\n#include \"\
    Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Typical/subset_sum_limited.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int V, E;\n  std::cin >> V >>\
    \ E;\n\n  hl::graph<int> g(V);\n  g.read<1, false, false>(E);\n\n  auto res =\
    \ hl::check_bipartite_graph(g);\n\n  if (std::all_of(res.begin(), res.end(), [](const\
    \ auto &a) { return (bool) a; })) {\n    int k = 0;\n\n    std::map<int, int>\
    \ c;\n\n    for (auto &x : res) {\n      int a = (*x).first.size();\n      int\
    \ b = (*x).second.size();\n\n      k += std::min(a, b);\n\n      c[std::abs(a\
    \ - b)] += 1;\n    }\n\n    std::vector<int> a, m;\n    for (auto &p : c) {\n\
    \      a.push_back(p.first);\n      m.push_back(p.second);\n    }\n\n    auto\
    \ r = hl::subset_sum_limited(c.size(), V, a, m);\n\n    int64_t ans = 0;\n\n \
    \   for (int i = 0; i <= V; ++i) {\n      if (r[i]) {\n        int64_t a = k +\
    \ i;\n        ans       = std::max(ans, a * (V - a));\n      }\n    }\n\n    ans\
    \ -= E;\n    std::cout << ans << \"\\n\";\n  } else {\n    std::cout << -1 <<\
    \ \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Typical/subset_sum_limited.cpp
  isVerificationFile: true
  path: test/aoj/2370/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2370/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2370/main.test.cpp
- /verify/test/aoj/2370/main.test.cpp.html
title: test/aoj/2370/main.test.cpp
---
