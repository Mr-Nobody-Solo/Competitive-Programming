//Starting with the name of Allah
#include <stdio.h>
#define loop(ini,end) for(int ini=1;i<=end;ini++)
#define N (int)1e3+10
const int mod = 1e9+7;
int parant[N],size[N];
long long weight[N],minWt[N],cnt[N];


int find(int v){
  if(parant[v]==v)return v;
  return parant[v]=find(parant[v]);
}

void Union(int x,int y){
  int mn = weight[x]<weight[y]?weight[x]:weight[y];
  x = find(x);
  y = find(y);
  if(x!=y){
    if(size[x]<size[y]){
      x=x+y;
      y=x-y;
      x=x-y;
    }
    parant[y]=x;
    size[x]+=size[y];
    if(minWt[x]>mn)minWt[x]=mn;
  }
}

int main(){
  int n,wt,e;
  scanf("%d", &n);
  loop(i,n){
    scanf("%d",&wt);
    parant[i]=i;
    size[i]=1;
    weight[i]=wt;
    minWt[i]=wt;
  }
  scanf("%d",&e);
  while(e--){
    int x,y;
    scanf("%d%d",&x,&y);
    Union(x,y);
  }
  loop(i,n) //most important
    parant[i]=find(i);
  loop(i,n)
    if(weight[i]==minWt[parant[i]])
      cnt[parant[i]]++;
  long long ans=1;
  loop(i,n){
    if(parant[i]==i && size[i]!=1)
      ans = (cnt[i]*ans)%mod;
  }
  printf("%lld\n",ans);
  return (( 0 - 0 ));
}