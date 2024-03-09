//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Binary Index Tree (BIT) or Fenwick tree -> Range update in range query ***
 Source 1 -> https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/ 
 Source 2 -> https://codeforces.com/blog/entry/10306
 Source 3 -> https://cp-algorithms.com/data_structures/fenwick.html#2-range-update-and-point-query
 Created -> 18/08/2023
 */
#include <iostream>
#include <vector>
using namespace std;

void update(int i, long long value, vector<long long>&bit){
    while(i < bit.size())
        bit[i] += value, i += i&(-i);
}

long long sum(int i,vector<long long>&bit){
    long long temp{0};
    while(i>0)
        temp += bit[i] , i -= i&(-i);
    return temp;
}

void range_update(int l,int r, long long value, vector<long long>& bit, vector<long long>& sub_bit){
    update(l, value , bit);
    update(r+1, -value , bit);
    update(l, value * (l-1) , sub_bit);
    update(r+1, -value * r , sub_bit);
}

long long prefix_sum(int i,vector<long long>& bit, vector<long long>& sub_bit){
    return sum(i,bit)*i - sum(i,sub_bit);
}

long long range_sum(int l, int r, vector<long long>& bit, vector<long long>& sub_bit){
    return prefix_sum(r , bit , sub_bit) - prefix_sum(l-1 , bit , sub_bit);
}

int main(){
    //index must be 1 based.
    int n,q,l,r;
    char ch;
    cin>>n>>q;
    long long value;
    vector<long long>bit(n+1,0),sub_bit(n+1,0); //for range update every index must be initialize with zero at the begining.
    while(q--){
        cin>>ch;
        if(ch == 'U' or ch == 'u'){   //U for update the value
            cin>>l>>r>>value;
            range_update(l,r,value,bit,sub_bit);
        }
        else{
            cin>>l>>r;
            cout<<range_sum(l,r,bit,sub_bit)<<endl;
        }
    }
    return (( 0 - 0 ));
}

/*
input :

10 5
u 5 10 1
q 1 10
u 1 10 1
q 1 4
q 1 10

*/

// ^-^ 0_0 >_< \_(^-^)_/