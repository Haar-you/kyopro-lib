---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':x:'
    path: Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp
    title: Link/cut tree
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
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n    using\
    \ value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 2 \"Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename Monoid>\n  struct link_cut_node {\n\
    \    using value_type = typename Monoid::value_type;\n    using node = link_cut_node;\n\
    \    const static Monoid M;\n\n    int subsize;\n    node *left, *right, *parent;\n\
    \    bool rev;\n    value_type value, result;\n\n    link_cut_node():\n      subsize(1),\n\
    \      left(nullptr),\n      right(nullptr),\n      parent(nullptr),\n      rev(false),\n\
    \      value(M()),\n      result(M())\n    {}\n\n    bool is_root() const {\n\
    \      return !parent or (parent->left != this and parent->right != this);\n \
    \   }\n\n    void update_node_status(){\n      subsize = 1;\n      result = value;\n\
    \n      if(left){\n        left->push_down();\n        subsize += left->subsize;\n\
    \        result = M(result, left->result);\n      }\n\n      if(right){\n    \
    \    right->push_down();\n        subsize += right->subsize;\n        result =\
    \ M(result, right->result);\n      }\n    }\n\n    void push_down(){\n      if(rev){\n\
    \        std::swap(left, right);\n        if(left) left->rev ^= true;\n      \
    \  if(right) right->rev ^= true;\n        rev = false;\n      }\n    }\n\n   \
    \ void rot(int dir_right){\n      node *p = parent, *g = p->parent;\n\n      if(dir_right){\n\
    \        if((p->left = right)) right->parent = p;\n        right = p;\n      \
    \  p->parent = this;\n      }else{\n        if((p->right = left)) left->parent\
    \ = p;\n        left = p;\n        p->parent = this;\n      }\n\n      p->update_node_status();\n\
    \      update_node_status();\n      parent = g;\n\n      if(not g) return;\n\n\
    \      if(g->left == p) g->left = this;\n      if(g->right == p) g->right = this;\n\
    \      g->update_node_status();\n    }\n\n    void splay(){\n      while(not is_root()){\n\
    \        node *p = parent, *gp = p->parent;\n\n        if(p->is_root()){\n   \
    \       p->push_down();\n          push_down();\n          rot(this == p->left);\n\
    \        }else{\n          gp->push_down();\n          p->push_down();\n     \
    \     push_down();\n          bool flag = this == p->left;\n          if((this\
    \ == p->left) == (p == gp->left)){\n            p->rot(flag);\n            rot(flag);\n\
    \          }else{\n            rot(flag);\n            rot(not flag);\n      \
    \    }\n        }\n      }\n      push_down();\n    }\n\n    static void expose(node\
    \ *u){\n      node* rp = nullptr;\n\n      for(node* p = u; p; p = p->parent){\n\
    \        p->splay();\n        p->right = rp;\n        p->update_node_status();\n\
    \        rp = p;\n      }\n\n      u->splay();\n    }\n\n    static void link(node\
    \ *u, node *v){\n      evert(u);\n      u->parent = v;\n    }\n\n    static void\
    \ cut(node *u){\n      expose(u);\n      u->left->parent = nullptr;\n      u->left\
    \ = nullptr;\n      u->update_node_status();\n    }\n\n    static void cut(node\
    \ *u, node *v){\n      expose(u);\n      expose(v);\n      if(u->is_root()) u->parent\
    \ = nullptr;\n      else{\n        v->left->parent = nullptr;\n        v->left\
    \ = nullptr;\n        v->update_node_status();\n      }\n    }\n\n    static void\
    \ evert(node *u){\n      expose(u);\n      u->rev ^= true;\n      u->push_down();\n\
    \    }\n  };\n\n  template <typename Monoid>\n  class link_cut_tree {\n  public:\n\
    \    using value_type = typename Monoid::value_type;\n\n  private:\n    using\
    \ node = link_cut_node<Monoid>;\n    Monoid M_;\n\n    int N_;\n    std::vector<node*>\
    \ nodes_;\n\n  public:\n    link_cut_tree(){}\n    link_cut_tree(int N): N_(N),\
    \ nodes_(N){\n      for(int i = 0; i < N_; ++i){\n        nodes_[i] = new node();\n\
    \      }\n    }\n\n    void expose(int k){\n      node::expose(nodes_[k]);\n \
    \   }\n\n    void cut(int i, int j){\n      node::cut(nodes_[i], nodes_[j]);\n\
    \    }\n\n    void link(int i, int j){\n      node::link(nodes_[i], nodes_[j]);\n\
    \    }\n\n    void evert(int k){\n      node::evert(nodes_[k]);\n    }\n\n   \
    \ void set(int k, value_type x){\n      node::evert(nodes_[k]);\n      nodes_[k]->value\
    \ = x;\n      nodes_[k]->push_down();\n    }\n\n    void update(int k, value_type\
    \ x){\n      set(k, M_(get(k), x));\n    }\n\n    value_type get(int k) const\
    \ {\n      return nodes_[k]->value;\n    }\n\n    value_type fold(int i, int j){\n\
    \      node::evert(nodes_[i]);\n      node::expose(nodes_[j]);\n      return nodes_[j]->result;\n\
    \    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include\
    \ <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){\n \
    \   (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
    \ &s, std::pair<T, U> &value){\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename ... Args>\n  std::istream& operator>>(std::istream\
    \ &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuples\
    \ {\n    struct iter {\n      using value_type = std::tuple<Args ...>;\n     \
    \ value_type value;\n      bool fetched = false;\n      int N, c = 0;\n\n    \
    \  value_type operator*(){\n        if(not fetched){\n          std::cin >> value;\n\
    \        }\n        return value;\n      }\n\n      void operator++(){\n     \
    \   ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n \
    \   int N;\n\n  public:\n    InputTuples(int N): N(N){}\n\n    iter begin() const\
    \ {return iter(N);}\n    iter end() const {return iter(N);}\n  };\n\n  template\
    \ <typename ... Args>\n  auto input_tuples(int N){\n    return InputTuples<Args\
    \ ...>(N);\n  }\n}\n#line 8 \"Mylib/IO/input_tuples_with_index.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename ... Args>\n  class InputTuplesWithIndex {\n\
    \    struct iter {\n      using value_type = std::tuple<int, Args ...>;\n    \
    \  value_type value;\n      bool fetched = false;\n      int N;\n      int c =\
    \ 0;\n\n      value_type operator*(){\n        if(not fetched){\n          std::tuple<Args\
    \ ...> temp; std::cin >> temp;\n          value = std::tuple_cat(std::make_tuple(c),\
    \ temp);\n        }\n        return value;\n      }\n\n      void operator++(){\n\
    \        ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter\
    \ &) const {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n  \
    \  };\n\n    int N;\n\n  public:\n    InputTuplesWithIndex(int N): N(N){}\n\n\
    \    iter begin() const {return iter(N);}\n    iter end() const {return iter(N);}\n\
    \  };\n\n  template <typename ... Args>\n  auto input_tuples_with_index(int N){\n\
    \    return InputTuplesWithIndex<Args ...>(N);\n  }\n}\n#line 8 \"test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  hl::link_cut_tree<hl::sum_monoid<int64_t>>\
    \ lct(N);\n\n  for(auto [i, a] : hl::input_tuples_with_index<int64_t>(N)){\n \
    \   lct.set(i, a);\n  }\n\n  for(auto [u, v] : hl::input_tuples<int, int>(N -\
    \ 1)){\n    lct.link(u, v);\n  }\n\n  for(auto [type] : hl::input_tuples<int>(Q)){\n\
    \    switch(type){\n    case 0: {\n      int u, v, w, x; std::cin >> u >> v >>\
    \ w >> x;\n      lct.cut(u, v);\n      lct.link(w, x);\n      break;\n    }\n\
    \    case 1: {\n      int p, x; std::cin >> p >> x;\n      lct.update(p, x);\n\
    \      break;\n    }\n    case 2: {\n      int u, v; std::cin >> u >> v;\n   \
    \   auto ans = lct.fold(u, v);\n      std::cout << ans << std::endl;\n      break;\n\
    \    }\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include <iostream>\n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\
    #include \"Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/IO/input_tuples_with_index.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, Q; std::cin >> N >> Q;\n\n  hl::link_cut_tree<hl::sum_monoid<int64_t>> lct(N);\n\
    \n  for(auto [i, a] : hl::input_tuples_with_index<int64_t>(N)){\n    lct.set(i,\
    \ a);\n  }\n\n  for(auto [u, v] : hl::input_tuples<int, int>(N - 1)){\n    lct.link(u,\
    \ v);\n  }\n\n  for(auto [type] : hl::input_tuples<int>(Q)){\n    switch(type){\n\
    \    case 0: {\n      int u, v, w, x; std::cin >> u >> v >> w >> x;\n      lct.cut(u,\
    \ v);\n      lct.link(w, x);\n      break;\n    }\n    case 1: {\n      int p,\
    \ x; std::cin >> p >> x;\n      lct.update(p, x);\n      break;\n    }\n    case\
    \ 2: {\n      int u, v; std::cin >> u >> v;\n      auto ans = lct.fold(u, v);\n\
    \      std::cout << ans << std::endl;\n      break;\n    }\n    }\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_tuples_with_index.cpp
  isVerificationFile: true
  path: test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-29 00:55:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
- /verify/test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp.html
title: test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
---
