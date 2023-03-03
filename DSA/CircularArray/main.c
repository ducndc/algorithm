//
//  main.c
//  CircularArray
//
//  Created by TungDT on 7/30/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "message_queue.h"

#define COMMAND_SIZE 250
#define QUIT 0
#define CONTINUE 1

int front = -1;
int rear = -1;
char *msg_queue[BUFFER_SIZE];

char read_command(char* command, char **msg);
int do_command(char command, char* msg);
int validate(char* command);
void send_all(void);
void send_msg(void);
void save_msg(char* msg);

int main(int argc, const char * argv[])
{
    int running = TRUE;
    clear_queue();
    char command[COMMAND_SIZE];
    char* msg;
    
    printf("Message sending simulation\n");

    while (running)
    {
        char c = read_command(command, &msg);
        running = do_command(c, msg);
    }
    
    return 0;
}

char read_command(char* command, char **msg)
{
    printf(">> ");
    scanf("%[^\n]s", command);
    getchar(); // remove '\n' in buffer
    
    if (validate(command))
    {
        *msg = command + 1;
        return command[0];
    }
    else
    {
        printf("Invalid command!\n");
        return 0;
    }
}

int validate(char* command)
{
    int empty_command = strlen(command) == 0;
    int not_valid_first_char = command[0] != 'a' &&
                           command[0] != 'q' &&
                           command[0] != '-' &&
                           command[0] != '+';
    int not_valid_add_command = command[0] == '+' && strlen(command) < 2;
    int not_valid_single_command = (command [0] == '-' || command[0] == 'q' || command[0] == 'a') && strlen(command) > 1;
    
    if (empty_command) return FALSE;
    if (not_valid_first_char) return FALSE;
    if (not_valid_add_command) return FALSE;
    if (not_valid_single_command) return FALSE;
    return TRUE;
    
}

int do_command(char command, char* msg)
{
    switch (command)
    {
        case 'q': send_all();    return QUIT;
        case 'a': send_all();    return CONTINUE;
        case '+': save_msg(msg); return CONTINUE;
        case '-': send_msg();    return CONTINUE;
        default:                 return CONTINUE;
    }
}

void send_all(void)
{
    // TODO:
    // - Check empty
    // - If not, send message until empty
    while (!is_empty())
    {
        send_msg();
    }
}

void save_msg(char* msg)
{
    if (is_full()) send_all();
    char *new_msg = (char*) malloc(sizeof(char) * strlen(msg));
    strcpy(new_msg, msg);
    printf("Saved %s\n", msg);
    enqueue(new_msg);
}

void send_msg(void)
{
    if (is_empty())
    {
        printf("No more message!\n");
    }
    else
    {
        char *msg = dequeue();
        printf("Sending %s ...\n", msg);
        free(msg);
    }
}
