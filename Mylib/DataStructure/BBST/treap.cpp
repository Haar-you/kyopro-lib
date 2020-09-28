#pragma once
#include <random>
#include <utility>
#include <tuple>

namespace haar_lib {
  template <typename Monoid>
  struct treap_node {
    using node = treap_node<Monoid>;
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    static std::mt19937 rand;

    value_type value, result;
    node *left = nullptr, *right = nullptr;
    int priority, size = 1;
    bool rev = false;

    treap_node(): priority(rand()){}
    treap_node(const value_type &value): value(value), result(value), priority(rand()){}

    static int count(node *t) {return !t ? 0 : t->size;}
    static value_type sum(node *t) {return !t ? M() : t->result;}

    static node* update_node_status(node *t){
      t->size = count(t->right) + count(t->left) + 1;
      t->result = M(M(sum(t->right), sum(t->left)), t->value);
      return t;
    }

    static void pushdown(node *t){
      if(!t) return;
      if(t->rev){
        std::swap(t->left, t->right);
        if(t->left) t->left->rev ^= true;
        if(t->right) t->right->rev ^= true;
        t->rev = false;
      }
      update_node_status(t);
    }

    static node* insert(node *t, int k, const value_type &val){
      auto s = split(t, k);
      return merge(s.first, merge(new node(val), s.second));
    }

    static node* erase(node *t, int k){
      node *l, *r, *m;
      std::tie(l, r) = split(t, k);
      std::tie(m, r) = split(r, 1);
      return merge(l, r);
    }

    static std::pair<node*, node*> split(node *t, int k){
      if(!t) return std::make_pair(nullptr, nullptr);
      pushdown(t);
      const int c = count(t->left);
      if(k <= c){
        auto s = split(t->left, k);
        t->left = s.second;
        return std::make_pair(s.first, update_node_status(t));
      }else{
        auto s = split(t->right, k - (c + 1));
        t->right = s.first;
        return std::make_pair(update_node_status(t), s.second);
      }
    }

    static node* merge(node *l, node *r){
      pushdown(l);
      pushdown(r);
      if(!l || !r) return !l ? r : l;
      if(l->priority > r->priority){
        l->right = merge(l->right, r);
        return update_node_status(l);
      }else{
        r->left = merge(l, r->left);
        return update_node_status(r);
      }
    }

    static node* reverse(node *t, int l, int r){
      node *a, *b, *c;
      std::tie(a, c) = split(t, l);
      std::tie(b, c) = split(c, r - l);
      b->rev ^= true;
      return t = merge(merge(a, b), c);
    }

    static void update_node(node *t, int k, const value_type &value){
      const int c = count(t->left);
      if(k == c) t->value = value;
      else if(k > c) update_node(t->right, k - (c + 1), value);
      else update_node(t->left, k, value);
      update_node_status(t);
    }

    static node* get_node(node *t, int k){
      if(!t) return t;
      pushdown(t);
      int c = count(t->left);
      if(k == c) return t;
      if(k > c) return get_node(t->right, k - (c + 1));
      else return get_node(t->left, k);
    }

    template <typename Func>
    static void traverse(node *t, const Func &f){
      if(t){
        pushdown(t);
        traverse(t->left, f);
        f(*t);
        traverse(t->right, f);
      }
    }
  };

  template <typename Monoid> std::mt19937 treap_node<Monoid>::rand;

  template <typename Monoid>
  class treap {
  public:
    using value_type = typename Monoid::value_type;

  protected:
    using node = treap_node<Monoid>;
    Monoid M_;
    node *root_ = nullptr;

    treap(node *t): root_(t){}

  public:
    treap(){}
    treap(int n){for(int i = 0; i < n; ++i) push_back(M_());}

    int size() const {return node::count(root_);}
    bool empty() const {return not root_;}

    void insert(int k, const value_type &val){
      root_ = node::insert(root_, k, val);
    }

    void erase(int k){root_ = node::erase(root_, k);}

    void merge_left(treap &left){
      root_ = node::merge(left.root_, root_); left.root_ = nullptr;
    }

    void merge_right(treap &right){
      root_ = node::merge(root_, right.root_); right.root_ = nullptr;
    }

    std::pair<treap, treap> split(int k){
      node *l, *r; std::tie(l, r) = node::split(root_, k);
      return std::make_pair(treap(l), treap(r));
    }

    void reverse(int l, int r){node::reverse(root_, l, r);}

    void set(int k, const value_type &value){node::update_node(root_, k, value);}

    value_type get(int k){return (node::get_node(root_, k))->value;}
    value_type operator[](int k){return get(k);}

    value_type fold(){return node::sum(root_);}
    value_type fold(int l, int r){
      node *left, *mid, *right;
      std::tie(mid, right) = node::split(root_, r);
      std::tie(left, mid) = node::split(mid, l);

      auto ret = node::sum(mid);

      mid = node::merge(left, mid);
      root_ = node::merge(mid, right);

      return ret;
    }

    template <typename Func>
    void traverse(const Func &f){
      node::traverse(root_, f);
    }

    void push_front(const value_type &val){insert(0, val);}
    void push_back(const value_type &val){insert(size(), val);}

    void pop_front(){erase(0);}
    void pop_back(){erase(size() - 1);}

    const value_type& front(){return get(0);}
    const value_type& back(){return get(size() - 1);}
  };
}
