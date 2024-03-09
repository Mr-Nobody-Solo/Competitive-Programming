//Starting with the name of Allah.
//Source -> https://youtu.be/u0e29JIdxZU
class Solution {
    vector<vector<int>> vv;
    void subset(vector<int>&v,int pos,int last,vector<int>&subs){
    if(pos==last){
      vv.push_back(subs);
      return;
    }
    subset(v,pos+1,last,subs);
    subs.push_back(v[pos]);
    subset(v,pos+1,last,subs);
    subs.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subs;
        subset(nums,0,nums.size(),subs);
        return vv;
    }
};

/*
//Solving by bit_manipulation
// source -> https://youtu.be/wpWGDHmpbgA
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all_subs; 
        int elements = nums.size();
        int combination=(1<<elements);
        for(int i=0;i<combination ;i++){
            vector<int>subs;
           for(int j=0;j<elements;j++) 
              if((i&(1<<j))!=0)
                 subs.push_back(nums[j]);
            all_subs.push_back(subs);
        }
     return all_subs;
 }
};

*/