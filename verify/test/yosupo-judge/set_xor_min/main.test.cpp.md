---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :x: test/yosupo-judge/set_xor_min/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6f93aab82d7c215145df0633d795fd90">test/yosupo-judge/set_xor_min</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/set_xor_min/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/set_xor_min">https://judge.yosupo.jp/problem/set_xor_min</a>


## Depends on

* :x: <a href="../../../../library/Mylib/DataStructure/Trie/binary_trie.cpp.html">Binary trie</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/DataStructure/Trie/binary_trie.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int Q; std::cin >> Q;

  BinaryTrie<uint32_t, 32> t;

  for(auto [type, x] : input_tuples<int, uint32_t>(Q)){
    switch(type){
    case 0:
      if(t.count(x) == 0) t.insert(x);
      break;
    case 1:
      if(t.count(x) == 1) t.erase(x);
      break;
    case 2:
      std::cout << (t.min_element(x) ^ x) << "\n";
      break;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/set_xor_min/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>
#line 3 "Mylib/IO/input_tuples.cpp"
#include <vector>
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples {
  struct iter {
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool fetched = false;
    int N, c = 0;

    value_type operator*(){
      if(not fetched){
        std::cin >> value;
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 3 "Mylib/DataStructure/Trie/binary_trie.cpp"

/**
 * @title Binary trie
 * @docs binary_trie.md
 */
template <typename T, unsigned int B>
class BinaryTrie {
protected:
  struct node {
    int count;
    node *ch[2];
    node(): count(0){
      ch[0] = ch[1] = nullptr;
    }
  };

  node *root = nullptr;

protected:
  int count(node *t) const {return t ? t->count : 0;}

  int count(node *t, T val, unsigned int depth = 1) const {
    if(!t) return 0;

    if(depth > B) return t->count;

    int b = (val >> (B - depth)) & 1;
    return count(t->ch[b], val, depth + 1);
  }

public:
  int count(T val) const {
    return count(root, val);
  }

public:
  int size() const {return root ? root->count : 0;}
  bool empty() const {return !root;}

protected:
  void to_list(node *t, T val, std::vector<T> &ret) const {
    if(!t) return;
    if(!t->ch[0] and !t->ch[1]) for(int i = 0; i < t->count; ++i) ret.push_back(val);

    if(t->ch[0]) to_list(t->ch[0], val << 1, ret);
    if(t->ch[1]) to_list(t->ch[1], (val << 1) | 1, ret);
  }

public:
  std::vector<T> to_list() const {
    std::vector<T> ret;
    to_list(root, 0, ret);
    return ret;
  }

protected:
  node* insert(node *t, T val, unsigned int depth = 1){
    if(!t) t = new node();

    ++(t->count);
    if(depth > B) return t;

    int b = (val >> (B - depth)) & 1;
    t->ch[b] = insert(t->ch[b], val, depth + 1);
    return t;
  }

public:
  void insert(T val){
    root = insert(root, val);
  }

protected:
  node* erase(node *t, T val, unsigned int depth = 1){
    if(!t) return t;

    --(t->count);
    if(t->count == 0) return nullptr;
    if(depth > B) return t;

    int b = (val >> (B - depth)) & 1;
    t->ch[b] = erase(t->ch[b], val, depth + 1);
    return t;
  }

public:
  void erase(T val){
    root = erase(root, val);
  }

protected:
  T min_element(node *t, T diff, unsigned int depth = 1) const {
    if(depth > B) return 0;
    int b = (diff >> (B - depth)) & 1;
    b ^= !t->ch[b];
    return min_element(t->ch[b], diff, depth + 1) | (b << (B - depth));
  }

public:
  T min_element(T diff = 0) const {
    return min_element(root, diff);
  }

protected:
  T max_element(node *t, T diff, unsigned int depth = 1) const {
    if(depth > B) return 0;
    int b = !((diff >> (B - depth)) & 1);
    b ^= !t->ch[b];
    return max_element(t->ch[b], diff, depth + 1) | (b << (B - depth));
  }

public:
  T max_element(T diff = 0) const {
    return max_element(root, diff);
  }

protected:
  T at(node *t, int index, unsigned int depth = 1) const {
    if(depth > B) return 0;

    int c = count(t->ch[0]);
    if(t->ch[0] and index < c) return at(t->ch[0], index, depth + 1);
    else return at(t->ch[1], index - c, depth + 1) | ((T)1 << (B - depth));
  }

public:
  T at(int index) const {
    return at(index);
  }

protected:
  int lower_bound(node *t, T val, unsigned int depth = 1) const {
    if(!t) return 0;
    int b = (val >> (B - depth)) & 1;
    return (b ? count(t->ch[0]) : 0) + lower_bound(t->ch[b], val, depth + 1);
  }

public:
  int lower_bound(T val) const {
    return lower_bound(root, val);
  }

  int upper_bound(T val) const {
    return lower_bound(root, val + 1);
  }
};
#line 6 "test/yosupo-judge/set_xor_min/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int Q; std::cin >> Q;

  BinaryTrie<uint32_t, 32> t;

  for(auto [type, x] : input_tuples<int, uint32_t>(Q)){
    switch(type){
    case 0:
      if(t.count(x) == 0) t.insert(x);
      break;
    case 1:
      if(t.count(x) == 1) t.erase(x);
      break;
    case 2:
      std::cout << (t.min_element(x) ^ x) << "\n";
      break;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

