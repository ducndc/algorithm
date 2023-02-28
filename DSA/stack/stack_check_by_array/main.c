//
//  main.c
//  ArrayStack
//
//  Created by TungDT on 7/25/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <string.h>
#include "stack.h"

#define TRUE  1
#define FALSE 0
int top = -1;
int stack[STACK_SIZE];


int validate_nesting(char * const expression);
int is_opened(const char c);
int is_closed(const char c);
int is_match(const char closed_char, const char opened_char);

int main(int argc, const char * argv[])
{
    printf("Enter an expression to check validate: ");
    char s[100];
    scanf("%[^\n]s", s);
    printf("%s:", s);
    if (validate_nesting(s)) printf("Validated\n");
    else printf("Not validated\n");
    
    return 0;
}


int validate_nesting(char * const expression)
{
    int i;
    unsigned long length = strlen(expression);
    
    for (i = 0; i < length; i++)
    {
        char c = expression[i];
        // TODO: write your code here
        // check if c is an opened parenthesis then push it to stack
        // check if c is a closed parenthesis
            // if stack is empty => not validated
            // if c is not match with the top of stack => not validated
		if (is_opened(c))
			push(c);

		if (is_closed(c))
		{
			if (is_empty())
				return 0;
			if (!is_match(c, stack[top]))
				return 0;
			pop();
		}
    }
    // if stack is empty => validated
	if (is_empty())
		return 1;
    // if stack is not empty => not validated   
	return 0;
}

int is_opened(const char c)
{
    switch (c)
    {
        case '(':
        case '[':
        case '{': return TRUE;
        default : return FALSE;
    }
}

int is_closed(const char c)
{
    switch (c)
    {
        case ')':
        case ']':
        case '}': return TRUE;
        default : return FALSE;
    }
}

int is_match(const char closed_char, const char opened_char)
{
    if (closed_char == ')' && opened_char == '(') return TRUE;
    if (closed_char == ']' && opened_char == '[') return TRUE;
    if (closed_char == '}' && opened_char == '{') return TRUE;
    return FALSE;
}
