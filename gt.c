
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Function to create a new adjacency list node
struct Node* c_node(int x,float w)
{
struct Node*q=(struct Node*)malloc(sizeof(Node));
q->weight=w;
q->data=x;
q->next=NULL;
return q;
}
//-------------------------------------------------------------------

//Function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));

graph->V=V;
graph->array=(struct List*)malloc(sizeof(struct List)*V);

int i;

for(i=0;i<V;i++)
{
graph->array[i].head=NULL;
}

return graph;
}
//-------------------------------------------------------------------

// Adds an edge to a directed graph
void addEdge(struct Graph* graph,int src,int des,float w)
{
struct Node*temp= c_node(des,w);

temp->next=graph->array[src].head;
graph->array[src].head=temp;
    
}
//-------------------------------------------------------------------

//Function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
int v;

for (v = 0; v < graph->V; ++v)
{
struct Node* trav = graph->array[v].head;
printf("\n Adjacency list of vertex %d\n head ", v);

	while (trav!=NULL)
	{
	printf("-> %d", trav->data);
	trav = trav->next;
	}
	
printf("\n");

}

}

//-------------------------------------------------------------------

int getNumVertices(struct Graph *G)
{
return G->V;
}

//-------------------------------------------------------------------


int getNumEdges(struct Graph *G)
{ 
int i,sum = 0; 
char a[10];

for(i=0; i< G->V; i++) 
{
struct Node* t = G->array[i].head;

	while (t!=NULL)
	{
	sum++;
	t=t->next;
	}
}


printf("Is the graph directed .. Enter Yes or NO: ");
scanf("\n");
gets(a);

if(strcmp(a,"Yes")==0 || strcmp(a,"yes")==0)
return sum;
else
return sum/2; 

}

//-------------------------------------------------------------------

void getOutNeighbors(struct Graph *G)
{
int v;
printf("Enter the vertice: v=");
scanf("%d",&v);

printf("getOutNeighbors of vertex %d is : ", v);

getOutNeighbors1(G,v);
	
printf("\n");

}

//-------------------------------------------------------------------

void getOutNeighbors1(struct Graph *G,int v)
{
int p=0;
struct Node* t = G->array[v].head;

while (t!=NULL)
	{
	//printf("-> %d", t->data);
	
	if(p==0)
	{printf("(%d,%d)",v,t->data); p=1;}
	else printf(" , (%d,%d)",v,t->data);
	
	t=t->next;
	}
	
}

//-------------------------------------------------------------------

void getInNeighbors1(struct Graph *G,int v)
{
int i,p=0;

for(i=0; i<G->V; i++)
if(i!=v)
{
struct Node* t=G->array[i].head;
	while (t!=NULL)
	{
	if(v==t->data)
	if(p==0)
	{printf("(%d,%d)",i,v); p=1;}
	else printf(" , (%d,%d)",i,v);
	t=t->next;
	}

} 

}

void getInNeighbors(struct Graph *G)
{
int v;
printf("Enter the vertice: v=");
scanf("%d",&v);

printf("getInNeighbors of vertex %d is : ", v);

getInNeighbors1(G,v);
	
printf("\n");

}

//-------------------------------------------------------------------

void getNeighbors(struct Graph *G)
{
int v;
printf("Enter the vertice: v=");
scanf("%d",&v);

printf("getNeighbors of vertex %d is : ", v);

int i,p=0,n=0,aux[G->V];

for(i=0; i<G->V; i++)
if(i!=v)
{
struct Node* t=G->array[i].head;

	while (t!=NULL)
	{
	if(v==t->data)
	{
	if(p==0)
	{printf("%d",i); p=1;}
	else printf(" , %d",i);
	
	aux[n++]=i;
	}
	t=t->next;
	}

} 

//printf(" , ");
int k1;
struct Node* t = G->array[v].head;

while (t!=NULL)
	{
	//printf("-> %d", t->data);
	k1=1;
	for(i=0; i<n+1; i++)
	if(aux[i]==t->data)
	k1=0;
	
	if(p==0 && k1==1)
	{printf("%d",t->data); p=1; }
	else if(p>0 && k1==1) printf(" , %d",t->data);
	
	
	t=t->next;
	}

printf("\n");

}

//-------------------------------------------------------------------

void addDirectedEdge(struct Graph *G) 
{
int v1,v2;
float w;
printf("Enter edge (v1,v2):\n");

printf("Enter v1=");
scanf("%d",&v1);
printf("Enter v2=");
scanf("%d",&v2);
printf("Enter weight=");
scanf("%f",&w);


addEdge(G,v1,v2,w);

}

//-------------------------------------------------------------------

void addUndirectedEdge(struct Graph *G) 
{
int v1,v2;
float w;
printf("Enter edge (v1,v2):\n");

printf("Enter v1=");
scanf("%d",&v1);
printf("Enter v2=");
scanf("%d",&v2);
printf("Enter weight=");
scanf("%f",&w);

addEdge(G,v1,v2,w);
addEdge(G,v2,v1,w);
}

//-------------------------------------------------------------------

void hasEdge1(struct Graph *G)
{
int v1,v2;
printf("Enter edge (v1,v2):\n");

printf("Enter v1=");
scanf("%d",&v1);
printf("Enter v2=");
scanf("%d",&v2);

if(hasEdge(G,v1,v2))
printf("hasEdge(%d,%d): True\n",v1,v2);
else
printf("hasEdge(%d,%d): False\n",v1,v2);

}

//-------------------------------------------------------------------

bool hasEdge(struct Graph *G,int v1,int v2)
{

struct Node* t = G->array[v1].head;

while (t!=NULL)
	{
	if(v2==t->data)
	return true;
	t=t->next;
	}

return false;

}

//-------------------------------------------------------------------
void load(struct Graph **G)
{
int v1,v2,i=0,max;
float w;
char name[100];
printf("Enter the file name: ");
scanf("\n");
gets(name);

FILE *p;
p=fopen(name,"r");

if(p==NULL) return;

while (fscanf(p,"%d %f %d",&v1,&w, &v2) != EOF) 
	{
	if(v1>v2 && i==0) {max=v1; i=1;}
	else if(v1<=v2 && i==0) {max=v2; i=1;}
	
	if(v1>=max) max=v1;
	if(v2>=max) max=v2;
	
	//printf("v1: %d v2: %d \n", n1,n2);
	}

//G->V=max;
max=max+1;
*G = createGraph(max);
fclose(p);

p=fopen(name,"r");

while (fscanf(p,"%d %f %d",&v1,&w,&v2) != EOF) 
	{
	addEdge(*G,v1,v2,w);
	}

fclose(p);

}

//-------------------------------------------------------------------

void createGraph1(struct Graph **G)
{
int n;
printf("Enter the number of vertices: ");
scanf("%d",&n);
*G=createGraph(n);
}
//-------------------------------------------------------------------
void getNumVertices1(struct Graph *G)
{
printf("V=%d \n",getNumVertices(G));
}
//-------------------------------------------------------------------
void getNumEdges1(struct Graph *G)
{
printf("E=%d \n",getNumEdges(G));
}
//-------------------------------------------------------------------

void save(struct Graph *G)
{	
	char name[100];
	printf("Enter the file name: ");
	scanf("\n");
	gets(name);
	
	FILE *p;
	p = fopen (name,"w");
	
	//--------------------------------
	
	int v;

for (v = 0; v < G->V; ++v)
{
struct Node* t = G->array[v].head;
//printf("\n Adjacency list of vertex %d\n head ", v);

	while (t!=NULL)
	{
	//printf("-> %d", trav->data);
	fprintf(p,"%d %f %d\n",v,t->weight,t->data);
	t=t->next;
	}
	
	//--------------------------------
	
    
}
fclose (p);
}

//-------------------------------------------------------------------

void Exit1(struct Graph *G)
{
char aa[10];
printf("Do you want to save the file? .. Enter Yes / No :");
scanf("\n");
gets(aa);
if(strcmp(aa,"Yes")==0 || strcmp(aa,"yes")==0)
{save(G); exit(0);}
else
exit(0);

}
//-------------------------------------------------------------------
float Edge(struct Graph *G,int v1,int v2)
{

struct Node* t = G->array[v1].head;

while (t!=NULL)
	{
	if(v2==t->data)
	return t->weight;
	t=t->next;
	}

return 0;

}
//-------------------------------------------------------------------
void dijkstra1(struct Graph *G,int src)
{
int i,j,V;
V=G->V;
float graph[V][V];
int count,v;
float dist[V]; 
bool sptSet[V];
//-------------------------------------Matrix--------------
for(i=0;i<V;i++)
for(j=0;j<V;j++)
graph[i][j]=0;

for(i=0; i< G->V;i++)
{
struct Node* t=G->array[i].head;

	while (t!=NULL)
	{
	graph[i][t->data]=t->weight;
	t=t->next;
	}
}
//-------------------------------------Matrix--------------

for (i = 0; i < V; i++) 
{dist[i] = 2147483647; sptSet[i] = false;} 
  
dist[src] = 0; 

for (count = 0; count < V - 1; count++)
{ 
 
int u = minDistance(dist, sptSet,V); 
sptSet[u] = true; 

for (v = 0; v < V; v++) 

if (!sptSet[v] && graph[u][v] && dist[u] != 2147483647 && dist[u] + graph[u][v] < dist[v]) 
dist[v] = dist[u] + graph[u][v]; 
} 
  
printSolution(dist,V);


}
//-------------------------------------------------------------------

int minDistance(float dist[], bool sptSet[],int V) 
{ 

float min = 2147483647;
int min_index,v; 

for (v = 0; v < V; v++) 
if (sptSet[v] == false && dist[v] <= min) 
{min = dist[v]; min_index = v;}

return min_index; 
} 
  
//------------------------------------------------------------------- 
void printSolution(float dist[],int V) 
{ int i;
printf("Vertex \t\t Distance from Source\n"); 
for (i = 0; i < V; i++) 
if(dist[i]!=2147483647)
printf("%d \t\t %f\n", i, dist[i]); 
else
printf("%d \t\t %s\n", i,"Inv");
}
//------------------------------------------------------------------- 
void dijkstra(struct Graph *G)
{
int v;
printf("Enter Source:");
scanf("%d",&v);
printf("\n");
dijkstra1(G,v);
printf("\n");
}


