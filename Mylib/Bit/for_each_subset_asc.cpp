#pragma once

/**
 * @title 下位集合を昇順に列挙
 * @docs for_each_subset_asc.md
 */
class SubsetAsc{
  struct iter{
    int t, a;
    bool is_end;

    int operator*() const {return t;}
    void operator++(){
      if(t == a) is_end = true;
      t = (t - a) & a;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int a;

public:
  SubsetAsc(int a): a(a){}
  iter begin() const {return iter({0, a, false});}
  iter end() const {return iter();}
};
