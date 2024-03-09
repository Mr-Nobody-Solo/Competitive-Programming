//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
*Created : 17/01/2023
*Source 1 : https://youtu.be/c3ZBgMBgrHo 
*Source 2 : https://www.geeksforgeeks.org/heap-sort/
*/
//#include<bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;
#define hi ios_base::sync_with_stdio(false);cout.tie(nullptr);

void MaxHeapify(vector<int>&v,int parent,int size){
  int FirstLeaf{size/2};
  if(parent>=FirstLeaf)return;

  int LeftChild{2*parent+1},RightChild{2*parent+2}; //only applicable for 0 based index
  int largest{parent}; 
  if(v[RightChild]>v[largest] and RightChild<size){ //must include for heap sort RightChild<size
    largest = RightChild;
  }
  if(v[LeftChild]>v[largest] and LeftChild<size){ //must include for heap sort LeftChild<size
    largest = LeftChild;
  }
  if(parent!=largest){
    swap(v[parent],v[largest]);
    MaxHeapify(v,largest,size);
  }
}

void HeapSortByMaxHeapify(vector<int> &v){
  int size{v.size()};
  int LastParent{size/2-1}; //as starting index is 0 based,first leap = size/2 ;
  //Building Max Heap Tree
  for(int i{LastParent};i>=0;i--){
      MaxHeapify(v,i,size);
  }
  //cout<<"\nMax Heap Tree :";for(auto it:v)cout<<it<<" ";cout<<endl;
  while(size){  //size is !0.
    swap(v[0],v[size-1]);
    size--;
    MaxHeapify(v,0,size); //root = 0;
  }
}

int main(){
  hi
  int n;
  cout<<"Enter the number of element your want to add :";
  cin>>n;
  vector<int> v(n);
  cout<<"\nEnter the element separated by spaces :";
  for(auto &it :v)cin>>it;

  HeapSortByMaxHeapify(v);
  cout<<"\nElement after sorted (by heap) :";
  for(auto &it :v)cout<<it<<" ";
  cout<<endl;
  return ( 0 - 0 );
}