//Starting with the name of ALLAH

//  Created by Mahmud on 11/13/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//  https://github.com/tr0j4n034/SPOJ/blob/master/CRAYON.cpp
//  problem link -> https://www.spoj.com/problems/CRAYON/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 1000100

int bit[N],subBit[N];
int l[N],r[N];
int linePos[N],line[N];
char ch[N];
int n;

void add(int i, int val , int arr[]){
    while(i<=n)
        arr[i] += val,i += i&(-i);
}
int pre_sum(int i,int arr[]){
    int sum{0};
    while(i>0)
        sum += arr[i],i -= i&(-i);
    return sum;
}

int main() {
    int lineNo{0},q;
    cin>>q;
    vector<int>v;
    for(int i{0};i<q;i++){
        cin>>ch[i];
        if(ch[i] == 'D' or ch[i] == 'Q'){
            cin>>l[i]>>r[i];
            v.push_back(l[i]);
            v.push_back(r[i]);
            if(ch[i] == 'D')
                linePos[++lineNo] = i;
        }else{
            cin>>line[i];
        }
    }
    v.push_back(0); //as bit starting index 1.

    //compressing the starting and terminal position of the line (l & r)
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    n = v.size();
    for(int i{0};i<q;i++){  
        if(ch[i] == 'D' or ch[i] == 'Q'){
            l[i] = lower_bound(v.begin(),v.end(), l[i]) - v.begin();
            r[i] = lower_bound(v.begin(),v.end(), r[i]) - v.begin();
        }
    }

    for(int i{0};i<q;i++){
        // cerr<<ch[i]<<endl;
        if(ch[i] == 'D'){
            add(l[i],1,bit);
            add(r[i],1,subBit);
        }else if(ch[i] == 'Q'){
            cout<<pre_sum(r[i],bit) - pre_sum(l[i]-1,subBit)<<endl;
        }else{
            lineNo = line[i];
            int idx = linePos[ lineNo ];
            add(l[ idx ],-1,bit);
            add(r[ idx ],-1,subBit);
        }
    }

    return (( 0 - 0 ));
}

// ^-^ 0_0 >_< \_(^-^)_/