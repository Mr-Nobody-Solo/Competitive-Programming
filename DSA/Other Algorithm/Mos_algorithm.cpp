// Starting with the name Allah.
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Mo's Algorithm
 Time complexity ->O( (N+Q)*sqrt(N) )
 Source -> https://youtu.be/NBGLvmP3PAc?si=aZzXl9RIpvs0RPyV
 Problem link -> https://www.spoj.com/problems/DQUERY/

 */

#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define N 1000010
int cnt[N];

void add(int idx, int& nowUnique , int arr[]){
    if(cnt[ arr[idx] ] == 0)
        nowUnique++;
    cnt[ arr[idx] ]++;
}
void remove(int idx, int& nowUnique , int arr[]){
    cnt[ arr[idx] ]--;
    if(cnt[ arr[idx] ] == 0)
        nowUnique--;
}

int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int num,q;
    cin>>num;
    int arr[num+1];     //as given query index is 1 based
    for(int i{1};i<=num;i++)
        cin>>arr[i];
    
    //Mo's algorithm start
    cin>>q;
    struct query{ int idx,L,R; };
    vector<query>v(q);
    int ans[q];
    for(int i{0};i<q;i++){
        v[i].idx = i;
        cin>>v[i].L>>v[i].R;
    }

    int block = sqrt(num);
    sort(v.begin(),v.end(), [&] (query& a, query& b){
        if(a.L/block == b.L/block)
            return a.R < b.R;
        return a.L/block < b.L/block;
    });

    int nowL{1},nowR{0},nowUnique{0};   //As given query index start from 1.
    for(const query& qq : v){
        while(nowL < qq.L)
            remove(nowL++,nowUnique,arr);
        while(nowL > qq.L)
            add(--nowL,nowUnique,arr);

        while(nowR < qq.R)
            add(++nowR,nowUnique,arr);
        while(nowR > qq.R)
            remove(nowR--,nowUnique,arr);

        ans[ qq.idx ] = nowUnique;      //finding index'th query (L->R) Unique number
    }

    for(int i{0};i<q;i++)
        cout<<ans[i]<<endl;
    return (( 0 - 0 ));
}

/*
Input :
5
1 1 2 1 3
3
1 5
2 4
3 5

*/
// (>.<) (^_^) (*_*) \_(^_^)_/
