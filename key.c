#include <stdio.h>
#include "key.h"

// return the ith bit of Key k
int KEYbit(Key k, int i)
{
   return (k.digit[i / B] >> (B - 1 - i % B)) & 1;
}

// print out the key in characters, base R, and binary
void KEYshow(Key k)
{
   int i;
   for (i = 0; i < C; i++)
      putchar(ALPHABET[k.digit[i]]);
   printf("  ");
   for (i = 0; i < C; i++)
      printf("%2d ", k.digit[i]);
   printf("  ");
   for (i = 0; i < N; i++)
      printf("%d", KEYbit(k, i));
   putchar('\n');
}

// convert from char to integer 0-31
Key KEYinit(unsigned char s[])
{
   Key k;
   int i, j;
   for (i = 0; i < C; i++)
      for (j = 0; j < R; j++)
         if (s[i] == ALPHABET[j])
            k.digit[i] = j;
   return k;
}

// c = a + b
Key KEYadd(Key a, Key b)
{
   int i;
   Key c = {{0}};
   int carry = 0;
   for (i = C - 1; i >= 0; i--)
   {
      c.digit[i] = (a.digit[i] + b.digit[i] + carry) % R;
      carry = (a.digit[i] + b.digit[i] + carry) >= R;
   }
   return c;
}

// compute sum of subset of T[i] for which ith bit of k is 1
Key KEYsubsetsum(Key k, Key T[N])
{
   int i;
   Key sum = {{0}};
   for (i = 0; i < N; i++)
      if (KEYbit(k, i))
      {
         sum = KEYadd(sum, T[i]);
         printf("%2d ", i); // for debugging
         KEYshow(T[i]);     // for debugging
      }
   return sum;
}
