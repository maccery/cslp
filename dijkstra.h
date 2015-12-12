//
// Created by Tom Macmichael on 12/12/2015.
//

#ifndef CSLP_DIJKSTRA_H
#define CSLP_DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges.
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E);
int makeDis(struct Graph* graph, int source);

#endif //CSLP_DIJKSTRA_H
