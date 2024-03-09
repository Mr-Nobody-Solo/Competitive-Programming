//Starting with the name of ALLAH
#include <iostream>
using namespace std;
#define N 111

long long bit[N][N][N];
int n;

void add(int x,int y,int z, int val){
    for(int i{x}; i<=n; i += i&(-i))
        for(int j{y}; j<=n; j += j&(-j))
            for(int k{z}; k<=n; k += k&(-k))
                bit[i][j][k] += val;
}

long long pre_sum(int x,int y,int z){
    long long sum{0};
    for(int i{x}; i>0; i -= i&(-i))
        for(int j{y}; j>0; j -= j&(-j))
            for(int k{z}; k>0; k -= k&(-k))
                sum += bit[i][j][k];
    return sum;
}

int64_t query(int x, int y, int z ,int X ,int Y, int Z){
    //3D prefix-sum
    return pre_sum(X,Y,Z)
        -pre_sum(x,Y,Z)-pre_sum(X,y,Z)+pre_sum(x,y,Z)
        -pre_sum(X,Y,z)+pre_sum(X,y,z)+pre_sum(x,Y,z)-pre_sum(x,y,z);
}

int main() {
    int q,check,x,y,z,X,Y,Z,val;
    long long total{0};
    cin>>n>>q;
    n++;
    while(q--){
        cin>>check;
        if(check & 1){
            cin>>x>>y>>z>>val;
            x++,y++,z++;
            add(x,y,z,val);
            total += val;
        }else{
            cin>>x>>y>>z>>X>>Y>>Z;
            X++,Y++,Z++;
            cout<< total - query(x,y,z,X,Y,Z)<<endl;
        }
    }
    return (( 0 - 0 ));
}

//opps I see the answer. ^-^ 0_0 >_< \_(^-^)_/

