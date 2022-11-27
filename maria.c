#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// A structure to represent an adjacency list node
struct Node
{
    int data;
    struct Node* next;
};

// A structure to represent an adjacency list
struct List
{
    struct Node* head;
};

struct Graph
{
    int V;
    struct List* array;
};


struct Node* c_node(int x);
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph,int src,int des);
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

int main()
{
struct Graph *G;
int x;
for(;;)
{
printf("1- createGraph.\n2- getNumVertices.\n3- getNumEdges.\n4- getNeighbors.\n5- getInNeighbors.\n6- getOutNeighbors.\n7- addDirectedEdge.\n8- addUndirectedEdge.\n9- hasEdge.\n10- Print Graph.\n11- Load.\n12- Save.\n13- Exit.\n");
printf("Enter the order number: ");
scanf("%d",&x);
printf("--------------------------------------------------------\n"); 

if(x==1) createGraph1(&G);
else if(x==2) getNumVertices1(G);
else if(x==3) getNumEdges1(G);
else if(x==4) getNeighbors(G);
else if(x==5) getInNeighbors(G);
else if(x==6) getOutNeighbors(G);
else if(x==7) addDirectedEdge(G);
else if(x==8) addUndirectedEdge(G);
else if(x==9) hasEdge1(G);
else if(x==10) printGraph(G);
else if(x==11) load(&G);
else if(x==12) save(G);
else if(x==13) Exit1(G);


printf("--------------------------------------------------------\n");
}
    
    
    return 0;
}


//-------------------------------------------------------------------

//Function to create a new adjacency list node
struct Node* c_node(int x)
{
struct Node*q=(struct Node*)malloc(sizeof(struct Node));
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
void addEdge(struct Graph* graph,int src,int des)
{
struct Node*temp= c_node(des);

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

int i,p=0;

for(i=0; i<G->V; i++)
if(i!=v)
{
struct Node* t=G->array[i].head;

	while (t!=NULL)
	{
	if(v==t->data)
	
	if(p==0)
	{printf("%d",i); p=1;}
	else printf(" , %d",i);
	
	t=t->next;
	}

} 

//printf(" , ");

struct Node* t = G->array[v].head;

while (t!=NULL)
	{
	//printf("-> %d", t->data);
	
	if(p==0)
	{printf("%d",t->data); p=1;}
	else printf(" , %d",t->data);
	
	t=t->next;
	}

printf("\n");

}

//-------------------------------------------------------------------

void addDirectedEdge(struct Graph *G) 
{
int v1,v2;
printf("Enter edge (v1,v2):\n");

printf("Enter v1=");
scanf("%d",&v1);
printf("Enter v2=");
scanf("%d",&v2);

addEdge(G,v1,v2);

}

//-------------------------------------------------------------------

void addUndirectedEdge(struct Graph *G) 
{
int v1,v2;
printf("Enter edge (v1,v2):\n");

printf("Enter v1=");
scanf("%d",&v1);
printf("Enter v2=");
scanf("%d",&v2);

addEdge(G,v1,v2);
addEdge(G,v2,v1);
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
char name[100];
printf("Enter the file name: ");
scanf("\n");
gets(name);

FILE *p;
p=fopen(name,"r");


while (fscanf(p,"%d %d",&v1, &v2) != EOF) 
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

while (fscanf(p,"%d %d",&v1, &v2) != EOF) 
	{
	addEdge(*G,v1,v2);
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
	fprintf(p,"%d %d\n",v,t->data);
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






