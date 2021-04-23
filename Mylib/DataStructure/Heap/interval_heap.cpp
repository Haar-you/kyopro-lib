#pragma once
#include <array>
#include <functional>
#include <utility>

namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class interval_heap {
  public:
    using value_type = T;

  private:
    Compare compare_;
    std::vector<T> data_;

    int left(int i) const { return i * 2 + 1; }
    int right(int i) const { return i * 2 + 2; }
    int parent(int i) const { return (i - 1) >> 1; }
    bool check(int i) const { return i < ((int) data_.size() + 1) / 2; }
    int back() const { return ((int) data_.size() - 1) / 2; }
    bool is_singleton(int i) const { return i == back() and data_.size() % 2 == 1; }
    int get_min_element(int i) const { return is_singleton(i) ? (int) data_.size() - 1 : 2 * i; }
    int get_max_element(int i) const { return is_singleton(i) ? (int) data_.size() - 1 : 2 * i + 1; }

    bool merge(int &parent, int &child) {
      if (is_singleton(child)) {
        auto &a = data_[get_min_element(parent)];
        auto &b = data_[get_max_element(parent)];
        auto &x = data_[get_min_element(child)];

        if (compare_(x, a)) {
          std::swap(x, a);
        } else if (compare_(b, x)) {
          std::swap(b, x);
        } else {
          return false;
        }
      } else {
        std::array<int, 4> a =
            {
                get_min_element(parent),
                get_min_element(child),
                get_max_element(child),
                get_max_element(parent)};

        if (compare_(data_[a[0]], data_[a[1]]) and
            compare_(data_[a[1]], data_[a[2]]) and
            compare_(data_[a[2]], data_[a[3]])) return false;

        for (int i = 0; i < 4; ++i) {
          for (int j = i + 1; j < 4; ++j) {
            if (not compare_(data_[a[i]], data_[a[j]])) std::swap(data_[a[i]], data_[a[j]]);
          }
        }
      }

      return true;
    }

    void top_down(int i, bool is_min_modified) {
      while (1) {
        int l = left(i), r = right(i);

        if (not check(l)) break;

        if (check(r)) {
          if (is_min_modified) {
            if (compare_(data_[get_min_element(l)], data_[get_min_element(r)])) {
              if (not merge(i, l)) break;
              i = l;
            } else {
              if (not merge(i, r)) break;
              i = r;
            }

          } else {
            if (compare_(data_[get_max_element(l)], data_[get_max_element(r)])) {
              if (not merge(i, r)) break;
              i = r;
            } else {
              if (not merge(i, l)) break;
              i = l;
            }
          }
        } else {
          if (not merge(i, l)) break;
          i = l;
        }
      }
    }

    void bottom_up(int i) {
      while (i > 0) {
        int p = parent(i);
        if (not merge(p, i)) break;
        i = p;
      }
    }

  public:
    interval_heap() : compare_(Compare()) {}

    const T &get_min() const {
      return data_[get_min_element(0)];
    }

    const T &get_max() const {
      return data_[get_max_element(0)];
    }

    void push(T value) {
      if (data_.size() % 2 == 1 and compare_(value, data_.back())) std::swap(value, data_.back());
      data_.push_back(value);
      bottom_up(back());
    }

    void pop_min() {
      std::swap(data_[get_min_element(0)], data_.back());
      data_.pop_back();
      top_down(0, true);
    }

    void pop_max() {
      std::swap(data_[get_max_element(0)], data_.back());
      data_.pop_back();
      top_down(0, false);
    }

    bool empty() const {
      return data_.empty();
    }

    int size() const {
      return data_.size();
    }
  };
}  // namespace haar_lib
