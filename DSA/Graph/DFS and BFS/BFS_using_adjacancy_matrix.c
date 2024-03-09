// Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                
 Topic ->Breadth first search or BFS using queue and adjacency matrix.
 Source -> Internet website
 Created -> 20/01/2023
*/
#include<stdio.h>

#define MAX  10001

int graph[MAX][MAX];
int visited[MAX];

int QUEUE[MAX];
int store[MAX];
int FRONT=1,REAR=0;

void BFS(int node,int size){
    visited[node]=1;
    store[FRONT]=node;
    for(int i=1;i<=size;i++){
      if(graph[node][i]==1 && visited[i]==0){
          visited[i]=1;  
          REAR++; //push in queue
          QUEUE[REAR]=i;
      }
    }
  if(REAR>=FRONT){
    FRONT++;  //pop from queue
    BFS(QUEUE[FRONT],size); 
  }
}

int main(){

  int nodes,i,j,u;
  printf("Enter the number of vertices :");
  scanf("%d",&nodes);
  printf("\nEnter adjacency matrix of the graph:\n");
  for(i=1;i<=nodes;i++){
    for(j=1;j<=nodes;j++){
      scanf("%d",&graph[i][j]);
    }
  }

  printf("\nEnter the starting vertex:");//Must be greater then zero and smaller or equal the number of nodes.
  scanf("%d",&u);
  QUEUE[++REAR]=u;
  BFS(u,nodes);

  printf("\nThe node which are reachable are: \n");
  for(i=1;i<FRONT;i++){
      printf("%d ",store[i]);
  }
  printf("\n");
  return 0;
}

/*
Input : 
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
1

Graphical view :
      1
    /   \
   2     4
    \   /
      3
*/