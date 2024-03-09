//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Trie by using only small letter word
 Source -> https://youtu.be/y9Qdb7maM4I
 Caution -> Every letter must be samll.
 */
#include<iostream>
#include<set>
#include <thread>
using namespace std;

//Clear screen for Linux
    #define clear system("clear")
//Clear screen for windows
    // #define clear system("CLS")

struct Node{
    bool isTerminal{false};
    Node* child[26];
};

void insert(int n, Node* root, string& s){
    if(n == s.size()){
        root->isTerminal = true;
        return;
    }
    if(root->child[s[n]-'a'] == NULL){
        Node* new_node = new Node;
        for(int i{0};i<26;i++)
            new_node->child[i] = NULL;
        root->child[s[n]-'a'] = new_node;
    }
    insert(n+1, root->child[s[n]-'a'], s);
}

bool search(int n, Node* root, string& s){
    if(n == s.size())
        return root->isTerminal;
    if(root->child[s[n]-'a'] == NULL)
        return false;
    else
        return search(n+1, root->child[s[n]-'a'], s);
}

//------------------deleting word------------------------
Node* deleteNode(int n,Node* root, string& s){
    if(n<s.size())
        root->child[s[n]-'a'] = deleteNode(n+1,root->child[s[n]-'a'],s);
    if(n==s.size()){
        root->isTerminal=false;
        bool need_to_delete{true};
        for(int i{0};i<n;i++)
            if(root->child[i] != NULL){
                need_to_delete = false;
                break;
            }
        if(need_to_delete){
            delete root;
            return NULL;
        }
    }
    if(root->child[s[n]-'a'] == NULL and root->isTerminal==false){
        delete root;
        return NULL;
    }
    else
        return root;
}

bool Delete(Node* root, string& s){
    if(search(0, root,  s)){
        root = deleteNode(0,root,s);
        return true;
    }
    return false;
}

void print_info(){
    cout<<"1. Insert in Trie.\n"
        <<"2. Search is Trie.\n"
        <<"3. Delete is Trie.\n"
        <<"4. Exit.\n"
        <<"---------------------------\n"
        <<"Enter your choice : ";
}

int main( ){
    Node* root = new Node;
    string str;
    set<string> st;
    while(true){
        char c='a';
        print_info();
        cin>>c;
        clear;
        switch(c){
            case '1' : {
                        cout<<"Enter the word you want to add : "; //Every letter must be small
                        cin>>str;
                        st.insert(str);
                        insert(0,root,str);
                        cout<<str<<" added in Trie."<<endl;
                        break;
            }
            case '2' : {
                        cout<<"Enter search word : ";  //Every letter must be small
                        cin>>str;
                        if(search(0,root,str))
                            cout<<"The is present in the Trie"<<endl;
                        else 
                            cout<<"The is not found in the Trie"<<endl;
                        break;
            }
            case '3' : {

                        cout<<"Enter the word you want to delete : "<<endl;
                        cin>>str;
                        if(Delete(root,str)){
                            cout<<str<<" has been deleted."<<endl;
                            st.erase(str);
                        }
                        else
                            cout<<"The word is not present in that Trie."<<endl;
                        break;
            }
            case '4' : {

                        cout<<"Have a nice day....\n(^_^)"<<endl;
                        break;
            }
            default : {
                        cout<<"Please Enter a valied input (-_-)."<<endl;
                        break;
            }
        }
            this_thread::sleep_for(chrono::milliseconds(1500));
            clear;
            cout<<endl;
        if(c == '4')
            break;
    }
    while(not st.empty()){
        str = *st.begin();
        deleteNode(0,root,str);
        st.erase(st.begin());
    }
    return (( 0 - 0 ));
}

//  >_< ^-^ *_* \_(^_^)_/
