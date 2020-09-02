#pragma once
#include <utility>
#include <tuple>

/**
 * @title Splay tree
 * @docs splay_tree.md
 */
namespace splay_tree {
  template <typename Monoid>
  struct SplayNode {
    using node = SplayNode<Monoid>;
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    node *left = nullptr, *right = nullptr, *parent = nullptr;
    int size;
    value_type value = M(), result = M();

    SplayNode(): size(1){}
    SplayNode(const value_type &value): size(1), value(value){}

    void rotate(){
      node *p, *pp, *c;

      p = this->parent;
      pp = p->parent;

      if(p->left == this){
        c = this->right;
        p->set_left(c);
        this->set_right(p);
      }else{
        c = this->left;
        p->set_right(c);
        this->set_left(p);
      }

      if(pp){
        if(pp->left == p) pp->left = this;
        if(pp->right == p) pp->right = this;
      }

      this->parent = pp;

      p->update();
      this->update();
    }

    int status(){
      if(!this->parent) return 0;
      if(this->parent->left == this) return 1;
      if(this->parent->right == this) return -1;
      return 0;
    }

    void splay(){
      while(status() != 0){
        if(this->parent->status() == 0){
          this->rotate();
        }else if(this->status() == this->parent->status()){
          this->parent->rotate();
          this->rotate();
        }else{
          this->rotate();
          this->rotate();
        }
      }
    }

    void update(){
      this->size = 1;
      if(this->left) this->size += this->left->size;
      if(this->right) this->size += this->right->size;

      this->result = this->value;
      if(this->left) this->result = M(this->result, this->left->result);
      if(this->right) this->result = M(this->result, this->right->result);
    }

    void set_left(node *l){
      this->left = l;
      if(l) l->parent = this;
    }

    void set_right(node *r){
      this->right = r;
      if(r) r->parent = this;
    }

    static node* get(node *root, int index){
      if(!root) return root;
      node *cur = root;

      while(1){
        int lsize = cur->left ? cur->left->size : 0;

        if(index < lsize){
          cur = cur->left;
        }else if(index == lsize){
          cur->splay();
          return cur;
        }else{
          cur = cur->right;
          index -= lsize + 1;
        }
      }
    }

    static node* merge(node *left, node *right){
      if(!left) return right;
      if(!right) return left;

      node *cur = node::get(left, left->size - 1);

      cur->right = right;
      right->parent = cur;

      right->update();
      cur->update();

      return cur;
    }

    static std::pair<node*, node*> split(node *root, int index){
      if(!root) return std::make_pair(nullptr, nullptr);
      if(index >= root->size) return std::make_pair(root, nullptr);

      auto *cur = node::get(root, index);
      auto *left = cur->left;

      if(left) left->parent = nullptr;
      cur->left = nullptr;

      if(left) left->update();
      cur->update();

      return std::make_pair(left, cur);
    }

    template <typename Func>
    static void traverse(node *cur, const Func &f){
      if(cur){
        traverse(cur->left, f);
        f(*cur);
        traverse(cur->right, f);
      }
    }
  };

  template <typename Monoid>
  struct SplayTree {
    using node = SplayNode<Monoid>;
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    node *root;

    SplayTree(): root(nullptr){}
    SplayTree(node *root): root(root){}
    SplayTree(int N): root(nullptr){
      for(int i = 0; i < N; ++i) push_back(M());
    }

    static auto singleton(const value_type &value){return SplayTree(new node(value));}

    int size() const {return root ? root->size : 0;}
    bool empty() const {return !root;}

    const value_type get(int index){root = node::get(root, index); return root->value;}
    const value_type operator[](int index){return get(index);}

    void update(int index, const value_type &value){
      root = node::get(root, index); root->value = value; root->update();
    }

    void merge_right(SplayTree &right){
      root = node::merge(root, right.root); right.root = nullptr;
    }

    void merge_left(SplayTree &left){
      root = node::merge(left.root, root); left.root = nullptr;
    }

    auto split(int index){
      node *left, *right; std::tie(left, right) = node::split(root, index);
      return std::make_pair(SplayTree(left), SplayTree(right));
    }

    void insert(int index, const value_type &value){
      auto s = node::split(root, index);
      root = node::merge(s.first, node::merge(new node(value), s.second));
    }

    void erase(int index){
      node *left, *right;
      std::tie(left, right) = node::split(root, index);
      std::tie(std::ignore, right) = node::split(right, 1);
      root = node::merge(left, right);
    }

    const value_type fold(){return root->result;}
    const value_type fold(int l, int r){ // [l, r)
      node *left, *mid, *right;
      std::tie(mid, right) = node::split(root, r);
      std::tie(left, mid) = node::split(mid, l);

      auto ret = mid->result;

      mid = node::merge(left, mid);
      root = node::merge(mid, right);

      return ret;
    }

    void push_back(const value_type &value){insert(size(), value);}
    void push_front(const value_type &value){insert(0, value);}

    void pop_back(){erase(size() - 1);}
    void pop_front(){erase(0);}

    template <typename Func>
    void traverse(const Func &f) const {
      node::traverse(root, f);
    }
  };
}
