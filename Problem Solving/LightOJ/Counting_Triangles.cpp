//Starting with the name of ALLAH
//source -> https://lightoj.com/problem/counting-triangles
//Concept -> Binary Search
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int main(){
    int tt,query,n;
    cin>>tt;
    query = tt;
    while(tt--){
        int comb{0};
        cin>>n;
        vector<int>v(n);
        for(auto& it : v)
            cin>>it;
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++){
            for(int j{i+1};j<n;j++){
                int idx = lower_bound(v.begin(),v.end(),v[i]+v[j])-v.begin();
                comb += idx-1-j;
            }
        }
        cout<<"Case "<<query-tt<<": "<<comb<<endl;
    }    
    return (( 0 - 0 ));
}
