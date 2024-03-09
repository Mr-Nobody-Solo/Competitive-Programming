// Starting with the name of Allah.
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
*Source 1 : https://youtu.be/HZOUwKCKF5o?si=1EbtrPl4HHKZP21W&t=2924
*Source 2 : https://youtu.be/co4_ahEDCho?si=srNUwIOXVcy8P_Q2
*Related problem link -> https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1
*/
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;


class Compression_by_huffman_code{

    //-------------------------- node part -------------------------
    class Node{
    public:
        //properties
        int data{0};
        Node* left;
        Node* right;
        char key;
        //methods
        Node(int val,char c={}) : data(val), right(nullptr), left(nullptr),key(c) {}
        bool operator<(const Node& rhs) const {
            return (this->data < rhs.data);
        }
        bool operator>(const Node& rhs) const {
            return (this->data >  rhs.data);
        }
        ~Node(){
            delete right;
            delete left;
            // cerr<<this->data<<endl;
        }
    };

    Node* huffman_tree_root{nullptr};

    //must needed custom comparator as all nodes are declared as a pointer 
    struct customComparator{   
        bool operator()(const Node* lhs, const Node* rhs) const {
            return *lhs > *rhs;     //declaring greater<>
        }
    };

//---------------------------------------- Encoding  function part ----------------------------------------
public:
    //Getting new unique bits ID for for each unique character and building Huffman encoded tree.
    map<char,string> huffmanCodes(string S,vector<int> f){

        priority_queue< Node*,vector<Node*>, customComparator > pq;
        for(int i{0};i<f.size(); i++){
            Node* it = new Node(f[i],S[i]);
            pq.push(it);
        }

        while(pq.size()>1){
            Node* first = pq.top();     pq.pop();
            Node* second = pq.top();    pq.pop();
            Node* new_node = new Node(first->data + second->data);
            //------- building tree -------
            new_node->left = first;     
            new_node->right = second;
            pq.push(new_node);
        }

        string s{};
        map<char,string>mp;
        pre_order(pq.top(),s,mp);
        huffman_tree_root = pq.top();    pq.pop();
        return mp;
    }


//---------------------------------------- tree traversal part ----------------------------------------
private:
    //function for pre-order traversal for encoding the massage 
    void pre_order(Node* root , string& nowStr ,map<char,string>& mp){
        if(root->left == nullptr and root->right == nullptr){
            mp[root->key] = nowStr;
            return;
        }
        nowStr.push_back('0');
        pre_order(root->left,nowStr,mp);
        nowStr.pop_back();        

        nowStr.push_back('1');
        pre_order(root->right,nowStr,mp);
        nowStr.pop_back();
    }

    //function for pre-order traversal for decoding the massage 
    void pre_order(Node* root, string& go, string& massage){

    }

//---------------------------------------- Decoding function part ----------------------------------------
public:
    string decode_huffmancodes( string& controler_str){
        string massage_str{};
        Node* tmp = huffman_tree_root;
        for(char& ch : controler_str){
            if(tmp->left == nullptr and tmp->right == nullptr){     //as node have the char
                massage_str.push_back(tmp->key);
                tmp = huffman_tree_root;
            }
            if(ch == '0')
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        massage_str.push_back(tmp->key);
        return massage_str;
    }

    ~Compression_by_huffman_code(){
        // delete huffman_tree_root;
         delete huffman_tree_root;
    }
};

string char_to_binary(string& str){
    string binary_str{};
    for(char& ch : str){
        int char_val = ch;
        for(int pos{7};pos>-1;pos--)
            if(char_val& 1<<pos)
                binary_str.push_back('1') ;
            else
                binary_str.push_back('0');
    }
    return binary_str;
}

int main( ){
    //------------------------------- input part -------------------------------
    string massage_str{};
    cout<<"Enter a massage you want to compress the size : ";
    getline(cin,massage_str);
    

    cout<<"\n\n>>>>>>>>>>>>>>>>>>>>> Before compress : "<<endl;
    string unCompressed_binary_str =  char_to_binary(massage_str);
    // int before_size = massage_str.size() * 8; // as every character take 8 bit.
    // cout<<"Size of the massage before compress = "<< before_size <<endl;
    cout<<"Size of the massage before compress = "<< unCompressed_binary_str.size() <<endl;
    cout<<"Non compress massage in binary : "<<unCompressed_binary_str<<endl;
    

    //-------------------------------- processing part --------------------------------
    map<char,int> mp;
    for(char& ch : massage_str)
        mp[ch]++;

    vector<int>frequency;
    string unique_char{};
    for(const auto& [ch , f] : mp){
        frequency.push_back(f);
        unique_char.push_back(ch);
    }

    // -------- declaring object -------------
    Compression_by_huffman_code compressor_obj;
    compressor_obj.huffmanCodes(unique_char,frequency);
    map<char,string> char_key_map = compressor_obj.huffmanCodes(unique_char,frequency);


    //-------------------------------- Documentation part --------------------------------
    int after_size{0};
    cout<<"\n--------------Table------------------\n";
    for(int i{0};i<frequency.size();i++){
        cout<<"char : "<<unique_char[i] <<" frequency : "<< frequency[i] <<". ID : "<< char_key_map[ unique_char[i] ]<<endl;
        after_size += 8 + frequency[i] * char_key_map[ unique_char[i] ].size() ;
    }

    //------------------- getting new compressed massage in binary ---------------------
    string compressed_binary_str{};
    for(char& ch : massage_str)
        compressed_binary_str += char_key_map[ch];


    cout<<"\n>>>>>>>>>>>>>>>>>>>>> After compress : "<<endl;
    cout<<"Size of the massage afer compress = "<< after_size <<endl;
    // cout<<"Compress massage in binary : "<<compressed_binary_str.size()+ unique_char.size()*8<<endl;
    cout<<"Compressed massage in binary = "<<compressed_binary_str<<endl;


    // ----------------- decoding part / getting the real massage -----------------------
    string massage_str_new = compressor_obj.decode_huffmancodes( compressed_binary_str );
    cout<<endl<<"Decoded massage for huffmanCodes : "<<massage_str_new<<endl;

    return (( 0 - 0 ));
}

/*
Input : 

All praise to the most merciful Allah, who created me and give the opportunity to write this code.

*/

//(>.<) (^_^) (*_*) \_(^_^)_/
