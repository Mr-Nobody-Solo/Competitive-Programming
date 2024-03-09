/*==============================================================================================================

                                        Starting with the name of ALLAH
                                           ____                  _ 
                                          / ___|  __ _  __ _  __| |
                                          \___ \ / _` |/ _` |/ _` |
                                           ___) | (_| | (_| | (_| |
                                          |____/ \__,_|\__,_|\__,_|
                                      Practice, practice, and practice
I hated every minute of training, but I said, ‘Don't quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali 
                              You may not be the best, but must be the most effort
==============================================================================================================*/
 /*
 Topic ->Finding the Lowest Common Ancestor(LCA) of a tree by DFS.
 Source -> https://youtu.be/NzEzJ6Rmv2Q
 Created -> 04/02/2023
 */
#include <iostream>
#include <vector>
using namespace std;
#define As_salamu_alaykum ios_base::sync_with_stdio(0);cout.tie(0);
#define test size_t _;cin>>_;while(_--)

int leaf,max_distance;
vector<vector<int>> v;

void dfs(int node,int parent=-1,int depth=0){
  if(depth>max_distance){
    leaf=node;
    max_distance=depth;
  }
  for(auto &child : v[node]){
    if(child==parent)continue;
    dfs(child,node,depth+1);
  }
}

int main(){

  As_salamu_alaykum
  int n,e,q;
  cout<<"Enter the number of node :";
  cin>>n;
  v.resize(n+1);
  
  cout<<"\nEnter every two connected edge one by one in new line,\n"; // node must start from 1.
  e=n-1;//as a tree has n-1 edges
  while(e--){
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  max_distance=-1;
  dfs(1);
  max_distance=-1;
  dfs(leaf);
  cout<<"Diameter of a tree is :"<<max_distance<<endl;
  return (( 0 - 0 ));
}

/*
Input :
      14
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
      11 14

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
                        \
                        14
*/
