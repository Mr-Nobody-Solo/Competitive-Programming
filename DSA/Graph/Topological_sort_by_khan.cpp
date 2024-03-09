//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
*Created : 17/01/2023
*Source : https://youtu.be/G1HuCjgvJb0
*Topic -> Khan's algorithm on Topological sort
*Caution : Topological sort only work for DAG(Directed Acyclic Graph)
*/
//#include<bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define hi ios_base::sync_with_stdio(false);cout.tie(nullptr);

vector<vector<int>> adj;
vector<int> indegree;
void TopologicalSortByKhan(){
  queue<int> q;
  for(int i{0};i<indegree.size();i++){
    if(indegree[i]==0)q.push(i);
  }
  vector<int>order;
  int count_node{0},u;
  while(!q.empty()){
    count_node++;
    u = q.front();
    order.push_back(u);
    q.pop();
    for(int i{0};i<adj[u].size();i++){
      int v =adj[u][i];   //here v denote ending node.
      --indegree[v];
      if(!indegree[v])q.push(v);
    }
  }
  if(count_node>indegree.size()){
    cout<<"There is a cycle in graph (It is not DAG).\n";
  }else{
    for(const auto &it:order)cout<<it<<" ";
    cout<<endl;
  }

}
int main(){
  hi
  int nodes,edges;
  cout<<"Enter the number of nodes and edges :";
  cin>>nodes>>edges;
  adj.clear();
  adj.resize(nodes);
  indegree.resize(nodes);
  cout<<"\nEnter the directed edges :";
  int u,v;
  for(int i{0};i<edges;i++){
    cin>>u>>v;
    adj[u].push_back(v);
    indegree.at(v)++;
  }
  TopologicalSortByKhan();
  return ( 0 - 0 );
}
/*
Input :
5 7

0 3
0 2
0 1
1 2
1 3
2 4
3 4

Graphical view :

       4
      ^^
     /  \
    2    3
    ^^  ^^
    | \/ |
    | /\ |
    |/  \|
    0--->1
*/