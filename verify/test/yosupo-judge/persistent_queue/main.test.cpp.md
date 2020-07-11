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


# :heavy_check_mark: test/yosupo-judge/persistent_queue/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9ebe5796a1fd941d1f273efb97ed22d8">test/yosupo-judge/persistent_queue</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/persistent_queue/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/persistent_queue">https://judge.yosupo.jp/problem/persistent_queue</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/Queue/persistent_queue.cpp.html">Persistent queue</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/Queue/persistent_queue.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int Q; std::cin >> Q;

  std::vector<PersistentQueue<int>> S;

  for(auto [type, t] : input_tuples<int, int>(Q)){
    if(type == 0){
      int x; std::cin >> x;
      if(t == -1){
        PersistentQueue<int> a(x);
        S.push_back(a);
      }else{
        auto res = S[t].push(x);
        S.push_back(res);
      }
    }else{
      std::cout << S[t].front() << std::endl;
      auto res = S[t].pop();
      S.push_back(res);
    }
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/persistent_queue/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <iostream>
#include <vector>
#line 2 "Mylib/DataStructure/Queue/persistent_queue.cpp"
#include <array>

/**
 * @title Persistent queue
 * @docs persistent_queue.md
 */
template <typename T>
class PersistentQueue{
  constexpr static int MAX_SIZE_2 = 20; // size <= 2 ^ MAX_SIZE_2
  
  struct node{
    T value;
    std::array<node*, MAX_SIZE_2> ancestors;
    int depth = 0;
  };

  node *front_node = nullptr, *back_node = nullptr;

  PersistentQueue(node* front_node, node* back_node): front_node(front_node), back_node(back_node){}
  
public:
  PersistentQueue(){}
  PersistentQueue(const T &value){
    node *t = new node();
    t->value = value;
    back_node = front_node = t;
  }
  
  PersistentQueue push(const T &value) const {
    node *t = new node();

    t->value = value;
    
    t->ancestors[0] = back_node;
    for(int i = 1; i < MAX_SIZE_2; ++i){
      node *s = t->ancestors[i-1];
      if(s) t->ancestors[i] = s->ancestors[i-1];
      else break;
    }

    t->depth = back_node ? back_node->depth + 1 : 0;
    
    return PersistentQueue(front_node ? front_node : t, t);
  }

  PersistentQueue pop() const {
    if(back_node->depth == front_node->depth){
      return PersistentQueue(nullptr, nullptr);
    }
    
    int d = back_node->depth - front_node->depth - 1;

    node *t = back_node;

    for(int i = MAX_SIZE_2 - 1; i >= 0; --i){
      if(d >= (1 << i)){
        d -= (1 << i);
        t = t->ancestors[i];
      }
      if(d == 0) break;
    }
    
    return PersistentQueue(t, back_node);
  }

  T front() const {
    return front_node->value;
  }

  T back() const {
    return back_node->value;
  }

  bool empty() const {
    return not front_node;
  }

  int size() const {
    return front_node ? back_node->depth - front_node->depth + 1 : 0;
  }
};
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 5 "Mylib/IO/input_tuple.cpp"
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
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
#line 7 "test/yosupo-judge/persistent_queue/main.test.cpp"

int main(){
  int Q; std::cin >> Q;

  std::vector<PersistentQueue<int>> S;

  for(auto [type, t] : input_tuples<int, int>(Q)){
    if(type == 0){
      int x; std::cin >> x;
      if(t == -1){
        PersistentQueue<int> a(x);
        S.push_back(a);
      }else{
        auto res = S[t].push(x);
        S.push_back(res);
      }
    }else{
      std::cout << S[t].front() << std::endl;
      auto res = S[t].pop();
      S.push_back(res);
    }
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

