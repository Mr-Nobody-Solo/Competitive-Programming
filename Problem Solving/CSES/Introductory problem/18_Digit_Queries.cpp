// Starting with the name of Allah.
// Source -> https://youtu.be/QAcH8qD9Pe0?si=uvBYRd_xDRooJBtt
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
 
typedef long long ll;
#define loop(i,n)  for(int i=0  ;  i<n  ;  i++)
#define F first
#define S second
#define pb push_back
#define vc(x) vector<x>
#define mod 1000000007 
#define in(v) go(x,v)  cin>>x;
#define go(i,v) for(auto& i : v) 
#define cin(typ,x) typ x; cin>>x;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define bin(x) cout<<(x?"YES\n":"NO\n");
#define cout(x) auto typ=x; cout<<typ<<'\n';
#define out(v)  go(x,v) cout<<x<<' '; cout<<'\n';
#define test int tc;cin>>tc;for(int tt=1;tt<=tc;tt++)
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    test{
        cin(ll,q)
        ll L=1, R=10, ten=1, pre_pos=1, pos=10,mid;
        while(q >= pos){
            L=R;
            R *=10;
            ten++;
            pre_pos=pos;
            pos += (R-L)*ten;
        }
        R--;
        ll l = L;
        while(L<R){
            mid = (L+R+1)>>1;
            if ( pre_pos+ (mid-l)*ten <= q) L=mid;
            else R = mid-1;
            //cout<< L <<' '<<mid <<' '<<R<<endl;
        }
        pos = pre_pos+ (L-l)*ten;
        string s{ to_string(L) };
        //cerr<<s<<endl;
        cout(s[q-pos])
    }
    return ((0 - 0));
}
//    (o.o)    ( -_-`)    \_(^ _ ^)_/
