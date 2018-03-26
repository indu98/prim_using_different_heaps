#include "Graph.h"
#include "BinaryHeap.h"
#include "BinomialHeap.h"
#include "FibonacciHeap.h"

# define INF 0x3f3f3f3f

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int> > [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    //adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src, int heap_type)
{
    Heap *heap;

    switch(heap_type)
    {
        case BINARY: heap = new BinaryHeap(); break;
        case BINOMIAL: heap = new BinomialHeap(); break;
        case FIBONACCI: heap = new FibonacciHeap(); break;
    }

    vector<int> dist(V, INF);

// Add Prim code here

    printf("Number of Operations performed : %d \n", (*heap).getOperations());
    return;
}
