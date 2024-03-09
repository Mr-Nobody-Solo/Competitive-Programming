//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Radix Sort (Compress space complexity of counting sort)
 Source -> https://youtu.be/Il45xNUHGp0
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countingSort(vector<int>&arr,int div){
    int maxElement = 10;    //as numbers are between 0 to 9
    vector<int>Count(maxElement+1,0);
    vector<int>temp(arr.size());

    for(int i{0};i<arr.size();i++){      
        int value = arr[i];
        int position_num = (value/div)%10;      //counting the elements according to i-th LSB of the number
        Count[position_num]++;
    }       

    for(int i{1};i<Count.size();i++)    //prefix_sum
        Count[i] += Count[i-1];     

    for(int i{(int)arr.size()-1};i>=0;i--){     //starting form last to first index for stability
        int value = arr[i];
        int position_num = (value/div)%10;
        temp[ Count[position_num]-1 ] = value;      //here Count[value] returning the actual position of the value but we need the index 
        --Count[position_num];
    }

    for(int i{0};i<arr.size();i++)      //coping elements
        arr[i]=temp[i];
}

void radixSort(vector<int>&arr){
    int maxElement = *max_element(arr.begin(),arr.end());
    for(int div{1}; maxElement/div > 0 ;div = div*10)
        countingSort(arr,div);
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
        cout<<"With negative integer counting sort will not work. <->_<->"<<endl;
    else{
        radixSort(arr);
        for(int i{0};i<arr.size();i++)
            cout<<arr[i]<<' ';
        cout<<endl;
    }
    return (( 0 - 0 ));
}