---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/BBST/splay_tree.cpp
    title: Splay tree
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/input_tuples_with_index.cpp
    title: Input tuples with index
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508
  bundledCode: "#line 1 \"test/aoj/1508/main.splay_tree.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\n\n#include\
    \ <iostream>\n#line 2 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n#include <algorithm>\n\
    #include <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ min_monoid {\n    using value_type = std::optional<T>;\n\n    value_type operator()()\
    \ const { return {}; }\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if (not a) return b;\n      if (not b) return a;\n      return\
    \ {std::min(*a, *b)};\n    }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/DataStructure/BBST/splay_tree.cpp\"\
    \n#include <tuple>\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  struct splay_node {\n    using node       = splay_node<Monoid>;\n\
    \    using value_type = typename Monoid::value_type;\n    const static Monoid\
    \ M;\n\n    node *left = nullptr, *right = nullptr, *parent = nullptr;\n    int\
    \ size;\n    value_type value = M(), result = M();\n\n    splay_node() : size(1)\
    \ {}\n    splay_node(const value_type &value) : size(1), value(value) {}\n\n \
    \   void rotate() {\n      node *p, *pp, *c;\n\n      p  = this->parent;\n   \
    \   pp = p->parent;\n\n      if (p->left == this) {\n        c = this->right;\n\
    \        p->set_left(c);\n        this->set_right(p);\n      } else {\n      \
    \  c = this->left;\n        p->set_right(c);\n        this->set_left(p);\n   \
    \   }\n\n      if (pp) {\n        if (pp->left == p) pp->left = this;\n      \
    \  if (pp->right == p) pp->right = this;\n      }\n\n      this->parent = pp;\n\
    \n      p->update();\n      this->update();\n    }\n\n    int status() {\n   \
    \   if (not this->parent) return 0;\n      if (this->parent->left == this) return\
    \ 1;\n      if (this->parent->right == this) return -1;\n      return 0;\n   \
    \ }\n\n    void splay() {\n      while (status() != 0) {\n        if (this->parent->status()\
    \ == 0) {\n          this->rotate();\n        } else if (this->status() == this->parent->status())\
    \ {\n          this->parent->rotate();\n          this->rotate();\n        } else\
    \ {\n          this->rotate();\n          this->rotate();\n        }\n      }\n\
    \    }\n\n    void update() {\n      this->size = 1;\n      if (this->left) this->size\
    \ += this->left->size;\n      if (this->right) this->size += this->right->size;\n\
    \n      this->result = this->value;\n      if (this->left) this->result = M(this->result,\
    \ this->left->result);\n      if (this->right) this->result = M(this->result,\
    \ this->right->result);\n    }\n\n    void set_left(node *l) {\n      this->left\
    \ = l;\n      if (l) l->parent = this;\n    }\n\n    void set_right(node *r) {\n\
    \      this->right = r;\n      if (r) r->parent = this;\n    }\n\n    static node\
    \ *get(node *root, int index) {\n      if (not root) return root;\n      node\
    \ *cur = root;\n\n      while (1) {\n        int lsize = cur->left ? cur->left->size\
    \ : 0;\n\n        if (index < lsize) {\n          cur = cur->left;\n        }\
    \ else if (index == lsize) {\n          cur->splay();\n          return cur;\n\
    \        } else {\n          cur = cur->right;\n          index -= lsize + 1;\n\
    \        }\n      }\n    }\n\n    static node *merge(node *left, node *right)\
    \ {\n      if (not left) return right;\n      if (not right) return left;\n\n\
    \      node *cur = node::get(left, left->size - 1);\n\n      cur->right    = right;\n\
    \      right->parent = cur;\n\n      right->update();\n      cur->update();\n\n\
    \      return cur;\n    }\n\n    static std::pair<node *, node *> split(node *root,\
    \ int index) {\n      if (not root) return std::make_pair(nullptr, nullptr);\n\
    \      if (index >= root->size) return std::make_pair(root, nullptr);\n\n    \
    \  auto *cur  = node::get(root, index);\n      auto *left = cur->left;\n\n   \
    \   if (left) left->parent = nullptr;\n      cur->left = nullptr;\n\n      if\
    \ (left) left->update();\n      cur->update();\n\n      return std::make_pair(left,\
    \ cur);\n    }\n\n    template <typename Func>\n    static void traverse(node\
    \ *cur, const Func &f) {\n      if (cur) {\n        traverse(cur->left, f);\n\
    \        f(*cur);\n        traverse(cur->right, f);\n      }\n    }\n  };\n\n\
    \  template <typename Monoid>\n  class splay_tree {\n  public:\n    using value_type\
    \ = typename Monoid::value_type;\n\n  private:\n    using node = splay_node<Monoid>;\n\
    \    Monoid M_;\n    node *root_;\n\n    splay_tree(node *root) : root_(root)\
    \ {}\n\n  public:\n    splay_tree() : root_(nullptr) {}\n    splay_tree(int N)\
    \ : root_(nullptr) {\n      for (int i = 0; i < N; ++i) push_back(M_());\n   \
    \ }\n\n    static auto singleton(const value_type &value) { return splay_tree(new\
    \ node(value)); }\n\n    int size() const { return root_ ? root_->size : 0; }\n\
    \    bool empty() const { return not root_; }\n\n    const value_type get(int\
    \ index) {\n      root_ = node::get(root_, index);\n      return root_->value;\n\
    \    }\n    const value_type operator[](int index) { return get(index); }\n\n\
    \    void set(int index, const value_type &value) {\n      root_        = node::get(root_,\
    \ index);\n      root_->value = value;\n      root_->update();\n    }\n\n    void\
    \ merge_right(splay_tree &right) {\n      root_       = node::merge(root_, right.root);\n\
    \      right.root_ = nullptr;\n    }\n\n    void merge_left(splay_tree &left)\
    \ {\n      root_      = node::merge(left.root_, root_);\n      left.root_ = nullptr;\n\
    \    }\n\n    auto split(int index) {\n      node *left, *right;\n      std::tie(left,\
    \ right) = node::split(root_, index);\n      return std::make_pair(splay_tree(left),\
    \ splay_tree(right));\n    }\n\n    void insert(int index, const value_type &value)\
    \ {\n      auto s = node::split(root_, index);\n      root_  = node::merge(s.first,\
    \ node::merge(new node(value), s.second));\n    }\n\n    void erase(int index)\
    \ {\n      node *left, *right;\n      std::tie(left, right)        = node::split(root_,\
    \ index);\n      std::tie(std::ignore, right) = node::split(right, 1);\n     \
    \ root_                        = node::merge(left, right);\n    }\n\n    const\
    \ value_type fold() { return root_->result; }\n    const value_type fold(int l,\
    \ int r) {  // [l, r)\n      node *left, *mid, *right;\n      std::tie(mid, right)\
    \ = node::split(root_, r);\n      std::tie(left, mid)  = node::split(mid, l);\n\
    \n      auto ret = mid->result;\n\n      mid   = node::merge(left, mid);\n   \
    \   root_ = node::merge(mid, right);\n\n      return ret;\n    }\n\n    void push_back(const\
    \ value_type &value) { insert(size(), value); }\n    void push_front(const value_type\
    \ &value) { insert(0, value); }\n\n    void pop_back() { erase(size() - 1); }\n\
    \    void pop_front() { erase(0); }\n\n    template <typename Func>\n    void\
    \ traverse(const Func &f) const {\n      node::traverse(root_, f);\n    }\n  };\n\
    }  // namespace haar_lib\n#line 2 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
    #line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>) {\n \
    \   (void) std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream &operator>>(std::istream\
    \ &s, std::pair<T, U> &value) {\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename... Args>\n  std::istream &operator>>(std::istream\
    \ &s, std::tuple<Args...> &value) {\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());\n\
    \    return s;\n  }\n}  // namespace haar_lib\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename... Args>\n  class InputTuples {\n\
    \    struct iter {\n      using value_type = std::tuple<Args...>;\n      value_type\
    \ value;\n      bool fetched = false;\n      int N, c = 0;\n\n      value_type\
    \ operator*() {\n        if (not fetched) {\n          std::cin >> value;\n  \
    \      }\n        return value;\n      }\n\n      void operator++() {\n      \
    \  ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N) : N(N) {}\n    };\n\n\
    \    int N;\n\n  public:\n    InputTuples(int N) : N(N) {}\n\n    iter begin()\
    \ const { return iter(N); }\n    iter end() const { return iter(N); }\n  };\n\n\
    \  template <typename... Args>\n  auto input_tuples(int N) {\n    return InputTuples<Args...>(N);\n\
    \  }\n}  // namespace haar_lib\n#line 8 \"Mylib/IO/input_tuples_with_index.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename... Args>\n  class InputTuplesWithIndex\
    \ {\n    struct iter {\n      using value_type = std::tuple<int, Args...>;\n \
    \     value_type value;\n      bool fetched = false;\n      int N;\n      int\
    \ c = 0;\n\n      value_type operator*() {\n        if (not fetched) {\n     \
    \     std::tuple<Args...> temp;\n          std::cin >> temp;\n          value\
    \ = std::tuple_cat(std::make_tuple(c), temp);\n        }\n        return value;\n\
    \      }\n\n      void operator++() {\n        ++c;\n        fetched = false;\n\
    \      }\n\n      bool operator!=(iter &) const {\n        return c < N;\n   \
    \   }\n\n      iter(int N) : N(N) {}\n    };\n\n    int N;\n\n  public:\n    InputTuplesWithIndex(int\
    \ N) : N(N) {}\n\n    iter begin() const { return iter(N); }\n    iter end() const\
    \ { return iter(N); }\n  };\n\n  template <typename... Args>\n  auto input_tuples_with_index(int\
    \ N) {\n    return InputTuplesWithIndex<Args...>(N);\n  }\n}  // namespace haar_lib\n\
    #line 8 \"test/aoj/1508/main.splay_tree.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main() {\n  int n, q;\n  std::cin >> n >> q;\n\n  hl::splay_tree<hl::min_monoid<int>>\
    \ s(n);\n\n  for (auto [i, a] : hl::input_tuples_with_index<int>(n)) {\n    s.set(i,\
    \ {a});\n  }\n\n  for (auto [x, y, z] : hl::input_tuples<int, int, int>(q)) {\n\
    \    if (x == 0) {\n      auto temp = s.get(z).value();\n      s.erase(z);\n \
    \     s.insert(y, {temp});\n    } else if (x == 1) {\n      auto ans = s.fold(y,\
    \ z + 1).value();\n      std::cout << ans << std::endl;\n    } else {\n      s.set(y,\
    \ z);\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508\"\
    \n\n#include <iostream>\n#include \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n\
    #include \"Mylib/DataStructure/BBST/splay_tree.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/IO/input_tuples_with_index.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main() {\n  int n, q;\n  std::cin >> n >> q;\n\n  hl::splay_tree<hl::min_monoid<int>>\
    \ s(n);\n\n  for (auto [i, a] : hl::input_tuples_with_index<int>(n)) {\n    s.set(i,\
    \ {a});\n  }\n\n  for (auto [x, y, z] : hl::input_tuples<int, int, int>(q)) {\n\
    \    if (x == 0) {\n      auto temp = s.get(z).value();\n      s.erase(z);\n \
    \     s.insert(y, {temp});\n    } else if (x == 1) {\n      auto ans = s.fold(y,\
    \ z + 1).value();\n      std::cout << ans << std::endl;\n    } else {\n      s.set(y,\
    \ z);\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/DataStructure/BBST/splay_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_tuples_with_index.cpp
  isVerificationFile: true
  path: test/aoj/1508/main.splay_tree.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1508/main.splay_tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1508/main.splay_tree.test.cpp
- /verify/test/aoj/1508/main.splay_tree.test.cpp.html
title: test/aoj/1508/main.splay_tree.test.cpp
---