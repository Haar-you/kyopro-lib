---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/Heap/skew_heap.cpp
    title: Skew heap
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/prim.cpp
    title: Prim algorithm
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':heavy_check_mark:'
    path: Mylib/Misc/merge_technique.cpp
    title: Merge technique
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/aoj/2559/main.skew_heap.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <map>\n#include <set>\n#include <tuple>\n\
    #line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n    int index\
    \ = -1;\n    edge(){}\n    edge(int from, int to, T cost): from(from), to(to),\
    \ cost(cost){}\n    edge(int from, int to, T cost, int index): from(from), to(to),\
    \ cost(cost), index(index){}\n  };\n\n  template <typename T>\n  struct graph\
    \ {\n    using weight_type = T;\n    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/MinimumSpanningTree/prim.cpp\"\
    \n#include <queue>\n#line 5 \"Mylib/Graph/MinimumSpanningTree/prim.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<edge<T>> prim(const graph<T>\
    \ &graph){\n    const int n = graph.size();\n    std::vector<bool> visit(n, false);\n\
    \    std::vector<edge<T>> ret;\n\n    auto cmp = [](const auto &a, const auto\
    \ &b){return a.cost > b.cost;};\n    std::priority_queue<edge<T>, std::vector<edge<T>>,\
    \ decltype(cmp)> pq(cmp);\n\n    visit[0] = true;\n    for(auto &e : graph[0])\
    \ pq.push(e);\n\n    while(not pq.empty()){\n      auto t = pq.top(); pq.pop();\n\
    \n      if(visit[t.from] == visit[t.to]) continue;\n\n      int i = visit[t.from]\
    \ ? t.to : t.from;\n      for(auto &e : graph[i]){\n        pq.push(e);\n    \
    \  }\n\n      visit[i] = true;\n      ret.push_back(t);\n    }\n\n    return ret;\n\
    \  }\n}\n#line 2 \"Mylib/Utils/fix_point.cpp\"\n#include <utility>\n\nnamespace\
    \ haar_lib {\n  template <typename F>\n  struct fix_point : F {\n    explicit\
    \ constexpr fix_point(F &&f) noexcept : F(std::forward<F>(f)){}\n\n    template\
    \ <typename ... Args>\n    constexpr auto operator()(Args &&... args) const {\n\
    \      return F::operator()(*this, std::forward<Args>(args) ...);\n    }\n  };\n\
    \n  template <typename F>\n  inline constexpr auto make_fix_point(F &&f){\n  \
    \  return fix_point<F>(std::forward<F>(f));\n  }\n\n  template <typename F>\n\
    \  inline constexpr auto make_fix_point(F &f){\n    return fix_point<F>(std::forward<F>(f));\n\
    \  }\n}\n#line 2 \"Mylib/DataStructure/Heap/skew_heap.cpp\"\n#include <functional>\n\
    #line 4 \"Mylib/DataStructure/Heap/skew_heap.cpp\"\n\nnamespace haar_lib {\n \
    \ template <typename T, class Compare = std::less<T>>\n  class skew_heap {\n \
    \ public:\n    using value_type = T;\n\n  private:\n    struct node {\n      T\
    \ val;\n      node *left, *right;\n      int size;\n      node(const T &val):\
    \ val(val), left(nullptr), right(nullptr), size(1){}\n    };\n\n    node *root_;\n\
    \    Compare compare_;\n\n  public:\n    skew_heap(): root_(nullptr), compare_(Compare()){}\n\
    \    skew_heap(const Compare &compare_): root_(nullptr), compare_(compare_){}\n\
    \n  protected:\n    node* meld(node *a, node *b){\n      if(not a) return b;\n\
    \      if(not b) return a;\n\n      if(compare_(a->val, b->val)) std::swap(a,\
    \ b);\n\n      a->size += b->size;\n      a->right = meld(a->right, b);\n    \
    \  std::swap(a->left, a->right);\n\n      return a;\n    }\n\n  public:\n    void\
    \ meld(skew_heap &heap){root_ = meld(root_, heap.root_); heap.root_ = nullptr;}\n\
    \    void push(const T &val){root_ = meld(root_, new node(val));}\n    const T&\
    \ top() const {return root_->val;}\n    void pop(){node *temp = root_; root_ =\
    \ meld(root_->left, root_->right); delete temp;}\n    bool empty() const {return\
    \ root_ == nullptr;}\n    size_t size() const {return root_ ? root_->size : 0;}\n\
    \  };\n}\n#line 4 \"Mylib/Misc/merge_technique.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  void merge_technique(std::set<T> &res, std::set<T>\
    \ &a, std::set<T> &b){\n    if(a.size() > b.size()){\n      a.insert(b.begin(),\
    \ b.end());\n      std::swap(res, a);\n    }else{\n      b.insert(a.begin(), a.end());\n\
    \      std::swap(res, b);\n    }\n  }\n}\n#line 13 \"test/aoj/2559/main.skew_heap.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n, m; std::cin >> n >> m;\n\
    \n  hl::graph<int64_t> g(n);\n  g.read<1, false>(m);\n\n  std::map<std::pair<int,\
    \ int>, int> index;\n  for(auto &a : g){\n    for(auto &e : a) index[{e.from,\
    \ e.to}] = e.index;\n  }\n\n  auto res = hl::prim(g);\n\n  std::vector<int64_t>\
    \ ans(m, -1);\n\n  if((int)res.size() == n - 1){\n    int64_t s = 0;\n    hl::tree<int64_t>\
    \ tree(n);\n\n    for(auto &e : res){\n      s += e.cost;\n      tree[e.from].push_back(e);\n\
    \    }\n\n    ans.assign(m, s);\n\n    std::vector<hl::skew_heap<std::tuple<int64_t,\
    \ int, int>, std::greater<>>> heaps(n);\n\n    std::vector<std::set<int>> sub(n);\n\
    \n    hl::make_fix_point(\n      [&](auto &&f, int cur, int par, int64_t cost)\
    \ -> void {\n        for(auto &e : g[cur]){\n          heaps[cur].push({e.cost,\
    \ e.from, e.to});\n        }\n\n        sub[cur].insert(cur);\n\n        for(auto\
    \ &e : tree[cur]){\n          if(e.to == par) continue;\n          f(e.to, cur,\
    \ e.cost);\n\n          heaps[cur].meld(heaps[e.to]);\n          hl::merge_technique(sub[cur],\
    \ sub[cur], sub[e.to]);\n        }\n\n        if(par != -1){\n          while(not\
    \ heaps[cur].empty()){\n            auto [c, i, j] = heaps[cur].top();\n     \
    \       if((sub[cur].find(i) != sub[cur].end() and sub[cur].find(j) != sub[cur].end())\
    \ or\n               (i == cur and j == par) or (i == par and j == cur)){\n  \
    \            heaps[cur].pop();\n            }else{\n              break;\n   \
    \         }\n          }\n\n          if(not heaps[cur].empty()){\n          \
    \  ans[index[{cur, par}]] = s - cost + std::get<0>(heaps[cur].top());\n      \
    \    }else{\n            ans[index[{cur, par}]] = -1;\n          }\n        }\n\
    \      }\n    )(0, -1, 0);\n  }\n\n  for(auto x : ans){\n    std::cout << x <<\
    \ std::endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2559\"\
    \n\n#include <iostream>\n#include <vector>\n#include <map>\n#include <set>\n#include\
    \ <tuple>\n#include \"Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Graph/MinimumSpanningTree/prim.cpp\"\
    \n#include \"Mylib/Utils/fix_point.cpp\"\n#include \"Mylib/DataStructure/Heap/skew_heap.cpp\"\
    \n#include \"Mylib/Misc/merge_technique.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int n, m; std::cin >> n >> m;\n\n  hl::graph<int64_t> g(n);\n \
    \ g.read<1, false>(m);\n\n  std::map<std::pair<int, int>, int> index;\n  for(auto\
    \ &a : g){\n    for(auto &e : a) index[{e.from, e.to}] = e.index;\n  }\n\n  auto\
    \ res = hl::prim(g);\n\n  std::vector<int64_t> ans(m, -1);\n\n  if((int)res.size()\
    \ == n - 1){\n    int64_t s = 0;\n    hl::tree<int64_t> tree(n);\n\n    for(auto\
    \ &e : res){\n      s += e.cost;\n      tree[e.from].push_back(e);\n    }\n\n\
    \    ans.assign(m, s);\n\n    std::vector<hl::skew_heap<std::tuple<int64_t, int,\
    \ int>, std::greater<>>> heaps(n);\n\n    std::vector<std::set<int>> sub(n);\n\
    \n    hl::make_fix_point(\n      [&](auto &&f, int cur, int par, int64_t cost)\
    \ -> void {\n        for(auto &e : g[cur]){\n          heaps[cur].push({e.cost,\
    \ e.from, e.to});\n        }\n\n        sub[cur].insert(cur);\n\n        for(auto\
    \ &e : tree[cur]){\n          if(e.to == par) continue;\n          f(e.to, cur,\
    \ e.cost);\n\n          heaps[cur].meld(heaps[e.to]);\n          hl::merge_technique(sub[cur],\
    \ sub[cur], sub[e.to]);\n        }\n\n        if(par != -1){\n          while(not\
    \ heaps[cur].empty()){\n            auto [c, i, j] = heaps[cur].top();\n     \
    \       if((sub[cur].find(i) != sub[cur].end() and sub[cur].find(j) != sub[cur].end())\
    \ or\n               (i == cur and j == par) or (i == par and j == cur)){\n  \
    \            heaps[cur].pop();\n            }else{\n              break;\n   \
    \         }\n          }\n\n          if(not heaps[cur].empty()){\n          \
    \  ans[index[{cur, par}]] = s - cost + std::get<0>(heaps[cur].top());\n      \
    \    }else{\n            ans[index[{cur, par}]] = -1;\n          }\n        }\n\
    \      }\n    )(0, -1, 0);\n  }\n\n  for(auto x : ans){\n    std::cout << x <<\
    \ std::endl;\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/MinimumSpanningTree/prim.cpp
  - Mylib/Utils/fix_point.cpp
  - Mylib/DataStructure/Heap/skew_heap.cpp
  - Mylib/Misc/merge_technique.cpp
  isVerificationFile: true
  path: test/aoj/2559/main.skew_heap.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2559/main.skew_heap.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2559/main.skew_heap.test.cpp
- /verify/test/aoj/2559/main.skew_heap.test.cpp.html
title: test/aoj/2559/main.skew_heap.test.cpp
---
