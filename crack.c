#define _XOPEN_SOURCE
#define PASSWORDLENGTH 5
//#define PASS_POSSIBLE_CHAR 52

#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int carryover(char guesser[PASSWORDLENGTH], int spot, int carry);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //creates salt, first 2 leters of the hashed command line argument argv[1]
        char salt[3];
        strncpy(salt,argv[1],2);

        char guess[5] = {'a'};
        int carrier = 0;
        int i = 0;

       while(strcmp(crypt(guess, salt), argv[1]) != 0)
        {
            if(guess[4] == 'Z')
            {
                return 0;
            }
            if(carrier == 1)
            {
                if(i + 1 > 4)
                {
                    i = 0;
                }
                else
                {
                    i += 1;
                }
            }
            else
            {
                i = 0;
            }
            carrier = carryover(guess,i,carrier);
            //counter += 1;
        }
        printf("%s\n",guess);

    }
    else
    {
        return 1;
    }
}

int carryover(char guesser[5], int spot, int carry)
{
    if (guesser[spot] == '\0')
    {
        guesser[spot] = 'a';
        carry = 0;
    }
    else if(guesser[spot] != 'Z')
    {
        if(guesser[spot] == 'z')
        {
            guesser[spot] = 'A';
        }
        else
        {
            guesser[spot] += 1;
        }
        carry = 0;
    }
    else
    {
        guesser[spot] = 'a';
        carry = 1;
    }
    return carry;
}
