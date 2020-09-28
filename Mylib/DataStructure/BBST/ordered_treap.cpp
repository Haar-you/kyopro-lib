#pragma once
#include <algorithm>
#include "Mylib/DataStructure/BBST/treap.cpp"

namespace haar_lib {
  template <typename Monoid>
  class ordered_treap : public treap<Monoid> {
  public:
    using value_type = typename Monoid::value_type;

  private:
    using node = treap_node<Monoid>;
    using super = treap<Monoid>;

  public:
    ordered_treap(): super(){}

  protected:
    int lower_bound(node *t, const value_type &val){
      if(not t) return 0;
      int c = super::count(t->left);
      if(t->value >= val) return std::min(c, lower_bound(t->left, val));
      else return c + 1 + lower_bound(t->right, val);
    }

  public:
    int lower_bound(const value_type &val){
      return lower_bound(super::root, val);
    }

  protected:
    int upper_bound(node *t, const value_type &val){
      if(not t) return 0;
      int c = super::count(t->left);
      if(t->val > val) return std::min(c, upper_bound(t->left, val));
      else return c + 1 + upper_bound(t->right, val);
    }

  public:
    int upper_bound(const value_type &val){
      return upper_bound(super::root, val);
    }

  public:
    void insert_by_order(const value_type &val){
      int k = lower_bound(val);
      super::insert(k, val);
    }

  public:
    int find_by_order(const value_type &val){
      int k = lower_bound(super::root, val);
      if(k >= super::size()) return -1;
      auto t = super::get(k);
      return t == val ? k : -1;
    }

  public:
    void erase_by_order(const value_type &val){
      int k = find_by_order(val);
      if(k == -1) return;
      super::erase(k);
    }
  };
}
