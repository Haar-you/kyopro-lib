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


# :heavy_check_mark: test/yosupo-judge/maximum_independent_set/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c23632d9cb1ef08c66b41109b76404c6">test/yosupo-judge/maximum_independent_set</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/maximum_independent_set/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/maximum_independent_set">https://judge.yosupo.jp/problem/maximum_independent_set</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Graph/maximum_independent_set.cpp.html">Maximum independent set</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/join.cpp.html">Mylib/IO/join.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include <iostream>
#include <vector>
#include "Mylib/Graph/maximum_independent_set.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int N,M; std::cin >> N >> M;
  std::vector<std::vector<int>> g(N, std::vector<int>(N));
  for(auto [u, v] : input_tuples<int, int>(M)){
    g[u][v] = g[v][u] = 1;
  }

  auto res = maximum_independent_set(g);

  std::vector<int> ans;
  for(int i = 0; i < N; ++i){
    if(res & (1LL << i)) ans.push_back(i);
  }

  std::cout << ans.size() << " " << join(ans.begin(), ans.end()) << "\n";
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/maximum_independent_set/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include <iostream>
#include <vector>
#line 3 "Mylib/Graph/maximum_independent_set.cpp"
#include <cassert>

/**
 * @title Maximum independent set
 * @docs maximum_independent_set.md
 */
int64_t maximum_independent_set(const std::vector<std::vector<int>> &g){
  const int n = g.size();

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      assert((int)g[i].size() == n);
      assert(g[i][j] == g[j][i]);
    }
  }
  
  const int h1 = n/2; // V1
  const int h2 = n-h1; // V2

  std::vector<bool> dp1(1<<h1, true); // dp1[S] := Sが独立集合か?
  for(int i = 0; i < h1; ++i){
    for(int j = 0; j < h1; ++j){
      if(g[i][j]) dp1[(1<<i) | (1<<j)] = false;
    }
  }
  
  for(int s = 0; s < (1<<h1); ++s){
    if(not dp1[s]){
      for(int j = 0; j < h1; ++j){
        dp1[s | (1<<j)] = false;
      }
    }
  }

  std::vector<bool> dp2(1<<h2, true); // dp2[S] := Sが独立集合か?
  for(int i = h1; i < n; ++i){
    for(int j = h1; j < n; ++j){
      if(g[i][j]) dp2[(1<<(i-h1)) | (1<<(j-h1))] = false;
    }
  }

  for(int s = 0; s < (1<<h2); ++s){
    if(!dp2[s]){
      for(int j = 0; j < h2; ++j){
        dp2[s | (1<<j)] = false;
      }
    }
  }
  
  std::vector<int> dp3(1<<h1, 0); // S1と接続しないV2の最大の部分集合
  dp3[0] = (1<<h2)-1;
  for(int i = 0; i < h1; ++i){
    int t = 0;
    for(int j = h1; j < n; ++j){
      if(g[i][j]){
        t |= (1<<(j-h1));
      }
    }
    dp3[1<<i] = t ^ ((1<<h2)-1);
  }
  
  for(int s = 0; s < (1<<h1); ++s){
    for(int j = 0; j < h1; ++j){
      if((s & (1<<j)) == 0){
        dp3[s | (1<<j)] = dp3[s] & dp3[1<<j];
      }
    }
  }

  std::vector<int> dp4(1<<h2, 0); // S2の最大独立集合
  for(int i = 0; i < (1<<h2); ++i){
    if(dp2[i]){
      dp4[i] = i;
    }
  }
  
  for(int s = 0; s < (1<<h2); ++s){
    for(int j = 0; j < h2; ++j){
      if((s & (1<<j)) == 0){
        if(__builtin_popcount(dp4[s | (1<<j)]) > __builtin_popcount(dp4[s])){
          dp4[s | (1<<j)] = dp4[s | (1<<j)];
        }else{
          dp4[s | (1<<j)] = dp4[s];
        }
      }
    }
  }
  
  int64_t ans = 0;
  int size = 0;
  
  for(int s = 0; s < (1<<h1); ++s){
    if(dp1[s]){
      int64_t t = (int64_t)s | (((int64_t)dp4[dp3[s]]) << h1);

      if(__builtin_popcountll(t) > size){
        size = __builtin_popcountll(t);
        ans = t;
      }
    }
  }
  
  return ans;
}
#line 3 "Mylib/IO/join.cpp"
#include <sstream>
#include <string>

/**
 * @docs join.md
 */
template <typename ITER>
std::string join(ITER first, ITER last, std::string delim = " "){
  std::stringstream s;

  for(auto it = first; it != last; ++it){
    if(it != first) s << delim;
    s << *it;
  }

  return s.str();
}
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
#line 8 "test/yosupo-judge/maximum_independent_set/main.test.cpp"

int main(){
  int N,M; std::cin >> N >> M;
  std::vector<std::vector<int>> g(N, std::vector<int>(N));
  for(auto [u, v] : input_tuples<int, int>(M)){
    g[u][v] = g[v][u] = 1;
  }

  auto res = maximum_independent_set(g);

  std::vector<int> ans;
  for(int i = 0; i < N; ++i){
    if(res & (1LL << i)) ans.push_back(i);
  }

  std::cout << ans.size() << " " << join(ans.begin(), ans.end()) << "\n";
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

