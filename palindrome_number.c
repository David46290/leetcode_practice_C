#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    
    if (x < 0)
    {
        return false;
    }
    else if (x == 0)
    {
        return true;
    }
    else
    {
        // transforming integer to char array
        // making a char array to store numbers
        // the numbers are the residuals of x divided by 10 
        int count = 0; // count of chars added to the array
        char *char_array = malloc(10 * sizeof(char));
        // and the length of char array can be set to 10
        while (x != 0) // if a single digit is divided by 10, the quotient is zero, and it indicates there's no number left in x
        {
            int residual = x % 10; 
            char_array[count] = residual;
            x = x / 10;
            count++;
        }

        // checking palindrome
        // using left/right index (increasing/decreasing order) to match numbers
        int left_idx = 0;
        int right_idx = count-1;
        while (left_idx < right_idx)
        {
            if (char_array[left_idx] != char_array[right_idx])
            {
                free(char_array);
                return false;
            }
            else
            {
                left_idx++;
                right_idx--;
            }
        }
        free(char_array);
        return true;
    }
    
}

bool isPalindrome2(int x)
{
    // if 'x is negative' or 'x is not 0' and 'x can be divided by 10'
    // x is definitely not palindrome
    if(x < 0 || x != 0 && x % 10 == 0 ) return false;
    int check = 0;
    // check will be the reversed version of 'the latter half of x'
     // and x will be 'the former half of x'
    while(x > check) 
    {
        check = check * 10 + x % 10; // add the last digit of x to check
        x /= 10; // remove the last digit from x
    }
    return (x == check || x == check/10);
}

int main(void)
{
    int num = 10;
    printf("number: ");
    scanf("%d", &num);
    if (isPalindrome2(num))
    {
        printf("number: %d is palindrome", num);
    }
    else
    {
        printf("number: %d is not palindrome", num);
    }
    

    return 0;
}