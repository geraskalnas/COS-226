#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "key.h"

#define SIZE C
// #define DEBUG

bool AreKeysTheSame(Key, Key);

int top = -1, inp_array[SIZE];
void push();
int pop();
int peek();
int length();

int main(int argc, char *argv[])
{
    int i;
    unsigned char buffer[C + 1]; // temporary string buffer
    Key target;                  // is encrypted password
    Key current = {{0}};         // brute force iteration
    Key currentEncrypted;        //

    Key T[N]; // the table T

    if (argc != 2)
        exit(EXIT_FAILURE);

    target = KEYinit((unsigned char *)argv[1]);

    // read in table T
    for (i = 0; i < N; i++)
    {
        scanf("%s", buffer);
        T[i] = KEYinit(buffer);
    }

    bool runFlag = true;
    while (runFlag)
    {
        if (length() < 5)
        {
            push(0);
        }
        else if (peek() != R - 1)
        {
            push(pop() + 1);
        }
        else
        {
            while (peek() == R - 1)
            {
                pop();
            }
            if (length() != 0)
            {
                push(pop() + 1);
            }
            else
            {
                runFlag = false;
            }
        }

        if (length() == SIZE)
        {
            for (i = 0; i < C; i++)
            {
                current.digit[i] = inp_array[i];
            }

            currentEncrypted = KEYsubsetsum(current, T);
            if (AreKeysTheSame(target, currentEncrypted))
            {
                for (i = 0; i < C; i++)
                    putchar(ALPHABET[current.digit[i]]);
                printf("\n");
            }
        }
#if defined(DEBUG)
        else if (C - length() == 4)
        {
            printf("Currently on: ");
            for (i = 0; i < C; i++)
                putchar(ALPHABET[current.digit[i]]);
            printf("\n");
        }
#endif
    }

    return 0;
}

bool AreKeysTheSame(Key key1, Key key2)
{
    for (int i = 0; i < C; i++)
    {
        if (key1.digit[i] != key2.digit[i])
        {
            return false;
        }
    }
    return true;
}

void push(int x)
{
    if (top == SIZE - 1)
    {
#if defined(DEBUG)
        printf("\nOverflow!!");
#endif
    }
    else
    {
        top = top + 1;
        inp_array[top] = x;
    }
}

int pop()
{
    if (top != -1)
    {
        return inp_array[top--];
    }
#if defined(DEBUG)
    printf("\nStack is empty!!!");
#endif
    return -1; // -1 in program will not be used
}

int peek()
{
    return inp_array[top];
}

int length()
{
    return top + 1;
}