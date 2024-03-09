///Starting with the name of Allah
//opps I saw the answer.
#include <iostream>
#include <map>
using namespace std;
const int N = 1e5+10;
int parent[N],Size[N];
map<int,int> mp;

int find(int v){
  if(v==parent[v])return v;
  return parent[v]=find(parent[v]);
}

void marge(int x,int y){
  mp[Size[x]]--;
  if(mp[Size[x]]==0)
    mp.erase(Size[x]);
  mp[Size[y]]--;
  if(mp[Size[y]]==0)
    mp.erase(Size[y]);
  mp[Size[x]+Size[y]]++;
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
    mp[1]++;
  }
    
  while(edge--){
    cin>>a>>b;
    Union(a,b);
    if(mp.size()==1)cout<<0<<endl;
    else{
      auto it = mp.begin();
      if(it->second>1)cout<<0<<endl; //as it is globally declared .(dot) will not work.
      else{
        int diff=N;
        int ff = it->first; 
        it++;
        while(it!=mp.end()){
          if(it->second>1){
            diff=0;
            break;
          }
          diff=min(diff,it->first-ff);
          ff=it->first;
          it++;
        }
        cout<<diff<<endl;
      }
    }
  }
  return (( 0 - 0 ));
}