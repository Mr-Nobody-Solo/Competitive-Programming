// Starting with the name of ALLAH

//source -> https://youtu.be/xvi8PqRrAyU
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define As_salamu_alaykum ios_base::sync_with_stdio(0);cout.tie(0);
#define tt size_t _;cin>>_;while(_--)
const int INF = 0x3f3f3f3f;
const int N = 550;
int adj[N][N],level[N][N];
int n,m,mx;

void reset(){
  memset(adj,0,sizeof(adj));
  memset(level,0,sizeof(level));

}

vector<pair<int,int>> movements{
  {-1,0},{1,0},{0,-1},{0,1},  //left-right-up-down
  {-1,-1},{1,1},{1,-1},{-1,1} //corners
};

bool isValid(int x,int y){
  return (x<n and x>=0 and y<m and y>=0 and !level[x][y] and adj[x][y]!=mx);
}

int bfs(){
  queue<pair<int,int>> q;
  for(int i{0};i<n;i++){
    for(int j{0};j<m;j++){
      if(adj[i][j]==mx){
        q.push({i,j});
        level[i][j]=1;
      }
    }
  }
  int ans=0;
  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    for(auto move : movements){
      int child_x=move.first+x;
      int child_y=move.second+y;
      if(!isValid(child_x,child_y))continue;
      adj[child_x][child_y]=mx;
      q.push({child_x,child_y});
      level[child_x][child_y]=level[x][y]+1;
      ans = max(ans,level[child_x][child_y]);
    }
  }   
  return ans>0?ans-1:0;
}

int main(){
  As_salamu_alaykum
  tt{
    reset();
    cin>>n>>m;
    mx=-1;
    for(int i{0};i<n;i++){
      for(int j{0};j<m;j++){
        cin>>adj[i][j];
        mx=max(mx,adj[i][j]);
      }
    }
    cout<<bfs()<<endl;
  }
  return (( 0 - 0 ));
}