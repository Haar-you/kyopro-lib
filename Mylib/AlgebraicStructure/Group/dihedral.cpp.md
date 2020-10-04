---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0390/main.test.cpp
    title: test/aoj/0390/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Group/dihedral.cpp\"\n#include\
    \ <iostream>\n#include <variant>\n\nnamespace haar_lib {\n  namespace dihedral_group_impl\
    \ {\n    struct R {\n      int value = 0;\n      friend std::ostream& operator<<(std::ostream\
    \ &s, const R &a){\n        s << \"R(\" << a.value << \")\";\n        return s;\n\
    \      }\n      R(){}\n      R(int value): value(value){}\n    };\n\n    struct\
    \ S {\n      int value = 0;\n      friend std::ostream& operator<<(std::ostream\
    \ &s, const S &a){\n        s << \"S(\" << a.value << \")\";\n        return s;\n\
    \      }\n      S(){}\n      S(int value): value(value){}\n    };\n  }\n\n  template\
    \ <const int &K>\n  struct dihedral_group {\n    using R = dihedral_group_impl::R;\n\
    \    using S = dihedral_group_impl::S;\n    using value_type = std::variant<R,\
    \ S>;\n\n    value_type operator()() const {\n      return R(0);\n    }\n\n  \
    \  value_type operator()(const value_type &a, const value_type &b) const {\n \
    \     if(std::holds_alternative<R>(a)){\n        if(std::holds_alternative<R>(b)){\n\
    \          return R((std::get<R>(a).value + std::get<R>(b).value) % K);\n    \
    \    }else{\n          return S((std::get<S>(b).value - std::get<R>(a).value +\
    \ K) % K);\n        }\n      }else{\n        if(std::holds_alternative<R>(b)){\n\
    \          return S((std::get<S>(a).value + std::get<R>(b).value) % K);\n    \
    \    }else{\n          return R((std::get<S>(b).value - std::get<S>(a).value +\
    \ K) % K);\n        }\n      }\n    }\n\n    value_type inv(const value_type &a)\
    \ const {\n      if(std::holds_alternative<R>(a)){\n        const int i = std::get<R>(a).value;\n\
    \        return R(i == 0 ? 0 : K - i);\n      }else{\n        return a;\n    \
    \  }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <variant>\n\nnamespace haar_lib\
    \ {\n  namespace dihedral_group_impl {\n    struct R {\n      int value = 0;\n\
    \      friend std::ostream& operator<<(std::ostream &s, const R &a){\n       \
    \ s << \"R(\" << a.value << \")\";\n        return s;\n      }\n      R(){}\n\
    \      R(int value): value(value){}\n    };\n\n    struct S {\n      int value\
    \ = 0;\n      friend std::ostream& operator<<(std::ostream &s, const S &a){\n\
    \        s << \"S(\" << a.value << \")\";\n        return s;\n      }\n      S(){}\n\
    \      S(int value): value(value){}\n    };\n  }\n\n  template <const int &K>\n\
    \  struct dihedral_group {\n    using R = dihedral_group_impl::R;\n    using S\
    \ = dihedral_group_impl::S;\n    using value_type = std::variant<R, S>;\n\n  \
    \  value_type operator()() const {\n      return R(0);\n    }\n\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {\n      if(std::holds_alternative<R>(a)){\n\
    \        if(std::holds_alternative<R>(b)){\n          return R((std::get<R>(a).value\
    \ + std::get<R>(b).value) % K);\n        }else{\n          return S((std::get<S>(b).value\
    \ - std::get<R>(a).value + K) % K);\n        }\n      }else{\n        if(std::holds_alternative<R>(b)){\n\
    \          return S((std::get<S>(a).value + std::get<R>(b).value) % K);\n    \
    \    }else{\n          return R((std::get<S>(b).value - std::get<S>(a).value +\
    \ K) % K);\n        }\n      }\n    }\n\n    value_type inv(const value_type &a)\
    \ const {\n      if(std::holds_alternative<R>(a)){\n        const int i = std::get<R>(a).value;\n\
    \        return R(i == 0 ? 0 : K - i);\n      }else{\n        return a;\n    \
    \  }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Group/dihedral.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0390/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Group/dihedral.cpp
layout: document
title: Dihedral group
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://en.wikipedia.org/wiki/Dihedral_group](https://en.wikipedia.org/wiki/Dihedral_group)
