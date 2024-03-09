//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
*Created : 22/01/2023
*Source : https://youtu.be/UGF4huZri_Y
*Topic -> Checking the graph is bipartite or not.
*/
//#include<bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;
#define As_salamu_alaykum ios_base::sync_with_stdio(false);cout.tie(nullptr);

bool bipartite_DFS(int node,vector<vector<int>> &v,vector<int> &vis,vector<int> &colour,int c){
    vis[node]=1;
    colour[node]=c;
    for(const auto &child :v[node]){  
      if(vis[child]==0){  //as it is a list representation of nodes so checking v[node][i]==1 is not need. 
        if(bipartite_DFS(child,v,vis,colour,(c^1))==false) return false;
      }
      else if(colour[child]==colour[node])return false;
    }
    return true;
}

int main(){
  As_salamu_alaykum
  int node,edge,x,y;
  cout<<"Enter the number of nodes and edges separated by spaces :";
  cin>>node>>edge;    
  vector<vector<int>> v(node+1);
  vector<int>visited(node+1,0),colour(node+1);
  cout<<"\nEnter every two node one by one whose are connected to each other\n";
  while(edge--){
    cin>>x>>y;    //here 0<x,y<=node
    v[x].push_back(y);
    v[y].push_back(x);
  }
  bool is_bipartite{true};
  for(int i{1};i<=node;i++){
    if(visited[i]==0){
      if(bipartite_DFS(i,v,visited,colour,0)==false){
        is_bipartite=false;
        break;
      }    
    }
  }
  if(is_bipartite)cout<<"This graph is bipartite graph :)\n";
  else cout<<"This graph is not bipartite graph (-_-)\n";

  return (( 0 - 0 ));
}

/*
1)Input:
 4 4 
1 4
1 2
2 3
3 4

Graphical view :
        
      1---4
      |   |
      2---3

2)Input:
 3 3 
1 2
2 3
3 1

Graphical view :
        
        1    
       / \
      2---3
*/