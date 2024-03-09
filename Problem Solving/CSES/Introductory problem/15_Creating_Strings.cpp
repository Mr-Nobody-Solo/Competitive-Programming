//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> recurtion -> back_tracking -> string combination with unique value.
 Source -> https://cses.fi/problemset/task/1622/
 Created -> 09/06/2023
 */
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

void make_parmutation(int i,string& s,set<string>& ans){
    if(i+1 == s.size()){
        ans.insert(s);
        return;
    }
    for(int j{i};j<s.size();j++){
        if(s[i]==s[j] and i != j)
            continue;
        swap(s[i],s[j]);
        make_parmutation(i+1,s,ans);
        swap(s[i],s[j]);
    }
}
    
/*
    while( next_permutation(s.begin(),s.end()) ){
        cout<<s<<endl;
    }
*/

int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    set<string> ans;
    make_parmutation(0,s,ans);
    cout<<ans.size()<<endl;
    for(auto& str : ans)
        cout<<str<<endl;

    return (( 0 - 0 ));
}
