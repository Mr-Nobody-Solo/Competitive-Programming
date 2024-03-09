//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Sub string hashing
 Source -> https://youtu.be/2qYc2rXdN6U
 problem link -> https://cses.fi/problemset/task/1753/
 */
#include <iostream>
#include <string>
using namespace std;

#define mod 10000007

int main(){
    int ans{0};
    string s,key;
    cin>>s>>key;
    //using sub string hashing technique
    long long subHash[s.size()+3];
    long long prime{29},power{1},checker{0};    //not work prime less then 29
    subHash[0]=0;//be aware (^_^)
    for(int i{0};i<s.size();i++)
        subHash[i+1] = ( (subHash[i]*prime)%mod +s[i])%mod;
    for(int i{0};i<key.size();i++){
        checker = ( (checker*prime)%mod +key[i])%mod;
        power = (power*prime)%mod;  //(prime ^ key.size())
    }
    long long subValue;
    for(int r=key.size();r<=s.size();r++){
        subValue = subHash[r] - (subHash[ r - key.size() ]*power)%mod;
        if(subValue<0)
            subValue+=mod;
        if(subValue == checker)
            ans++;
    }
    cout<<ans<<endl;
    return (( 0 - 0 ));
}

// >_< ^.^ *_* \_(^_^)_/