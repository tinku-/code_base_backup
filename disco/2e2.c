#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int t=0;
int adj[2001][2001];
int deg[2001];
int V ,w,v1,v2,i;  
int E ;  
struct edge
{
    int src, dest, weight;
};
struct Graph
{
    int V, E;
    struct edge* edge;
};
struct Graph* creator(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct edge*) malloc( graph->E * sizeof( struct edge ) );
 
    return graph;
}
struct subset
{
    int parent;
    int rank;
};
int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int mycomp(const void* a, const void* b)
{
    struct edge* a1 = (struct edge*)a;
    struct edge* b1 = (struct edge*)b;
    return a1->weight > b1->weight;
}
void mst(struct Graph* graph)
{
    int V = graph->V;
    struct edge result[V];  
    int e = 0; 
    int i = 0;
    int ans=0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), mycomp);
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1)
    {
        struct edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    for (i = 0; i < e; ++i)
        ans = ans + result[i].weight;
    printf("%d\n",ans);
    return;
}
int main()
{
    scanf("%d %d",&V,&E);
    struct Graph* graph = creator(V, E);
 
    for(i=0;i<E;i++)
    {
        scanf("%d %d %d",&v1,&v2,&w);
        graph->edge[i].src = v1;
        graph->edge[i].dest = v2;
        graph->edge[i].weight = w;
    }
    mst(graph);
    return 0;
}