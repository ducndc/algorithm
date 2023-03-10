#include "graph.h"

int top = -1;
int stack[STACK_SIZE];

int main()
{
    graph* g = read_graph("input.txt");
    printf("Checking for cycle...\n");
    int start = 0;
    if (has_cycle(g, start))
    {
        printf("Graph has cycle from vertex %d\n", start);
    }
    else
        printf("Graph has no cycle from vertex %d\n", start);
    
    clear_graph(g);

    return 0;
}