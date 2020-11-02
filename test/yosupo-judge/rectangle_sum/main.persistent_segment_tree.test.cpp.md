---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp
    title: Persistent segment tree
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/Utils/compressor.cpp
    title: Compressor
  - icon: ':question:'
    path: Mylib/Utils/sort_simultaneously.cpp
    title: Sort simultaneously
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 3 \"Mylib/Utils/sort_simultaneously.cpp\"\
    \n#include <utility>\n#include <algorithm>\n#include <numeric>\n#include <initializer_list>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  namespace sort_simultaneously_impl\
    \ {\n    template <typename T>\n    void sub(int N, const std::vector<int> &ord,\
    \ std::vector<T> &a){\n      std::vector<T> temp(N);\n      for(int i = 0; i <\
    \ N; ++i) temp[i] = a[ord[i]];\n      std::swap(temp, a);\n    }\n  }\n\n  template\
    \ <typename Compare, typename ... Args>\n  void sort_simultaneously(const Compare\
    \ &compare, std::vector<Args> &... args){\n    const int N = std::max({args.size()\
    \ ...});\n    assert((int)std::min({args.size() ...}) == N);\n    std::vector<int>\
    \ ord(N);\n    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(),\
    \ ord.end(), compare);\n\n    (void)std::initializer_list<int>{\n      (void(sort_simultaneously_impl::sub(N,\
    \ ord, args)), 0) ...};\n  }\n}\n#line 4 \"Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  class persistent_segment_tree\
    \ {\n  public:\n    using value_type = typename Monoid::value_type;\n\n  private:\n\
    \    struct node {\n      value_type value;\n      node *left = nullptr, *right\
    \ = nullptr;\n      node(const value_type &value): value(value){}\n    };\n\n\
    \    Monoid M_;\n    int depth_, size_;\n    node *root_ = nullptr;\n\n    persistent_segment_tree(int\
    \ depth, node *root): depth_(depth), root_(root){}\n\n    node* assign(node *t,\
    \ const std::vector<value_type> &init_list, int d, int &pos){\n      if(d == depth_){\n\
    \        t = new node(pos < (int)init_list.size() ? init_list[pos] : M_());\n\
    \        ++pos;\n      }else{\n        t = new node(M_());\n        t->left =\
    \ assign(t->left, init_list, d + 1, pos);\n        t->right = assign(t->right,\
    \ init_list, d + 1, pos);\n        t->value = M_(t->left->value, t->right->value);\n\
    \      }\n      return t;\n    }\n\n    void init(const std::vector<value_type>\
    \ &init_list){\n      size_ = init_list.size();\n      depth_ = size_ == 1 ? 1\
    \ : 32 - __builtin_clz(size_ - 1) + 1;\n      int pos = 0;\n      root_ = assign(root_,\
    \ init_list, 1, pos);\n    }\n\n  public:\n    persistent_segment_tree(){}\n \
    \   persistent_segment_tree(const std::vector<value_type> &init_list){\n     \
    \ init(init_list);\n    }\n    persistent_segment_tree(int size){\n      init(std::vector(size,\
    \ M_()));\n    }\n    persistent_segment_tree(int size, const value_type &value){\n\
    \      init(std::vector(size, value));\n    }\n\n  protected:\n    node* set(node\
    \ *t, int l, int r, int pos, const value_type &val) const {\n      if(r <= pos\
    \ or pos + 1 <= l){\n        return t;\n      }else if(pos <= l and r <= pos +\
    \ 1){\n        return new node(val);\n      }else{\n        const int m = (l +\
    \ r) >> 1;\n        auto lp = set(t->left, l, m, pos, val);\n        auto rp =\
    \ set(t->right, m, r, pos, val);\n\n        node *s = new node(M_(lp->value, rp->value));\n\
    \n        s->left = lp;\n        s->right = rp;\n\n        return s;\n      }\n\
    \    }\n\n  public:\n    persistent_segment_tree set(int i, const value_type &val)\
    \ const {\n      assert(0 <= i and i < size_);\n      node *t = set(root_, 0,\
    \ 1 << (depth_ - 1), i, val);\n      return persistent_segment_tree(depth_, t);\n\
    \    }\n\n    persistent_segment_tree update(int i, const value_type &val) const\
    \ {\n      return set(i, M_((*this)[i], val));\n    }\n\n  protected:\n    value_type\
    \ get(node *t, int i, int j, int l, int r) const {\n      if(i <= l and r <= j)\
    \ return t->value;\n      if(r <= i or j <= l) return M_();\n      const int m\
    \ = (l + r) >> 1;\n      return M_(get(t->left, i, j, l, m), get(t->right, i,\
    \ j, m, r));\n    }\n\n  public:\n    value_type fold(int l, int r) const {\n\
    \      assert(0 <= l and l <= r and r <= size_);\n      return get(root_, l, r,\
    \ 0, 1 << (depth_ - 1));\n    }\n\n    value_type operator[](int i) const {\n\
    \      return fold(i, i + 1);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 4 \"Mylib/Utils/compressor.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class compressor {\n    std::vector<T> data_;\n    template <typename>\
    \ friend class compressor_builder;\n\n  public:\n    int get_index(const T &val)\
    \ const {\n      return std::lower_bound(data_.begin(), data_.end(), val) - data_.begin();\n\
    \    }\n\n    auto& compress(std::vector<T> &vals) const {\n      for(auto &x\
    \ : vals) x = get_index(x);\n      return *this;\n    }\n\n    auto& compress(T\
    \ &val) const {\n      val = get_index(val);\n      return *this;\n    }\n\n \
    \   template <typename U, typename ... Args>\n    auto& compress(U &val, Args\
    \ &... args) const {\n      compress(val);\n      return compress(args ...);\n\
    \    }\n\n    auto& decompress(std::vector<T> &vals) const {\n      for(auto &x\
    \ : vals) x = data_[x];\n      return *this;\n    }\n\n    auto& decompress(T\
    \ &val) const {\n      val = data_[val];\n      return *this;\n    }\n\n    template\
    \ <typename U, typename ... Args>\n    auto& decompress(U &val, Args &... args)\
    \ const {\n      decompress(val);\n      return decompress(args ...);\n    }\n\
    \n    int size() const {return data_.size();}\n    T operator[](int index) const\
    \ {return data_[index];}\n  };\n\n  template <typename T>\n  class compressor_builder\
    \ {\n    std::vector<T> data_;\n\n  public:\n    auto& add(const T &val){\n  \
    \    data_.push_back(val);\n      return *this;\n    }\n\n    auto& add(const\
    \ std::vector<T> &vals){\n      data_.insert(data_.end(), vals.begin(), vals.end());\n\
    \      return *this;\n    }\n\n    template <typename U, typename ... Args>\n\
    \    auto& add(const U &val, const Args &... args){\n      add(val);\n      return\
    \ add(args ...);\n    }\n\n    auto build() const {\n      compressor<T> ret;\n\
    \      ret.data_ = data_;\n      std::sort(ret.data_.begin(), ret.data_.end());\n\
    \      ret.data_.erase(std::unique(ret.data_.begin(), ret.data_.end()), ret.data_.end());\n\
    \      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include <tuple>\n#line 7 \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T &val,\
    \ int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 11 \"test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing Seg = hl::persistent_segment_tree<hl::sum_monoid<int64_t>>;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, Q; std::cin >> N >> Q;\n\n  auto [x, y, w] = hl::input_tuple_vector<int64_t,\
    \ int64_t, int64_t>(N);\n\n  hl::sort_simultaneously(\n    [&](int i, int j){\n\
    \      return y[i] < y[j];\n    },\n    x, y, w\n  );\n\n  auto c = hl::compressor_builder<int64_t>().add(x).build().compress(x);\n\
    \  const int m = c.size();\n\n  std::vector<Seg> seg;\n  seg.push_back(Seg(m));\n\
    \n  for(int i = 0; i < N; ++i){\n    auto &s = seg.back();\n    seg.push_back(s.update(x[i],\
    \ w[i]));\n  }\n\n  for(auto [l, d, r, u] : hl::input_tuples<int64_t, int64_t,\
    \ int64_t, int64_t>(Q)){\n    l = c.get_index(l);\n    r = c.get_index(r);\n\n\
    \    u = std::lower_bound(y.begin(), y.end(), u) - y.begin();\n    d = std::lower_bound(y.begin(),\
    \ y.end(), d) - y.begin();\n\n    auto ans = seg[u].fold(l, r) - seg[d].fold(l,\
    \ r);\n    std::cout << ans << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include \"Mylib/Utils/sort_simultaneously.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp\"\n#include\
    \ \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/Utils/compressor.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing Seg = hl::persistent_segment_tree<hl::sum_monoid<int64_t>>;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, Q; std::cin >> N >> Q;\n\n  auto [x, y, w] = hl::input_tuple_vector<int64_t,\
    \ int64_t, int64_t>(N);\n\n  hl::sort_simultaneously(\n    [&](int i, int j){\n\
    \      return y[i] < y[j];\n    },\n    x, y, w\n  );\n\n  auto c = hl::compressor_builder<int64_t>().add(x).build().compress(x);\n\
    \  const int m = c.size();\n\n  std::vector<Seg> seg;\n  seg.push_back(Seg(m));\n\
    \n  for(int i = 0; i < N; ++i){\n    auto &s = seg.back();\n    seg.push_back(s.update(x[i],\
    \ w[i]));\n  }\n\n  for(auto [l, d, r, u] : hl::input_tuples<int64_t, int64_t,\
    \ int64_t, int64_t>(Q)){\n    l = c.get_index(l);\n    r = c.get_index(r);\n\n\
    \    u = std::lower_bound(y.begin(), y.end(), u) - y.begin();\n    d = std::lower_bound(y.begin(),\
    \ y.end(), d) - y.begin();\n\n    auto ans = seg[u].fold(l, r) - seg[d].fold(l,\
    \ r);\n    std::cout << ans << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Utils/sort_simultaneously.cpp
  - Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/Utils/compressor.cpp
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
- /verify/test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp.html
title: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
---
