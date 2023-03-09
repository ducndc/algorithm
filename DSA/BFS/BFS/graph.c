//
//  graph.c
//  BFS
//
//  Created by TungDT on 8/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "graph.h"
#include "queue.h"

int front;
int rear;
int queue[QUEUE_SIZE];

node* create_node(int vertex)
{
    node* n = malloc(sizeof(node));
    n->vertex = vertex;
    n->next = NULL;
    return n;
}
graph* init_graph(int n_vertices)
{
    graph* g = malloc(sizeof(graph));
    g->n_vertices = n_vertices;
    
    g->adj_lists = malloc(n_vertices * sizeof(node*));
    g->visited   = malloc(n_vertices * sizeof(int));
    g->urls      = malloc(n_vertices * sizeof(char*));
    
    for (int i = 0; i < n_vertices; i++)
    {
        g->adj_lists[i] = NULL;
        g->visited[i] = WHITE;
    }
    
    return g;
}
graph* read_graph(char* finput)
{
    FILE *fp = fopen(finput, "r");
    if (fp == NULL)
    {
        printf("File %s not found!\n", finput);
        exit(1);
    }
    // Read number of vertices, each vertex is a url
    int n_urls;
    fscanf(fp, "%d", &n_urls);

    graph* g = init_graph(n_urls);

    // Read urls
    for (int i = 0; i < n_urls; i++)
    {
        char url[250];
        fscanf(fp, "%s", url);
        add_url(g, i, url);
    }

    // Read number of edges then read edges
    int n_edges;
    fscanf(fp, "%d", &n_edges);
    for (int i = 0; i < n_edges; i++)
    {
        int src, dest;
        fscanf(fp, "%d", &src);
        fscanf(fp, "%d", &dest);
        add_edge(g, src, dest);
    }

    fclose(fp);
    return g;
}
void add_edge(graph* g, int src, int dest)
{
    // TODO: Add edge from src to dest
    // create a node for destionation
    node *dest_node = create_node(dest);
    // add destination to adjancent list of source
    dest_node->next = g->adj_lists[src];
    // add source to adjancent list of destination
    g->adj_lists[src] = dest_node;
    
    // TODO: Add edge from dest to src (same as above)
    node* source_node = create_node(src);
    source_node->next = g->adj_lists[dest];
    g->adj_lists[dest] = source_node;
}

void visit(graph* g, int vertex)
{
    // TODO: Get url of vertex, print download message for that url
    char *url = g->urls[vertex];
    printf("Download %s ... done\n", url);
}

void add_url(graph* g, int vertex, char* url)
{
    // TODO: Add url to the corresponding vertex
    g->urls[vertex] = malloc(strlen(url) + 1);
    strcpy(g->urls[vertex], url);
    g->urls[vertex][strlen(url)] = '\0';
}

void bfs(graph* g, int start)
{
    // TODO: Implement BFS
    // Paint all vertices white then clear queue
    for (int vertex = 0; vertex < g->n_vertices; vertex++)
    {
        g->visited[vertex] = WHITE;
    }
    clear_queue();
    // Paint start vertex grey then enqueue it
    g->visited[start] = GREY;
    enqueue(start);
    while (!is_empty())
    {
        int u = dequeue();
        node* adj_list_u = g->adj_lists[u];
        node* node_w = adj_list_u;
        while (node_w != NULL)
        {
            int w = node_w->vertex;
            if (g->visited[w] == WHITE)
            {
                g->visited[w] = GREY;
                enqueue(w);
            }
            node_w = node_w->next;
        }
        g->visited[u] = BLACK;
        visit(g, u);
    }
}

void delete_graph(graph** g)
{
    free((*g)->visited);
    for (int i = 0; i < (*g)->n_vertices; i++)
    {
        free((*g)->adj_lists[i]);
        free((*g)->urls[i]);
    }
    free((*g)->adj_lists);
    free((*g)->urls);
}
