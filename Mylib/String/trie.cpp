#pragma once
#include <string>
#include <vector>
#include <map>

namespace haar_lib {
  template <typename T>
  class trie_node {
    std::map<char, trie_node*> children_;
    T val_;

  public:
    trie_node(){}
    trie_node(T val): val_(val){}

    const T& value() const {return val_;}
    T& value(){return val_;}

    trie_node* insert(char c, const T &v){
      if(children_.find(c) != children_.end()){
        children_[c]->val_ = v;
      }else{
        children_[c] = new trie_node<T>(v);
      }

      return children_[c];
    }

    template <typename Iter>
    trie_node* insert(Iter first, Iter last, const T &v){
      if(first == last){
        val_ = v;
        return this;
      }else{
        const auto c = *first;
        if(children_.find(c) == children_.end()){
          children_[c] = new trie_node(T());
        }

        return children_[c]->insert(first + 1, last, v);
      }
    }

    trie_node* find(char c){
      if(children_.find(c) != children_.end()) return children_[c];
      else return nullptr;
    }
  };

  template <typename T>
  struct trie {
    using node = trie_node<T>;

  private:
    node *root_;

  public:
    trie(): root_(new node(T())){}

    node* root() const {return root;}

    template <typename Iter>
    node* insert(Iter first, Iter last, const T &v){
      return root->insert(first, last, v);
    }
  };
}
