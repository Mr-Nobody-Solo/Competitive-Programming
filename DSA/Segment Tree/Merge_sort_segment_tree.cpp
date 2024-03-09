//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Segment tree -> Merge sort tree (space complexity NlogN)
 Source -> https://youtu.be/4tr5aFoBark
 Created -> 12/07/2023
 */
/*
Problem statement : 
Given an array of size N and Q queries from L,R and k.
Find the number of elements from range L to R which are 
strictly smaller than K.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 10001
int arr[N];
vector<int>st[4*N];

void buildSegmentMergeSortTree(int si, int ss, int se){
    if(ss == se){
        st[si].push_back(arr[ss]);
        return;
    }
    int mid = (ss+se)/2;
    buildSegmentMergeSortTree(2*si,ss,mid);
    buildSegmentMergeSortTree(2*si+1,mid+1,se);
    int i{0},j{0};
    while(i<st[2*si].size() and j<st[2*si+1].size()){
        if(st[2*si][i] <= st[2*si+1][j])
            st[si].push_back(st[2*si][i]),i++;
        else
            st[si].push_back(st[2*si+1][j]),j++;
    }
    while(i<st[2*si].size())
        st[si].push_back(st[2*si][i]),i++;
    while(j<st[2*si+1].size())
        st[si].push_back(st[2*si+1][j]),j++;
}

int query(int si, int ss, int se , int qs ,int qe, int k){
    if(ss > qe or qs > se)
        return 0;
    if(ss>=qs and se<= qe){
        int count = upper_bound(st[si].begin(),st[si].end(),k-1) - st[si].begin();
        return count;
    }
    int mid = (ss+se)/2;
    int l = query(2*si,ss,mid,qs,qe,k);
    int r = query(2*si+1,mid+1,se,qs,qe,k);
    return l+r;
}

int main(){
    int n,l,r,k,q;
    cin>>n>>q;
    for(int i{1};i<=n;i++)
        cin>>arr[i];
    buildSegmentMergeSortTree(1,1,n);
    while(q--){
        cin>>l>>r>>k;
        cout<<query(1,1,n,l,r,k)<<endl;
    }
    return (( 0 - 0 ));
}

/*
Input:
8 6
1 4 3 5 6 4 3 2
3 7 4
3 7 1
3 7 10
1 10 2
1 10 3
1 1 2
*/