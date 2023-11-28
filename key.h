#ifndef KEY_H
#define KEY_H

#include "keysize.h"

#define B 5          // number of bits per character
#define R (1 << B)   // size of alphabet (32)
#define N (B * C)    // number of bits per password

#define ALPHABET "abcdefghijklmnopqrstuvwxyz012345"

// base 64 alphabet
// #define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

/****************************************************************
 * An extended precision base R integer consisting of C digits.
 * An array packaged in a struct for easy memory management and
 * pass-by-value.
 ****************************************************************/
typedef struct {
   unsigned char digit[C];
} Key;


void KEYshow(Key k);              // print k
Key  KEYadd(Key a, Key b);        // return a + b (mod 2^N)
int  KEYbit(Key k, int i);        // return the ith bit of k

/****************************************************************
 * Add and return the subset of the integers T[i] that are 
 * indexed by the bits of k. Do sum mod 2^N.
 ****************************************************************/
Key  KEYsubsetsum(Key k, Key T[N]);

/****************************************************************
 * Initialize k from a character string.
 * Example: s = "abcdwxyz"  =>  k = 0 1 2 3 22 23 24 25
 ****************************************************************/
Key  KEYinit(unsigned char s[]);

#endif
