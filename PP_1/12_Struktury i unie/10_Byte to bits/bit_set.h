#ifndef ZAD12_8_BYTE_SET_H
#define ZAD12_8_BYTE_SET_H

union bit_set{
  signed char x;
  struct str{
    unsigned char one: 1;
    unsigned char two: 1;
    unsigned char three: 1;
    unsigned char four: 1;
    unsigned char five: 1;
    unsigned char six: 1;
    unsigned char seven: 1;
    unsigned char eight: 1;
  } str;
};

#endif