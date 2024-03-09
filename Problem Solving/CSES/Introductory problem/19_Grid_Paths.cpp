// Starting with the name of Allah.
// Source -> https://youtu.be/wWUWA70drAY?si=BXHq7U79npIQgSjX
// Problem link -> https://cses.fi/problemset/task/1625/
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int ans;
string s;

bool visited[7][7];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

bool valied(int x, int y){
	return (x<7 and y<7 and x>-1 and y>-1 and visited[x][y]==false);
}

void dfs(int x,int y,int i){
	// cout<<x<<' '<<y<<' '<<i<<endl;
	if(i>=48){
		if(x==6 and y==0 and i==48)ans++;
		return;
	}
	//Optimizing the DFS
	if(x==6 and y==0)return; //if reach end point without using all cell
	//checking vertical line condition for stop
	if( (valied(x,y+1) and valied(x,y-1)) and 
		( (x<6 and x>0 and visited[x+1][y] and visited[x-1][y]) or (x==0 and visited[x+1][y]) or (x==6 and visited[x-1][y])) )return;
	//checking horizontal line condition for stop
	if( (valied(x-1,y) and valied(x+1,y)) and 
		( (y<6 and y>0 and visited[x][y-1] and visited[x][y+1]) or (y==0 and visited[x][y+1]) or (y==6 and visited[x][y-1])) )return;
	if(x>0 and y<6 and visited[x-1][y+1] and not visited[x-1][y] and not visited[x][y+1])return; // checking upper right corner / 	-> X
	if(x<6 and y>0 and visited[x+1][y-1] and not visited[x+1][y] and not visited[x][y-1])return; // checking lower left corner /	-> X
	if(x>0 and y>0 and visited[x-1][y-1] and !visited[x-1][y] and !visited[x][y-1])return; // checking upper left corner \	-> X
	if(x<6 and y<6 and visited[x+1][y+1] and !visited[x+1][y] and !visited[x][y+1])return; // checking lower right corner \	-> X

	visited[x][y]=true;
	if(s[i]=='?'){
		for(int idx=0;idx<4;idx++)
			if(valied(x+dx[idx] , y+dy[idx])) 
				dfs(x+dx[idx],y+dy[idx], i+1);
	}else{
		if(s[i] == 'D' and valied(x+1,y)) dfs(x+1,y, i+1);
		if(s[i] == 'U' and valied(x-1,y)) dfs(x-1,y, i+1);
		if(s[i] == 'L' and valied(x,y-1)) dfs(x,y-1, i+1);
		if(s[i] == 'R' and valied(x,y+1)) dfs(x,y+1, i+1);
	}
	visited[x][y]=false;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin>>s;
    dfs(0,0,0);
    cout<<ans<<endl;
    return ((0 - 0));
}
//    (o.o)    ( -_-`)    \_(^ _ ^)_/
