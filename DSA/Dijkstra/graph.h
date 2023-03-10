//
//  graph.h
//  Dijkstra
//
//  Created by TungDT on 8/20/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int **matrix;
    int n_vertices;
    char **cities;
} graph;

graph* read_graph(char* fname);
void read_cities(graph* g, FILE* fp);
void read_matrix(graph* g, FILE* fp);
void clean_graph(graph* g);
void print_edge(graph* g, int src, int dest);
void print_graph(graph* g);

void dijkstra(graph* g, int start);

void init_distance(int* distance, int* confirmed, int n);
int get_nearest(graph* g, int *distance, int* confirmed);
int need_update_distance(graph *g, int* distance, int* confirmed, int u, int w);
void print_shortest(graph* g, int start, int *distance);
#endif /* graph_h */
