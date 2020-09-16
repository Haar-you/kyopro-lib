#pragma once
#include <string>
#include <vector>
#include <map>

namespace haar_lib {
  template <typename T>
  struct trie_node {
    std::map<char, trie_node*> children;
    T val;

  public:
    trie_node(){}
    trie_node(T val): val(val){}

    const T& value() const {return val;}
    T& value(){return val;}

    trie_node* insert(char c, const T &v){
      if(children.find(c) != children.end()){
        children[c]->val = v;
      }else{
        children[c] = new trie_node<T>(v);
      }

      return children[c];
    }

    template <typename Iter>
    trie_node* insert(Iter first, Iter last, const T &v){
      if(first == last){
        val = v;
        return this;
      }else{
        const auto c = *first;
        if(children.find(c) == children.end()){
          children[c] = new trie_node(T());
        }

        return children[c]->insert(first + 1, last, v);
      }
    }

    trie_node* find(char c){
      if(children.find(c) != children.end()) return children[c];
      else return nullptr;
    }
  };

  template <typename T>
  struct trie {
    using node = trie_node<T>;

    node *root;

    trie(){
      root = new node(T());
    }

    template <typename Iter>
    node* insert(Iter first, Iter last, const T &v){
      return root->insert(first, last, v);
    }
  };
}
