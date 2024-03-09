//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|                      
*/
#include <iostream>
#include <algorithm> //Need for find()
#include <iterator>
#include <vector>
#include <list>
// #include<bits/stdc++.h>
using namespace std;
#define test size_t t;cin>>t;while(t--)
#define pb push_back 

int main(){
    list<int> myList;
    // list<int>::iterator it;
    myList.push_back(1);
    myList.push_front(2);
    myList.push_back(3);
    myList.push_front(4);
    for(auto it=myList.begin();it!=myList.end();it++)cout<<*it<<'\t';cout<<endl;
   
    //Inserting an element before a element in the list
    // auto it = find(myList.begin(),myList.end(),50);
    auto it = find(myList.begin(),myList.end(),100);
    if(it == myList.end()){
        cout<<"Element is not present in the list.\n";
    }else{
        myList.insert(it,100);
        cout<<"Element inserted in the list\n"
        <<"Elements are : ";
        for(it=myList.begin();it!=myList.end();it++)cout<<*it<<' ';cout<<endl;
    }
    
    //Erasing element
    myList.push_front(15);
    it = find(myList.begin(),myList.end(),15);
    if(it == myList.end()){
        cout<<"Element is not present in the list.\n";
    }else{
        myList.erase(it);
        // myList.erase(15);//Caution -> this type of erase which delete all same value elements is not support in list.
        cout<<"After erase elements are : ";
        for(it=myList.begin();it!=myList.end();it++)cout<<*it<<' ';cout<<endl;
    }

    myList.reverse();
    cout<<"Elements after reverse :";
    for(it=myList.begin();it!=myList.end();it++)cout<<*it<<' ';cout<<endl;

    myList.sort();
    cout<<"Elements after sort :";
    for(it=myList.begin();it!=myList.end();it++)cout<<*it<<' ';cout<<endl;

    myList.clear();
    cout<<"List size after clear :"<<myList.size()<<endl;

    int arr[ ]={1,2,3,4,5};
    // list<int> myList_2(arr,arr+5);  //Only work for new inetialized list (-_- )
    list<int> myList_2(arr,arr+(sizeof(arr)/sizeof(int)));
    cout<<"New elements are :";
    for(it=myList_2.begin();it!=myList_2.end();it++)cout<<*it<<' ';cout<<endl;

    return 0;
}
