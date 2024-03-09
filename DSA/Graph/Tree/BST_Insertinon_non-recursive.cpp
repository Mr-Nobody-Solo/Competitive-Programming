/*
Starting with the name of ALLAH 
Author Saad Ibn Abdullah
Created -> 13/01/2023
Work-> BST (Binary Search Tree) INSERTION : Non-recursive Implementation
Source -> https://youtu.be/cpeZo5T5-Kk
	   -> https://youtu.be/602BXxG6Q6w
*/
#include <iostream>
// #include<bits/stdc++.h>
using namespace std;

typedef struct BST{
    int data;
    struct BST *left;
    struct BST *right;
}Node;

Node *root;

void insert(int value){
    Node * newNode = new Node; //In c language alternative of new Node is : (Node*) malloc(sizeof(Node)); (must include stdlib.h header file for malloc() function)
    newNode->data = value;
    newNode->left = nullptr;    //In c language alternative of nullptr is : NULL.
    newNode->right = nullptr;
    if(root==nullptr){
        root = newNode;

    }else{
        Node * temp = root;
        while(true){    //ture not work in c languange.There alternative of true is : 1.
            //For left
            if(newNode->data<=temp->data){
                if(temp->left==nullptr){
                    temp->left=newNode;
                    break;
                }
                temp=temp->left;
            }
            //For Right
            else{
                if(temp->right==nullptr){
                    temp->right=newNode;
                    break;
                }
                temp=temp->right;
            }
        }   
    }
}

//Traversal the Nodes
void preOrder(Node * N){    //root > left >right
    if(N==nullptr) return;
    cout<<N->data<<" ";
    preOrder(N->left);
    preOrder(N->right);
}

void inOrder(Node * N){     //left > root >right
    if(N==nullptr) return;
    inOrder(N->left);
    cout<<N->data<<" ";
    inOrder(N->right);
}
void postOrder(Node * N){    //left > right > root
    if(N==nullptr) return;
    postOrder(N->left);
    postOrder(N->right);
    cout<<N->data<<" ";
}

int main(){
    root = nullptr;
    int nodeNum,temp,loop;
    cout<<"Enter the number of node you want to insert in BST : ";
    cin>>nodeNum;
    loop=nodeNum;
    cout<<"\nEnter nodes separated by spaces : ";
    while(loop--){
        cin>>temp;
        insert(temp);
    }
    cout<<"\nNode inserted in BST.\n";
    cout<<"Nodes in pre_order :";preOrder(root);cout<<endl;
    cout<<"Nodes in in_order :";inOrder(root);cout<<endl;
    cout<<"Nodes in post_order :";postOrder(root);cout<<endl;
    return 0;
}

/*
Inputs:
6
55 40 80 34 70 90

graphical view :

          55 
        /   \
       40   80
      /     / \
     34    70 90
*/