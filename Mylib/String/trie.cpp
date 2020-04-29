#pragma once
#include <string>
#include <vector>

/**
 * @title Trie木
 * @docs trie.md
 */
template <typename T>
class Trie{
  constexpr static int CHAR_MAX = 128;
  int table[CHAR_MAX];
  int N;
  
  struct node{
    T val;
    std::vector<node*> ch;
    
    node(int N): val(0), ch(N){}
  };

public:
  Trie(const std::string &s): N(s.size()){
    for(int i = 0; i < CHAR_MAX; ++i) table[i] = -1;
    for(int i = 0; i < (int)s.size(); ++i){
      table[(int)s[i]] = i;
    }
  }

  node *root = nullptr;
  
  node* insert(node *t, const std::string &s, const T &val, int i = 0){
    if(!t) t = new node(N);

    if(i >= (int)s.size()){
      t->val = val;
      return t;
    }

    int c = table[(int)s[i]];
    t->ch[c] = insert(t->ch[c], s, val, i+1);

    return t;
  }
  
  void insert(const std::string &s, const T &val){
    root = insert(root, s, val, 0);
  }

  node* find(node *t, char c){
    if(!t) return t;
    return t->ch[table[(int)c]];
  }
};
