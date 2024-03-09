//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Disjoint Set Union (DSU)
 Source -> https://youtu.be/zEAmQqOpfzM
 Created -> 17/02/2023
 */

#include<iostream>
using namespace std;
const int N = 1e5;
int parent[N];
int Size[N];

void make(int i){
	parent[i]=i;
	Size[i]=1;
}

int find(int v){
	if(parent[v]==v)return v;
	//path compression
	return parent[v]=find(parent[v]);
}

void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(Size[a]<Size[b])
			swap(a,b);
		parent[b]=a;
		Size[a]+=Size[b];
	}
}

int main(){
	int n,v;
	cin>>n>>v;
	for(int i=1;i<=n;i++)
		make(i);
	while(v--){
		int x,y;
		cin>>x>>y;
		Union(x,y);
	}
	int connected_component{0};
	for(int i=1;i<=n;i++)
		if(parent[i]==i)connected_component++;
	cout<<"There are "<<connected_component<<" connected component in this Graph."<<endl;
	return 0;
}


/*
Input :
	8 7

	2 1
	2 5
	5 7
	3 6
	3 8
	8 4
	4 6

Graphical view :
    
	2---5   3
	|	|	| \
	1 	1 	|  6
			|   \
		    8----4 
*/