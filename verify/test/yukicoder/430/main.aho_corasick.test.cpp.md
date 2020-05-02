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


# :x: test/yukicoder/430/main.aho_corasick.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0bdfbad8357bf1fcb5738704a6247436">test/yukicoder/430</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/430/main.aho_corasick.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="https://yukicoder.me/problems/no/430">https://yukicoder.me/problems/no/430</a>


## Depends on

* :x: <a href="../../../../library/Mylib/String/aho_corasick.cpp.html">Aho-Corasick法</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/430"

#include <iostream>
#include <string>
#include <vector>

#include "Mylib/String/aho_corasick.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  std::string S; std::cin >> S;
  int M; std::cin >> M;

  std::vector<std::string> C(M);
  for(int i = 0; i < M; ++i) std::cin >> C[i];

  AhoCorasick ac;
  for(int i = 0; i < M; ++i){
    ac.add(C[i]);
  }

  ac.build();
  
  int ans = 0;
  ac.match(S, [&](int, int){++ans;});
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/430/main.aho_corasick.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/430"

#include <iostream>
#include <string>
#include <vector>

#line 3 "Mylib/String/aho_corasick.cpp"
#include <unordered_map>
#line 5 "Mylib/String/aho_corasick.cpp"
#include <queue>

/**
 * @title Aho-Corasick法
 * @docs aho_corasick.md
 */
class AhoCorasick{
public:
  int n;
  std::vector<std::unordered_map<char,int>> trie;
  std::vector<int> failure_edge;
  std::vector<std::string> dict;
  std::vector<std::vector<int>> dict_index;
  
  AhoCorasick(): n(1), trie(1), failure_edge(1){}

  void add(const std::string &s){
    dict.push_back(s);

    int cur = 0;

    for(int i = 0; i < (int)s.size(); ++i){
      char c = s[i];

      if(trie[cur].find(c) != trie[cur].end()){
        cur = trie[cur][c];
      }else{
        ++n;
        trie.resize(n);

        trie[cur][c] = n-1;
	
        cur = trie[cur][c];
      }
    }

    dict_index.resize(n);
    dict_index[cur].push_back(dict.size()-1);
  }

  void build(){
    failure_edge.resize(n);
    
    std::queue<int> dq;
    dq.push(0);

    while(not dq.empty()){
      int cur = dq.front(); dq.pop();

      for(auto &kv : trie[cur]){
        char c = kv.first;
        int next = kv.second;

        if(cur == 0){
          failure_edge[next] = 0;

        }else{
          int i = failure_edge[cur];
          int j = 0;
	
          while(1){
            if(trie[i].find(c) != trie[i].end()){
              j = trie[i][c];
              break;
            }else{
              if(i == 0) break;
              i = failure_edge[i];
            }
          }
	
          failure_edge[next] = j;

          for(auto k : dict_index[failure_edge[next]]){
            dict_index[next].push_back(k);
          }
        }
	
        dq.push(next);
      }
    }
  }

  template <typename Func> // function<void(int,int)>
  void match(const std::string &s, const Func &f){
    int cur = 0;

    for(int i = 0; i < (int)s.size(); ++i){
      char c = s[i];

      while(cur != 0 and trie[cur].find(c) == trie[cur].end()){
        cur = failure_edge[cur];
      }

      cur = trie[cur][c];

      for(auto j : dict_index[cur]){
        int len = dict[j].size();
        f(i-len+1, len);
      }
    }
  }
};
#line 8 "test/yukicoder/430/main.aho_corasick.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  std::string S; std::cin >> S;
  int M; std::cin >> M;

  std::vector<std::string> C(M);
  for(int i = 0; i < M; ++i) std::cin >> C[i];

  AhoCorasick ac;
  for(int i = 0; i < M; ++i){
    ac.add(C[i]);
  }

  ac.build();
  
  int ans = 0;
  ac.match(S, [&](int, int){++ans;});
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

