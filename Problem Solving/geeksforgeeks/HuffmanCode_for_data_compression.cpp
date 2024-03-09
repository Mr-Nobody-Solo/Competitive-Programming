// Starting with the name Allah.
//Problem link -> https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    //Declaring the node 
    class Node{
    public:
        //properties
        int data{0};
        Node* left;
        Node* right;
        //methods
        Node(int val) : data(val), right(nullptr), left(nullptr) {}
        bool operator<(const Node& rhs) const {
            return (this->data < rhs.data);
        }
        bool operator>(const Node& rhs) const {
            return (this->data >  rhs.data);
        }
        ~Node(){
            if(this->right)
                delete this->right;
            if(this->left)
                delete this->left;
            delete this;
        }
    };
    //must needed custom comparator as all nodes are declared as a pointer 
    struct customComparator{   
    public:
        bool operator()(const Node* lhs, const Node* rhs) const {
            return *lhs > *rhs;     //declaring greater<>
        }
    };


public:
    //Getting new unique bits ID for for each unique character 
    vector<string> huffmanCodes(string S,vector<int> f,int N){

        priority_queue< Node*,vector<Node*>, customComparator > pq;
        for(int& val : f){
            Node* it = new Node(val);
            pq.push(it);
        }

        while(pq.size()>1){
            Node* first = pq.top();     pq.pop();
            Node* second = pq.top();    pq.pop();
            Node* new_node = new Node(first->data + second->data);
            new_node->left = first;
            new_node->right = second;
            pq.push(new_node);
        }
        string s{};
        vector<string>v;
        pre_order(pq.top(),s,v);
        pq.pop();
        return v;
    }
    //function for pre-order traversal 
    void pre_order(Node* root , string& nowStr ,vector<string>& ans){
        if(root->left == nullptr and root->right == nullptr){
            ans.push_back(nowStr);
            return;
        }
        nowStr.push_back('0');
        pre_order(root->left,nowStr,ans);
        nowStr.pop_back();        

        nowStr.push_back('1');
        pre_order(root->right,nowStr,ans);
        nowStr.pop_back();
    }    
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
