---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/palindromic_tree.cpp\"\n#include <vector>\n\
    #include <map>\n#include <string>\n#include <algorithm>\n#include <string_view>\n\
    \nnamespace haar_lib {\n  class palindromic_tree {\n    struct node {\n      int\
    \ length;\n      int count;\n      std::map<char, node*> children;\n      node\
    \ *suffix_link;\n      std::vector<node*> reverse_suffix_links;\n    };\n\n  \
    \  node *even_root_, *odd_root_;\n    int size_ = 2;\n\n  public:\n    palindromic_tree(){}\n\
    \    palindromic_tree(const std::string_view &s){\n      even_root_ = new node();\n\
    \      even_root_->length = 0;\n\n      odd_root_ = new node();\n      odd_root_->length\
    \ = -1;\n\n      even_root_->suffix_link = odd_root_;\n      odd_root_->reverse_suffix_links.emplace_back(even_root_);\n\
    \n      node *cur = odd_root_;\n\n      const int N = s.size();\n\n      for(int\
    \ i = 0; i < N; ++i){\n        node *t = cur;\n\n        while(1){\n         \
    \ if(i - t->length - 1 >= 0 and s[i] == s[i - t->length - 1]){\n            if(t->children.find(s[i])\
    \ == t->children.end()){\n              node *a = new node();\n              a->length\
    \ = t->length + 2;\n              a->count = 1;\n              t->children[s[i]]\
    \ = a;\n              ++size_;\n            }else{\n              t->children[s[i]]->count\
    \ += 1;\n            }\n            break;\n          }else{\n            t =\
    \ t->suffix_link;\n          }\n        }\n\n        node *next = t->children[s[i]];\n\
    \n        if(not next->suffix_link){\n          if(next->length == 1){\n     \
    \       next->suffix_link = even_root_;\n            even_root_->reverse_suffix_links.emplace_back(next);\n\
    \          }else{\n            node *p = cur;\n\n            while(1){\n     \
    \         if(p != t){\n                if(i - p->length - 1 >= 0 and s[i] == s[i\
    \ - p->length - 1]){\n                  next->suffix_link = p->children[s[i]];\n\
    \                  p->children[s[i]]->reverse_suffix_links.emplace_back(next);\n\
    \                  break;\n                }else{\n                  p = p->suffix_link;\n\
    \                }\n              }else{\n                p = p->suffix_link;\n\
    \              }\n            }\n          }\n        }\n\n        cur = next;\n\
    \      }\n    }\n\n    int size() const {\n      return size_;\n    }\n\n  private:\n\
    \    int longest_(node *t) const {\n      int ret = t->length;\n      for(auto\
    \ &p : t->children) ret = std::max(ret, longest_(p.second));\n      return ret;\n\
    \    }\n\n  public:\n    int longest() const {\n      int ret = std::max(longest_(odd_root_),\
    \ longest_(even_root_));\n      return ret;\n    }\n\n  private:\n    int count_sub_palindromes_(node\
    \ *t, int &c) const {\n      int ret = t->count;\n\n      for(auto &s : t->reverse_suffix_links){\n\
    \        ret += count_sub_palindromes_(s, c);\n      }\n\n      if(t != odd_root_\
    \ and t != even_root_) c += ret;\n\n      return ret;\n    }\n\n  public:\n  \
    \  int count_sub_palindromes() const {\n      int ret = 0;\n      count_sub_palindromes_(odd_root_,\
    \ ret);\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <map>\n#include <string>\n#include\
    \ <algorithm>\n#include <string_view>\n\nnamespace haar_lib {\n  class palindromic_tree\
    \ {\n    struct node {\n      int length;\n      int count;\n      std::map<char,\
    \ node*> children;\n      node *suffix_link;\n      std::vector<node*> reverse_suffix_links;\n\
    \    };\n\n    node *even_root_, *odd_root_;\n    int size_ = 2;\n\n  public:\n\
    \    palindromic_tree(){}\n    palindromic_tree(const std::string_view &s){\n\
    \      even_root_ = new node();\n      even_root_->length = 0;\n\n      odd_root_\
    \ = new node();\n      odd_root_->length = -1;\n\n      even_root_->suffix_link\
    \ = odd_root_;\n      odd_root_->reverse_suffix_links.emplace_back(even_root_);\n\
    \n      node *cur = odd_root_;\n\n      const int N = s.size();\n\n      for(int\
    \ i = 0; i < N; ++i){\n        node *t = cur;\n\n        while(1){\n         \
    \ if(i - t->length - 1 >= 0 and s[i] == s[i - t->length - 1]){\n            if(t->children.find(s[i])\
    \ == t->children.end()){\n              node *a = new node();\n              a->length\
    \ = t->length + 2;\n              a->count = 1;\n              t->children[s[i]]\
    \ = a;\n              ++size_;\n            }else{\n              t->children[s[i]]->count\
    \ += 1;\n            }\n            break;\n          }else{\n            t =\
    \ t->suffix_link;\n          }\n        }\n\n        node *next = t->children[s[i]];\n\
    \n        if(not next->suffix_link){\n          if(next->length == 1){\n     \
    \       next->suffix_link = even_root_;\n            even_root_->reverse_suffix_links.emplace_back(next);\n\
    \          }else{\n            node *p = cur;\n\n            while(1){\n     \
    \         if(p != t){\n                if(i - p->length - 1 >= 0 and s[i] == s[i\
    \ - p->length - 1]){\n                  next->suffix_link = p->children[s[i]];\n\
    \                  p->children[s[i]]->reverse_suffix_links.emplace_back(next);\n\
    \                  break;\n                }else{\n                  p = p->suffix_link;\n\
    \                }\n              }else{\n                p = p->suffix_link;\n\
    \              }\n            }\n          }\n        }\n\n        cur = next;\n\
    \      }\n    }\n\n    int size() const {\n      return size_;\n    }\n\n  private:\n\
    \    int longest_(node *t) const {\n      int ret = t->length;\n      for(auto\
    \ &p : t->children) ret = std::max(ret, longest_(p.second));\n      return ret;\n\
    \    }\n\n  public:\n    int longest() const {\n      int ret = std::max(longest_(odd_root_),\
    \ longest_(even_root_));\n      return ret;\n    }\n\n  private:\n    int count_sub_palindromes_(node\
    \ *t, int &c) const {\n      int ret = t->count;\n\n      for(auto &s : t->reverse_suffix_links){\n\
    \        ret += count_sub_palindromes_(s, c);\n      }\n\n      if(t != odd_root_\
    \ and t != even_root_) c += ret;\n\n      return ret;\n    }\n\n  public:\n  \
    \  int count_sub_palindromes() const {\n      int ret = 0;\n      count_sub_palindromes_(odd_root_,\
    \ ret);\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/palindromic_tree.cpp
  requiredBy: []
  timestamp: '2020-10-03 19:28:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/String/palindromic_tree.cpp
layout: document
title: Palindromic tree
---

## Operations

## Requirements

## Notes

## Problems

- [SPOJ LPS](https://www.spoj.com/problems/LPS/) (最長回文部分列)
- [SPOJ NUMOFPAL](https://www.spoj.com/problems/NUMOFPAL/) (回文部分列の個数)

## References
