#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include <iostream>
#include <string>
#include "Mylib/DataStructure/Heap/binary_heap.cpp"

namespace hl = haar_lib;

int main(){
  hl::binary_heap<int> heap;
  std::string s;

  while(1){
    std::cin >> s;

    if(s == "insert"){
      int k; std::cin >> k;
      heap.push(k);
    }else if(s == "extract"){
      std::cout << heap.top() << "\n";
      heap.pop();
    }else{
      break;
    }
  }

  return 0;
}
