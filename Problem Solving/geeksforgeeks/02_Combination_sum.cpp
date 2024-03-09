//Starting with the name of Allah.

vector<vector<int>>vvi;
vector<int>v;

class Solution {
    void generate(int i,int sum,int B, vector<int>&A){
        if(sum>=B or i==A.size()){
            if(sum==B)
                vvi.push_back(v);
            return;
        }
        sum+=A[i];
        v.push_back(A[i]);
        generate(i,sum,B,A);
        sum-=A[i];
        v.pop_back();
        generate(i+1,sum,B,A);
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        set<int>st;
        for(auto &it :A)st.insert(it);
        A.clear();
        for(auto &it :st)A.push_back(it);
        v.clear();vvi.clear();
        generate(0,0,B,A);
        return vvi;
    }
};