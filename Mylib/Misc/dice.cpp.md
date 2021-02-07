---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0502/main.test.cpp
    title: test/aoj/0502/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Misc/dice.cpp\"\n#include <iostream>\n\nnamespace\
    \ haar_lib {\n  struct dice {\n    int top, bottom, front, back, right, left;\n\
    \n    dice(): top(), bottom(), front(), back(), right(), left(){}\n    dice(int\
    \ top, int bottom, int front, int back, int right, int left):\n      top(top),\
    \ bottom(bottom), front(front), back(back), right(right), left(left){}\n\n   \
    \ dice rot_left() const {\n      return dice(right, left, front, back, bottom,\
    \ top);\n    }\n\n    dice rot_right() const {\n      return dice(left, right,\
    \ front, back, top, bottom);\n    }\n\n    dice rot_front() const {\n      return\
    \ dice(back, front, top, bottom, right, left);\n    }\n\n    dice rot_back() const\
    \ {\n      return dice(front, back, bottom, top, right, left);\n    }\n\n    dice\
    \ rot_clockwise() const {\n      return dice(top, bottom, right, left, back, front);\n\
    \    }\n\n    dice rot_counterclockwise() const {\n      return dice(top, bottom,\
    \ left, right, front, back);\n    }\n\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const dice &a){\n      s << \"(\"\n        << a.top << \", \"\n        <<\
    \ a.bottom << \", \"\n        << a.front << \", \"\n        << a.back << \", \"\
    \n        << a.right << \", \"\n        << a.left << \")\";\n      return s;\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <iostream>\n\nnamespace haar_lib {\n  struct dice\
    \ {\n    int top, bottom, front, back, right, left;\n\n    dice(): top(), bottom(),\
    \ front(), back(), right(), left(){}\n    dice(int top, int bottom, int front,\
    \ int back, int right, int left):\n      top(top), bottom(bottom), front(front),\
    \ back(back), right(right), left(left){}\n\n    dice rot_left() const {\n    \
    \  return dice(right, left, front, back, bottom, top);\n    }\n\n    dice rot_right()\
    \ const {\n      return dice(left, right, front, back, top, bottom);\n    }\n\n\
    \    dice rot_front() const {\n      return dice(back, front, top, bottom, right,\
    \ left);\n    }\n\n    dice rot_back() const {\n      return dice(front, back,\
    \ bottom, top, right, left);\n    }\n\n    dice rot_clockwise() const {\n    \
    \  return dice(top, bottom, right, left, back, front);\n    }\n\n    dice rot_counterclockwise()\
    \ const {\n      return dice(top, bottom, left, right, front, back);\n    }\n\n\
    \    friend std::ostream& operator<<(std::ostream &s, const dice &a){\n      s\
    \ << \"(\"\n        << a.top << \", \"\n        << a.bottom << \", \"\n      \
    \  << a.front << \", \"\n        << a.back << \", \"\n        << a.right << \"\
    , \"\n        << a.left << \")\";\n      return s;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/dice.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0502/main.test.cpp
documentation_of: Mylib/Misc/dice.cpp
layout: document
title: Dice
---

## Operations

## Requirements

## Notes

## Problems

## References
