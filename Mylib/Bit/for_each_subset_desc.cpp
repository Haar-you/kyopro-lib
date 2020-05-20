#pragma once

/**
 * @title 下位集合を降順に列挙
 * @docs for_each_subset_desc.md
 */
class SubsetDesc{
  struct iter{
    int t, a;
    bool is_end;

    int operator*() const {return t;}
    void operator++(){
      if(t == 0) is_end = true;
      t = (t - 1) & a;
    }
    bool operator!=(const iter &) const {return not is_end;}
  };

  int a;

public:
  SubsetDesc(int a): a(a){}
  iter begin() const {return iter({a, a, false});}
  iter end() const {return iter();}
};
