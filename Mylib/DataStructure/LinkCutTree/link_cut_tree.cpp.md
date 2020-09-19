---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
    title: test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp\"\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  struct link_cut_node\
    \ {\n    using value_type = typename Monoid::value_type;\n    using node = link_cut_node;\n\
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
    \      update_node_status();\n      parent = g;\n\n      if(!g) return;\n\n  \
    \    if(g->left == p) g->left = this;\n      if(g->right == p) g->right = this;\n\
    \      g->update_node_status();\n    }\n\n    void splay(){\n      while(not is_root()){\n\
    \        node *p = parent, *gp = p->parent;\n\n        if(p->is_root()){\n   \
    \       p->push_down();\n          push_down();\n          rot(this == p->left);\n\
    \        }else{\n          gp->push_down();\n          p->push_down();\n     \
    \     push_down();\n          bool flag = this == p->left;\n          if((this\
    \ == p->left) == (p == gp->left)){\n            p->rot(flag);\n            rot(flag);\n\
    \          }else{\n            rot(flag);\n            rot(!flag);\n         \
    \ }\n        }\n      }\n      push_down();\n    }\n\n    static void expose(node\
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
    \    }\n  };\n\n  template <typename Monoid>\n  class link_cut_tree {\n    using\
    \ value_type = typename Monoid::value_type;\n    using node = link_cut_node<Monoid>;\n\
    \    const static Monoid M;\n\n    int N;\n    std::vector<node*> nodes;\n\n \
    \ public:\n    link_cut_tree(int N): N(N), nodes(N){\n      for(int i = 0; i <\
    \ N; ++i){\n        nodes[i] = new node();\n      }\n    }\n\n    void expose(int\
    \ k){\n      node::expose(nodes[k]);\n    }\n\n    void cut(int i, int j){\n \
    \     node::cut(nodes[i], nodes[j]);\n    }\n\n    void link(int i, int j){\n\
    \      node::link(nodes[i], nodes[j]);\n    }\n\n    void evert(int k){\n    \
    \  node::evert(nodes[k]);\n    }\n\n    void update(int k, value_type x){\n  \
    \    node::evert(nodes[k]);\n      nodes[k]->value = x;\n      nodes[k]->push_down();\n\
    \    }\n\n    value_type at(int k){\n      return nodes[k]->value;\n    }\n\n\
    \    value_type get(int i, int j){\n      node::evert(nodes[i]);\n      node::expose(nodes[j]);\n\
    \      return nodes[j]->result;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  struct link_cut_node {\n    using value_type = typename Monoid::value_type;\n\
    \    using node = link_cut_node;\n    const static Monoid M;\n\n    int subsize;\n\
    \    node *left, *right, *parent;\n    bool rev;\n    value_type value, result;\n\
    \n    link_cut_node():\n      subsize(1),\n      left(nullptr),\n      right(nullptr),\n\
    \      parent(nullptr),\n      rev(false),\n      value(M()),\n      result(M())\n\
    \    {}\n\n    bool is_root() const {\n      return !parent or (parent->left !=\
    \ this and parent->right != this);\n    }\n\n    void update_node_status(){\n\
    \      subsize = 1;\n      result = value;\n\n      if(left){\n        left->push_down();\n\
    \        subsize += left->subsize;\n        result = M(result, left->result);\n\
    \      }\n\n      if(right){\n        right->push_down();\n        subsize +=\
    \ right->subsize;\n        result = M(result, right->result);\n      }\n    }\n\
    \n    void push_down(){\n      if(rev){\n        std::swap(left, right);\n   \
    \     if(left) left->rev ^= true;\n        if(right) right->rev ^= true;\n   \
    \     rev = false;\n      }\n    }\n\n    void rot(int dir_right){\n      node\
    \ *p = parent, *g = p->parent;\n\n      if(dir_right){\n        if((p->left =\
    \ right)) right->parent = p;\n        right = p;\n        p->parent = this;\n\
    \      }else{\n        if((p->right = left)) left->parent = p;\n        left =\
    \ p;\n        p->parent = this;\n      }\n\n      p->update_node_status();\n \
    \     update_node_status();\n      parent = g;\n\n      if(!g) return;\n\n   \
    \   if(g->left == p) g->left = this;\n      if(g->right == p) g->right = this;\n\
    \      g->update_node_status();\n    }\n\n    void splay(){\n      while(not is_root()){\n\
    \        node *p = parent, *gp = p->parent;\n\n        if(p->is_root()){\n   \
    \       p->push_down();\n          push_down();\n          rot(this == p->left);\n\
    \        }else{\n          gp->push_down();\n          p->push_down();\n     \
    \     push_down();\n          bool flag = this == p->left;\n          if((this\
    \ == p->left) == (p == gp->left)){\n            p->rot(flag);\n            rot(flag);\n\
    \          }else{\n            rot(flag);\n            rot(!flag);\n         \
    \ }\n        }\n      }\n      push_down();\n    }\n\n    static void expose(node\
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
    \    }\n  };\n\n  template <typename Monoid>\n  class link_cut_tree {\n    using\
    \ value_type = typename Monoid::value_type;\n    using node = link_cut_node<Monoid>;\n\
    \    const static Monoid M;\n\n    int N;\n    std::vector<node*> nodes;\n\n \
    \ public:\n    link_cut_tree(int N): N(N), nodes(N){\n      for(int i = 0; i <\
    \ N; ++i){\n        nodes[i] = new node();\n      }\n    }\n\n    void expose(int\
    \ k){\n      node::expose(nodes[k]);\n    }\n\n    void cut(int i, int j){\n \
    \     node::cut(nodes[i], nodes[j]);\n    }\n\n    void link(int i, int j){\n\
    \      node::link(nodes[i], nodes[j]);\n    }\n\n    void evert(int k){\n    \
    \  node::evert(nodes[k]);\n    }\n\n    void update(int k, value_type x){\n  \
    \    node::evert(nodes[k]);\n      nodes[k]->value = x;\n      nodes[k]->push_down();\n\
    \    }\n\n    value_type at(int k){\n      return nodes[k]->value;\n    }\n\n\
    \    value_type get(int i, int j){\n      node::evert(nodes[i]);\n      node::expose(nodes[j]);\n\
    \      return nodes[j]->result;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp
documentation_of: Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp
layout: document
title: Link/cut tree
---

## Operations

## Requirements

## Notes

## Problems

## References
