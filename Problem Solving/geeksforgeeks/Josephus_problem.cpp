//Starting with the name of Allah.
int last_one(int k,int pass,set<int>&st){
  if(st.size()==1)return *st.begin();
  auto it=st.find(k);
  it++;
  if(it==st.end())it=st.begin();
  st.erase(k);
  int loop{pass-1};
  while(loop--){
    it++;
    if(it==st.end()) it=st.begin();
  }
  k=*it;
  return last_one(k,pass,st);
}

class Solution
{
    public:
    int josephus(int n, int k)
    {
        int pass = k;
        set<int>st;
        for(int i{1};i<=n;i++)st.insert(i);
        k=k%n;
        if(!k)k=n;
        return last_one(k,pass,st);;
    }
};