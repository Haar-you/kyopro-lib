#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

namespace haar_lib {
  class aho_corasick {
    int n_;
    std::vector<std::unordered_map<char, int>> trie_;
    std::vector<int> failure_edge_;
    std::vector<std::string> dict_;
    std::vector<std::vector<int>> dict_index_;

  public:
    aho_corasick(): n_(1), trie_(1), failure_edge_(1){}

    void add(const std::string &s){
      dict_.push_back(s);

      int cur = 0;

      for(int i = 0; i < (int)s.size(); ++i){
        char c = s[i];

        if(trie_[cur].find(c) != trie_[cur].end()){
          cur = trie_[cur][c];
        }else{
          ++n_;
          trie_.resize(n_);

          trie_[cur][c] = n_ - 1;

          cur = trie_[cur][c];
        }
      }

      dict_index_.resize(n_);
      dict_index_[cur].push_back(dict_.size() - 1);
    }

    void build(){
      failure_edge_.resize(n_);

      std::queue<int> dq;
      dq.push(0);

      while(not dq.empty()){
        int cur = dq.front(); dq.pop();

        for(auto &kv : trie_[cur]){
          char c = kv.first;
          int next = kv.second;

          if(cur == 0){
            failure_edge_[next] = 0;

          }else{
            int i = failure_edge_[cur];
            int j = 0;

            while(1){
              if(trie_[i].find(c) != trie_[i].end()){
                j = trie_[i][c];
                break;
              }else{
                if(i == 0) break;
                i = failure_edge_[i];
              }
            }

            failure_edge_[next] = j;

            for(auto k : dict_index_[failure_edge_[next]]){
              dict_index_[next].push_back(k);
            }
          }

          dq.push(next);
        }
      }
    }

    template <typename Func> // function<void(int, int)>
    void match(const std::string &s, const Func &f){
      int cur = 0;

      for(int i = 0; i < (int)s.size(); ++i){
        const char c = s[i];

        while(cur != 0 and trie_[cur].find(c) == trie_[cur].end()){
          cur = failure_edge_[cur];
        }

        cur = trie_[cur][c];

        for(auto j : dict_index_[cur]){
          const int len = dict_[j].size();
          f(i - len + 1, len);
        }
      }
    }
  };
}
