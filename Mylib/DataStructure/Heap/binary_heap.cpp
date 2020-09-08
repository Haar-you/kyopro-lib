#pragma once
#include <vector>
#include <functional>
#include <utility>

/**
 * @title Binary heap
 * @docs binary_heap.md
 */
namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class BinaryHeap {
    std::vector<T> data;

    int left(int i) const {return i * 2 + 1;}
    int right(int i) const {return i * 2 + 2;}
    int parent(int i) const {return (i - 1) >> 1;}

    Compare compare;

  public:
    BinaryHeap(): compare(Compare()){}
    BinaryHeap(size_t capacity): compare(Compare()){data.reserve(capacity);}

    void push(T value){
      data.emplace_back(value);

      int i = (int)data.size() - 1;

      while(i > 0){
        int p = parent(i);
        if(compare(data[i], data[p])) break;
        std::swap(data[i], data[p]);
        i = p;
      }
    }

    T top() const {
      return data.front();
    }

    void pop(){
      data.front() = data.back();
      data.pop_back();

      int i = 0;

      while(1){
        int l = left(i);
        int r = right(i);

        if((int)data.size() <= l) break;
        if((int)data.size() <= r){
          if(compare(data[l], data[i])) break;
          std::swap(data[l], data[i]);
          i = l;
        }else{
          if(compare(data[l], data[i]) and compare(data[r], data[i])) break;
          if(compare(data[r], data[l])){
            std::swap(data[l], data[i]);
            i = l;
          }else{
            std::swap(data[r], data[i]);
            i = r;
          }
        }
      }
    }

    bool empty() const {
      return data.empty();
    }

    size_t size() const {
      return data.size();
    }
  };
}
