---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/Heap/pairing_heap.cpp
    title: Pairing heap
  - icon: ':question:'
    path: Mylib/Graph/MinimumSpanningTree/prim.cpp
    title: Prim algorithm
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/Misc/merge_technique.cpp
    title: Merge technique
  - icon: ':question:'
    path: Mylib/Utils/fix_point.cpp
    title: Fixed point combinator
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559
  bundledCode: "#line 1 \"test/aoj/2559/main.pairing_heap.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559\"\n\n#include\
    \ <iostream>\n#include <map>\n#include <set>\n#include <tuple>\n#include <vector>\n\
    #line 2 \"Mylib/DataStructure/Heap/pairing_heap.cpp\"\n#include <functional>\n\
    #line 4 \"Mylib/DataStructure/Heap/pairing_heap.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T, typename Compare = std::less<T>>\n  class pairing_heap\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    struct node_ {\n\
    \      T value;\n      std::vector<node_ *> ch;\n      node_(const T &value) :\
    \ value(value) {}\n    };\n\n    Compare compare_;\n    node_ *root_ = nullptr;\n\
    \    size_t size_ = 0;\n\n    node_ *merge_(node_ *a, node_ *b) {\n      if (not\
    \ a) return b;\n      if (not b) return a;\n      if (compare_(b->value, a->value))\
    \ {\n        a->ch.push_back(b);\n        return a;\n      } else {\n        b->ch.push_back(a);\n\
    \        return b;\n      }\n    }\n\n    node_ *merge_list_(node_ *a) {\n   \
    \   if ((a->ch.size() & 1) == 1) a->ch.push_back(nullptr);\n\n      for (size_t\
    \ i = 0; i < a->ch.size(); i += 2) {\n        a->ch[i >> 1] = merge_(a->ch[i],\
    \ a->ch[i + 1]);\n      }\n\n      a->ch.resize(a->ch.size() / 2);\n\n      node_\
    \ *ret = nullptr;\n      for (int i = a->ch.size(); --i >= 0;) {\n        ret\
    \ = merge_(ret, a->ch[i]);\n      }\n\n      return ret;\n    }\n\n  public:\n\
    \    pairing_heap() : compare_(Compare()) {}\n    pairing_heap(const Compare &compare_)\
    \ : compare_(compare_) {}\n\n    void meld(pairing_heap &that) {\n      root_\
    \      = merge_(root_, that.root_);\n      that.root_ = nullptr;\n      size_\
    \ += that.size_;\n      that.size_ = 0;\n    }\n    void push(const T &val) {\n\
    \      root_ = merge_(root_, new node_(val));\n      ++size_;\n    }\n    void\
    \ pop() {\n      root_ = merge_list_(root_);\n      --size_;\n    }\n    const\
    \ T &top() const { return root_->value; }\n    bool empty() const { return root_\
    \ == nullptr; }\n    size_t size() const { return size_; }\n  };\n}  // namespace\
    \ haar_lib\n#line 2 \"Mylib/Graph/MinimumSpanningTree/prim.cpp\"\n#include <queue>\n\
    #line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n    int index\
    \ = -1;\n    edge() {}\n    edge(int from, int to, T cost) : from(from), to(to),\
    \ cost(cost) {}\n    edge(int from, int to, T cost, int index) : from(from), to(to),\
    \ cost(cost), index(index) {}\n  };\n\n  template <typename T>\n  struct graph\
    \ {\n    using weight_type = T;\n    using edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
    \ data;\n\n    auto& operator[](size_t i) { return data[i]; }\n    const auto&\
    \ operator[](size_t i) const { return data[i]; }\n\n    auto begin() const { return\
    \ data.begin(); }\n    auto end() const { return data.end(); }\n\n    graph()\
    \ {}\n    graph(int N) : data(N) {}\n\n    bool empty() const { return data.empty();\
    \ }\n    int size() const { return data.size(); }\n\n    void add_edge(int i,\
    \ int j, T w, int index = -1) {\n      data[i].emplace_back(i, j, w, index);\n\
    \    }\n\n    void add_undirected(int i, int j, T w, int index = -1) {\n     \
    \ add_edge(i, j, w, index);\n      add_edge(j, i, w, index);\n    }\n\n    template\
    \ <size_t I, bool DIRECTED = true, bool WEIGHTED = true>\n    void read(int M)\
    \ {\n      for (int i = 0; i < M; ++i) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n        if (WEIGHTED)\
    \ std::cin >> w;\n        if (DIRECTED)\n          add_edge(u, v, w, i);\n   \
    \     else\n          add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 5 \"\
    Mylib/Graph/MinimumSpanningTree/prim.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<edge<T>> prim(const graph<T> &graph) {\n    const\
    \ int n = graph.size();\n    std::vector<bool> visit(n, false);\n    std::vector<edge<T>>\
    \ ret;\n\n    auto cmp = [](const auto &a, const auto &b) { return a.cost > b.cost;\
    \ };\n    std::priority_queue<edge<T>, std::vector<edge<T>>, decltype(cmp)> pq(cmp);\n\
    \n    visit[0] = true;\n    for (auto &e : graph[0]) pq.push(e);\n\n    while\
    \ (not pq.empty()) {\n      auto t = pq.top();\n      pq.pop();\n\n      if (visit[t.from]\
    \ == visit[t.to]) continue;\n\n      int i = visit[t.from] ? t.to : t.from;\n\
    \      for (auto &e : graph[i]) {\n        pq.push(e);\n      }\n\n      visit[i]\
    \ = true;\n      ret.push_back(t);\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n#line 3 \"Mylib/Misc/merge_technique.cpp\"\n#include <utility>\n\n\
    namespace haar_lib {\n  template <typename T>\n  void merge_technique(std::set<T>\
    \ &res, std::set<T> &a, std::set<T> &b) {\n    if (a.size() > b.size()) {\n  \
    \    a.insert(b.begin(), b.end());\n      std::swap(res, a);\n    } else {\n \
    \     b.insert(a.begin(), a.end());\n      std::swap(res, b);\n    }\n  }\n} \
    \ // namespace haar_lib\n#line 3 \"Mylib/Utils/fix_point.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename F>\n  struct fix_point : F {\n    explicit constexpr\
    \ fix_point(F &&f) noexcept : F(std::forward<F>(f)) {}\n\n    template <typename...\
    \ Args>\n    constexpr auto operator()(Args &&... args) const {\n      return\
    \ F::operator()(*this, std::forward<Args>(args)...);\n    }\n  };\n\n  template\
    \ <typename F>\n  inline constexpr auto make_fix_point(F &&f) {\n    return fix_point<F>(std::forward<F>(f));\n\
    \  }\n\n  template <typename F>\n  inline constexpr auto make_fix_point(F &f)\
    \ {\n    return fix_point<F>(std::forward<F>(f));\n  }\n}  // namespace haar_lib\n\
    #line 13 \"test/aoj/2559/main.pairing_heap.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main() {\n  int n, m;\n  std::cin >> n >> m;\n\n  hl::graph<int64_t> g(n);\n\
    \  g.read<1, false>(m);\n\n  std::map<std::pair<int, int>, int> index;\n  for\
    \ (auto &a : g) {\n    for (auto &e : a) index[{e.from, e.to}] = e.index;\n  }\n\
    \n  auto res = hl::prim(g);\n\n  std::vector<int64_t> ans(m, -1);\n\n  if ((int)\
    \ res.size() == n - 1) {\n    int64_t s = 0;\n    hl::tree<int64_t> tree(n);\n\
    \n    for (auto &e : res) {\n      s += e.cost;\n      tree[e.from].push_back(e);\n\
    \    }\n\n    ans.assign(m, s);\n\n    std::vector<hl::pairing_heap<std::tuple<int64_t,\
    \ int, int>, std::greater<>>> heaps(n);\n\n    std::vector<std::set<int>> sub(n);\n\
    \n    hl::make_fix_point(\n        [&](auto &&f, int cur, int par, int64_t cost)\
    \ -> void {\n          for (auto &e : g[cur]) {\n            heaps[cur].push({e.cost,\
    \ e.from, e.to});\n          }\n\n          sub[cur].insert(cur);\n\n        \
    \  for (auto &e : tree[cur]) {\n            if (e.to == par) continue;\n     \
    \       f(e.to, cur, e.cost);\n\n            heaps[cur].meld(heaps[e.to]);\n \
    \           hl::merge_technique(sub[cur], sub[cur], sub[e.to]);\n          }\n\
    \n          if (par != -1) {\n            while (not heaps[cur].empty()) {\n \
    \             auto [c, i, j] = heaps[cur].top();\n              if ((sub[cur].find(i)\
    \ != sub[cur].end() and sub[cur].find(j) != sub[cur].end()) or\n             \
    \     (i == cur and j == par) or (i == par and j == cur)) {\n                heaps[cur].pop();\n\
    \              } else {\n                break;\n              }\n           \
    \ }\n\n            if (not heaps[cur].empty()) {\n              ans[index[{cur,\
    \ par}]] = s - cost + std::get<0>(heaps[cur].top());\n            } else {\n \
    \             ans[index[{cur, par}]] = -1;\n            }\n          }\n     \
    \   })(0, -1, 0);\n  }\n\n  for (auto x : ans) {\n    std::cout << x << std::endl;\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559\"\
    \n\n#include <iostream>\n#include <map>\n#include <set>\n#include <tuple>\n#include\
    \ <vector>\n#include \"Mylib/DataStructure/Heap/pairing_heap.cpp\"\n#include \"\
    Mylib/Graph/MinimumSpanningTree/prim.cpp\"\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n#include \"Mylib/Misc/merge_technique.cpp\"\n#include \"Mylib/Utils/fix_point.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int n, m;\n  std::cin >> n >>\
    \ m;\n\n  hl::graph<int64_t> g(n);\n  g.read<1, false>(m);\n\n  std::map<std::pair<int,\
    \ int>, int> index;\n  for (auto &a : g) {\n    for (auto &e : a) index[{e.from,\
    \ e.to}] = e.index;\n  }\n\n  auto res = hl::prim(g);\n\n  std::vector<int64_t>\
    \ ans(m, -1);\n\n  if ((int) res.size() == n - 1) {\n    int64_t s = 0;\n    hl::tree<int64_t>\
    \ tree(n);\n\n    for (auto &e : res) {\n      s += e.cost;\n      tree[e.from].push_back(e);\n\
    \    }\n\n    ans.assign(m, s);\n\n    std::vector<hl::pairing_heap<std::tuple<int64_t,\
    \ int, int>, std::greater<>>> heaps(n);\n\n    std::vector<std::set<int>> sub(n);\n\
    \n    hl::make_fix_point(\n        [&](auto &&f, int cur, int par, int64_t cost)\
    \ -> void {\n          for (auto &e : g[cur]) {\n            heaps[cur].push({e.cost,\
    \ e.from, e.to});\n          }\n\n          sub[cur].insert(cur);\n\n        \
    \  for (auto &e : tree[cur]) {\n            if (e.to == par) continue;\n     \
    \       f(e.to, cur, e.cost);\n\n            heaps[cur].meld(heaps[e.to]);\n \
    \           hl::merge_technique(sub[cur], sub[cur], sub[e.to]);\n          }\n\
    \n          if (par != -1) {\n            while (not heaps[cur].empty()) {\n \
    \             auto [c, i, j] = heaps[cur].top();\n              if ((sub[cur].find(i)\
    \ != sub[cur].end() and sub[cur].find(j) != sub[cur].end()) or\n             \
    \     (i == cur and j == par) or (i == par and j == cur)) {\n                heaps[cur].pop();\n\
    \              } else {\n                break;\n              }\n           \
    \ }\n\n            if (not heaps[cur].empty()) {\n              ans[index[{cur,\
    \ par}]] = s - cost + std::get<0>(heaps[cur].top());\n            } else {\n \
    \             ans[index[{cur, par}]] = -1;\n            }\n          }\n     \
    \   })(0, -1, 0);\n  }\n\n  for (auto x : ans) {\n    std::cout << x << std::endl;\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/Heap/pairing_heap.cpp
  - Mylib/Graph/MinimumSpanningTree/prim.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Misc/merge_technique.cpp
  - Mylib/Utils/fix_point.cpp
  isVerificationFile: true
  path: test/aoj/2559/main.pairing_heap.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2559/main.pairing_heap.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2559/main.pairing_heap.test.cpp
- /verify/test/aoj/2559/main.pairing_heap.test.cpp.html
title: test/aoj/2559/main.pairing_heap.test.cpp
---
