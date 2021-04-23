#pragma once
#include <algorithm>
#include <map>
#include <string>
#include <string_view>
#include <vector>

namespace haar_lib {
  class palindromic_tree {
    struct node {
      int length;
      int count;
      std::map<char, node *> children;
      node *suffix_link;
      std::vector<node *> reverse_suffix_links;
    };

    node *even_root_, *odd_root_;
    int size_ = 2;

  public:
    palindromic_tree() {}
    palindromic_tree(const std::string_view &s) {
      even_root_         = new node();
      even_root_->length = 0;

      odd_root_         = new node();
      odd_root_->length = -1;

      even_root_->suffix_link = odd_root_;
      odd_root_->reverse_suffix_links.emplace_back(even_root_);

      node *cur = odd_root_;

      const int N = s.size();

      for (int i = 0; i < N; ++i) {
        node *t = cur;

        while (1) {
          if (i - t->length - 1 >= 0 and s[i] == s[i - t->length - 1]) {
            if (t->children.find(s[i]) == t->children.end()) {
              node *a           = new node();
              a->length         = t->length + 2;
              a->count          = 1;
              t->children[s[i]] = a;
              ++size_;
            } else {
              t->children[s[i]]->count += 1;
            }
            break;
          } else {
            t = t->suffix_link;
          }
        }

        node *next = t->children[s[i]];

        if (not next->suffix_link) {
          if (next->length == 1) {
            next->suffix_link = even_root_;
            even_root_->reverse_suffix_links.emplace_back(next);
          } else {
            node *p = cur;

            while (1) {
              if (p != t) {
                if (i - p->length - 1 >= 0 and s[i] == s[i - p->length - 1]) {
                  next->suffix_link = p->children[s[i]];
                  p->children[s[i]]->reverse_suffix_links.emplace_back(next);
                  break;
                } else {
                  p = p->suffix_link;
                }
              } else {
                p = p->suffix_link;
              }
            }
          }
        }

        cur = next;
      }
    }

    int size() const {
      return size_;
    }

  private:
    int longest_(node *t) const {
      int ret = t->length;
      for (auto &p : t->children) ret = std::max(ret, longest_(p.second));
      return ret;
    }

  public:
    int longest() const {
      int ret = std::max(longest_(odd_root_), longest_(even_root_));
      return ret;
    }

  private:
    int count_sub_palindromes_(node *t, int &c) const {
      int ret = t->count;

      for (auto &s : t->reverse_suffix_links) {
        ret += count_sub_palindromes_(s, c);
      }

      if (t != odd_root_ and t != even_root_) c += ret;

      return ret;
    }

  public:
    int count_sub_palindromes() const {
      int ret = 0;
      count_sub_palindromes_(odd_root_, ret);
      return ret;
    }
  };
}  // namespace haar_lib
