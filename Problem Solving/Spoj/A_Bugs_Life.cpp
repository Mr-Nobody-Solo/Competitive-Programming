//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
*/
//#include<bits/stdc++.h> 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define As_salamu_alaykum ios_base::sync_with_stdio(false);cout.tie(nullptr);
 
bool check_DFS(vector<vector<int>>&v,vector<int>&vis,vector<int>&gender_check){
  for(int i{1};i<v.size();i++){
    if(vis[i]==0){
      vis[i]=1;
      stack<int> s;
      s.push(i);
      while(!s.empty()){
        int x=s.top();
        s.pop();
        for(auto &child :v[x]){
          if(vis[child]==0){
            vis[child]=1;
            gender_check[child]=gender_check[x]^1;
            s.push(child);
          }else{
            if(gender_check[child] == gender_check[x])return true;
          }
        }
      }
    }
  }
  return false;
}
 
int main(){
  As_salamu_alaykum
  int node,edge,x,y,tc;
  cin>>tc;
  for(int i{1};i<=tc;i++){
    cin>>node>>edge;    
    vector<vector<int>> v(node+1);
    vector<int>visited(node+1,0),gender(node+1);
    while(edge--){
      cin>>x>>y;    //here 0<x,y<=node
      v[x].push_back(y);
      v[y].push_back(x);
    }
    bool is_any_homosexual = check_DFS(v,visited,gender);
    cout<<"Scenario #"<<i<<":\n"
    <<((is_any_homosexual)?"Suspicious bugs found!":"No suspicious bugs found!")
    <<endl;
  }
 
  return (( 0 - 0 ));
}