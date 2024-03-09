//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> BIT -> getting the i-th index value(index must 1-based)
 problem link -> https://www.spoj.com/problems/UPDATEIT/en/
 Source -> https://youtu.be/08HzVTjCAsk
 Created -> 14/07/2023
 */
#include <iostream>
#include <vector>
using namespace std;

void update(int i,int val,vector<int>&v){
    while(i<v.size()){
        v[i] += val;
        i += i&(-i);
    }
}

int getIdxValue(int i, vector<int>&v){
    int sum{0};
    while(i>0){
        sum += v[i];
        i -= i& (-i);
    }
    return sum;
}

int main(){
    int tt,n,u,q,l,r,val;
    cin>>tt;
    while(tt--){
        cin>>n>>u;
        vector<int>v(n+1,0);
        while(u--){
            cin>>l>>r>>val;
            l++;r++;
            update(l,val,v);
            update(r+1,-val,v);
        }
        cin>>q;
        while(q--){
            int idx;cin>>idx;
            idx++;
            cout<<getIdxValue(idx,v)<<endl;
        }
    }
    return (( 0 - 0 ));
}

//^-^ 0_0 >_< \_(^-^)_/
