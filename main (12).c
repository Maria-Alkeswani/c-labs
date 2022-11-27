#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"gt.h"



int main()
{
struct Graph *G;
float **a;
int x;
for(;;)
{
printf("1- createGraph.\n2- getNumVertices.\n3- getNumEdges.\n4- getNeighbors.\n5- getInNeighbors.\n6- getOutNeighbors.\n7- addDirectedEdge.\n8- addUndirectedEdge.\n9- hasEdge.\n10- Print Graph.\n11- Dijkstra.\n12- Load.\n13- Save.\n14- Exit.\n");
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
else if(x==11) dijkstra(G);
else if(x==12) load(&G);
else if(x==13) save(G);
else if(x==14) Exit1(G);



printf("--------------------------------------------------------\n");
}
    
    
    return 0;
}

