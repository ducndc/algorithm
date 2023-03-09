//
//  main.c
//  BFS
//
//  Created by TungDT on 8/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "graph.h"

int main(int argc, const char * argv[])
{
    graph *g = read_graph("input.txt");
    bfs(g, 0);
    delete_graph(&g);
    return 0;
}
