//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|                      
*/
//Question -> 11518 - Dominos 2 - Online Judge
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
#define test size_t t;cin>>t;while(t--)
#define pb push_back 

int cnt;
void DFS(vector<vector<int>> &v,vector<int> &color,int n){
    cnt++;
    color[n]=0;
    for(auto &it : v[n]){
        if(color[it])
            DFS(v,color,it);
    }
}

int main(){
    int nodes,edges,starting_nodes,n1,n2;
    test{
        cnt=0;
        cin>>nodes>>edges>>starting_nodes;
        vector<vector<int>> v(nodes+1);
        vector<int>starting_point(starting_nodes),color(nodes+1,1);
        while(edges--){
            cin>>n1>>n2;
            v[n1].pb(n2);
        }
        for(auto &it : starting_point)cin>>it;
        for(auto &it : starting_point){
            if(color[it])
                DFS(v,color,it);
        }
        cout<<cnt<<endl;

    }
    return 0;
}

/*inputs :
1
3 2 1
1 2
2 3
2
*/