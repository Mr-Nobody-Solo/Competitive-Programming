//Starting with the name of Allah.
// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define N (int)2e3+100
#define loop(i,n) for(int i=1;i<=n;i++)
int parent[N],Size[N];
int g[N][3];

void make(int n){
  loop(i,n){
    Size[i]=1;
    parent[i]=i;
  }
}

int find(int v){
  if(parent[v]==v)return v;
  return parent[v]=find(parent[v]);
}

void Union(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y)return;
  if(Size[x]<Size[y])
    swap(x,y);
  parent[y]=x;
  Size[x]+=Size[y];
}

int main(){
  long long node,wt,cost,x,y;
  long long total_cast{0};
  cin>>node;
  vector<pair<long long,pair<int,int>>>graph;
  vector<pair<int,int>>edges;
  vector<int>station;
  make(node);
  loop(i,node){
    cin>>g[i][0]>>g[i][1];
  }
  loop(i,node){
    cin>>cost;  
    graph.push_back({cost,{0,i}});  //station build cast also adding as nodes edge 
  }
  loop(i,node){
    cin>>g[i][2];
  }
  loop(i,node){
    for(int j{i+1};j<=node;j++){
      wt = abs(g[i][0]-g[j][0])+abs(g[i][1]-g[j][1]);
      wt = wt*1LL*(g[i][2]+g[j][2]);
      graph.push_back({wt,{i,j}});
    }
  }

  sort(graph.begin(),graph.end());  //for minimum spanning tree 
  
  for(auto &it : graph){
    wt = it.first;
    x = it.second.first;
    y = it.second.second;
    if(find(x)==find(y))
      continue;
    Union(x,y);
    total_cast+=wt;
    if(x==0 or y==0)
      station.push_back(x+y);
    else
      edges.push_back({x,y});
  }
  cout<<total_cast<<endl;
  cout<<station.size()<<endl;
  for(auto &it : station){
    cout<<it<<' ';
  }
  cout<<endl<<edges.size()<<endl;
  for(auto &it : edges){
    cout<<it.first<<' '<<it.second<<endl;
  }
  return ((0 - 0));
}
//Opps I copy the Code (^-^)
//Source -> https://youtu.be/pZXatDdVELI