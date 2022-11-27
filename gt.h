
// A structure to represent an adjacency list node
typedef struct Node
{
    int data;
    float weight;
	struct Node* next;
}Node;

// A structure to represent an adjacency list
typedef struct List
{
    struct Node* head;
}List;

typedef struct Graph
{
    int V;
    struct List* array;
}Graph;


struct Node* c_node(int x,float w);
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph,int src,int des,float w);
void printGraph(struct Graph* graph);
int getNumVertices(struct Graph *G);
int getNumEdges(struct Graph *G);
void getOutNeighbors1(struct Graph *G,int v);
void getOutNeighbors(struct Graph *G);
void getInNeighbors1(struct Graph *G,int v);
void getInNeighbors(struct Graph *G);
void getNeighbors(struct Graph *G);
void addDirectedEdge(struct Graph *G);
void addUndirectedEdge(struct Graph *G);
bool hasEdge(struct Graph *G,int v1,int v2);
void hasEdge1(struct Graph *G);
void load(struct Graph **G);
void createGraph1(struct Graph **G);
void getNumVertices1(struct Graph *G);
void getNumEdges1(struct Graph *G);
void save(struct Graph *G);
void Exit1(struct Graph *G);
float Edge(struct Graph *G,int v1,int v2);
void dijkstra1(struct Graph *G,int src);
void printSolution(float dist[],int V);
int minDistance(float dist[], bool sptSet[],int V);
void dijkstra(struct Graph *G);

#include"gt.c"





