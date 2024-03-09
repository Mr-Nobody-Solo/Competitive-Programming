//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Algorithm -> Tries 
 Source -> Youtube 
 problem link -> //All Tracks > Data Structures > Advanced Data Structures > Trie (Keyword Tree) > Beautiful Substrings
 */
#include<iostream>
#include<string>
using namespace std;
#define mod 1000000007
int ans;
struct Node{
    bool end{false};
    Node* a{nullptr};
    Node* b{nullptr};
};
Node*root = new Node;

void addWord(int n,Node* root,string& s){
    if(n == s.size()){
        root->end=true;
        return;
    }
    if(root->end == true)
        root->end = false;
    if( s[n]=='a' and root->a == nullptr){
        Node* tmp = new Node;
        root->a = tmp;
        addWord(n+1,root->a,s);
    }
    else if(s[n]=='b' and root->b == nullptr){
        Node* tmp = new Node;
        root->b = tmp;
        addWord(n+1,root->b,s); 
    }else{
        if(s[n]=='a')
            addWord(n+1,root->a,s);
        else
            addWord(n+1,root->b,s);
    }
}

void DFS(Node*root,int cnt,bool bFind){
    if(root->end == true)
        return;
    if(bFind and root->b != nullptr)
        cnt++;
    cnt = cnt%mod;
    ans = (ans + 0LL + cnt)%mod;
    if(root->b != nullptr)
        DFS(root->b,cnt,true);
    if(root->a != nullptr)
        DFS(root->a,cnt,bFind);
}

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        addWord(0,root,s);
    }
    ans=0;
    DFS(root,0,false);
    cout<<ans<<endl;
    return (( 0 - 0 ));
}

//  >_< ^-^ *_* \_(^_^)_/
