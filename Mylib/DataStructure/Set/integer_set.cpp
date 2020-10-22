#pragma once
#include <map>
#include <optional>
#include <iterator>

namespace haar_lib {
  class integer_set {
    std::map<int64_t, int64_t> data_;
    using citer = typename std::map<int64_t, int64_t>::const_iterator;

    std::optional<citer> get_interval(int64_t x) const {
      if(data_.empty()) return std::nullopt;
      auto next = data_.lower_bound(x);
      if(next == data_.end()){
        auto prev = std::prev(next);
        if(x <= prev->second) return {prev};
        return std::nullopt;
      }
      if(next->first == x) return {next};
      if(next == data_.begin()) return std::nullopt;
      auto prev = std::prev(next);
      if(x <= prev->second) return {prev};
      return std::nullopt;
    }

  public:
    integer_set(){}

    bool contains(int64_t x) const {
      return (bool)get_interval(x);
    }

    void add(int64_t x){
      if(data_.empty()){
        data_[x] = x;
        return;
      }

      auto next = data_.lower_bound(x);
      if(next == data_.end()){
        auto prev = std::prev(next);
        if(x <= prev->second) return;
        if(prev->second + 1 == x){
          prev->second = x;
        }else{
          data_[x] = x;
        }
        return;
      }
      if(next->first == x) return;

      if(next == data_.begin()){
        if(x + 1 == next->first){
          auto t = next->second;
          data_.erase(next);
          data_[x] = t;
        }else{
          data_[x] = x;
        }
        return;
      }

      auto prev = std::prev(next);
      if(x <= prev->second) return;
      if(prev->second + 1 == x){
        prev->second = x;

        if(prev->second + 1 == next->first){
          prev->second = next->second;
          data_.erase(next);
        }
      }else if(x + 1 == next->first){
        auto t = next->second;
        data_.erase(next);
        data_[x] = t;
      }else{
        data_[x] = x;
      }

      return;
    }

    void erase(int64_t x){
      const auto res = get_interval(x);
      if(res){
        const auto it = res.value();
        const auto [l, r] = *it;
        data_.erase(it);
        if(l <= x - 1) data_[l] = x - 1;
        if(x + 1 <= r) data_[x + 1] = r;
      }
    }

    int64_t mex(int64_t x) const {
      auto res = get_interval(x);
      if(res) return (*res)->second + 1;
      return x;
    }
  };
};
