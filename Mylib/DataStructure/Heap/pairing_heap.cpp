#pragma once
#include <functional>
#include <vector>

namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class pairing_heap {
  public:
    using value_type = T;

  private:
    struct node_ {
      T value;
      std::vector<node_*> ch;
      node_(const T &value): value(value){}
    };

    Compare compare_;
    node_ *root_ = nullptr;
    size_t size_ = 0;

    node_* merge_(node_ *a, node_ *b){
      if(not a) return b;
      if(not b) return a;
      if(compare_(b->value, a->value)){
        a->ch.push_back(b);
        return a;
      }else{
        b->ch.push_back(a);
        return b;
      }
    }

    node_* merge_list_(node_ *a){
      if((a->ch.size() & 1) == 1) a->ch.push_back(nullptr);

      for(size_t i = 0; i < a->ch.size(); i += 2){
        a->ch[i >> 1] = merge_(a->ch[i], a->ch[i + 1]);
      }

      a->ch.resize(a->ch.size() / 2);

      node_ *ret = nullptr;
      for(int i = a->ch.size(); --i >= 0;){
        ret = merge_(ret, a->ch[i]);
      }

      return ret;
    }

  public:
    pairing_heap(): compare_(Compare()){}
    pairing_heap(const Compare &compare_): compare_(compare_){}

    void meld(pairing_heap &that){
      root_ = merge_(root_, that.root_);
      that.root_ = nullptr;
      size_ += that.size_;
      that.size_ = 0;
    }
    void push(const T &val){root_ = merge_(root_, new node_(val)); ++size_;}
    void pop(){root_ = merge_list_(root_); --size_;}
    const T& top() const {return root_->value;}
    bool empty() const {return root_ == nullptr;}
    size_t size() const {return size_;}
  };
}
