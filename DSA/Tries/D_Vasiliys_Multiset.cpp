//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Tries : Binary tree 
 Source -> // Solution link -> https://youtu.be/y9Qdb7maM4I?si=i2LYGPKSDU83qfSf
 Problem link-> https://codeforces.com/contest/706/problem/D
 */

#include<iostream>
#include<string>
using namespace std;

struct binary_tree{
    int val{0},cnt{0};
    binary_tree* one{nullptr};
    binary_tree* zero{nullptr};
};
binary_tree* root = new binary_tree;

void add(int num){
    binary_tree* tmp_root = root;
    for(int i{30};i>-1;i--){
        if(num&1<<i){
            if(tmp_root->one == nullptr)
                tmp_root->one = new binary_tree;
            tmp_root=tmp_root->one;
        }else{
            if(tmp_root->zero == nullptr)
                tmp_root->zero = new binary_tree;;
            tmp_root=tmp_root->zero;
        }
        tmp_root->cnt++;
    }
    tmp_root->val =  num;
}

void remove(int num){
    binary_tree* tmp_root = root;
    for(int i{30};i>-1;i--){
        if(num&1<<i)
            tmp_root = tmp_root->one;
        else
            tmp_root = tmp_root->zero;
        tmp_root->cnt--;    
    }
}

int find_max(int num){
    binary_tree* tmp_root = root;
    for(int i{30};i>-1;i--){
        bool one = num&1<<i;
        if(tmp_root->one == nullptr)
            tmp_root = tmp_root->zero;
        else if(tmp_root->zero == nullptr)
            tmp_root = tmp_root->one;
        else
            if(one and tmp_root->zero->cnt>0)
                tmp_root = tmp_root->zero;
            else if(not one and tmp_root->one->cnt>0) //i think there is some issue you need to solve (find it)
                tmp_root = tmp_root->one;
            else
                if(tmp_root->zero->cnt>0)
                    tmp_root = tmp_root->zero;
                else    //when both cnt are zero 
                    tmp_root = tmp_root->one;
    }
    return num^tmp_root->val;
}

int main( ){
ios_base::sync_with_stdio(false);cin.tie(nullptr);
    add(0);     //be carefull about that!
    int tt,num;
    char c;
    cin>>tt;
    while(tt--){
        cin>>c>>num;
        if(c=='+')
            add(num);
        else if(c=='-')
            remove(num);
        else
            cout<<find_max(num)<<endl;
    }
    return (( 0 - 0 ));
}
//Opps i saw the code (>.<) (^_^) (*_*) \_(^_^)_/
//copied code link -> https://codeforces.com/contest/706/submission/40885678
