---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/Heap/binary_heap.cpp
    title: Binary heap
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_9_C/main.binary.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\n\n#include\
    \ <iostream>\n#include <string>\n#line 2 \"Mylib/DataStructure/Heap/binary_heap.cpp\"\
    \n#include <vector>\n#include <functional>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare = std::less<T>>\n  class binary_heap\
    \ {\n    std::vector<T> data;\n\n    int left(int i) const {return i * 2 + 1;}\n\
    \    int right(int i) const {return i * 2 + 2;}\n    int parent(int i) const {return\
    \ (i - 1) >> 1;}\n\n    Compare compare;\n\n  public:\n    binary_heap(): compare(Compare()){}\n\
    \    binary_heap(size_t capacity): compare(Compare()){data.reserve(capacity);}\n\
    \n    void push(T value){\n      data.emplace_back(value);\n\n      int i = (int)data.size()\
    \ - 1;\n\n      while(i > 0){\n        int p = parent(i);\n        if(compare(data[i],\
    \ data[p])) break;\n        std::swap(data[i], data[p]);\n        i = p;\n   \
    \   }\n    }\n\n    T top() const {\n      return data.front();\n    }\n\n   \
    \ void pop(){\n      data.front() = data.back();\n      data.pop_back();\n\n \
    \     int i = 0;\n\n      while(1){\n        int l = left(i);\n        int r =\
    \ right(i);\n\n        if((int)data.size() <= l) break;\n        if((int)data.size()\
    \ <= r){\n          if(compare(data[l], data[i])) break;\n          std::swap(data[l],\
    \ data[i]);\n          i = l;\n        }else{\n          if(compare(data[l], data[i])\
    \ and compare(data[r], data[i])) break;\n          if(compare(data[r], data[l])){\n\
    \            std::swap(data[l], data[i]);\n            i = l;\n          }else{\n\
    \            std::swap(data[r], data[i]);\n            i = r;\n          }\n \
    \       }\n      }\n    }\n\n    bool empty() const {\n      return data.empty();\n\
    \    }\n\n    size_t size() const {\n      return data.size();\n    }\n  };\n\
    }\n#line 6 \"test/aoj/ALDS1_9_C/main.binary.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  hl::binary_heap<int> heap;\n  std::string s;\n\n  while(1){\n\
    \    std::cin >> s;\n\n    if(s == \"insert\"){\n      int k; std::cin >> k;\n\
    \      heap.push(k);\n    }else if(s == \"extract\"){\n      std::cout << heap.top()\
    \ << \"\\n\";\n      heap.pop();\n    }else{\n      break;\n    }\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/DataStructure/Heap/binary_heap.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  hl::binary_heap<int> heap;\n  std::string\
    \ s;\n\n  while(1){\n    std::cin >> s;\n\n    if(s == \"insert\"){\n      int\
    \ k; std::cin >> k;\n      heap.push(k);\n    }else if(s == \"extract\"){\n  \
    \    std::cout << heap.top() << \"\\n\";\n      heap.pop();\n    }else{\n    \
    \  break;\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/Heap/binary_heap.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_9_C/main.binary.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ALDS1_9_C/main.binary.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_9_C/main.binary.test.cpp
- /verify/test/aoj/ALDS1_9_C/main.binary.test.cpp.html
title: test/aoj/ALDS1_9_C/main.binary.test.cpp
---
