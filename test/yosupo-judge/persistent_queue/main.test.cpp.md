---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/Queue/persistent_queue.cpp
    title: Persistent queue
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/yosupo-judge/persistent_queue/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n#include <iostream>\n\
    #include <vector>\n#line 2 \"Mylib/DataStructure/Queue/persistent_queue.cpp\"\n\
    #include <array>\n#line 5 \"Mylib/DataStructure/Queue/persistent_queue.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  class persistent_queue {\n\
    \  public:\n    using value_type = T;\n\n  private:\n    constexpr static int\
    \ MAX_SIZE_2 = 20; // size <= 2 ^ MAX_SIZE_2\n\n    struct node {\n      T value;\n\
    \      std::array<node*, MAX_SIZE_2> ancestors;\n      int depth = 0;\n    };\n\
    \n    node *front_node_ = nullptr, *back_node_ = nullptr;\n\n    persistent_queue(node*\
    \ front_node, node* back_node):\n      front_node_(front_node), back_node_(back_node){}\n\
    \n  public:\n    persistent_queue(){}\n    persistent_queue(const T &value){\n\
    \      node *t = new node();\n      t->value = value;\n      back_node_ = front_node_\
    \ = t;\n    }\n\n    persistent_queue push(const T &value) const {\n      node\
    \ *t = new node();\n\n      t->value = value;\n\n      t->ancestors[0] = back_node_;\n\
    \      for(int i = 1; i < MAX_SIZE_2; ++i){\n        node *s = t->ancestors[i\
    \ - 1];\n        if(s) t->ancestors[i] = s->ancestors[i - 1];\n        else break;\n\
    \      }\n\n      t->depth = back_node_ ? back_node_->depth + 1 : 0;\n\n     \
    \ return persistent_queue(front_node_ ? front_node_ : t, t);\n    }\n\n    persistent_queue\
    \ pop() const {\n      if(back_node_->depth == front_node_->depth){\n        return\
    \ persistent_queue(nullptr, nullptr);\n      }\n\n      int d = back_node_->depth\
    \ - front_node_->depth - 1;\n\n      node *t = back_node_;\n\n      for(int i\
    \ = MAX_SIZE_2 - 1; i >= 0; --i){\n        if(d >= (1 << i)){\n          d -=\
    \ (1 << i);\n          t = t->ancestors[i];\n        }\n        if(d == 0) break;\n\
    \      }\n\n      return persistent_queue(t, back_node_);\n    }\n\n    T front()\
    \ const {\n      return front_node_->value;\n    }\n\n    T back() const {\n \
    \     return back_node_->value;\n    }\n\n    bool empty() const {\n      return\
    \ not front_node_;\n    }\n\n    int size() const {\n      return front_node_\
    \ ? back_node_->depth - front_node_->depth + 1 : 0;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream &s, const persistent_queue &a){\n      s << \"{\";\n\
    \      std::vector<T> temp;\n      node *t = a.back_node_;\n      while(t){\n\
    \        if(t == a.front_node_){\n          temp.push_back(t->value);\n      \
    \    break;\n        }\n        temp.push_back(t->value);\n        t = t->ancestors[0];\n\
    \      }\n\n      for(auto it = temp.begin(); it != temp.end(); ++it){\n     \
    \   if(it != temp.begin()) s << \", \";\n        s << *it;\n      }\n\n      s\
    \ << \"}\";\n      return s;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#include <utility>\n#include <initializer_list>\n#line 6 \"\
    Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename T, size_t\
    \ ... I>\n  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)\
    \ ...};\n  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
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
    \ ...>(N);\n  }\n}\n#line 7 \"test/yosupo-judge/persistent_queue/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int Q; std::cin >> Q;\n\n  std::vector<hl::persistent_queue<int>>\
    \ S;\n\n  for(auto [type, t] : hl::input_tuples<int, int>(Q)){\n    if(type ==\
    \ 0){\n      int x; std::cin >> x;\n      if(t == -1){\n        hl::persistent_queue<int>\
    \ a(x);\n        S.push_back(a);\n      }else{\n        auto res = S[t].push(x);\n\
    \        S.push_back(res);\n      }\n    }else{\n      std::cout << S[t].front()\
    \ << std::endl;\n      auto res = S[t].pop();\n      S.push_back(res);\n    }\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"Mylib/DataStructure/Queue/persistent_queue.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int Q; std::cin >> Q;\n\n  std::vector<hl::persistent_queue<int>> S;\n\n  for(auto\
    \ [type, t] : hl::input_tuples<int, int>(Q)){\n    if(type == 0){\n      int x;\
    \ std::cin >> x;\n      if(t == -1){\n        hl::persistent_queue<int> a(x);\n\
    \        S.push_back(a);\n      }else{\n        auto res = S[t].push(x);\n   \
    \     S.push_back(res);\n      }\n    }else{\n      std::cout << S[t].front()\
    \ << std::endl;\n      auto res = S[t].pop();\n      S.push_back(res);\n    }\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/Queue/persistent_queue.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/persistent_queue/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/persistent_queue/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/persistent_queue/main.test.cpp
- /verify/test/yosupo-judge/persistent_queue/main.test.cpp.html
title: test/yosupo-judge/persistent_queue/main.test.cpp
---
