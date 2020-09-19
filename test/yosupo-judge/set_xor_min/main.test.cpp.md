---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  - icon: ':x:'
    path: Mylib/DataStructure/Trie/binary_trie.cpp
    title: Binary trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo-judge/set_xor_min/main.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include <iostream>\n#line\
    \ 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n#include <tuple>\n#include\
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
    \ ...>(N);\n  }\n}\n#line 3 \"Mylib/DataStructure/Trie/binary_trie.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, unsigned int B>\n  class binary_trie {\n\
    \  protected:\n    struct node {\n      int count;\n      node *ch[2];\n     \
    \ node(): count(0){\n        ch[0] = ch[1] = nullptr;\n      }\n    };\n\n   \
    \ node *root = nullptr;\n\n  protected:\n    int count(node *t) const {return\
    \ t ? t->count : 0;}\n\n    int count(node *t, T val, unsigned int depth = 1)\
    \ const {\n      if(!t) return 0;\n\n      if(depth > B) return t->count;\n\n\
    \      int b = (val >> (B - depth)) & 1;\n      return count(t->ch[b], val, depth\
    \ + 1);\n    }\n\n  public:\n    int count(T val) const {\n      return count(root,\
    \ val);\n    }\n\n  public:\n    int size() const {return root ? root->count :\
    \ 0;}\n    bool empty() const {return !root;}\n\n  protected:\n    void to_list(node\
    \ *t, T val, std::vector<T> &ret) const {\n      if(!t) return;\n      if(!t->ch[0]\
    \ and !t->ch[1]) for(int i = 0; i < t->count; ++i) ret.push_back(val);\n\n   \
    \   if(t->ch[0]) to_list(t->ch[0], val << 1, ret);\n      if(t->ch[1]) to_list(t->ch[1],\
    \ (val << 1) | 1, ret);\n    }\n\n  public:\n    std::vector<T> to_list() const\
    \ {\n      std::vector<T> ret;\n      to_list(root, 0, ret);\n      return ret;\n\
    \    }\n\n  protected:\n    node* insert(node *t, T val, unsigned int depth =\
    \ 1){\n      if(!t) t = new node();\n\n      ++(t->count);\n      if(depth > B)\
    \ return t;\n\n      int b = (val >> (B - depth)) & 1;\n      t->ch[b] = insert(t->ch[b],\
    \ val, depth + 1);\n      return t;\n    }\n\n  public:\n    void insert(T val){\n\
    \      root = insert(root, val);\n    }\n\n  protected:\n    node* erase(node\
    \ *t, T val, unsigned int depth = 1){\n      if(!t) return t;\n\n      --(t->count);\n\
    \      if(t->count == 0) return nullptr;\n      if(depth > B) return t;\n\n  \
    \    int b = (val >> (B - depth)) & 1;\n      t->ch[b] = erase(t->ch[b], val,\
    \ depth + 1);\n      return t;\n    }\n\n  public:\n    void erase(T val){\n \
    \     root = erase(root, val);\n    }\n\n  protected:\n    T min_element(node\
    \ *t, T diff, unsigned int depth = 1) const {\n      if(depth > B) return 0;\n\
    \      int b = (diff >> (B - depth)) & 1;\n      b ^= !t->ch[b];\n      return\
    \ min_element(t->ch[b], diff, depth + 1) | (b << (B - depth));\n    }\n\n  public:\n\
    \    T min_element(T diff = 0) const {\n      return min_element(root, diff);\n\
    \    }\n\n  protected:\n    T max_element(node *t, T diff, unsigned int depth\
    \ = 1) const {\n      if(depth > B) return 0;\n      int b = !((diff >> (B - depth))\
    \ & 1);\n      b ^= !t->ch[b];\n      return max_element(t->ch[b], diff, depth\
    \ + 1) | (b << (B - depth));\n    }\n\n  public:\n    T max_element(T diff = 0)\
    \ const {\n      return max_element(root, diff);\n    }\n\n  protected:\n    T\
    \ at(node *t, int index, unsigned int depth = 1) const {\n      if(depth > B)\
    \ return 0;\n\n      int c = count(t->ch[0]);\n      if(t->ch[0] and index < c)\
    \ return at(t->ch[0], index, depth + 1);\n      else return at(t->ch[1], index\
    \ - c, depth + 1) | ((T)1 << (B - depth));\n    }\n\n  public:\n    T at(int index)\
    \ const {\n      return at(index);\n    }\n\n  protected:\n    int lower_bound(node\
    \ *t, T val, unsigned int depth = 1) const {\n      if(!t) return 0;\n      int\
    \ b = (val >> (B - depth)) & 1;\n      return (b ? count(t->ch[0]) : 0) + lower_bound(t->ch[b],\
    \ val, depth + 1);\n    }\n\n  public:\n    int lower_bound(T val) const {\n \
    \     return lower_bound(root, val);\n    }\n\n    int upper_bound(T val) const\
    \ {\n      return lower_bound(root, val + 1);\n    }\n  };\n}\n#line 6 \"test/yosupo-judge/set_xor_min/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int Q; std::cin >> Q;\n\n  hl::binary_trie<uint32_t, 32> t;\n\n  for(auto\
    \ [type, x] : hl::input_tuples<int, uint32_t>(Q)){\n    switch(type){\n    case\
    \ 0:\n      if(t.count(x) == 0) t.insert(x);\n      break;\n    case 1:\n    \
    \  if(t.count(x) == 1) t.erase(x);\n      break;\n    case 2:\n      std::cout\
    \ << (t.min_element(x) ^ x) << \"\\n\";\n      break;\n    }\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <iostream>\n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/DataStructure/Trie/binary_trie.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int Q; std::cin >> Q;\n\n  hl::binary_trie<uint32_t, 32> t;\n\n  for(auto\
    \ [type, x] : hl::input_tuples<int, uint32_t>(Q)){\n    switch(type){\n    case\
    \ 0:\n      if(t.count(x) == 0) t.insert(x);\n      break;\n    case 1:\n    \
    \  if(t.count(x) == 1) t.erase(x);\n      break;\n    case 2:\n      std::cout\
    \ << (t.min_element(x) ^ x) << \"\\n\";\n      break;\n    }\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/DataStructure/Trie/binary_trie.cpp
  isVerificationFile: true
  path: test/yosupo-judge/set_xor_min/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/set_xor_min/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/set_xor_min/main.test.cpp
- /verify/test/yosupo-judge/set_xor_min/main.test.cpp.html
title: test/yosupo-judge/set_xor_min/main.test.cpp
---
