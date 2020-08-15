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


# :heavy_check_mark: test/aoj/2955/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#72c367391a592066d7074720e48b0693">test/aoj/2955</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/2955/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-06 22:54:09+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/UnionFind/unionfind.cpp.html">Union-find</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp.html">Subset sum problem (With quantity limitations)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955"

#include <iostream>
#include <vector>
#include <map>
#include "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include "Mylib/IO/input_vector.cpp"

int main(){
  int N,R; std::cin >> N >> R;

  auto p = input_vector<int>(N);
  for(auto &x : p) x -= 1;
  
  UnionFind uf(N);
  
  for(int i = 0; i < N; ++i){
    uf.merge(i, p[i]);
  }
  
  std::map<int, int> cycles;
  for(int i = 0; i < N; ++i){
    if(i == uf.root_of(i)) cycles[uf.size_of(i)] += 1;
  }
  
  std::vector<int> a,m;
  for(auto &[k, v] : cycles){
    a.push_back(k);
    m.push_back(v);
  }
  
  bool ans = subset_sum_limited(a.size(), R, a, m)[R];
  
  std::cout << (ans ? "Yes" : "No") << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/2955/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955"

#include <iostream>
#include <vector>
#include <map>
#line 3 "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp"

/**
 * @title Subset sum problem (With quantity limitations)
 * @docs subset_sum_limited.md
 */
auto subset_sum_limited(int N, int K, const std::vector<int> &a, const std::vector<int> &m){
  std::vector<int> dp(K+1, -1);

  dp[0] = 0;
  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(dp[j] >= 0){
        dp[j] = m[i];
      }else if(j < a[i] or dp[j-a[i]] <= 0){
        dp[j] = -1;
      }else{
        dp[j] = dp[j-a[i]] - 1;
      }
    }
  }

  for(int i = 0; i <= K; ++i) dp[i] = dp[i] >= 0;

  return dp;
}
#line 3 "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include <numeric>

/**
 * @title Union-find
 * @docs unionfind.md
 */
class UnionFind{
  std::vector<int> parent, depth, size;
  int count;

public:
  UnionFind(){}
  UnionFind(int n): parent(n), depth(n,1), size(n,1), count(n){
    std::iota(parent.begin(), parent.end(), 0);
  }
  
  int root_of(int i){
    if(parent[i] == i) return i;
    else return parent[i] = root_of(parent[i]);
  }
  
  bool is_same(int i, int j){return root_of(i) == root_of(j);}

  int merge(int i, int j){
    int ri = root_of(i), rj = root_of(j);
    if(ri == rj) return ri;
    else{
      --count;
      if(depth[ri] < depth[rj]){
        parent[ri] = rj;
        size[rj] += size[ri];
        return rj;
      }else{
        parent[rj] = ri;
        size[ri] += size[rj];
        if(depth[ri] == depth[rj]) ++depth[ri];
        return ri;
      }
    }
  }

  int size_of(int i){return size[root_of(i)];}

  int count_group(){return count;}
};
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}
#line 9 "test/aoj/2955/main.test.cpp"

int main(){
  int N,R; std::cin >> N >> R;

  auto p = input_vector<int>(N);
  for(auto &x : p) x -= 1;
  
  UnionFind uf(N);
  
  for(int i = 0; i < N; ++i){
    uf.merge(i, p[i]);
  }
  
  std::map<int, int> cycles;
  for(int i = 0; i < N; ++i){
    if(i == uf.root_of(i)) cycles[uf.size_of(i)] += 1;
  }
  
  std::vector<int> a,m;
  for(auto &[k, v] : cycles){
    a.push_back(k);
    m.push_back(v);
  }
  
  bool ans = subset_sum_limited(a.size(), R, a, m)[R];
  
  std::cout << (ans ? "Yes" : "No") << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

