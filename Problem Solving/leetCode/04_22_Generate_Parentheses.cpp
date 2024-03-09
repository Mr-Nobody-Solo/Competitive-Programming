//Staring with the name of Allah.
//source-> https://youtu.be/4KpSXSIPH2s
void generate(int l,int r,string &s,vector<string>&v){
    if(not(l+r)){
        v.push_back(s);
        return;
    }
    if(l>0){
        s.push_back('(');
        generate(l-1,r,s,v);
        s.pop_back();
    }
    if(r>0 and r>l){
        s.push_back(')');
        generate(l,r-1,s,v);
        s.pop_back();
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>v;
        generate(n,n,s,v);
        return v;
    }
};