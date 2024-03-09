/*
Starting with the name of ALLAH 
Author - Saad Ibn Abdullah
Created -> 12/10/2023

Source -> https://youtube.com/watch?v=-1HUUMnCRjs&si=EnSIkaIECMiOmarE
*/
#include <iostream>
// #include<bits/stdc++.h>
using namespace std;

#define white 1
#define black 2

int node_num,edge_num,color[101],adj[100][100];
int start_time[100],end_time[100],Time=1; //as globally diclared all index value are zero now.

void visite_DFS(int node){
	color[node]=black;
	start_time[node] = Time;
	Time++;
	for(int i{0};i<node_num;i++){
		if(adj[node][i]==1){
			if(color[i]==white){
				visite_DFS(i);
			}
		}
	}
	end_time[node] = Time;
	Time++;
}

void DFS(){
	for(int i{0};i<node_num;i++){
		color[i]=white;
	}
	for(int i{0};i<node_num;i++){
		if(color[i] == white){
			visite_DFS(i);
		}
	}
}

int main(){
	int n1,n2;
	cin>>node_num>>edge_num;
	for(int i{0};i<edge_num;i++){
		cin>>n1>>n2;
		adj[n1][n2]=1;
		adj[n2][n1]=1;
	}
	cout<<"Array view to show connected node :\n";
	for(int i{0};i<node_num;i++){
		for(int j{0};j<node_num;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	DFS();
	bool all_node_visited{true};
	for(int i{0};i<node_num;i++){
		if(color[i] != black) all_node_visited = false;
	}
	cout<<((all_node_visited) ? "Alhamdullah,DFS has visited all nodes." : "DFS Don't worked :(")<<endl<<endl;
	for(int i{0};i<node_num;i++){
		cout<<(char)('A'+i)<<'('<<i<<')'<<" Discovery time :"<<start_time[i]<<" .Finishing time :"<<end_time[i]<<endl;
	}
	return 0;
}

/*
Inputs:
7 7
0 1
2 1
1 3
3 4
1 4
5 6

graphical view :

	       3---4
		\ /
		 1 		5--6
	   	/ \
	       0---2
*/