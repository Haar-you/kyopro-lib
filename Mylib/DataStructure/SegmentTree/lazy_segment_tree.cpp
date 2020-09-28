#pragma once
#include <vector>

namespace haar_lib {
  template <typename MonoidGet, typename MonoidUpdate, template <typename, typename> typename Connector>
  class lazy_segment_tree {
  public:
    using value_type_get = typename MonoidGet::value_type;
    using value_type_update = typename MonoidUpdate::value_type;

  private:
    Connector<MonoidGet, MonoidUpdate> M_;
    MonoidGet M_get_;
    MonoidUpdate M_update_;

    int depth_, size_, hsize_;
    std::vector<value_type_get> data_;
    std::vector<value_type_update> lazy_;

    void propagate(int i){
      if(lazy_[i] == M_update_()) return;
      if(i < hsize_){
        lazy_[i << 1 | 0] = M_update_(lazy_[i], lazy_[i << 1 | 0]);
        lazy_[i << 1 | 1] = M_update_(lazy_[i], lazy_[i << 1 | 1]);
      }
      const int len = hsize_ >> (31 - __builtin_clz(i));
      data_[i] = M_(data_[i], lazy_[i], len);
      lazy_[i] = M_update_();
    }

    void propagate_top_down(int i){
      std::vector<int> temp;
      while(i > 1){
        i >>= 1;
        temp.push_back(i);
      }

      for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
    }

    void bottom_up(int i){
      while(i > 1){
        i >>= 1;
        propagate(i << 1 | 0);
        propagate(i << 1 | 1);
        data_[i] = M_get_(data_[i << 1 | 0], data_[i << 1 | 1]);
      }
    }

  public:
    lazy_segment_tree(){}
    lazy_segment_tree(int n):
      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size_(1 << depth_),
      hsize_(size_ / 2),
      data_(size_, M_get_()),
      lazy_(size_, M_update_())
    {}

    void update(int l, int r, const value_type_update &x){
      propagate_top_down(l + hsize_);
      if(r < hsize_) propagate_top_down(r + hsize_);

      int L = l + hsize_, R = r + hsize_;

      while(L < R){
        if(R & 1){
          --R;
          lazy_[R] = M_update_(x, lazy_[R]);
          propagate(R);
        }
        if(L & 1){
          lazy_[L] = M_update_(x, lazy_[L]);
          propagate(L);
          ++L;
        }
        L >>= 1;
        R >>= 1;
      }

      bottom_up(l + hsize_);
      if(r < hsize_) bottom_up(r + hsize_);
    }

    void update(int i, const value_type_update &x){update(i, i + 1, x);}

    value_type_get fold(int l, int r){
      propagate_top_down(l + hsize_);
      if(r < hsize_) propagate_top_down(r + hsize_);

      value_type_get ret_left = M_get_(), ret_right = M_get_();

      int L = l + hsize_, R = r + hsize_;

      while(L < R){
        if(R & 1){
          --R;
          propagate(R);
          ret_right = M_get_(data_[R], ret_right);
        }
        if(L & 1){
          propagate(L);
          ret_left = M_get_(ret_left, data_[L]);
          ++L;
        }
        L >>= 1;
        R >>= 1;
      }

      return M_get_(ret_left, ret_right);
    }

    value_type_get operator[](int i){return fold(i, i + 1);}

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<T>(hsize_, val));
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data_.assign(size_, M_get_());
      lazy_.assign(size_, M_update_());
      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = (value_type_get)val[i];
      for(int i = hsize_; --i > 0;) data_[i] = M_get_(data_[i << 1 | 0], data_[i << 1 | 1]);
    }
  };
}
