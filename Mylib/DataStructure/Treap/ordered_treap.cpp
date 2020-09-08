#pragma once
#include <algorithm>
#include "Mylib/DataStructure/Treap/treap.cpp"

/**
 * @title Treap (Ordered set)
 * @docs ordered_treap.md
 */
namespace haar_lib {
  namespace treap {
    template <typename Monoid>
    class OrderedTreap : public Treap<Monoid> {
      using value_type = typename Monoid::value_type;
      using node = TreapNode<Monoid>;
      using super = Treap<Monoid>;

    public:
      OrderedTreap(): super(){}

    protected:
      int lower_bound(node *t, const value_type &val){
        if(!t) return 0;
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
        if(!t) return 0;
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
}
