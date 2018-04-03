#include "../include/Graph.h"
#include "../include/BinaryHeap.h"
#include "../include/BinomialHeap.h"
#include "../include/FibonacciHeap.h"

int mstCount=0;
int graphV;

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
    vector<int> parent(V, -1);
    vector<int> visit(V, 0);
// Add Prim code here
// Dijkstra Code
/*    printf("Beginnning\n");
(*heap).push(make_pair(0, src));

    dist[src] = 0;

    while ((*heap).top() != make_pair(-1, -1))
    {
        int u = (*heap).top().second;
        (*heap).pop();

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                (*heap).push(make_pair(dist[v], v));
            }
        }
    }
printf("End\n");
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
*/
//printf("Beginning of the code\n");
    (*heap).push(make_pair(0, src));
    parent[src] = src;
    dist[src] = 0;
    //printf("1\n");
    int exitf=0;
 mstCount=0;

    while (((*heap).top() != make_pair(-1, -1)) && exitf==0)
    {
        int u = (*heap).top().second;
        while( ( (*heap).top() != make_pair(-1, -1) ) && visit[u] == 1)
        {
            (*heap).pop();
            u = (*heap).top().second;
               // printf("2\n");

        }
        int k = visit[u];
        visit[u] = 1;
        //printf("3\n");
        (*heap).pop();
        mstCount++;

        printf("In MST-%d\tIn Graph-%d\n",mstCount,graphV);

        if(mstCount == graphV-1){
            exitf=1;
            break;
        }
           // printf("4\n");


        list< pair<int, int> >::iterator i;
           // printf("5\n");
       if(exitf!=1)
       {

        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            printf("----\n");


            printf("a--%d--\n",u);
           // printf("Inside-\t%d\n",*i);
           // printf("--a\n");
            int v = (*i).first;
           // printf("Here done!");
            int weight = (*i).second;
           //     printf("6\n");


            if (dist[v] > weight)
            {
                dist[v] = weight;
                parent[v] = u;
                (*heap).push(make_pair(dist[v], v));
                   // printf("7\n");

            }
        }
    }
    }
//printf("End of the code\n");

    printf("Minimum Spanning Tree\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, parent[i]);


    printf("Number of Operations performed : %d \n", (*heap).getOperations());
    return;
}
