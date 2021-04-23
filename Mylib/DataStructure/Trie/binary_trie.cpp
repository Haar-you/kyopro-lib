#pragma once
#include <vector>

namespace haar_lib {
  template <typename T, unsigned int B>
  class binary_trie {
  public:
    using value_type = T;

  protected:
    struct node {
      int count;
      node *ch[2];
      node() : count(0) {
        ch[0] = ch[1] = nullptr;
      }
    };

    node *root_ = nullptr;

  protected:
    int count(node *t) const { return t ? t->count : 0; }

    int count(node *t, T val, unsigned int depth = 1) const {
      if (not t) return 0;

      if (depth > B) return t->count;

      int b = (val >> (B - depth)) & 1;
      return count(t->ch[b], val, depth + 1);
    }

  public:
    int count(T val) const {
      return count(root_, val);
    }

  public:
    int size() const { return root_ ? root_->count : 0; }
    bool empty() const { return not root_; }

  protected:
    void to_list(node *t, T val, std::vector<T> &ret) const {
      if (not t) return;
      if (not t->ch[0] and not t->ch[1])
        for (int i = 0; i < t->count; ++i) ret.push_back(val);

      if (t->ch[0]) to_list(t->ch[0], val << 1, ret);
      if (t->ch[1]) to_list(t->ch[1], (val << 1) | 1, ret);
    }

  public:
    std::vector<T> to_list() const {
      std::vector<T> ret;
      to_list(root_, 0, ret);
      return ret;
    }

  protected:
    node *insert(node *t, T val, unsigned int depth = 1) {
      if (not t) t = new node();

      ++(t->count);
      if (depth > B) return t;

      int b    = (val >> (B - depth)) & 1;
      t->ch[b] = insert(t->ch[b], val, depth + 1);
      return t;
    }

  public:
    void insert(T val) {
      root_ = insert(root_, val);
    }

  protected:
    node *erase(node *t, T val, unsigned int depth = 1) {
      if (not t) return t;

      --(t->count);
      if (t->count == 0) return nullptr;
      if (depth > B) return t;

      int b    = (val >> (B - depth)) & 1;
      t->ch[b] = erase(t->ch[b], val, depth + 1);
      return t;
    }

  public:
    void erase(T val) {
      root_ = erase(root_, val);
    }

  protected:
    T min_element(node *t, T diff, unsigned int depth = 1) const {
      if (depth > B) return 0;
      int b = (diff >> (B - depth)) & 1;
      b ^= not t->ch[b];
      return min_element(t->ch[b], diff, depth + 1) | (b << (B - depth));
    }

  public:
    T min_element(T diff = 0) const {
      return min_element(root_, diff);
    }

  protected:
    T max_element(node *t, T diff, unsigned int depth = 1) const {
      if (depth > B) return 0;
      int b = not((diff >> (B - depth)) & 1);
      b ^= not t->ch[b];
      return max_element(t->ch[b], diff, depth + 1) | (b << (B - depth));
    }

  public:
    T max_element(T diff = 0) const {
      return max_element(root_, diff);
    }

  protected:
    T at(node *t, int index, unsigned int depth = 1) const {
      if (depth > B) return 0;

      int c = count(t->ch[0]);
      if (t->ch[0] and index < c)
        return at(t->ch[0], index, depth + 1);
      else
        return at(t->ch[1], index - c, depth + 1) | ((T) 1 << (B - depth));
    }

  public:
    T at(int index) const {
      return at(index);
    }

  protected:
    int lower_bound(node *t, T val, unsigned int depth = 1) const {
      if (not t) return 0;
      int b = (val >> (B - depth)) & 1;
      return (b ? count(t->ch[0]) : 0) + lower_bound(t->ch[b], val, depth + 1);
    }

  public:
    int lower_bound(T val) const {
      return lower_bound(root_, val);
    }

    int upper_bound(T val) const {
      return lower_bound(root_, val + 1);
    }
  };
}  // namespace haar_lib
