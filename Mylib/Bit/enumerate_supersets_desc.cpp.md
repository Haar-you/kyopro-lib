---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_11_B/main.desc.test.cpp
    title: test/aoj/ITP2_11_B/main.desc.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Bit/enumerate_supersets_desc.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename Func>\n  void enumerate_supersets_desc(int a, int n,\
    \ const Func &f){\n    const int x = (1 << n) - 1, y = x ^ (a & x);\n    for(int\
    \ t = y; ; t = (t - 1) & y){\n      if(not f(t | a)) break;\n      if(t == 0)\
    \ break;\n    }\n  }\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Func>\n  void\
    \ enumerate_supersets_desc(int a, int n, const Func &f){\n    const int x = (1\
    \ << n) - 1, y = x ^ (a & x);\n    for(int t = y; ; t = (t - 1) & y){\n      if(not\
    \ f(t | a)) break;\n      if(t == 0) break;\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/enumerate_supersets_desc.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP2_11_B/main.desc.test.cpp
documentation_of: Mylib/Bit/enumerate_supersets_desc.cpp
layout: document
title: Enumerate supersets (Descending order)
---

## Operations

- `for(int i : SupersetDesc(a, n)){...}`
	- 大きさ`n`の集合で`a`の上位集合であるものを降順に列挙する。

## Requirements

## Notes

## Problems

## References

- [https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/](https://kimiyuki.net/blog/2017/07/16/enumerate-sets-with-bit-manipulation/)
- [https://jetbead.hatenablog.com/entry/20121202/1354406422](https://jetbead.hatenablog.com/entry/20121202/1354406422)
- [https://ark4rk.hatenablog.com/entry/2018/03/07/230257](https://ark4rk.hatenablog.com/entry/2018/03/07/230257)
- [https://primenumber.hatenadiary.jp/entry/2016/12/01/000000](https://primenumber.hatenadiary.jp/entry/2016/12/01/000000)
