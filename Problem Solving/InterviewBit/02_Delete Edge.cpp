//Starting with the name of ALLAH

//source->https://youtu.be/NzEzJ6Rmv2Q

void dfs(int node,int par,vector<int>g[],vector<long long>&subTree,vector<int> & val){
    subTree[node]=val[node-1];
    for(auto child :g[node]){
        if(child==par)continue;
        dfs(child,node,g,subTree,val);
        subTree[node]+=subTree[child];
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    const int mod = 1e9+7;
    int sz=A.size()+1;
    vector<int>g[sz];
    vector<long long>sub_tree_sum(sz,0);
    for(auto &v : B){
        g[v[0]].push_back(v[1]);
        g[v[1]].push_back(v[0]);
    }
    dfs(1,0,g,sub_tree_sum,A);
    long long ans=0;
    for(int i{2};i<=A.size();i++){  //Here 1 is a root.(fixed)
        long long sub=(sub_tree_sum[1]-sub_tree_sum[i])*sub_tree_sum[i];//it is not real answer.(-_-)
        //sub = (sub_tree_sum[1]-sub_tree_sum[i])*1LL*sub_tree_sum[i])%mod;     //there is a problem in question input.
        ans = max(ans,sub);
    }
    return ans%mod;
}
