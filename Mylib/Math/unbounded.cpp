#pragma once
#include <iostream>

template <typename T>
struct unbounded {
private:
  enum class tag_t { POSITIVE_INFINITY, NEGATIVE_INFINITY, FINITE } tag_;
  T value_;

  unbounded(tag_t tag_): tag_(tag_){}

public:
  using value_type = T;

  unbounded(): tag_(tag_t::FINITE), value_(T()){}
  unbounded(T value_): tag_(tag_t::FINITE), value_(value_){}
  unbounded(const unbounded<T> &that): tag_(that.tag_), value_(that.value_){}

  bool is_positive_inf() const {return tag_ == tag_t::POSITIVE_INFINITY;}
  bool is_negative_inf() const {return tag_ == tag_t::NEGATIVE_INFINITY;}
  bool is_finite() const {return tag_ == tag_t::FINITE;}

  T value() const {return value_;}
  T& value(){return value_;}

  static auto positive_inf(){
    return unbounded(tag_t::POSITIVE_INFINITY);
  }

  static auto negative_inf(){
    return unbounded(tag_t::NEGATIVE_INFINITY);
  }

  friend std::ostream& operator<<(std::ostream &s, const unbounded &a){
    switch(a.tag_){
    case tag_t::POSITIVE_INFINITY: s << "∞"; break;
    case tag_t::NEGATIVE_INFINITY: s << "-∞"; break;
    case tag_t::FINITE: s << a.value_;
    }
    return s;
  }

  unbounded operator-() const {
    if(is_finite()) return -value_;
    else if(is_positive_inf()) return unbounded::negative_inf();
    return unbounded::positive_inf();
  }

  auto& operator+=(unbounded that){
    if(is_finite()){
      if(that.is_finite()) value_ += that.value_;
      else tag_ = that.tag_;
    }
    return *this;
  }

  auto operator+(unbounded that) const {
    return unbounded(*this) += that;
  }

  auto& operator-=(unbounded that){
    return (*this) += (-that);
  }

  auto operator-(unbounded that) const {
    return unbounded(*this) -= that;
  }

  int compare(unbounded that) const {
    if(is_positive_inf()){
      if(that.is_positive_inf()) return 0;
      else return 1;
    }else if(is_negative_inf()){
      if(that.is_negative_inf()) return 0;
      else return -1;
    }else{
      if(that.is_positive_inf()) return -1;
      else if(that.is_negative_inf()) return 1;
      else return (value_ > that.value_) - (value_ < that.value_);
    }
  }

  bool operator==(unbounded that) const {return compare(that) == 0;}
  bool operator!=(unbounded that) const {return compare(that) != 0;}
  bool operator<(unbounded that) const {return compare(that) < 0;}
  bool operator<=(unbounded that) const {return compare(that) <= 0;}
  bool operator>(unbounded that) const {return compare(that) > 0;}
  bool operator>=(unbounded that) const {return compare(that) >= 0;}
};
