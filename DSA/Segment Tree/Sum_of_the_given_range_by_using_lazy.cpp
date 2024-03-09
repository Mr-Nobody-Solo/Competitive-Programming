//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Segment Tree -> finding the sum of the given range (by using lazy converting NlogN -> log N)
 Source -> https://youtu.be/f-GW4ZWxT0o
 Created -> 11/07/2023
 */
#include <iostream>
#include <climits> 
using namespace std;

#define N 400004
int arr[N],st[N],lazy[N];

void buildTree(int si, int ss, int se){
    if(ss == se){
        st[si] = arr[ss];
        return;
    }
    int mid = (ss+se)/2;
    buildTree(2*si,ss,mid);
    buildTree(2*si+1,mid+1,se);
    st[si] = st[si*2] + st[2*si+1];
}

int query(int si, int ss, int se , int qs, int qe){
    if(lazy[si] != 0){
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += (se-ss+1)*dx;
        if(ss != se){        
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }

    if(qs > se or qe < ss)
        return 0;

    if(ss>= qs and se <= qe)
        return st[si];

    int mid = (ss+se)/2;
    int l = query(2*si,ss,mid,qs,qe);
    int r = query(2*si+1,mid+1,se,qs,qe);
    return l + r;
}

void update(int si, int ss, int se, int l,int r, int value){
    if(lazy[si] != 0){
        int dx = lazy[si];
        lazy[si] = 0;
        st[si] += (se-ss+1)*dx;
        if(ss != se){        
            lazy[2*si] += dx;
            lazy[2*si+1] += dx;
        }
    }
    if(r < ss or l > se)
        return;
    if(ss>= l and se <= r){
        st[si] += (se-ss+1)*value;
        if(ss != se){
            lazy[2*si] += value;
            lazy[2*si+1] += value;
        }
        return;
    }
    int mid = (ss+se)/2;
    update(2*si,ss,mid,l,r,value);
    update(2*si,mid+1,se,l,r,value);
    st[si] = st[si*2] + st[2*si+1];
}

int main(){
    int n,test;
    cin>>n>>test;
    // for(int i{1};i<=n;i++)
    //     cin>>arr[i];
    buildTree(1,1,n);
    while(test--){
        int choice,l,r,value;
        cin>>choice;
        if(choice == 1){
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
        else{
            cin>>l>>r>>value;
            update(1,1,n,l,r,value);
        }
    }

    return (( 0 - 0 ));
}

/*
input :
10 6
1 1 10
2 1 1 10
1 1 10
2 1 10 10
1 1 10
1 1 2

*/