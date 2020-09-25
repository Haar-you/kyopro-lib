---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/BBST/treap.cpp
    title: Treap
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuples_with_index.cpp
    title: Mylib/IO/input_tuples_with_index.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
  bundledCode: "#line 1 \"test/aoj/1508/main.treap.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\n\n#include <iostream>\n\
    #line 2 \"Mylib/DataStructure/BBST/treap.cpp\"\n#include <random>\n#include <utility>\n\
    #include <tuple>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  struct\
    \ treap_node {\n    using node = treap_node<Monoid>;\n    using value_type = typename\
    \ Monoid::value_type;\n    const static Monoid M;\n\n    static std::mt19937 rand;\n\
    \n    value_type value, result;\n    node *left = nullptr, *right = nullptr;\n\
    \    int priority, size = 1;\n    bool rev = false;\n\n    treap_node(): priority(rand()){}\n\
    \    treap_node(const value_type &value): value(value), result(value), priority(rand()){}\n\
    \n    static int count(node *t) {return !t ? 0 : t->size;}\n    static value_type\
    \ sum(node *t) {return !t ? M() : t->result;}\n\n    static node* update_node_status(node\
    \ *t){\n      t->size = count(t->right) + count(t->left) + 1;\n      t->result\
    \ = M(M(sum(t->right), sum(t->left)), t->value);\n      return t;\n    }\n\n \
    \   static void pushdown(node *t){\n      if(!t) return;\n      if(t->rev){\n\
    \        std::swap(t->left, t->right);\n        if(t->left) t->left->rev ^= true;\n\
    \        if(t->right) t->right->rev ^= true;\n        t->rev = false;\n      }\n\
    \      update_node_status(t);\n    }\n\n    static node* insert(node *t, int k,\
    \ const value_type &val){\n      auto s = split(t, k);\n      return merge(s.first,\
    \ merge(new node(val), s.second));\n    }\n\n    static node* erase(node *t, int\
    \ k){\n      node *l, *r, *m;\n      std::tie(l, r) = split(t, k);\n      std::tie(m,\
    \ r) = split(r, 1);\n      return merge(l, r);\n    }\n\n    static std::pair<node*,\
    \ node*> split(node *t, int k){\n      if(!t) return std::make_pair(nullptr, nullptr);\n\
    \      pushdown(t);\n      const int c = count(t->left);\n      if(k <= c){\n\
    \        auto s = split(t->left, k);\n        t->left = s.second;\n        return\
    \ std::make_pair(s.first, update_node_status(t));\n      }else{\n        auto\
    \ s = split(t->right, k - (c + 1));\n        t->right = s.first;\n        return\
    \ std::make_pair(update_node_status(t), s.second);\n      }\n    }\n\n    static\
    \ node* merge(node *l, node *r){\n      pushdown(l);\n      pushdown(r);\n   \
    \   if(!l || !r) return !l ? r : l;\n      if(l->priority > r->priority){\n  \
    \      l->right = merge(l->right, r);\n        return update_node_status(l);\n\
    \      }else{\n        r->left = merge(l, r->left);\n        return update_node_status(r);\n\
    \      }\n    }\n\n    static node* reverse(node *t, int l, int r){\n      node\
    \ *a, *b, *c;\n      std::tie(a, c) = split(t, l);\n      std::tie(b, c) = split(c,\
    \ r - l);\n      b->rev ^= true;\n      return t = merge(merge(a, b), c);\n  \
    \  }\n\n    static void update_node(node *t, int k, const value_type &value){\n\
    \      const int c = count(t->left);\n      if(k == c) t->value = value;\n   \
    \   else if(k > c) update_node(t->right, k - (c + 1), value);\n      else update_node(t->left,\
    \ k, value);\n      update_node_status(t);\n    }\n\n    static node* get_node(node\
    \ *t, int k){\n      if(!t) return t;\n      pushdown(t);\n      int c = count(t->left);\n\
    \      if(k == c) return t;\n      if(k > c) return get_node(t->right, k - (c\
    \ + 1));\n      else return get_node(t->left, k);\n    }\n\n    template <typename\
    \ Func>\n    static void traverse(node *t, const Func &f){\n      if(t){\n   \
    \     pushdown(t);\n        traverse(t->left, f);\n        f(*t);\n        traverse(t->right,\
    \ f);\n      }\n    }\n  };\n\n  template <typename Monoid> std::mt19937 treap_node<Monoid>::rand;\n\
    \n  template <typename Monoid>\n  class treap {\n  protected:\n    using node\
    \ = treap_node<Monoid>;\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    node *root = nullptr;\n\n  public:\n    treap(){}\n\
    \    treap(int n){for(int i = 0; i < n; ++i) push_back(M());}\n    treap(node\
    \ *t): root(t){}\n\n    int size() const {return node::count(root);}\n    bool\
    \ empty() const {return !root;}\n\n    void insert(int k, const value_type &val\
    \ = M()){\n      root = node::insert(root, k, val);\n    }\n\n    void erase(int\
    \ k){root = node::erase(root, k);}\n\n    void merge_left(treap &left){\n    \
    \  root = node::merge(left.root, root); left.root = nullptr;\n    }\n\n    void\
    \ merge_right(treap &right){\n      root = node::merge(root, right.root); right.root\
    \ = nullptr;\n    }\n\n    std::pair<treap, treap> split(int k){\n      node *l,\
    \ *r; std::tie(l, r) = node::split(root, k);\n      return std::make_pair(treap(l),\
    \ treap(r));\n    }\n\n    void reverse(int l, int r){node::reverse(root, l, r);}\n\
    \n    void set(int k, const value_type &value){node::update_node(root, k, value);}\n\
    \n    value_type get(int k){return (node::get_node(root, k))->value;}\n    value_type\
    \ operator[](int k){return get(k);}\n\n    value_type fold(){return node::sum(root);}\n\
    \    value_type fold(int l, int r){\n      node *left, *mid, *right;\n      std::tie(mid,\
    \ right) = node::split(root, r);\n      std::tie(left, mid) = node::split(mid,\
    \ l);\n\n      auto ret = node::sum(mid);\n\n      mid = node::merge(left, mid);\n\
    \      root = node::merge(mid, right);\n\n      return ret;\n    }\n\n    template\
    \ <typename Func>\n    void traverse(const Func &f){\n      node::traverse(root,\
    \ f);\n    }\n\n    void push_front(const value_type &val){insert(0, val);}\n\
    \    void push_back(const value_type &val){insert(size(), val);}\n\n    void pop_front(){erase(0);}\n\
    \    void pop_back(){erase(size() - 1);}\n\n    const value_type& front(){return\
    \ get(0);}\n    const value_type& back(){return get(size() - 1);}\n  };\n}\n#line\
    \ 2 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n#include <algorithm>\n#include\
    \ <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct min_monoid\
    \ {\n    using value_type = std::optional<T>;\n\n    value_type operator()() const\
    \ {return {};}\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if(not a) return b;\n      if(not b) return a;\n      return\
    \ {std::min(*a, *b)};\n    }\n  };\n}\n#line 3 \"Mylib/IO/input_tuples.cpp\"\n\
    #include <vector>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
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
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 8 \"Mylib/IO/input_tuples_with_index.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuplesWithIndex\
    \ {\n    struct iter {\n      using value_type = std::tuple<int, Args ...>;\n\
    \      value_type value;\n      bool fetched = false;\n      int N;\n      int\
    \ c = 0;\n\n      value_type operator*(){\n        if(not fetched){\n        \
    \  std::tuple<Args ...> temp; std::cin >> temp;\n          value = std::tuple_cat(std::make_tuple(c),\
    \ temp);\n        }\n        return value;\n      }\n\n      void operator++(){\n\
    \        ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter\
    \ &) const {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n  \
    \  };\n\n    int N;\n\n  public:\n    InputTuplesWithIndex(int N): N(N){}\n\n\
    \    iter begin() const {return iter(N);}\n    iter end() const {return iter(N);}\n\
    \  };\n\n  template <typename ... Args>\n  auto input_tuples_with_index(int N){\n\
    \    return InputTuplesWithIndex<Args ...>(N);\n  }\n}\n#line 8 \"test/aoj/1508/main.treap.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\
    \n  hl::treap<hl::min_monoid<int>> s(n);\n\n  for(auto [i, a] : hl::input_tuples_with_index<int>(n)){\n\
    \    s.set(i, {a});\n  }\n\n  for(auto [x, y, z] : hl::input_tuples<int, int,\
    \ int>(q)){\n    if(x == 0){\n      auto temp = s.get(z).value();\n      s.erase(z);\n\
    \      s.insert(y, {temp});\n    }else if(x == 1){\n      auto ans = s.fold(y,\
    \ z + 1).value();\n      std::cout << ans << std::endl;\n    }else{\n      s.set(y,\
    \ z);\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\
    \n\n#include <iostream>\n#include \"Mylib/DataStructure/BBST/treap.cpp\"\n#include\
    \ \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/IO/input_tuples_with_index.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int n, q; std::cin >> n >> q;\n\n  hl::treap<hl::min_monoid<int>>\
    \ s(n);\n\n  for(auto [i, a] : hl::input_tuples_with_index<int>(n)){\n    s.set(i,\
    \ {a});\n  }\n\n  for(auto [x, y, z] : hl::input_tuples<int, int, int>(q)){\n\
    \    if(x == 0){\n      auto temp = s.get(z).value();\n      s.erase(z);\n   \
    \   s.insert(y, {temp});\n    }else if(x == 1){\n      auto ans = s.fold(y, z\
    \ + 1).value();\n      std::cout << ans << std::endl;\n    }else{\n      s.set(y,\
    \ z);\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/BBST/treap.cpp
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_tuples_with_index.cpp
  isVerificationFile: true
  path: test/aoj/1508/main.treap.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1508/main.treap.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1508/main.treap.test.cpp
- /verify/test/aoj/1508/main.treap.test.cpp.html
title: test/aoj/1508/main.treap.test.cpp
---
