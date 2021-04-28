---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Mylib/Debug/debug.cpp\"\n#include <array>\n#include <complex>\n\
    #include <deque>\n#include <forward_list>\n#include <initializer_list>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <list>\n#include <map>\n#include <optional>\n\
    #include <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <variant>\n#include <vector>\n\
    \ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream&, std::vector<T,\
    \ Allocator>);\n\ntemplate <class T, std::size_t N>\nvoid debug_print(std::ostream&,\
    \ std::array<T, N>);\n\ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream&,\
    \ std::deque<T, Allocator>);\n\ntemplate <class T, class Container>\nvoid debug_print(std::ostream&,\
    \ std::stack<T, Container>);\n\ntemplate <class T, class Container>\nvoid debug_print(std::ostream&,\
    \ std::queue<T, Container>);\n\ntemplate <class T, class Container, class Compare>\n\
    void debug_print(std::ostream&, std::priority_queue<T, Container, Compare>);\n\
    \ntemplate <class Key, class Compare, class Allocator>\nvoid debug_print(std::ostream&,\
    \ std::set<Key, Compare, Allocator>);\n\ntemplate <class Key, class Hash, class\
    \ Pred, class Allocator>\nvoid debug_print(std::ostream&, std::unordered_set<Key,\
    \ Hash, Pred, Allocator>);\n\ntemplate <class Key, class T, class Compare, class\
    \ Allocator>\nvoid debug_print(std::ostream&, std::map<Key, T, Compare, Allocator>);\n\
    \ntemplate <class Key, class T, class Hash, class Pred, class Allocator>\nvoid\
    \ debug_print(std::ostream&, std::unordered_map<Key, T, Hash, Pred, Allocator>);\n\
    \ntemplate <class T1, class T2>\nvoid debug_print(std::ostream&, std::pair<T1,\
    \ T2>);\n\ntemplate <class... Args>\nvoid debug_print(std::ostream&, std::tuple<Args...>);\n\
    \ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream&, std::list<T,\
    \ Allocator>);\n\ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream&,\
    \ std::forward_list<T, Allocator>);\n\ntemplate <class Key, class Compare, class\
    \ Allocator>\nvoid debug_print(std::ostream&, std::multiset<Key, Compare, Allocator>);\n\
    \ntemplate <class Key, class Hash, class Pred, class Allocator>\nvoid debug_print(std::ostream&,\
    \ std::unordered_multiset<Key, Hash, Pred, Allocator>);\n\ntemplate <class Key,\
    \ class T, class Compare, class Allocator>\nvoid debug_print(std::ostream&, std::multimap<Key,\
    \ T, Compare, Allocator>);\n\ntemplate <class Key, class T, class Hash, class\
    \ Pred, class Allocator>\nvoid debug_print(std::ostream&, std::unordered_multimap<Key,\
    \ T, Hash, Pred, Allocator>);\n\ntemplate <class T>\nvoid debug_print(std::ostream&,\
    \ std::complex<T>);\n\ntemplate <class T>\nvoid debug_print(std::ostream&, std::optional<T>);\n\
    \ntemplate <class... Types>\nvoid debug_print(std::ostream&, std::variant<Types...>);\n\
    \nvoid debug_print(std::ostream&, bool);\nvoid debug_print(std::ostream&, int);\n\
    void debug_print(std::ostream&, double);\nvoid debug_print(std::ostream&, std::string);\n\
    void debug_print(std::ostream&, char);\n\ntemplate <size_t N>\nvoid debug_print(std::ostream&,\
    \ const char (&)[N]);\n\ntemplate <typename T, size_t N>\nvoid debug_print(std::ostream&,\
    \ const T (&)[N]);\n\ntemplate <typename T>\nvoid debug_print(std::ostream&, T);\n\
    \n#define dump(...) dump_(__LINE__, #__VA_ARGS__, __VA_ARGS__)\n\ntemplate <class\
    \ T>\nvoid dump_helper(int line, T value) {\n  std::cerr << \"[\\e[1;33mL\" <<\
    \ std::setw(3) << line << \"\\e[m] \";\n  std::cerr << \"\\e[1;32m\";\n  debug_print(std::cerr,\
    \ value);\n  std::cerr << \"\\e[m\" << std::endl;\n}\n\ntemplate <class... Args>\n\
    void dump_(int line, std::string names, Args&&... args) {\n  std::cerr << \"[\\\
    e[1m====\\e[m] \\e[1m\" << names << \"\\e[m\"\n            << \"\\n\";\n  (void)\
    \ std::initializer_list<int>{(void(dump_helper(line, args)), 0)...};\n}\n\ntemplate\
    \ <typename Iter>\nvoid dump_container(std::ostream& s, Iter first, Iter last)\
    \ {\n  s << \"{\";\n  for (auto it = first; it != last; ++it) {\n    if (it !=\
    \ first) s << \",\";\n    debug_print(s, *it);\n  }\n  s << \"}\";\n}\n\n// vector\n\
    template <class T, class Allocator>\nvoid debug_print(std::ostream& s, std::vector<T,\
    \ Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n}\n\n// array\n\
    template <class T, std::size_t N>\nvoid debug_print(std::ostream& s, std::array<T,\
    \ N> val) {\n  dump_container(s, val.begin(), val.end());\n}\n\n// deque\ntemplate\
    \ <class T, class Allocator>\nvoid debug_print(std::ostream& s, std::deque<T,\
    \ Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n}\n\n// stack\n\
    template <class T, class Container>\nvoid debug_print(std::ostream& s, std::stack<T,\
    \ Container> val) {\n  int N = val.size();\n\n  s << \"{\";\n  for (int i = 0;\
    \ i < N; ++i) {\n    if (i) s << \",\";\n    auto x = val.top();\n    val.pop();\n\
    \    debug_print(s, x);\n  }\n  s << \"}\";\n}\n\n// queue\ntemplate <class T,\
    \ class Container>\nvoid debug_print(std::ostream& s, std::queue<T, Container>\
    \ val) {\n  int N = val.size();\n\n  s << \"{\";\n  for (int i = 0; i < N; ++i)\
    \ {\n    if (i) s << \",\";\n    auto x = val.front();\n    val.pop();\n    debug_print(s,\
    \ x);\n  }\n  s << \"}\";\n}\n\n// priority_queue\ntemplate <class T, class Container,\
    \ class Compare>\nvoid debug_print(std::ostream& s, std::priority_queue<T, Container,\
    \ Compare> val) {\n  int N = val.size();\n\n  s << \"{\";\n  for (int i = 0; i\
    \ < N; ++i) {\n    if (i) s << \",\";\n    auto x = val.top();\n    val.pop();\n\
    \    debug_print(s, x);\n  }\n  s << \"}\";\n}\n\n// set\ntemplate <class Key,\
    \ class Compare, class Allocator>\nvoid debug_print(std::ostream& s, std::set<Key,\
    \ Compare, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n}\n\
    \n// unrodered_set\ntemplate <class Key, class Hash, class Pred, class Allocator>\n\
    void debug_print(std::ostream& s, std::unordered_set<Key, Hash, Pred, Allocator>\
    \ val) {\n  dump_container(s, val.begin(), val.end());\n}\n\n// map\ntemplate\
    \ <class Key, class T, class Compare, class Allocator>\nvoid debug_print(std::ostream&\
    \ s, std::map<Key, T, Compare, Allocator> val) {\n  dump_container(s, val.begin(),\
    \ val.end());\n}\n\n// unordered_map\ntemplate <class Key, class T, class Hash,\
    \ class Pred, class Allocator>\nvoid debug_print(std::ostream& s, std::unordered_map<Key,\
    \ T, Hash, Pred, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n\
    }\n\n// pair\ntemplate <class T1, class T2>\nvoid debug_print(std::ostream& s,\
    \ std::pair<T1, T2> val) {\n  s << \"(\";\n  debug_print(s, val.first);\n  s <<\
    \ \",\";\n  debug_print(s, val.second);\n  s << \")\";\n}\n\n// tuple\ntemplate\
    \ <size_t I, class... Args>\nvoid tuple_dump_helper(std::ostream& s, std::tuple<Args...>\
    \ val) {\n  if constexpr (I == 1) {\n    debug_print(s, std::get<0>(val));\n \
    \ } else {\n    tuple_dump_helper<I - 1, Args...>(s, val);\n    s << \",\";\n\
    \    debug_print(s, std::get<I - 1>(val));\n  }\n}\n\ntemplate <class... Args>\n\
    void debug_print(std::ostream& s, std::tuple<Args...> val) {\n  s << \"(\";\n\
    \  tuple_dump_helper<sizeof...(Args), Args...>(s, val);\n  s << \")\";\n}\n\n\
    // list\ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream& s,\
    \ std::list<T, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n\
    }\n\n// forward_list\ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream&\
    \ s, std::forward_list<T, Allocator> val) {\n  dump_container(s, val.begin(),\
    \ val.end());\n}\n\n// multiset\ntemplate <class Key, class Compare, class Allocator>\n\
    void debug_print(std::ostream& s, std::multiset<Key, Compare, Allocator> val)\
    \ {\n  dump_container(s, val.begin(), val.end());\n}\n\n// unordered_multiset\n\
    template <class Key, class Hash, class Pred, class Allocator>\nvoid debug_print(std::ostream&\
    \ s, std::unordered_multiset<Key, Hash, Pred, Allocator> val) {\n  dump_container(s,\
    \ val.begin(), val.end());\n}\n\n// multimap\ntemplate <class Key, class T, class\
    \ Compare, class Allocator>\nvoid debug_print(std::ostream& s, std::multimap<Key,\
    \ T, Compare, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n\
    }\n\n// unordered_multimap\ntemplate <class Key, class T, class Hash, class Pred,\
    \ class Allocator>\nvoid debug_print(std::ostream& s, std::unordered_multimap<Key,\
    \ T, Hash, Pred, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n\
    }\n\n// complex number\ntemplate <class T>\nvoid debug_print(std::ostream& s,\
    \ std::complex<T> val) {\n  s << val.real() << (val.imag() < 0 ? \"\" : \"+\"\
    ) << val.imag() << \"i\";\n}\n\n// optional\ntemplate <class T>\nvoid debug_print(std::ostream&\
    \ s, std::optional<T> val) {\n  s << \"{\";\n  if (val.has_value()) {\n    debug_print(s,\
    \ val.value());\n  }\n  s << \"}\";\n}\n\n// variant\ntemplate <class... Types>\n\
    void debug_print(std::ostream& s, std::variant<Types...> val) {\n  std::visit([&s](const\
    \ auto& x) { debug_print(s, x); }, val);\n}\n\n// others\nvoid debug_print(std::ostream&\
    \ s, bool val) {\n  if (val) {\n    s << \"true\";\n  } else {\n    s << \"false\"\
    ;\n  }\n}\n\nvoid debug_print(std::ostream& s, int val) {\n  s << val;\n}\n\n\
    void debug_print(std::ostream& s, double val) {\n  s << val;\n}\n\nvoid debug_print(std::ostream&\
    \ s, std::string val) {\n  s << \"\\\"\" << val << \"\\\"\";\n}\n\nvoid debug_print(std::ostream&\
    \ s, char val) {\n  s << \"'\" << val << \"'\";\n}\n\n// array\n\ntemplate <size_t\
    \ N>\nvoid debug_print(std::ostream& s, const char (&val)[N]) {\n  s << \"\\\"\
    \" << val << \"\\\"\";\n}\n\ntemplate <typename T, size_t N>\nvoid debug_print(std::ostream&\
    \ s, const T val[N]) {\n  s << \"{\";\n  for (int i = 0; i < (int) N; ++i) {\n\
    \    if (i) s << \",\";\n    debug_print(s, val[i]);\n  }\n  s << \"}\";\n}\n\n\
    template <typename T>\nvoid debug_print(std::ostream& s, T val) {\n  s << val;\n\
    }\n"
  code: "#include <array>\n#include <complex>\n#include <deque>\n#include <forward_list>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <iostream>\n#include\
    \ <list>\n#include <map>\n#include <optional>\n#include <queue>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <variant>\n#include <vector>\n\ntemplate <class T, class Allocator>\n\
    void debug_print(std::ostream&, std::vector<T, Allocator>);\n\ntemplate <class\
    \ T, std::size_t N>\nvoid debug_print(std::ostream&, std::array<T, N>);\n\ntemplate\
    \ <class T, class Allocator>\nvoid debug_print(std::ostream&, std::deque<T, Allocator>);\n\
    \ntemplate <class T, class Container>\nvoid debug_print(std::ostream&, std::stack<T,\
    \ Container>);\n\ntemplate <class T, class Container>\nvoid debug_print(std::ostream&,\
    \ std::queue<T, Container>);\n\ntemplate <class T, class Container, class Compare>\n\
    void debug_print(std::ostream&, std::priority_queue<T, Container, Compare>);\n\
    \ntemplate <class Key, class Compare, class Allocator>\nvoid debug_print(std::ostream&,\
    \ std::set<Key, Compare, Allocator>);\n\ntemplate <class Key, class Hash, class\
    \ Pred, class Allocator>\nvoid debug_print(std::ostream&, std::unordered_set<Key,\
    \ Hash, Pred, Allocator>);\n\ntemplate <class Key, class T, class Compare, class\
    \ Allocator>\nvoid debug_print(std::ostream&, std::map<Key, T, Compare, Allocator>);\n\
    \ntemplate <class Key, class T, class Hash, class Pred, class Allocator>\nvoid\
    \ debug_print(std::ostream&, std::unordered_map<Key, T, Hash, Pred, Allocator>);\n\
    \ntemplate <class T1, class T2>\nvoid debug_print(std::ostream&, std::pair<T1,\
    \ T2>);\n\ntemplate <class... Args>\nvoid debug_print(std::ostream&, std::tuple<Args...>);\n\
    \ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream&, std::list<T,\
    \ Allocator>);\n\ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream&,\
    \ std::forward_list<T, Allocator>);\n\ntemplate <class Key, class Compare, class\
    \ Allocator>\nvoid debug_print(std::ostream&, std::multiset<Key, Compare, Allocator>);\n\
    \ntemplate <class Key, class Hash, class Pred, class Allocator>\nvoid debug_print(std::ostream&,\
    \ std::unordered_multiset<Key, Hash, Pred, Allocator>);\n\ntemplate <class Key,\
    \ class T, class Compare, class Allocator>\nvoid debug_print(std::ostream&, std::multimap<Key,\
    \ T, Compare, Allocator>);\n\ntemplate <class Key, class T, class Hash, class\
    \ Pred, class Allocator>\nvoid debug_print(std::ostream&, std::unordered_multimap<Key,\
    \ T, Hash, Pred, Allocator>);\n\ntemplate <class T>\nvoid debug_print(std::ostream&,\
    \ std::complex<T>);\n\ntemplate <class T>\nvoid debug_print(std::ostream&, std::optional<T>);\n\
    \ntemplate <class... Types>\nvoid debug_print(std::ostream&, std::variant<Types...>);\n\
    \nvoid debug_print(std::ostream&, bool);\nvoid debug_print(std::ostream&, int);\n\
    void debug_print(std::ostream&, double);\nvoid debug_print(std::ostream&, std::string);\n\
    void debug_print(std::ostream&, char);\n\ntemplate <size_t N>\nvoid debug_print(std::ostream&,\
    \ const char (&)[N]);\n\ntemplate <typename T, size_t N>\nvoid debug_print(std::ostream&,\
    \ const T (&)[N]);\n\ntemplate <typename T>\nvoid debug_print(std::ostream&, T);\n\
    \n#define dump(...) dump_(__LINE__, #__VA_ARGS__, __VA_ARGS__)\n\ntemplate <class\
    \ T>\nvoid dump_helper(int line, T value) {\n  std::cerr << \"[\\e[1;33mL\" <<\
    \ std::setw(3) << line << \"\\e[m] \";\n  std::cerr << \"\\e[1;32m\";\n  debug_print(std::cerr,\
    \ value);\n  std::cerr << \"\\e[m\" << std::endl;\n}\n\ntemplate <class... Args>\n\
    void dump_(int line, std::string names, Args&&... args) {\n  std::cerr << \"[\\\
    e[1m====\\e[m] \\e[1m\" << names << \"\\e[m\"\n            << \"\\n\";\n  (void)\
    \ std::initializer_list<int>{(void(dump_helper(line, args)), 0)...};\n}\n\ntemplate\
    \ <typename Iter>\nvoid dump_container(std::ostream& s, Iter first, Iter last)\
    \ {\n  s << \"{\";\n  for (auto it = first; it != last; ++it) {\n    if (it !=\
    \ first) s << \",\";\n    debug_print(s, *it);\n  }\n  s << \"}\";\n}\n\n// vector\n\
    template <class T, class Allocator>\nvoid debug_print(std::ostream& s, std::vector<T,\
    \ Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n}\n\n// array\n\
    template <class T, std::size_t N>\nvoid debug_print(std::ostream& s, std::array<T,\
    \ N> val) {\n  dump_container(s, val.begin(), val.end());\n}\n\n// deque\ntemplate\
    \ <class T, class Allocator>\nvoid debug_print(std::ostream& s, std::deque<T,\
    \ Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n}\n\n// stack\n\
    template <class T, class Container>\nvoid debug_print(std::ostream& s, std::stack<T,\
    \ Container> val) {\n  int N = val.size();\n\n  s << \"{\";\n  for (int i = 0;\
    \ i < N; ++i) {\n    if (i) s << \",\";\n    auto x = val.top();\n    val.pop();\n\
    \    debug_print(s, x);\n  }\n  s << \"}\";\n}\n\n// queue\ntemplate <class T,\
    \ class Container>\nvoid debug_print(std::ostream& s, std::queue<T, Container>\
    \ val) {\n  int N = val.size();\n\n  s << \"{\";\n  for (int i = 0; i < N; ++i)\
    \ {\n    if (i) s << \",\";\n    auto x = val.front();\n    val.pop();\n    debug_print(s,\
    \ x);\n  }\n  s << \"}\";\n}\n\n// priority_queue\ntemplate <class T, class Container,\
    \ class Compare>\nvoid debug_print(std::ostream& s, std::priority_queue<T, Container,\
    \ Compare> val) {\n  int N = val.size();\n\n  s << \"{\";\n  for (int i = 0; i\
    \ < N; ++i) {\n    if (i) s << \",\";\n    auto x = val.top();\n    val.pop();\n\
    \    debug_print(s, x);\n  }\n  s << \"}\";\n}\n\n// set\ntemplate <class Key,\
    \ class Compare, class Allocator>\nvoid debug_print(std::ostream& s, std::set<Key,\
    \ Compare, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n}\n\
    \n// unrodered_set\ntemplate <class Key, class Hash, class Pred, class Allocator>\n\
    void debug_print(std::ostream& s, std::unordered_set<Key, Hash, Pred, Allocator>\
    \ val) {\n  dump_container(s, val.begin(), val.end());\n}\n\n// map\ntemplate\
    \ <class Key, class T, class Compare, class Allocator>\nvoid debug_print(std::ostream&\
    \ s, std::map<Key, T, Compare, Allocator> val) {\n  dump_container(s, val.begin(),\
    \ val.end());\n}\n\n// unordered_map\ntemplate <class Key, class T, class Hash,\
    \ class Pred, class Allocator>\nvoid debug_print(std::ostream& s, std::unordered_map<Key,\
    \ T, Hash, Pred, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n\
    }\n\n// pair\ntemplate <class T1, class T2>\nvoid debug_print(std::ostream& s,\
    \ std::pair<T1, T2> val) {\n  s << \"(\";\n  debug_print(s, val.first);\n  s <<\
    \ \",\";\n  debug_print(s, val.second);\n  s << \")\";\n}\n\n// tuple\ntemplate\
    \ <size_t I, class... Args>\nvoid tuple_dump_helper(std::ostream& s, std::tuple<Args...>\
    \ val) {\n  if constexpr (I == 1) {\n    debug_print(s, std::get<0>(val));\n \
    \ } else {\n    tuple_dump_helper<I - 1, Args...>(s, val);\n    s << \",\";\n\
    \    debug_print(s, std::get<I - 1>(val));\n  }\n}\n\ntemplate <class... Args>\n\
    void debug_print(std::ostream& s, std::tuple<Args...> val) {\n  s << \"(\";\n\
    \  tuple_dump_helper<sizeof...(Args), Args...>(s, val);\n  s << \")\";\n}\n\n\
    // list\ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream& s,\
    \ std::list<T, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n\
    }\n\n// forward_list\ntemplate <class T, class Allocator>\nvoid debug_print(std::ostream&\
    \ s, std::forward_list<T, Allocator> val) {\n  dump_container(s, val.begin(),\
    \ val.end());\n}\n\n// multiset\ntemplate <class Key, class Compare, class Allocator>\n\
    void debug_print(std::ostream& s, std::multiset<Key, Compare, Allocator> val)\
    \ {\n  dump_container(s, val.begin(), val.end());\n}\n\n// unordered_multiset\n\
    template <class Key, class Hash, class Pred, class Allocator>\nvoid debug_print(std::ostream&\
    \ s, std::unordered_multiset<Key, Hash, Pred, Allocator> val) {\n  dump_container(s,\
    \ val.begin(), val.end());\n}\n\n// multimap\ntemplate <class Key, class T, class\
    \ Compare, class Allocator>\nvoid debug_print(std::ostream& s, std::multimap<Key,\
    \ T, Compare, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n\
    }\n\n// unordered_multimap\ntemplate <class Key, class T, class Hash, class Pred,\
    \ class Allocator>\nvoid debug_print(std::ostream& s, std::unordered_multimap<Key,\
    \ T, Hash, Pred, Allocator> val) {\n  dump_container(s, val.begin(), val.end());\n\
    }\n\n// complex number\ntemplate <class T>\nvoid debug_print(std::ostream& s,\
    \ std::complex<T> val) {\n  s << val.real() << (val.imag() < 0 ? \"\" : \"+\"\
    ) << val.imag() << \"i\";\n}\n\n// optional\ntemplate <class T>\nvoid debug_print(std::ostream&\
    \ s, std::optional<T> val) {\n  s << \"{\";\n  if (val.has_value()) {\n    debug_print(s,\
    \ val.value());\n  }\n  s << \"}\";\n}\n\n// variant\ntemplate <class... Types>\n\
    void debug_print(std::ostream& s, std::variant<Types...> val) {\n  std::visit([&s](const\
    \ auto& x) { debug_print(s, x); }, val);\n}\n\n// others\nvoid debug_print(std::ostream&\
    \ s, bool val) {\n  if (val) {\n    s << \"true\";\n  } else {\n    s << \"false\"\
    ;\n  }\n}\n\nvoid debug_print(std::ostream& s, int val) {\n  s << val;\n}\n\n\
    void debug_print(std::ostream& s, double val) {\n  s << val;\n}\n\nvoid debug_print(std::ostream&\
    \ s, std::string val) {\n  s << \"\\\"\" << val << \"\\\"\";\n}\n\nvoid debug_print(std::ostream&\
    \ s, char val) {\n  s << \"'\" << val << \"'\";\n}\n\n// array\n\ntemplate <size_t\
    \ N>\nvoid debug_print(std::ostream& s, const char (&val)[N]) {\n  s << \"\\\"\
    \" << val << \"\\\"\";\n}\n\ntemplate <typename T, size_t N>\nvoid debug_print(std::ostream&\
    \ s, const T val[N]) {\n  s << \"{\";\n  for (int i = 0; i < (int) N; ++i) {\n\
    \    if (i) s << \",\";\n    debug_print(s, val[i]);\n  }\n  s << \"}\";\n}\n\n\
    template <typename T>\nvoid debug_print(std::ostream& s, T val) {\n  s << val;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Debug/debug.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Debug/debug.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
