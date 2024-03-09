/*
Starting with the name of ALLAH 
Author - Saad Ibn Abdullah
Created -> 12/10/2023
Work-> BFS(Breadth First Search) traverse all node (of Tree) by level wise
Source -> https://youtu.be/iWTEjkGqL6M
*/

#include <iostream>
// #include<bits/stdc++.h>
#include <queue>
using namespace std;

//requre c++17 to use define (-_- )
// #define black 1;
// #define white 0;

int adj[100][100],
	color[100],
	dis[100],
	parent[100],
	node,edge;

void BFS(int root){
	int white = 0,black =1;
	queue<int> q;
	for(int i=0;i<node;i++){
		color[i]=white;
	}
	dis[0]=0;
	q.push(root);
	while(!q.empty()){
		int x{q.front()};
		color[x]=black;	//Be awear of this
		for(int i=0;i<node;i++){
			if(adj[x][i]==1){
				if(color[i] == white){
					q.push(i);
					dis[i]=dis[x]+1;
					parent[i]=x;
				}
			}
		}
		q.pop();
	}		
}
int main(){
	int n1,n2,root;
	cin>>node>>edge;
	root = 0;
	for(int i=0;i<edge;i++){
		cin>>n1>>n2;
		adj[n1][n2]=1;
		adj[n2][n1]=1;
	}
	BFS(root);
	cout<<"3's patents is : "<<parent[3]<<endl;
	cout<<"The distance from root 0 to leaf 6 is : "<<dis[6]<<endl;
	cout<<"The distance from node 2 to leaf 4 is : "<<dis[4]-dis[2]<<endl;
	return 0;
	}

/*

Input:
8 7
0 1
0 2
1 3
2 4
2 5
3 6
3 7


Graphical representation :
				0
			  /	     \
		        1 	       2
		     /	 	   /	   \
		   3		  4	    5
	       /	\
       	      6		 7
*/
