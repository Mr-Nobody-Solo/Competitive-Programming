//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
*Created : 17/01/2023
*** Caution : As this algorithm working by indexes,it cant not sort value less than 0.
*/
//#include<bits/stdc++.h> 
#include <iostream>
#include <cstring>
#include <algorithm> //required to find the max element.
using namespace std;
#define hi ios_base::sync_with_stdio(false);cout.tie(nullptr);

void CountingSort(int arr[],int size){ 
  int max;
  max = *max_element(arr,arr+size);
  int count[max+1];
  memset(count,0,sizeof(count));//all of the vector element are
  for(int i{0};i<size;i++)count[arr[i]]++;
  for(int i{0},pos{0};i<=max;i++){
    int k = count[i];
    while(k--){
      arr[pos++] = i;
    }
  }
}

int main(){
  hi
  int n;
  cout<<"Enter the number of element your want to add :";
  cin>>n;
  int array[n];
  cout<<"\nEnter the element separated by spaces :";
  for(int i{0};i<n;i++)cin>>array[i];

  CountingSort(array,n);
  cout<<"\nElement after sorted (by Count sort) :";
  for(int i{0};i<n;i++)cout<<array[i]<<" ";
  cout<<endl;
  return ( 0 - 0 );
}