//Starting with the name of ALLAH
//Source -> https://youtube.com/watch?v=cWvruDR-hJA&si=EnSIkaIECMiOmarE
//#include<bits/stdc++.h>
#include <iostream>
#include <climits>  //For INT_MAX 
#include <cmath>
using namespace std;
#define As_salamu_alikum ios_base::sync_with_stdio(0);cout.tie(0);
#define watch(x) cerr  << (#x) << " is " << (x) << endl
// #define cerr if(false)cerr

void print(int arr[],int size){
  for(int i{0};i<size;i++)cout<<arr[i]<<' ';cout<<endl;
}

void marge(int l,int r,int mid,int arr[]){
  int l_size = mid-l +1;
  int r_size = r-mid;
  int L[l_size+1];
  int R[r_size+1];
  L[l_size]=R[r_size]=INT_MAX;  //Adding aditional extra max element at last.

  for(int i{0};i<l_size;i++)
    L[i]=arr[l+i];

  for(int i{0};i<r_size;i++)
    R[i]=arr[mid+i+1];

  int l_pos = 0;
  int r_pos = 0;
  for(int i=l;i<=r;i++){
    if(L[l_pos]<=R[r_pos]){
      arr[i]=L[l_pos];
      l_pos++;
    }else{
      arr[i]=R[r_pos];
      r_pos++;
    }
  }
}

void margeSort(int l,int r,int arr[]){
  if(l==r)return;
  int mid = (l+r)>>1; //(l+r)/2
  margeSort(l,mid,arr);
  margeSort(mid+1,r,arr);
  marge(l,r,mid,arr);
}

int main(){
  As_salamu_alikum
  int n;  cin>>n;
  int arr[n];
  for(int i{0};i<n;i++)cin>>arr[i];
  // /*  selection sort Algorithm . Time complexity -> O(n^2)  */
  // for(int i{0};i<n;i++){
  //   int minIndx=i;
  //   for(int j{i+1};j<n;j++){
  //     if(arr[j]<arr[minIndx])minIndx=j;
  //   }
  //   swap(arr[i],arr[minIndx]);
  // }
  // print(arr,n);
  /*  Marge_sort Algorithm . Time complexity -> O(n*log(n))  */
  margeSort(0,(sizeof(arr)/sizeof(arr[0]))-1,arr);
  print(arr,n);
  return (( 0 - 0 ));
}
