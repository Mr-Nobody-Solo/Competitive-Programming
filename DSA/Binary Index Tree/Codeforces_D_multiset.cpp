//Starting with the name of ALLAH
//problem link -> https://codeforces.com/contest/1354/problem/D
//Topic need to know -> Fenwick tree or BIT
//Editorial link -> https://codeforces.com/blog/entry/77616 
#include<iostream>
#define FIO ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int N,bit[1<<20];

int getSum(int i){
    int sum{0};
    for(;i>0;i -= i&-i)
        sum+=bit[i];
    return sum;
}

void update(int i,int num){
    for(;i<=N;i += i&-i)
        bit[i]+=num;
}

int search(int nth_num){    //binary search for kth order statistic
    int l=1,r=N,mid,pos=0;
    while(r-l>=0){
        mid=(r+l)/2;
        if(getSum(mid)>=nth_num){
            pos = mid;
            r=mid-1;
        }else
            l=mid+1;
    }
    return pos;
}

int main( ){
    FIO;    // Be careful about, Only for this I got TLE with the same code (-_-)
    int q,tmp;
    cin>>N>>q;
    for(int i{1};i<=N;i++){
        cin>>tmp;
        update(tmp,1);
    }
    for(int i{1};i<=q;i++){
        cin>>tmp;
        if(tmp>0)
            update(tmp,1);
        else{
            int nth_num = search(-tmp);
            // cerr<<nth_num<<endl;
            update(nth_num,-1);
        }
    }
    tmp = search(1);
    cout<<tmp<<endl;
    return (( 0 - 0 ));
}
//Opps i see the answer (>.<) (^_^) (*_*) \_(^_^)_/
