#pragma once
#include <cstdio>
#include <cstddef>
#include <cctype>

void memory_dump(const void* p, size_t size){
  unsigned char *cur = (unsigned char*)p;

  printf("                 | 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\n");
  printf("__________________________________________________________________\n");

  size_t padding = (size_t)cur % 0x10;
  size += padding;
  cur -= padding;

  char temp[17];

  size_t i = 0;
  for(; i < size; ++i){
    if(i % 16 == 0){
      if(i != 0){
        printf("|%s|\n", temp);
      }
      printf("%16p | ", cur);
      for(size_t j = 0; j < 16; ++j) temp[j] = ' ';
      temp[16] = '\0';
    }

    printf("%02x ", (int)(*cur));

    if(isprint((char)(*cur))){
      temp[i % 16] = (char)(*cur);
    }else{
      temp[i % 16] = '.';
    }

    ++cur;
  }

  for(size_t k = 0; k < (16 - (i % 16)) % 16; ++k) printf("   ");
  printf("|%s|\n", temp);

  printf("\n");
}
