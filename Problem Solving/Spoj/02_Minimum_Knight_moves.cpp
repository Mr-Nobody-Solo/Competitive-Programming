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

//source ->https://youtu.be/WOV3LYhPews

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#define As_salamu_alaykum ios_base::sync_with_stdio(0);cout.tie(0);
#define test size_t t;cin>>t;while(t--)

int level[8][8];
int visited[8][8];

int getX(string &pos){return (pos[0]-'a');}
int getY(string &pos){return (pos[1]-'1');}

vector<pair<int,int>> movements ={
  {-1,2},{1,2}, //knight down move 
  {-1,-2},{1,-2},//knight up move 
  {2,-1},{2,1},//knight right move 
  {-2,-1},{-2,1},//knight left move 
};

bool isValied(int x,int y) {
  return (x>=0 and x<8 and y>=0 and y<8 and !visited[x][y]);
}

int bfs(string &start,string &end){
  int sourceX = getX(start);
  int sourceY = getY(start);
  int endX = getX(end);
  int endY = getY(end);
  queue< pair<int,int>> q;
  q.push({sourceX,sourceY});
  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    visited[x][y]=1;
    q.pop();
    for(auto &moves : movements){
      int childX=moves.first+x;
      int childY=moves.second+y;
      if(!isValied(childX,childY))continue;
      visited[childX][childY]=1;
      q.push({childX,childY});
      level[childX][childY]=level[x][y]+1;
    } 
    if(level[endX][endY])break;
  }
  return level[endX][endY];
}

void reset(){
  for(int i{0};i<8;i++){
    for(int j{0};j<8;j++){
      level[i][j]=0;
      visited[i][j]=0;
    }
  }
}

int main(){
  As_salamu_alaykum
  string src,dest;
  test{
    reset();
    cin>>src>>dest;
    cout<<bfs(src,dest)<<endl;
  }
  return (( 0 - 0 ));
}
