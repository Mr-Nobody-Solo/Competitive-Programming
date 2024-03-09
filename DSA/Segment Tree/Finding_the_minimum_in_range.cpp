//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> Segment Tree -> Finding the minimum element in range 
 Source -> https://youtu.be/QT4RQzt1VO8
 Created -> 11/07/2023
 */
#include <iostream>
#include <climits> 
using namespace std;

void buildTree(int si, int ss, int se, int arr[], int st[]){
    if(ss == se){
        st[si] = arr[ss-1];
        return;
    }
    int mid = (ss+se)/2;
    buildTree(si*2,ss,mid,arr,st);
    buildTree(si*2+1,mid+1,se,arr,st);
    st[si] = min(st[si*2],st[si*2+1]);
}

int query(int si,int ss,int se, int qs, int qe , int st[]){
    if( qe < ss or qs > se)     //completely outside
        return INT_MAX;
    if(qs<= ss and qe >= se)    //completely inside 
        return st[si];
    int mid = (ss+se)/2;
    int l = query(si*2,ss,mid,qs,qe,st);
    int r = query(si*2+1,mid+1,se,qs,qe,st);
    return min(l,r);
}

void pointUpdate(int si, int ss, int se, int qi,int value,int st[],int arr[]){
    if(ss == se){
        st[si] = value;
        // cerr<<st[si]<<' '<<ss<<' '<<se<<' '<<qi<<endl;
        return;
    }
    int mid = (ss+se)/2;
    if(qi <= mid)
        pointUpdate(si*2,ss,mid, qi,value,st,arr);
    else
        pointUpdate(2*si+1,mid+1,se, qi,value,st,arr);
    st[si] = min(st[si*2],st[2*si+1]);
}

int main(){
    int n,q,l,r;
    cin>>n;
    int arr[n];
    for(int i{0};i<n;i++)
        cin>>arr[i];
    int st[sizeof(arr)];
    buildTree(1,1,sizeof(arr)/sizeof(arr[0]),arr,st);


    cout<<"If you want update a value Enter 1 else 2 : ";
    int check;
    cin>>check;
    if(check == 1){
        cout<<"Enter index and value ";
        int idx,value;
        cin>>idx>>value;
        idx++;
        pointUpdate(1,1,sizeof(arr)/sizeof(arr[0]),  idx,value ,st,arr);
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l++,r++;
        cout<<endl<<query(1,1,sizeof(arr)/sizeof(arr[0]), l , r , st);
    }
    for(int i{1};i<sizeof(arr);i++)
        cerr<<st[i]<<' ';cerr<<endl;
    return (( 0 - 0 ));
}

/*
Input 
3
1 4 1
1
0 -4
2
0 1
1 2

*/
