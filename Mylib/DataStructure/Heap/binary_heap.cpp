#pragma once
#include <vector>
#include <functional>
#include <utility>

/**
 * @title BinaryHeap
 * @docs binary_heap.md
 */
template <typename T, typename Compare = std::less<T>>
struct BinaryHeap{
  std::vector<T> data;

  BinaryHeap(){}
  BinaryHeap(size_t capacity){data.reserve(capacity);}

  void push(T value){
    data.emplace_back(value);

    int i = data.size();

    while(i > 1){
      int p = i >> 1;
      if(Compare()(data[p-1], data[i-1])){
        std::swap(data[i-1], data[p-1]);
        i = p;
      }else{
        break;
      }
    }
  }

  T top() const {
    return data.front();
  }

  void pop(){
    data.front() = data.back();
    data.pop_back();

    int i = 1;

    while(1){
      int left = i << 1 | 0;
      int right = i << 1 | 1;

      if((int)data.size() < left){
        break;
      }else if((int)data.size() < right){
        if(Compare()(data[i-1], data[left-1])){
          std::swap(data[left-1], data[i-1]);
          i = left;
        }else{
          break;
        }
      }else{
        if(Compare()(data[left-1], data[i-1]) and Compare()(data[right-1], data[i-1])){
          break;
        }else{
          if(Compare()(data[right-1], data[left-1])){
            std::swap(data[left-1], data[i-1]);
            i = left;
          }else{
            std::swap(data[right-1], data[i-1]);
            i = right;
          }
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
