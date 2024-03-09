//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Minimum Spanning Tree : Kruskal's Algorithm
 Source -> https://youtu.be/xDrLSOxaFrA
 Created -> 20/02/2023
 */
#include<iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N (int)1e5+10
int parent[N];
int Size[N];

void make(int n){
  for(int i=1;i<=n;i++){
    parent[i]=i;
    Size[i]=1;
  }
}
int find(int v){
  if(parent[v]==v)return v;
  return parent[v]=find(parent[v]);
}

void Union(int x,int y){
  x=find(x);
  y=find(y);
  if(x!=y){
    if(x<y)
      swap(x,y);
    parent[y]=x;
    Size[x]+=Size[y];
  }
}

#define vi(n) vector<int> v(n)
int main(){
  int node,edge,x,y,wt;
  cin>>node>>edge;
  make(node);
  vector<pair<int,pair<int,int>>>edges;
  while(edge--){
    cin>>x>>y>>wt;
    edges.push_back({wt,{x,y}});
  }
  sort(edges.begin(),edges.end());
  int minWt=0;
  for(auto it : edges){
    wt = it.first;
    x=it.second.first;
    y=it.second.second;
    if(find(x)==find(y))continue;
    Union(x,y);
    minWt+=wt;
    cout<<x<<' '<<y<<endl;
  }
  cout<<"Minimum weight = "<<minWt<<endl;
return((0 - 0));
}

/*
Input :
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7

Graphical view:

         5
      4------3
   9/ | \    | \8
  5   |1  \4 |3  6
   4\ |     \| /7
      1------2
          2

answer :
  5   4       3   6
   \  |1      |3 /
    \4|       | /7
      1-------2
          2
*/
