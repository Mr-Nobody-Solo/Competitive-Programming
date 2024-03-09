//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                
 Topic ->Depth First Search or DFS for a Graph using stack and adjacency matrix.
 Source -> Internet website
 Created -> 20/01/2023
*/
#include<stdio.h>
#define MAX  10001

int graph[MAX][MAX];
int visited[MAX];

int STACK[MAX];
int TOP=-1;

void DFS(int node,int size){
  visited[node]=1;
  TOP=TOP+1;
  STACK[TOP]=node;
  for(int i=1;i<=size;i++){
    if(graph[node][i]==1){
      if(visited[i]==0){
        DFS(i,size);      
      }
    }  
  }
}

int main(){

  int nodes,i,j;
  printf("Enter the number of vertices :");
  scanf("%d",&nodes);
  printf("\nEnter adjacency matrix of the graph:\n");
  for(i=1;i<=nodes;i++){
    for(j=1;j<=nodes;j++){
      scanf("%d",&graph[i][j]);
    }
  }
  for(i=1;i<=nodes;i++){
    for(j=1;j<=nodes;j++){
      if(graph[i][j]==1){
        if(visited[j]==0){
          DFS(i,nodes);      
        }
      }
    }
  }

  printf("\nPath :");
  while(TOP>=0){
    printf("%d",STACK[TOP]);
    TOP = TOP-1;
    if(TOP>-1){
      printf("<-");
    }
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