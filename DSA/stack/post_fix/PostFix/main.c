//
//  main.c
//  PostFix
//
//  Created by TungDT on 7/28/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#include "stack.h"

int* stack = NULL;
int top = -1;
int stack_size = 100;

int postfix_evaluate(char* expression);
int is_number(char* token);
int is_operator(char* token);
char* get_token(char** expression);
int evaluate(int a, int b, char op);
void stop_program(void);

int main(int argc, const char * argv[])
{
    printf("Enter a postfix expression (ex: 1 2 + 3 *): ");
    char expr[100];
    scanf("%[^\n]s", expr);
    printf("Expression: %s\n", expr);
    
    printf("Value = %d\n", postfix_evaluate(expr));
    return 0;
}

int postfix_evaluate(char* expression)
{
    init_stack();
    // TODO
    // while there are token to be read in from expression
    //      read a token
    //      if the token is a number then push it onto the stack
    //      else if the token is an operator then
    //          pop the top two numbers from the stack
    //          evaluate the operator, with the numbers as arguments
    //          push the result onto the stack
    //      else
    //          stop_program()
    // if there is only one value in the stack
    //      that value is the result of the calculation, pop it from the stack and return it
    // else
    //      stop_program()
	while (expression != NULL)
	{
		char *token = get_token(&expression);
		if (is_number(token))
			push(atoi(token));
		else if (is_operator(token))
		{
			int a = pop();
			int b = pop();
			int c = evaluate(b, a, *token);
			push(c);
		}
		else
		{
			stop_program();
		}
	}

	if (top == 0)
		return pop();
	else
		stop_program();
}

char* get_token(char** expression)
{
    if (*expression == NULL) return NULL;
    char* token = *expression;
    char* end = *expression;
    while (*end != ' ' && *end != '\0') end++;
    if (*end == '\0') *expression = NULL;
    else
    {
        *end = '\0';
        *expression = end+1;
    }
    return token;
}

int is_number(char* token)
{
    for (int i = 0; i < strlen(token); i++)
        if (!isdigit(token[i])) return 0;
    return 1;
}

int is_operator(char* token)
{
    if (strlen(token) != 1) return 0;
    switch (token[0])
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return 1;
        default : return 0;
    }
}

int evaluate(int a, int b, char op)
{
    switch (op)
    {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/': return b / a;
        case '^': return pow(b, a);
        default : return 0; // never get this
    }
}

void stop_program()
{
    clear_stack();
    printf("Error: Invalid postfix!\n");
	exit(-1);
}
