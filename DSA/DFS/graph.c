#include "graph.h"

graph* init_graph(int n_vertices)
{
    graph* g = (graph*) malloc(sizeof(graph));
    g->n_vertices = n_vertices;
    g->adj_matrix = (int**) malloc(n_vertices * sizeof(int*));
    g->visited = (int*) malloc(n_vertices * sizeof(int));
    for (int i = 0; i < n_vertices; i++)
    {
        g->adj_matrix[i] = (int*) malloc(n_vertices * sizeof(int));
        g->visited[i] = WHITE;  // paint all vertices to white
        for (int j = 0; j < n_vertices; j++)
            g->adj_matrix[i][j] = 0; // no dependency yet
    }

    return g;
}

graph* read_graph(char* finput)
{
    FILE* f = fopen(finput, "r");
    if (f == NULL)
    {
        printf("Cannot open file %s\n", finput);
        exit(1);
    }
    int n_vertices, n_edges;
    fscanf(f, "%d %d", &n_vertices, &n_edges);
    graph* g = init_graph(n_vertices);

    int src, dest;
    printf("Tasks dependencies: \n");
    for (int i = 0; i < n_edges; i++)
    {
        fscanf(f, "%d %d", &src, &dest);
        add_edge(g, src, dest);
        printf("Task %d -> Task %d\n", src, dest);
    }

    fclose(f);
    return g;
}

void add_edge(graph* g, int src, int dest)
{
    g->adj_matrix[src][dest] = 1;
}

int has_cycle(graph* g, int start)
{
    push(start);
    g->visited[start] = GREY;

    while (!is_empty())
    {
        int u = stack_top();        // Get the top of the stack without removing it
        printf("Task %d -> ", u);
        
        int v = 0;
        while (v < g->n_vertices)
        {
            if ((1 == g->adj_matrix[u][v]) && (WHITE == g->visited[v]))// there is a dependency between (u, v) and v is not visited)
            {
                // push v to stack
                // print task v
                // set v to GREY
                // set u to v (now we DFS from v)
                // set v to 0 (start searching again from the beginning)
                push(v);
                printf("TASK: %d -> ", v);
                g->visited[v] = GREY;
                u = v;
                v = 0;
            }
            else if ((1 == g->adj_matrix[u][v]) && (GREY == g->visited[v]))// there is a dependency between (u, v) and vi is considering)
            {
               // print task v
               // return TRUE
               printf("TASK: %d -> ", v);
               return TRUE;
            }
            else // search the next vertex
            v++;
        }
        // if we reach here, it means that we have finished DFS from u
        // remove u from stack
        // set u to BLACK
        pop();
        g->visited[u] = BLACK;
        
        printf("\n"); // print a new line to separate the DFS from u
    }

    return FALSE;
}

void clear_graph(graph* g)
{
    for (int i = 0; i < g->n_vertices; i++)
        free(g->adj_matrix[i]);
    free(g->adj_matrix);
    free(g->visited);
    free(g);
}