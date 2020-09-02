#pragma once
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <string_view>

/**
 * @title Palindromic tree
 * @docs palindromic_tree
 */
class PalindromicTree {
  struct node{
    int length;
    int count;
    std::map<char, node*> children;
    node *suffix_link;
    std::vector<node*> reverse_suffix_links;
  };

  node *even_root, *odd_root;
  int size_ = 2;

public:
  PalindromicTree(const std::string_view &s){
    even_root = new node();
    even_root->length = 0;

    odd_root = new node();
    odd_root->length = -1;

    even_root->suffix_link = odd_root;
    odd_root->reverse_suffix_links.emplace_back(even_root);

    node *cur = odd_root;

    const int N = s.size();

    for(int i = 0; i < N; ++i){
      node *t = cur;

      while(1){
        if(i - t->length - 1 >= 0 and s[i] == s[i - t->length - 1]){
          if(t->children.find(s[i]) == t->children.end()){
            node *a = new node();
            a->length = t->length + 2;
            a->count = 1;
            t->children[s[i]] = a;
            ++size_;
          }else{
            t->children[s[i]]->count += 1;
          }
          break;
        }else{
          t = t->suffix_link;
        }
      }

      node *next = t->children[s[i]];

      if(!next->suffix_link){
        if(next->length == 1){
          next->suffix_link = even_root;
          even_root->reverse_suffix_links.emplace_back(next);
        }else{
          node *p = cur;

          while(1){
            if(p != t){
              if(i - p->length - 1 >= 0 and s[i] == s[i - p->length - 1]){
                next->suffix_link = p->children[s[i]];
                p->children[s[i]]->reverse_suffix_links.emplace_back(next);
                break;
              }else{
                p = p->suffix_link;
              }
            }else{
              p = p->suffix_link;
            }
          }
        }
      }

      cur = next;
    }
  }

  int size() const {
    return size_;
  }

private:
  int longest_(node *t) const {
    int ret = t->length;
    for(auto &p : t->children) ret = std::max(ret, longest_(p.second));
    return ret;
  }

public:
  int longest() const {
    int ret = std::max(longest_(odd_root), longest_(even_root));
    return ret;
  }

private:
  int count_sub_palindromes_(node *t, int &c) const {
    int ret = t->count;

    for(auto &s : t->reverse_suffix_links){
      ret += count_sub_palindromes_(s, c);
    }

    if(t != odd_root and t != even_root) c += ret;

    return ret;
  }

public:
  int count_sub_palindromes() const {
    int ret = 0;
    count_sub_palindromes_(odd_root, ret);
    return ret;
  }
};
