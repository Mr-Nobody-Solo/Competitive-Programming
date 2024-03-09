const int N = 1e5;
const int INF = 1e9+7;
vector<pair<int,int>> g[N];
int vis[N];
int dist[N];
void reset(int n){
    for(int i=0;i<=n;i++){
        dist[i]=INF;
        vis[i]=0;
        g[i].clear();
    }
}
int dijkstra(int source,int n){
    dist[source]=0;
    set<pair<int,int>> st;
    st.insert({0,source});
    int ans=0;
    while(st.size()){
        pair<int,int> node = *st.begin();
        int par = node.second;
        st.erase(st.begin());
        if(vis[par])continue;
        vis[par]=1;
        for(auto child : g[par] ){
            int child_v=child.first;
            int wt = child.second;
            if(dist[par]+wt<dist[child_v]){
                dist[child_v]=dist[par]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
    for(int i=1;i<=n;i++)ans=ans=max(ans,dist[i]);
    return ans==INF ? -1 : ans;
}
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        reset(n);
        for(auto &vec : times){
            g[vec[0]].push_back({vec[1],vec[2]});
        }
        return dijkstra(k,n);
    }
};