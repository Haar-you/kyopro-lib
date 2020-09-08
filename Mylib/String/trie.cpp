#pragma once
#include <string>
#include <vector>
#include <map>

/**
 * @title Trie
 * @docs trie.md
 */
namespace haar_lib {
  template <typename T>
  struct TrieNode {
    std::map<char, TrieNode*> children;
    T val;

  public:
    TrieNode(){}
    TrieNode(T val): val(val){}

    const T& value() const {return val;}
    T& value(){return val;}

    TrieNode* insert(char c, const T &v){
      if(children.find(c) != children.end()){
        children[c]->val = v;
      }else{
        children[c] = new TrieNode<T>(v);
      }

      return children[c];
    }

    template <typename Iter>
    TrieNode* insert(Iter first, Iter last, const T &v){
      if(first == last){
        val = v;
        return this;
      }else{
        const auto c = *first;
        if(children.find(c) == children.end()){
          children[c] = new TrieNode(T());
        }

        return children[c]->insert(first + 1, last, v);
      }
    }

    TrieNode* find(char c){
      if(children.find(c) != children.end()) return children[c];
      else return nullptr;
    }
  };

  template <typename T>
  struct Trie {
    using node = TrieNode<T>;

    node *root;

    Trie(){
      root = new node(T());
    }

    template <typename Iter>
    node* insert(Iter first, Iter last, const T &v){
      return root->insert(first, last, v);
    }
  };
}
