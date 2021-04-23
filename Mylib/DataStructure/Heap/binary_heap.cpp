#pragma once
#include <functional>
#include <utility>
#include <vector>

namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class binary_heap {
  public:
    using value_type = T;

  private:
    std::vector<T> data_;
    Compare compare_;

    int left(int i) const { return i * 2 + 1; }
    int right(int i) const { return i * 2 + 2; }
    int parent(int i) const { return (i - 1) >> 1; }

  public:
    binary_heap() : compare_(Compare()) {}
    binary_heap(size_t capacity) : compare_(Compare()) { data_.reserve(capacity); }

    void push(T value) {
      data_.emplace_back(value);

      int i = (int) data_.size() - 1;

      while (i > 0) {
        int p = parent(i);
        if (compare_(data_[i], data_[p])) break;
        std::swap(data_[i], data_[p]);
        i = p;
      }
    }

    T top() const {
      return data_.front();
    }

    void pop() {
      data_.front() = data_.back();
      data_.pop_back();

      int i = 0;

      while (1) {
        int l = left(i);
        int r = right(i);

        if ((int) data_.size() <= l) break;
        if ((int) data_.size() <= r) {
          if (compare_(data_[l], data_[i])) break;
          std::swap(data_[l], data_[i]);
          i = l;
        } else {
          if (compare_(data_[l], data_[i]) and compare_(data_[r], data_[i])) break;
          if (compare_(data_[r], data_[l])) {
            std::swap(data_[l], data_[i]);
            i = l;
          } else {
            std::swap(data_[r], data_[i]);
            i = r;
          }
        }
      }
    }

    bool empty() const {
      return data_.empty();
    }

    size_t size() const {
      return data_.size();
    }
  };
}  // namespace haar_lib
