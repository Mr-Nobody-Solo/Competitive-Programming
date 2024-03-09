//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Counting sort
 Source -> https://youtu.be/pEJiGC-ObQE
 Lickings -> take to much memory and can't sort negative element.(Can be compressed memory using Radix sort)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countingSort(vector<int>&arr){
    int maxElement = *max_element(arr.begin(),arr.end());
    vector<int>Count(maxElement+1,0);
    vector<int>temp(arr.size());

    for(int i{0};i<arr.size();i++)      //counting the elements
        Count[arr[i]]++;

    for(int i{1};i<Count.size();i++)    //prefix_sum
        Count[i] += Count[i-1];     

    for(int i{(int)arr.size()-1};i>=0;i--){     //starting form last to first index for stability
        int value = arr[i];
        temp[ Count[value]-1 ] = value;     //here Count[value] returning the actual position of the value
        --Count[value];
    }

    for(int i{0};i<arr.size();i++)      //copy elements
        arr[i]=temp[i];
}

int main( ){
    int size,minElement;
    cout<<"Enter the size of an array :";
    cin>>size;
    cout<<"Enter the array"<<endl;
    vector<int> arr(size);
    for(int i{0};i<arr.size();i++)
        cin>>arr[i];

    minElement = *min_element(arr.begin(),arr.end());
    if(minElement<0)
        cout<<"With negative intizer counting sort will not work. <->_<->"<<endl;
    else{
        countingSort(arr);
        for(int i{0};i<arr.size();i++)
            cout<<arr[i]<<' ';
        cout<<endl;
    }
    return (( 0 - 0 ));
}