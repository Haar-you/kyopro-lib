#pragma once

/**
 * @title 上位集合を昇順に列挙
 * @docs for_each_superset_asc.md
 */
class SupersetAsc{
  struct iter{
    int t, a, n;
    bool is_end;

    int operator*() const {return t;}
    void operator++(){
      t = (t + 1) | a;
      if(t >= (1 << n)) is_end = true;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int a, n;

public:
  SupersetAsc(int a, int n): a(a), n(n){}
  iter begin() const {return iter({a, a, n, false});}
  iter end() const {return iter();}
};
