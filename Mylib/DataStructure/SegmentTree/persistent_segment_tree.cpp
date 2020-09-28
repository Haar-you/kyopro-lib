#pragma once
#include <vector>

namespace haar_lib {
  template <typename Monoid>
  class persistent_segment_tree {
  public:
    using value_type = typename Monoid::value_type;

  private:
    struct node {
      value_type value;
      node *left = nullptr, *right = nullptr;
      node(const value_type &value): value(value){}
    };

    Monoid M_;
    int depth_;
    node *root_ = nullptr;

    persistent_segment_tree(int depth, node *root): depth_(depth), root_(root){}

    node* assign(node *t, const std::vector<value_type> &init_list, int d, int &pos){
      if(d == depth_){
        t = new node(pos < (int)init_list.size() ? init_list[pos] : M_());
        ++pos;
      }else{
        t = new node(M_());
        t->left = assign(t->left, init_list, d + 1, pos);
        t->right = assign(t->right, init_list, d + 1, pos);
        t->value = M_(t->left->value, t->right->value);
      }
      return t;
    }

    void init(const std::vector<value_type> &init_list){
      const int size = init_list.size();
      depth_ = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;
      int pos = 0;
      root_ = assign(root_, init_list, 1, pos);
    }

  public:
    persistent_segment_tree(){}
    persistent_segment_tree(const std::vector<value_type> &init_list){
      init(init_list);
    }
    persistent_segment_tree(int size){
      init(std::vector(size, M_()));
    }
    persistent_segment_tree(int size, const value_type &value){
      init(std::vector(size, value));
    }

  protected:
    node* set(node *t, int l, int r, int pos, const value_type &val) const {
      if(r <= pos or pos + 1 <= l){
        return t;
      }else if(pos <= l and r <= pos + 1){
        return new node(val);
      }else{
        const int m = (l + r) >> 1;
        auto lp = set(t->left, l, m, pos, val);
        auto rp = set(t->right, m, r, pos, val);

        node *s = new node(M_(lp->value, rp->value));

        s->left = lp;
        s->right = rp;

        return s;
      }
    }

  public:
    persistent_segment_tree set(int i, const value_type &val) const {
      node *t = set(root_, 0, 1 << (depth_ - 1), i, val);
      return persistent_segment_tree(depth_, t);
    }

    persistent_segment_tree update(int i, const value_type &val) const {
      return set(i, M_((*this)[i], val));
    }

  protected:
    value_type get(node *t, int i, int j, int l, int r) const {
      if(i <= l and r <= j) return t->value;
      if(r <= i or j <= l) return M_();
      const int m = (l + r) >> 1;
      return M_(get(t->left, i, j, l, m), get(t->right, i, j, m, r));
    }

  public:
    value_type fold(int i, int j) const {
      return get(root_, i, j, 0, 1 << (depth_ - 1));
    }

    value_type operator[](int i) const {
      return fold(i, i + 1);
    }
  };
}
