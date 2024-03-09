int Solution::solve(int A, vector<vector<int> > &B){
    vector<int> vis(A+1),adj[A+1],parant(A+1);
    for(int i{1};i<=A;i++)vis[i]=0;
    for(auto &pair : B){
        adj[pair[0]].push_back(pair[1]);
        adj[pair[1]].push_back(pair[0]);
    }
    stack<int>s;
    for(int i{1};i<=A;i++){
        if(vis[i])continue;
        s.push(i);
        parant[i]=0;
        vis[i]=1;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            for(auto &child : adj[node]){
                if(!vis[child]){
                    s.push(child);
                    parant[child]=node;
                    vis[child]=1;
                    continue;
                }
                if(child != parant[node])return 1;         
            }
        }
    }
    return 0;
}