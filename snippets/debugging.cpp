# -*- mode: snippet -*-
# name: debugging
# key: debugging
# --

#ifdef DEBUG
#include <Mylib/Debug/debug.cpp>
#else
#define dump(...)
#endif