//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> String matching by KMP (Knuth-Morris-Pratt)
 Source -> https://youtu.be/sMARZCTPyNI
 problem link -> https://cses.fi/problemset/task/1753/
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> creatLps(string& pattern){
    vector<int>lps(pattern.size());
    lps[0]=0;
    int index{0},i{1};
    while(i<pattern.size()){
        if(pattern[index] == pattern[i])
            lps[i++] = ++index;
        else{
            if(index != 0)
                index = lps[index-1];   //i only increment if index=0 or find a match
            else
                lps[i++] = index;   //index == 0 
        }
    }
    return lps;
    /*  
        0 1 2 3 4 5 6 7 8
        a a b a a b a a a
        0 1 0 1 2 3 4 5 2 
    */
}
int KMP(string& str, string& pattern){  
    int match_cnt{0};
    vector<int> lps = creatLps(pattern);
    int i{0},j{0};
    //i -> str and j -> pattern
    while(i<str.size()){
        if(str[i] == pattern[j])
            i++,j++;
        else{
            if(j>0)
                j = lps[j-1];
            else
                i++;
        }
        if(j == pattern.size()){
            match_cnt++;
            j = lps[j-1];   //again checking how many element prefix == suffinx
        }
    }
    return match_cnt;
}
int main(){
    string str,pattern;
    cin>>str>>pattern;
    cout<<KMP(str,pattern)<<endl;
    return (( 0 - 0 ));
}

//Actually I don't fully konw how this algorithm work .>_< ^.^ *_* \_(^_^)_/