---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_11_B/main.asc.test.cpp
    title: test/aoj/ITP2_11_B/main.asc.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Bit/enumerate_supersets_asc.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename Func>\n  void enumerate_supersets_asc(int a, int n,\
    \ const Func &f){\n    for(int t = a; t < (1 << n); t = (t + 1) | a){\n      if(not\
    \ f(t)) break;\n    }\n  }\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Func>\n  void\
    \ enumerate_supersets_asc(int a, int n, const Func &f){\n    for(int t = a; t\
    \ < (1 << n); t = (t + 1) | a){\n      if(not f(t)) break;\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/enumerate_supersets_asc.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP2_11_B/main.asc.test.cpp
documentation_of: Mylib/Bit/enumerate_supersets_asc.cpp
layout: document
title: Enumerate supersets (Ascending order)
---

## Operations

- `for(int i : SupersetAsc(a, n)){...}`
	- 大きさ`n`の集合で`a`の上位集合であるものを昇順に列挙する。

## Requirements

## Notes

## Problems

## References

- [https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/](https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/)
- [https://jetbead.hatenablog.com/entry/20121202/1354406422](https://jetbead.hatenablog.com/entry/20121202/1354406422)
- [https://ark4rk.hatenablog.com/entry/2018/03/07/230257](https://ark4rk.hatenablog.com/entry/2018/03/07/230257)
- [https://primenumber.hatenadiary.jp/entry/2016/12/01/000000](https://primenumber.hatenadiary.jp/entry/2016/12/01/000000)
