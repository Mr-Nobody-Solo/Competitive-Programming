//Starting with the name of ALLAH

/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Binary Index Tree (BIT) or Fenwick tree -> Range update in range query ***
 problem link -> https://lightoj.com/problem/horrible-queries
 Created -> 18/08/2023
 */

#include <iostream>
#include <cstring>
using namespace std;
#define N 100100

long long bit[N],sub_bit[N];
int n;

void add(int i,long long val,long long arr[]){
    while(i<=n)
        arr[i] += val, i+= i&(-i);
}
long long sum(int i,long long arr[]){
    long long temp{0};
    while(i>0)
        temp += arr[i] ,i -= i&(-i);
    return temp;
}
void update(int l,int r, long long val){
    add(l,val,bit);
    add(r+1,-val,bit);
    add(l,val*(l-1),sub_bit);
    add(r+1,-val*r,sub_bit);
}
long long prefix_sum(int i){
    return sum(i,bit)*i - sum(i,sub_bit);
}
long long query(int l,int r){
    return prefix_sum(r) - prefix_sum(l-1);
}
int main() {
    int tt,q,l,r,checker;
    cin>>tt;
    for(int i{1};i<=tt;i++){
        memset(bit,0,(n+1)*sizeof(long long));
        memset(sub_bit,0,(n+1)*sizeof(long long));
        cout<<"Case "<<i<<':'<<endl;
        cin>>n>>q;
        long long value;
        while(q--){
            cin>>checker>>l>>r;
            l++,r++;
            if(checker == 0)
                cin>>value , update(l,r,value);
            else
                cout<<query(l,r)<<endl;
        }
    }
    return 0;
}
