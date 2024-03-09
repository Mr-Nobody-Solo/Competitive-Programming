//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Segment tree -> Horrible Queries
 Source -> https://lightoj.com/problem/horrible-queries
 Created -> 12/07/2023
 */
#include <iostream>
#include <cstring>
using namespace std;

#define N 100010
long long st[4*N],lazy[4*N];

long long query(int si , int ss, int se ,int qs, int qe){
    if(lazy[si] != 0){
        long long dx = lazy[si];
        lazy[si] = 0;
        st[si] += (se-ss+1)*dx;
        if(ss != se)
            lazy[si<<1] += dx , lazy[(si<<1)+1] += dx;
    }

    if(ss > qe or se < qs)
        return 0;
    if(ss>= qs and se<= qe)
        return st[si];
    int mid = (ss+se)>>1;
    long long l = query(si<<1,ss,mid,qs,qe);
    long long r = query((si<<1)+1,mid+1,se,qs,qe);
    return l+r;
}

void update(int si, int ss, int se, int l, int r, long long val){
    if(lazy[si] != 0){
        long long dx = lazy[si];
        lazy[si] = 0;
        st[si] += (se-ss+1)*dx;
        if(ss != se)
            lazy[si<<1] += dx , lazy[(si<<1)+1] += dx;
    }

    if(ss > r or se < l)
        return;
    if(ss >= l and se <= r){
        st[si]+=(se-ss+1)*val;
        if(ss != se)
            lazy[si<<1]+=val,lazy[(si<<1)+1]+=val;
        return;
    }
    int mid = (ss+se)>>1;
    update(si<<1,ss,mid,l,r,val);
    update((si<<1)+1,mid+1,se,l,r,val);
    st[si] = st[si<<1] + st[(si<<1)+1];
}

int main(){
    int tt,n,q,check,Case{1};
    cin>>tt;
    while(tt--){
        cout<<"Case "<<Case++<<':'<<endl;
        cin>>n>>q;
        memset(st,0,sizeof(st));
        memset(lazy,0,sizeof(lazy));
        while(q--){
            int l,r;
            cin>>check>>l>>r;
            if(check == 0){
                int val;
                cin>>val;
                update(1,1,n,l+1,r+1,val);
            }else
                cout<<query(1,1,n,l+1,r+1)<<endl;
        }
    }
    return (( 0 - 0 ));
}

//^-^ 0_0 >_< \_(^-^)_/