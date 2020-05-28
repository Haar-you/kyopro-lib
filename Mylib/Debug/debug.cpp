#include <bits/stdc++.h>


template <typename T> void dump_aux(std::vector<T>);
template <typename T, size_t N> void dump_aux(std::array<T,N>);
template <typename T> void dump_aux(std::deque<T>);
template <typename T> void dump_aux(std::stack<T>);
template <typename T> void dump_aux(std::queue<T>);
template <typename T> void dump_aux(std::priority_queue<T>);
template <typename T, typename Container, typename Compare> void dump_aux(std::priority_queue<T,Container,Compare>);
template <typename T> void dump_aux(std::set<T>);
template <typename T> void dump_aux(std::unordered_set<T>);
template <typename T, typename U> void dump_aux(std::map<T,U>);
template <typename T, typename U> void dump_aux(std::unordered_map<T,U>);

template <typename T, typename U> void dump_aux(std::pair<T,U>);
template <typename... T> void dump_aux(std::tuple<T...>);

template <typename T> void dump_aux(std::list<T>);
template <typename T> void dump_aux(std::forward_list<T>);

template <typename T> void dump_aux(std::multiset<T>);
template <typename T> void dump_aux(std::unordered_multiset<T>);
template <typename T, typename U> void dump_aux(std::multimap<T,U>);
template <typename T, typename U> void dump_aux(std::unordered_multimap<T,U>);

template <typename T> void dump_aux(std::complex<T>);

#if __cplusplus >= 201703L
template <typename T> void dump_aux(std::optional<T>);
#endif

void dump_aux(bool);
void dump_aux(int);
void dump_aux(double);
void dump_aux(std::string);
void dump_aux(char);

template <size_t N> void dump_aux(const char (&)[N]);
template <typename T, size_t N> void dump_aux(const T (&)[N]);

template <typename T> void dump_aux(T);


void dump(){}

template <class Head, class... Tail>
void dump(Head&& head, Tail&&... tail){
  std::cerr << "\e[1;32m";
  dump_aux(head);
  std::cerr << "\e[m" << std::endl;
  dump(std::forward<Tail>(tail)...);
}

template <typename Iter> void dump_container(Iter first, Iter last){
  std::cerr << "{";
  for(auto it = first; it != last; ++it){
    if(it != first) std::cerr << ",";
    dump_aux(*it);
  }
  std::cerr << "}";
}

// vector
template <typename T> void dump_aux(std::vector<T> val){
  dump_container(val.begin(), val.end());
}

// array
template <typename T, size_t N> void dump_aux(std::array<T,N> val){
  dump_container(val.begin(), val.end());
}

// deque
template <typename T> void dump_aux(std::deque<T> val){
  dump_container(val.begin(), val.end());
}

// stack
template <typename T> void dump_aux(std::stack<T> val){
  int N = val.size();

  std::cerr << "{";
  for(int i = 0; i < N; ++i){
    if(i) std::cerr << ",";
    auto x = val.top(); val.pop();
    dump_aux(x);
  }
  std::cerr << "}";
}

// queue
template <typename T> void dump_aux(std::queue<T> val){
  int N = val.size();

  std::cerr << "{";
  for(int i = 0; i < N; ++i){
    if(i) std::cerr << ",";
    auto x = val.front(); val.pop();
    dump_aux(x);
  }
  std::cerr << "}";
}

// priority_queue
template <typename T> void dump_aux(std::priority_queue<T> val){
  int N = val.size();

  std::cerr << "{";
  for(int i = 0; i < N; ++i){
    if(i) std::cerr << ",";
    auto x = val.top(); val.pop();
    dump_aux(x);
  }
  std::cerr << "}";
}

template <typename T, typename Container, typename Compare> void dump_aux(std::priority_queue<T,Container,Compare> val){
  int N = val.size();

  std::cerr << "{";
  for(int i = 0; i < N; ++i){
    if(i) std::cerr << ",";
    auto x = val.top(); val.pop();
    dump_aux(x);
  }
  std::cerr << "}";
}

// set
template <typename T> void dump_aux(std::set<T> val){
  dump_container(val.begin(), val.end());
}

// unrodered_set
template <typename T> void dump_aux(std::unordered_set<T> val){
  dump_container(val.begin(), val.end());
}

// map
template <typename T, typename U> void dump_aux(std::map<T,U> val){
  dump_container(val.begin(), val.end());
}

// unordered_map
template <typename T, typename U> void dump_aux(std::unordered_map<T,U> val){
  dump_container(val.begin(), val.end());
}


// pair
template <typename T, typename U> void dump_aux(std::pair<T,U> val){
  std::cerr << "(";
  dump_aux(val.first);
  std::cerr<< ",";
  dump_aux(val.second);
  std::cerr << ")";
}

// tuple
template <typename T, size_t N>
struct TuplePrintHelper{
  static void print(T val){
    TuplePrintHelper<T,N-1>::print(val);
    std::cerr << ",";
    dump_aux(std::get<N-1>(val));
  }
};

template <typename T>
struct TuplePrintHelper<T,1>{
  static void print(T val){
    dump_aux(std::get<0>(val));
  }
};

template <typename... T> void dump_aux(std::tuple<T...> val){
  std::cerr << "(";
  TuplePrintHelper<std::tuple<T...>, sizeof...(T)>::print(val);
  std::cerr << ")";
}


// list
template <typename T> void dump_aux(std::list<T> val){
  dump_container(val.begin(), val.end());
}

// forward_list
template <typename T> void dump_aux(std::forward_list<T> val){
  dump_container(val.begin(), val.end());
}

// multiset
template <typename T> void dump_aux(std::multiset<T> val){
  dump_container(val.begin(), val.end());
}

// unordered_multiset
template <typename T> void dump_aux(std::unordered_multiset<T> val){
  dump_container(val.begin(), val.end());
}

// multimap
template <typename T, typename U> void dump_aux(std::multimap<T,U> val){
  dump_container(val.begin(), val.end());
}

// unordered_multimap
template <typename T, typename U> void dump_aux(std::unordered_multimap<T,U> val){
  dump_container(val.begin(), val.end());
}

// complex number
template <typename T> void dump_aux(std::complex<T> val){
  std::cerr << val.real() << (val.imag() < 0 ? "" : "+") << val.imag() << "i";
}

#if __cplusplus >= 201703L

// optional
template <typename T> void dump_aux(std::optional<T> val){
  std::cerr << "{";
  if(val.has_value()){
    dump_aux(val.value());
  }
  std::cerr << "}";
}

#endif

// others
void dump_aux(bool val){
  if(val){
    std::cerr << "true";
  }else{
    std::cerr << "false";
  }
}

void dump_aux(int val){
  std::cerr << val;
}

void dump_aux(double val){
  std::cerr << val;
}

void dump_aux(std::string val){
  std::cerr << "\"" << val << "\"";
}

void dump_aux(char val){
  std::cerr << "'" << val << "'";
}

// array

template <size_t N> void dump_aux(const char (&val)[N]){
  std::cerr << "\"" << val << "\"";
}

template <typename T, size_t N> void dump_aux(const T (&val)[N]){
  std::cerr << "{";
  for(int i = 0; i < (int)N; ++i){
    if(i) std::cerr << ",";
    std::cerr << val[i];
  }
  std::cerr << "}";
}

template <typename T> void dump_aux(T val){
  std::cerr << val;
}
