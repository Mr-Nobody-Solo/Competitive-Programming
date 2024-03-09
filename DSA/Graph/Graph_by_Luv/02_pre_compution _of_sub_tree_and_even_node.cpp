//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                
 Topic ->Finding the sum of sub tree and the number of even node in sub tree by DFS.
 Source -> https://youtu.be/w2oz11KWNQY
 Created -> 03/02/2023
*/
//Starting with the name of ALLAH
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define As_salamu_alaykum ios_base::sync_with_stdio(0);cout.tie(0);
#define test size_t t;cin>>t;while(t--)

vector<vector<int>> v;
vector<int>evenNode,subTreeSum;

void dfs(int node,int parent=0){
  if(node%2==0)evenNode[node]=1;
  subTreeSum[node]=node;
  for(auto &child : v[node]){
    if(child==parent)continue;
    dfs(child,node);
    evenNode[node]+=evenNode[child];
    subTreeSum[node]+=subTreeSum[child];
  }
}

int main(){

  As_salamu_alaykum
  int n,e,q;
  cout<<"Enter the number of node :";
  cin>>n;
  v.resize(n+1);
  evenNode.resize(n+1,0);
  subTreeSum.resize(n+1,0);
  
  cout<<"\nEnter every two connected edge one by one in new line,\n"; // node must start from 1.
  e=n-1;//as a tree has n-1 edges
  while(e--){
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1);
  cout<<"\nEnter the number of query:";
  cin>>q;
  cout<<endl;
  while(q--){
    int node;
    cin>>node;
    cout<<"Sum of sub-tree of node "<<node<<" is :"<<subTreeSum[node]<<",Even node :"<<evenNode[node]<<endl;
  }

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

3
4
3
2


Graphical view :
               1
            /  |   \
          2    3    13
        /       \
       5         4
     / | \      / \
    6  7  8    9   10
           \         \
           12         11
*/