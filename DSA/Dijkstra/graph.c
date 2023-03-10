//
//  graph.c
//  Dijkstra
//
//  Created by TungDT on 8/20/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "graph.h"
#include <string.h>
#include <limits.h>

#define MAX_LEN 25
#define INFINITY INT_MAX
#define TRUE 1
#define FALSE 0

graph* read_graph(char* fname)
{
    graph *g = (graph*) malloc(sizeof(graph));
    FILE *fp = fopen(fname, "r");
    int n = 0;
    
    fscanf(fp, "%d", &n);
    g->n_vertices = n;
    
    g->cities = (char**) malloc(n * sizeof(char*));
    g->matrix = (int**)  malloc(n * sizeof(int*));
    
    read_cities(g, fp);
    read_matrix(g, fp);
    
    fclose(fp);
    
    return g;
}
void read_cities(graph* g, FILE* fp)
{
    char citi_name[MAX_LEN];
    for (int i = 0; i < g->n_vertices; i++)
    {
        fscanf(fp, "%s", citi_name);
        g->cities[i] = (char*) malloc(strlen(citi_name) * sizeof(char) + 1);
        strcpy(g->cities[i], citi_name);
    }
}
void read_matrix(graph* g, FILE* fp)
{
    for (int i = 0; i < g->n_vertices; i++)
    {
        g->matrix[i] = (int*) malloc(g->n_vertices * sizeof(int));
        for (int j = 0; j < g->n_vertices; j++)
        {
            fscanf(fp, "%d", &g->matrix[i][j]);
        }
    }
}
void clean_graph(graph* g)
{
    for (int i = 0; i < g->n_vertices; i++)
    {
        free(g->cities[i]);
        free(g->matrix[i]);
    }
    free(g->cities);
    free(g->matrix);
    free(g);
}
void print_edge(graph* g, int src, int dest)
{
    printf("From %s to %s: %d\n", g->cities[src], g->cities[dest], g->matrix[src][dest]);
}
void print_graph(graph* g)
{
    for (int i = 0; i < g->n_vertices; i++)
    {
        for (int j = i + 1; j < g->n_vertices; j++)
        {
            if (g->matrix[i][j] != 0) print_edge(g, i, j);
        }
    }
}
void dijkstra(graph* g, int start)
{
    int n = g->n_vertices;
    int distance[n];   // distance[u] is distance form vertex start to vertex u
    int confirmed[n];  // confirmed[u] is true if distance from start to u is shortest
    
    init_distance(distance, confirmed, n);
    distance[start] = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        // TODO:
        // - get u which is the nearest vertex from start
        int u = get_nearest(g, distance, confirmed);
        // - set u is confirmed
        confirmed[u] = TRUE;
        // - for each w, if need to update distance for w
        for (int w = 0; w < n; w++)
        {
            if (need_update_distance(g, distance, confirmed, u, w))
            {   // - then update new distance for w = distance for u + weight of edge (u, w)
                distance[w] = distance[u] + g->matrix[u][w];
            }
        }
    }
    print_shortest(g, start, distance);
}
void init_distance(int* distance, int* confirmed, int n)
{
    for (int i = 0; i < n; i++)
    {
        distance[i] = INFINITY;
        confirmed[i] = FALSE;
    }
}
int get_nearest(graph* g, int *distance, int* confirmed)
{
    int min = INFINITY;
    int nearest = -1;
    
    // TODO:
    // Finding u (nearest) that has the min distance among all distances
    // u must not be confirmed
    for (int u = 0; u < g->n_vertices; u++)
    {
        if (confirmed[u] == FALSE && distance[u] < min)
        {
            min = distance[u];
            nearest = u;
        }
    }
    
    return nearest;
}
int need_update_distance(graph *g, int* distance, int* confirmed, int u, int w)
{
    // TODO:
    // need to update distance if:
    // - w is not confirmed
    // - there is an edge between u and w
    // - distance u + weight (u, w) is less than distance w
    if (confirmed[w] == TRUE) return FALSE;
    if (g->matrix[u][w] == 0) return FALSE;
    if (distance[u] + g->matrix[u][w] >= distance[w]) return FALSE;
    return TRUE;
}
void print_shortest(graph* g, int start, int *distance)
{
    for (int u = 0; u < g->n_vertices; u++)
        printf("Shortest path from %s to %s: %d\n", g->cities[start], g->cities[u], distance[u]);
}
