// Starting with the name Allah.

// CSES DP 4 : Removing Digits
// https://cses.fi/problemset/task/1637
// source link -> https://youtu.be/YZDjUDW4xwc?si=KuRSDFkzVeoxvxgl

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
	
int main( ){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int n;	cin>>n;
    int cnt=0;
    while(n){
    	string s = to_string(n);
    	char mx_char='0';
    	for(char c : s)
    		mx_char = max(c,mx_char);
    	n -= (mx_char-'0');
    	cnt++;
    }
    cout<<cnt<<endl;
    return (( 0 - 0 ));
}
// (-_-) (^_^) (*_*) \_(^_^)_/  
