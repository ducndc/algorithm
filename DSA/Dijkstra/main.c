//
//  main.c
//  Dijkstra
//
//  Created by TungDT on 8/20/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "graph.h"

int main(int argc, const char * argv[])
{
    graph *g = read_graph("input.txt");
    print_graph(g);
    dijkstra(g, 0);
    clean_graph(g);
    return 0;
}
