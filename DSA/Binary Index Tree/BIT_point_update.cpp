//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Binary Index Tree (BIT) or Fenwick tree -> Point update in range query 
        -> also can be modify range update in point query (only get the i-th index value)
 Source 1(bangla) -> https://youtu.be/aAALKHLeexw 
 Source 2(english) -> https://youtube.com/playlist?list=PLDV1Zeh2NRsCvoyP-bztk6uXAYoyZg_U9
 Source 2(hindi) -> https://youtube.com/playlist?list=PLauivoElc3gi9zjJ9wIYFfmQ0-rdAKl85
 
 Created -> 17/08/2023
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int>bit;

void update(int i,int value){  //point update , O(logN)
    while(i<= bit.size()){
        bit[i] += value;
        i += i&(-i);
    }
}

int prefix_sum(int i){     //O(log(i))
    int sum{0};
    while(i>0){
        sum += bit[i];
        i -= i&(-i);
    }
    return sum;
}

int query(int l, int r){    //sum between l to r
    return prefix_sum(r)-prefix_sum(l-1);
}

void set(int i, int value){     
   int previous_value = query(i,i);     //getting i th index own value
   update(i,value - previous_value);
}

int main(){
    int n,q,l,r,chacker,temp;
    vector<int>arr; //BIT must be 1-based index for avoiding infinie loop
    cin>>n>>q;

    /*Building BItree method 1 : O(N log N)*/

    // arr.assign(n+1,0);
    // bit = arr;
    // for(int i{1};i<=n;i++){
    //     cin>>temp;
    //     update(i,temp);
    // }

    //---------------------------------------

    /*Building BItree method 2 : O(N)*/

    arr.resize(n+1);
    bit = arr;
    for(int i{1};i<=n;i++)
        cin>>arr[i];
    bit = arr;
    for(int i{1};i<=n;i++){
        int j = i + (i&(-i));
        if(j<=n)
            bit[j] += bit[i];
    }

    //--------------------------------------------

    while(q--){
        cin>>chacker;
        if(chacker == 1 ){
            cin>>l>>r;      //index must be 1-based
            cout<<query(l,r)<<endl;     //geting sum of index l to r
        }
        else{
            int idx,value;
            cin>>idx>>value;
            set(idx,value);     //setting i th index value.
        }
    }

    return (( 0 - 0 ));
}


/*
input :

5 6
1 2 3 4 5
1 1 1
1 5 5
1 1 5
2 5 0
1 5 5
1 1 5

*/