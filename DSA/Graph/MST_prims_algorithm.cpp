//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Minimum Spanning Tree : Prim's Algorithm
 Source -> random YouTube channel 
 */
#include<iostream>
#include<vector>
#include<tuple>
#include<set>
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
int main( ){
    FIO;
    int node,edge,x,y,dis,current_node;
    cin>>node>>edge;
    node++;
    vector<pair<int,int>>graph[node];
    vector<bool>visited(node,false);

    for(int i{0};i<edge;i++){
        cin>>x>>y>>dis;
        graph[x].push_back({y,dis});
        graph[y].push_back({x,dis});
    }

    long long total_cost{0};
    for(int i{0};i<node;i++){
        if(graph[i].empty() or visited[i])
            continue;
        cerr<<endl<<i;
        visited[i] = true;
        multiset<pair<int,int>> st;
        for(auto& [v,length] : graph[i])
            st.insert({length,v});

        while(not st.empty()){
            tie(dis,current_node) = *st.begin();
            st.erase(st.begin());

            // if lowest distance found st inside node after inserting other node in st
            if(visited[current_node])   
                continue;
            cerr<<" >--"<<dis<<"--> "<<current_node;

            visited[current_node] = true;
            total_cost += dis;

            for(auto& [child,length] : graph[current_node])
                if( visited[child] )
                    continue;
                else
                    st.insert({length,child});
        }
    }
    cerr<<endl;
    cout<<total_cost<<endl;

    return (( 0 - 0 ));
}
//(>.<) (^_^) (*_*) \_(^_^)_/
