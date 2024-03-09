//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                
 Topic ->Height and depth of a tree by using DFS.
 Source -> https://youtu.be/i_FktdKVXDc
 Created -> 03/02/2023
*/

#include <iostream>
#include <vector>
using namespace std;
#define As_salamu_alaykum ios_base::sync_with_stdio(0);cout.tie(0);
#define test size_t t;cin>>t;while(t--)

vector<vector<int>> v;
vector<int>height,depth;

void dfs(int node, int parent=0){
  for(auto &child : v[node]){
    if(child==parent)continue;    //As it is a tree (not a connected graph) visited array doesn't needed.
    depth[child]= depth[node]+1;
    dfs(child,node);
    height[node]=max(height[node],height[child]+1);
  }
}

int main(){

  As_salamu_alaykum
  int n,e;
  cout<<"Enter the number of node :";
  cin>>n;
  v.resize(n+1);
  height.resize(n+1,0);
  depth.resize(n+1,0);
  
  cout<<"\nEnter every two connected edge one by one in new line,\n"; // node must start from 1.
  e=n-1;//as a tree has n-1 edges
  while(e--){
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1);//as it is a tree one call is enough.

  cout<<"Depth  of the tree (1 to n):";
  for(int i{1};i<depth.size();i++){
    cout<<depth[i]<<" ";
  }
  cout<<endl;
  cout<<"height of the tree (1 to n):";
  for(int i{1};i<depth.size();i++){
    cout<<height[i]<<" ";
  }
  cout<<endl;

  return (( 0 - 0 ));
}

/*
Input:
      13
      1 2
      1 3
      1 13
      2 5
      3 4
      5 6
      5 7
      5 8
      8 12
      4 9
      4 10
      10 11

Graphical view :
               1
            /  |   \
          1    3    13
        /       \
       5         4
     / | \      / \
    6  7  8    9   10
           \         \
           12         11
*/