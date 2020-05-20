#pragma once

/**
 * @title 上位集合を降順に列挙
 * @docs for_each_superset_desc.md
 */
class SupersetDesc{
  struct iter{
    int t, a, y;
    bool is_end;

    int operator*() const {return t | a;}
    void operator++(){
      if(t == 0) is_end = true;
      t = (t - 1) & y;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int a, n, x, y;

public:
  SupersetDesc(int a, int n): a(a), n(n), x((1 << n) - 1), y(x ^ (a & x)){}
  iter begin() const {return iter({y, a, y, false});}
  iter end() const {return iter();}
};
