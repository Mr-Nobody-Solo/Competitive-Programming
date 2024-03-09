//Starting with the name of ALLAH

//source -> https://youtu.be/SQOQ99stCas
#include <iostream>
#include <vector> 
#include <deque> 
using namespace std;
#define As_salamu_alaykum ios_base::sync_with_stdio(0);cout.tie(0);
const int N = 1e5+10;
const int INF=1e9+7;
vector<pair<int,int>>g[N];
vector<int>level(N,INF);
int n,e;

int BFS(){
    deque<int> q;
    q.push_back(1);
    level[1]=0;
    while(!q.empty()){
        int parent = q.front();
        q.pop_front();
        for(auto child : g[parent]){
            int child_v = child.first;
            int wet = child.second;
            if(level[parent]+wet<level[child_v]){
                if(wet==0)q.push_front(child_v);
                else q.push_back(child_v);
                level[child_v]=level[parent]+wet;
            }
        }
    }
    return level[n] == INF ? -1 : level[n]; //This problem only want the shortest path 1 to n.
}

int main(){
	As_salamu_alaykum
    cin>>n>>e;
    while(e--){
        int x,y;
        cin>>x>>y;
        if(x==y)continue;
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }
    cout<<BFS()<<endl;
    return (( 0 - 0 ));
}

