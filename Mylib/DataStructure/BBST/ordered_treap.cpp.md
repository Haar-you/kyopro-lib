---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Mylib/DataStructure/Treap/treap.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include \"Mylib/DataStructure/Treap/treap.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  class ordered_treap\
    \ : public treap<Monoid> {\n    using value_type = typename Monoid::value_type;\n\
    \    using node = treap_node<Monoid>;\n    using super = treap<Monoid>;\n\n  public:\n\
    \    ordered_treap(): super(){}\n\n  protected:\n    int lower_bound(node *t,\
    \ const value_type &val){\n      if(!t) return 0;\n      int c = super::count(t->left);\n\
    \      if(t->value >= val) return std::min(c, lower_bound(t->left, val));\n  \
    \    else return c + 1 + lower_bound(t->right, val);\n    }\n\n  public:\n   \
    \ int lower_bound(const value_type &val){\n      return lower_bound(super::root,\
    \ val);\n    }\n\n  protected:\n    int upper_bound(node *t, const value_type\
    \ &val){\n      if(!t) return 0;\n      int c = super::count(t->left);\n     \
    \ if(t->val > val) return std::min(c, upper_bound(t->left, val));\n      else\
    \ return c + 1 + upper_bound(t->right, val);\n    }\n\n  public:\n    int upper_bound(const\
    \ value_type &val){\n      return upper_bound(super::root, val);\n    }\n\n  public:\n\
    \    void insert_by_order(const value_type &val){\n      int k = lower_bound(val);\n\
    \      super::insert(k, val);\n    }\n\n  public:\n    int find_by_order(const\
    \ value_type &val){\n      int k = lower_bound(super::root, val);\n      if(k\
    \ >= super::size()) return -1;\n      auto t = super::get(k);\n      return t\
    \ == val ? k : -1;\n    }\n\n  public:\n    void erase_by_order(const value_type\
    \ &val){\n      int k = find_by_order(val);\n      if(k == -1) return;\n     \
    \ super::erase(k);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/BBST/ordered_treap.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/BBST/ordered_treap.cpp
layout: document
title: Treap (Ordered set)
---

## Operations

## Requirements

## Notes

## Problems

## References
