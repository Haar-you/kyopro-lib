#pragma once

/**
 * @title サイズKの集合を列挙
 * @docs for_subsets_of_size_k.md
 */
class KSubsets{
  struct iter{
    int c, n;
    bool is_end;

    int operator*() const {return c;}
    void operator++(){
      int x = c & (-c);
      int y = c + x;

      c = ((c & ~y) / x >> 1) | y;

      if(c >= 1 << n) is_end = true;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int k, n;

public:
  KSubsets(int k, int n): k(k), n(n){}
  iter begin() const {return iter({(1 << k) - 1, n, false});}
  iter end() const {return iter();}
};
