
//Starting with the name of Allah.
//source -> https://youtu.be/hVFFWpSRY4o
#include <iostream>
#include <set>
using namespace std;
const int N = 1e5+10;
int parent[N],Size[N];
multiset<int> st;

int find(int v){
  if(v==parent[v])return v;
  return parent[v]=find(parent[v]);
}

void marge(int x,int y){
  st.erase(st.find(Size[x]));
  st.erase(st.find(Size[y]));
  st.insert(Size[x]+Size[y]);
}

void Union(int x,int y){
  x=find(x);
  y=find(y);
  if(x!=y){
    if(Size[x]<Size[y])
      swap(x,y);
    marge(x,y);
    parent[y]=x;
    Size[x]+=Size[y];
  }
}

int main() {
  int node,edge,a,b,mx,mn;
  cin>>node>>edge;
  for(int i{1};i<=node;i++){
    parent[i]=i;
    Size[i]=1;
    st.insert(1);
  }
    
  while(edge--){
    cin>>a>>b;
    Union(a,b);
    if(st.size()==1)cout<<0<<endl;
    else{
      mn=*(st.begin());
      mx=*(--st.end());
      cout<<mx-mn<<endl;
    }
  }
}