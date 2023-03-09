//
//  graph.h
//  BFS
//
//  Created by TungDT on 8/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 0
#define GREY  1
#define BLACK 2

typedef struct str_node node;

struct str_node
{
    int vertex;  // vertex in graph
    node* next;  // adjacent list of this vertex
};

typedef struct
{
    int n_vertices;     // number of vertices
    node** adj_lists;   // adjacent lists
    int* visited;       // visited array
    char** urls;        // urls array
} graph;

node* create_node(int vertex);
graph* init_graph(int n_vertices);
graph* read_graph(char* finput);
void add_edge(graph* g, int src, int dest);
void bfs(graph* g, int start);
void visit(graph* g, int vertex);
void add_url(graph* g, int vertex, char* url);
void delete_graph(graph** g);
#endif /* graph_h */
