#pragma once
#include <utility>
#include <tuple>

/**
 * @title スプレー木
 * @docs splay_tree.md
 */
namespace splay_tree{
  template <typename Monoid>
  struct SplayNode{
    using node = SplayNode<Monoid>;
    using value_type = typename Monoid::value_type;
    
    node *left = nullptr, *right = nullptr, *parent = nullptr;
    int size;
    value_type value = Monoid::id(), result = Monoid::id();

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
      if(this->left) this->result = Monoid::op(this->result, this->left->result);
      if(this->right) this->result = Monoid::op(this->result, this->right->result);
    }

    void set_left(node *l){
      this->left = l;
      if(l) l->parent = this;
    }

    void set_right(node *r){
      this->right = r;
      if(r) r->parent = this;
    }

    inline static node* get(node *root, int index){
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

    inline static node* merge(node *left, node *right){
      if(!left) return right;
      if(!right) return left;
      
      node *cur = node::get(left, left->size - 1);

      cur->right = right;
      right->parent = cur;

      right->update();
      cur->update();

      return cur;
    }

    inline static std::pair<node*, node*> split(node *root, int index){
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
    inline static void traverse(node *cur, const Func &f){
      if(cur){
        traverse(cur->left, f);
        f(*cur);
        traverse(cur->right, f);
      }
    }
  };

  template <typename Monoid>
  struct SplayTree{
    using node = SplayNode<Monoid>;
    using value_type = typename Monoid::value_type;

    node *root;
    
    SplayTree(): root(nullptr){}
    SplayTree(node *root): root(root){}
    SplayTree(int N): root(nullptr){
      for(int i = 0; i < N; ++i) push_back(Monoid::id());
    }

    static auto singleton(const value_type &value){return SplayTree(new node(value));}

    inline int size() const {return root ? root->size : 0;}
    inline bool empty() const {return !root;}
  
    inline const value_type get(int index){root = node::get(root, index); return root->value;}
    inline const value_type operator[](int index){return get(index);}

    inline void update(int index, const value_type &value){
      root = node::get(root, index); root->value = value; root->update();
    }
    
    inline void merge_right(SplayTree &right){
      root = node::merge(root, right.root); right.root = nullptr;
    }
    inline void merge_left(SplayTree &left){
      root = node::merge(left.root, root); left.root = nullptr;
    }

    inline auto split(int index){
      node *left, *right; std::tie(left, right) = node::split(root, index);
      return std::make_pair(SplayTree(left), SplayTree(right));
    }
    
    inline void insert(int index, const value_type &value){
      auto s = node::split(root, index);
      root = node::merge(s.first, node::merge(new node(value), s.second));
    }

    inline void erase(int index){
      node *left, *right;
      std::tie(left, right) = node::split(root, index);
      std::tie(std::ignore, right) = node::split(right, 1);
      root = node::merge(left, right);
    }

    inline const value_type fold(){return root->result;}
    inline const value_type fold(int l, int r){ // [l, r)
      node *left, *mid, *right;
      std::tie(mid, right) = node::split(root, r);
      std::tie(left, mid) = node::split(mid, l);

      auto ret = mid->result;

      mid = node::merge(left, mid);
      root = node::merge(mid, right);

      return ret;
    }

    inline void push_back(const value_type &value){insert(size(), value);}
    inline void push_front(const value_type &value){insert(0, value);}

    inline void pop_back(){erase(size() - 1);}
    inline void pop_front(){erase(0);}

    template <typename Func>
    inline void traverse(const Func &f) const {
      node::traverse(root, f);
    }
  };
}
