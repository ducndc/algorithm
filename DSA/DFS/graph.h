#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define WHITE 0
#define GREY  1
#define BLACK 2

#define TRUE 1
#define FALSE 0

// define graph using adjacency matrix
typedef struct
{
    int n_vertices;
    int** adj_matrix;
    int* visited;
} graph;

graph* init_graph(int n_vertices);
graph* read_graph(char* finput);
void add_edge(graph* g, int src, int dest);
int has_cycle(graph* g, int start);
void clear_graph(graph* g);

#endif