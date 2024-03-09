//Starting with the name of Allah.
class Solution {
bool seek(int n,int k,int cnt){
        if(n==2){
            if(k==1)
                return cnt&1;   //if count is odd return will 0 esle 1
            else
                return !(cnt&1);  //if count is odd return will 1 esle 0

        }
        if(k>(1<<n-2)){
            cnt++;
            k%=(1<<n-2);
            if(!k)
                k=1<<n-2;
        }
        return seek(n-1,k,cnt);
}
public:
    int kthGrammar(int n, int k) {
        if(n==1 or k == 1) return 0;
        return seek(n,k,0);
    }
};