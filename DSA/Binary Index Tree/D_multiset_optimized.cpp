//Starting with the name of ALLAH
//Bit or Fenwick tree-> https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees#lazy
//Binary search -> https://codeforces.com/blog/entry/77616 
//Binary lefting -> https://codeforces.com/blog/entry/61364
#include<iostream>
#include<cmath>
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

int binary_search(int nth_num){    //binary search for kth order statistic
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


int bit_search(int nth_num){    //binary lifting search for kth order statistic or kth number 
    int sum,pos;
    sum = pos = 0;
    int i{(int)log2(N)};
    while(i>=0){
        if(pos + (1<<i) <= N and sum + bit[ pos + (1<<i) ] < nth_num){
            sum += bit[pos + (1<<i)];
            pos += (1<<i);
        }
        i--;
    }
    return pos+1;
}

int main( ){
    FIO;    // Be careful about, Only for this line I get TLE (-_-) though I copied same to same code.
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
            // int nth_num = binary_search(-tmp);    // O(Log N * Log N)
            int nth_num = bit_search(-tmp);      // O( Log N )
            // cerr<<nth_num<<endl;
            update(nth_num,-1);
        }
    }
    // tmp = binary_search(1);
    tmp = bit_search(1);    
    if(tmp>N)       // if there no element then pos(in bit_search) will be N (as every element is 0 <1)
        tmp = 0;
    cout<<tmp<<endl;
    return (( 0 - 0 ));
}
//Opps i see the answer (>.<) (^_^) (*_*) \_(^_^)_/
