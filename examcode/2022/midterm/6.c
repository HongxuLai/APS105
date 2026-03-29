/*
A palindrome is a word, number, phrase or any sequence of characters that read the same forward
and backward. Given a sequence of characters in a char-type array, named sequence, and the size
of the array size, complete the definition of the function isPalindrome(), the prototype of which
is given below, that returns true if the sequence of characters makes a palindrome, and false
otherwise. We assume that the array sequence has at least one element, i.e. size is at least 1.
For example if sequence holds ‘r’, ‘a’, ‘d’, ‘a’, ‘r’, then your function should return true.
This is because if we reverse radar, it will read the same. However, if sequence is holding ‘f’,
‘l’, ‘a’, ‘g’, then your function will return false, because galf is not the same as flag. For an
array with only one element, it is considered a palindrome.
Note: Do not change the contents of the array sequence or create another array. Do not use
recursion.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char sequence[], int size)
{
    int len = strlen(sequence);
    int low = 0;
    int high = len - 1;
    while(low < high)
    {
        if(sequence[low] != sequence[high]) return false;
        else 
        {
            low ++;
            high --;
        }
    }
    return true;
}

int main()
{
    return 0;
}

