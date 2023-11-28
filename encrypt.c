/**********************************************************************
 *  Encrypt a file using subset-sum algorithm.
 *
 *  Compiliation:   % gcc226 encrypt.c key.c -o encrypt
 *  Execution:      % encrypt password < rand8.txt
 *                  vbskbezp
 *
 *  Note: need to set C = 8 in key.h before compiling and executing
 *        with rand8.txt.
 *
 **********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "key.h"

int main(int argc, char *argv[]) {
   int i;
   unsigned char buffer[C+1];     // temporary string buffer 
   Key password;                  // the user supplied password
   Key encrypted;                 // the encrypted password
   Key T[N];                      // the table T

   if (argc != 2) exit(EXIT_FAILURE);

   password = KEYinit((unsigned char *) argv[1]);
   // print out input password
   printf("   ");
   KEYshow(password);
   printf("\n");

   // read in table T
   for (i = 0; i < N; i++) {
      scanf("%s", buffer);
        T[i] = KEYinit(buffer);
   }

   // compute subset sum
   encrypted = KEYsubsetsum(password, T);

   // print results
   printf("\n   ");
   KEYshow(encrypted);

   return 0;
}
