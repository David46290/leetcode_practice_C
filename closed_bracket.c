#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define bracket_open_1 40 // ASCII of '('
#define bracket_open_2 91 // ASCII of '['
#define bracket_open_3 123 // ASCII of '{'
#define bracket_closed_1 41 // ASCII of ')'
#define bracket_closed_2 93 // ASCII of ']'
#define bracket_closed_3 125 // ASCII of '}'

bool isValid(char* s)
{
    if (s == NULL || s[0] == '\0') // s is NULL or empty char
    {
        return true;
    }

    // building map for matching the bracket
    // the map's size has to be at least (ASCII of '}' + 1)
    // because the indices of KEYs (')', ']', '}') signed to the array are their ASCII number
    // any size not longer than that will result in errors
    char bracket_map[bracket_closed_3+1] = {0}; 
    bracket_map[')'] = '(';
    bracket_map[']'] = '[';
    bracket_map['}'] = '{';

    int len_s = strlen(s);
    char *open_bracket_stack = malloc(len_s * sizeof(char));

    int stack_idx = 0; // index to push open-bracket-char into open_bracket_stack 
    for (int i=0; i<len_s; i++)
    {
        char current_char = s[i];
        switch (current_char)
        {
            // meeting open bracket => push that char into the stack
            case '(':
            case '[':
            case '{':
                open_bracket_stack[stack_idx] = current_char;
                stack_idx++; // move on to the next stack position
                break;

            // meeting close bracket 
            case ')':
            case ']':
            case '}':
                char its_open_partner = bracket_map[current_char];

                // (stack_idx == 0) means there's no isolated open bracket currently
                // (open_bracket_stack[stack_idx-1] != its_open_partner) means the last open bracket found doesn't match the current closed bracket
        
                if ((stack_idx == 0) || (open_bracket_stack[stack_idx-1] != its_open_partner))
                {
                    free(open_bracket_stack);
                    return false;
                }
                // if match successfully, move back to the last stack position
                // as its content is now useless (considering empty)
                stack_idx--; 
                break;

        }
    }
    free(open_bracket_stack);
    // if the stack position is the initial position (stack_idx == 0)
    // that means after all the operations
    // there's no isolated open bracket left
    // so all brackets are matched
    return stack_idx == 0;

}

int main(void)
{
    char brackets[] = "{([]}";
    if(isValid(brackets))
    {
        printf("bracketS %s is properly closed", brackets);
    }
    else
    {
        printf("bracketS %s is NOT properly closed", brackets);
    }

    return 0;
}