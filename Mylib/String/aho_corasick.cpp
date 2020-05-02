#pragma once
#include <vector>
#include <unordered_map>
#include <string>
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
