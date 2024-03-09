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
 Topic ->Finding  the minimum distance from single source and multiple node.
 Source -> https://youtu.be/F3PNsWE6_hM
 Created -> 10/02/2023
 */

#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int INF = 1e9+10;
vector<vector<pair<int,int>>> graph;	//node then weight

vector<int> dijkstra(int src,int n){
	vector<int>visited(n+1,0);
	vector<int>distance(n+1,INF);
	distance[src]=0;
	set<pair<int,int>> st;	//weight then node 
	st.insert({0,src}); //first distance then node
	while(st.size()>0){
		auto node = *st.begin();
		int parent_v=node.second;
		st.erase(st.begin());
		if(visited[parent_v])continue;
		visited[parent_v]=1;
		for(auto child : graph[parent_v]){
			int child_v=child.first;
			int wt = child.second;
			if(distance[parent_v]+wt < distance[child_v]){
				distance[child_v] = distance[parent_v]+wt;
				st.insert({distance[child_v],child_v});
			}
		}
	}
	return distance;
}

int main(){
	int n,e,x,y,w,soucrce;
	cout<<"Enter the number of node and edge for directed weight graph :";
	cin>>n>>e;
	graph.resize(n+1);	//considering node number starting form 1.

	cout<<"\nEnter "<<e<<" connected edge where left side is connected to the right side only and their weight at the end.\n";
	while(e--){
		cin>>x>>y>>w;
		graph[x].push_back({y,w});	//as it is a directed graph.
	}

	cout<<"\nEnter the source node to find minimum distance of others node from it :";
	cin>>soucrce;
	vector<int> dis = dijkstra(soucrce,n);
	cout<<endl;
	for(int i{1};i<dis.size();i++){
		cout<<"minimum distance form source :"<<soucrce<<" to node "<<i<<" is:"<<dis[i]<<endl;
	}
	return 0;
}


/*
Input :
    3 3
    1 2 1
    1 3 5
    2 3 2
    1

Graphical view :
    
		    3
		    ^\
		  5 | \ 2
		    |  \
   source-> 1-->2
		      1
*/