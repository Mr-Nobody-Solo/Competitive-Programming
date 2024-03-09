//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Segment Tree -> Range Minimum Query (minimum element in 0 based index range)
 Source -> https://youtu.be/QT4RQzt1VO8
 Problem link -> https://www.spoj.com/problems/RMQSQ/
 Created -> 11/07/2023
 */
#include <iostream>
#include <vector> 
#include <climits> 
using namespace std;
void buildTree(int si, int ss, int se, int arr[], int st[]){
    if(ss == se){
        st[si] = arr[ss-1]; //as it is zero based.
        return;
    }
    int mid = (ss+se)/2;
    buildTree(si*2,ss,mid,arr,st);
    buildTree(si*2+1,mid+1,se,arr,st);
    st[si] = min(st[si*2],st[si*2+1]);
}

int query(int si,int ss,int se, int qs, int qe , int st[]){
    if( qe < ss or qs > se)     //completely outside
        return INT_MAX;
    if(qs<= ss and qe >= se)    //completely inside 
        return st[si];
    int mid = (ss+se)/2;
    int l = query(si*2,ss,mid,qs,qe,st);
    int r = query(si*2+1,mid+1,se,qs,qe,st);
    return min(l,r);
}

int main(){
    int n,q,l,r;
    cin>>n;
    int arr[n];
    for(int i{0};i<n;i++)
        cin>>arr[i];
    int st[sizeof(arr)];
    buildTree(1,1,sizeof(arr)/sizeof(arr[0]),arr,st);
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l++,r++;
        cout<<query(1,1,sizeof(arr)/sizeof(arr[0]), l , r , st)<<endl;
    }

    return (( 0 - 0 ));
}

//opps I saw the answer. ^-^ 0_0 >_< \_(^-^)_/
