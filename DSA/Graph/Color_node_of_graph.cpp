//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Graph node color using back-tracking
 Source -> https://youtu.be/br3w8D12d0g?si=yt0zu5n-A8R4lwDO
 Time complexity -> O( C^(n-1) )
 */
#include<algorithm>
#include<iostream>
#include<chrono>
#include<vector>
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

vector<vector<int>>graph;
vector<char>colors;
vector<char>vertex_color;
int total_way{};

void color_nodes(int parent){

    if(parent == graph.size()){
        total_way++;
        for(char& c : vertex_color)
            cout<<c<<' ';
        cout<<endl;
        return;
    }

    for(char& c : colors){
        vertex_color[parent] = c;
        bool check_color{true};

        for(int& child : graph[ parent ])
            if(vertex_color[parent] == vertex_color[child]){
                check_color = false;
                break;
            }
        if(check_color)
            color_nodes(parent+1);
        //back-track
        vertex_color[parent] = '-';
    }
}

int main( ){
    FIO;
    int nodes,edges,color;
    cin>>nodes>>edges>>color;

    graph.resize(nodes);
    colors.resize(color);
    vertex_color = vector<char>(nodes,'-');
    total_way = 0;

    for(char& c : colors)
        cin>>c;
    for(int i{0};i<edges;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    auto beg = chrono::high_resolution_clock::now();

    color_nodes(0);
    if(not total_way)
        cout<<"You need more different color to color all the node."<<endl;
    else
        cout<<"Total possible way to color all node are : "<<total_way<<endl;

    auto end = chrono::high_resolution_clock::now();
    auto total_duration = chrono::duration_cast<chrono::microseconds>(end - beg);
    cout<<"Elapsed time : " << total_duration.count()<< " [µs]"<<endl;

    return (( 0 - 0 ));
}
//(>.<) (^_^) (*_*) \_(^_^)_/

/*
Input : 
4 4 3
g b r
1 2
2 3
3 4
4 1

    1 -- 2
    \    \
     4 -- 3
*/
