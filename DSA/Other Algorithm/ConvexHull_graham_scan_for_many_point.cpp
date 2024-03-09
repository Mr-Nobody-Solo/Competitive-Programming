//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> ConvexHull -> using graham-scan-bug upgraded 
 Source -> Editorial -> https://practice.geeksforgeeks.org/problems/convex-hull2138/1
 Time complexity -> O(nLogn)  
 */
#include<algorithm>
#include<iostream>
#include<chrono>
#include<vector>
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

#define point pair<int,int>
#define x first
#define y second


const int mod = 1000000007;

inline int orientation(point a, point b, point c){
    // https://www.geeksforgeeks.org/orientation-3-ordered-points/
    long long p1 = (c.y-b.y)*1LL*(b.x-a.x);
    long long p2 = (b.y-a.y)*1LL*(c.x-b.x);
    int rotation = (p1-p2)%mod ;    // just simple subtract slop of ab and ac 
    return rotation ; // 0 == collinear , 0 > clockwise , 0 < counter-clockwise
}

void convexHull(vector<point>& v){

    sort(v.begin(), v.end(), 
        [&](const point& a , const point& b){     //sorting according to most left and bottom side
            return a.x < b.x or (a.x == b.x and a.y < b.y);
        }
    );

    point start = v[0];
    point end = v.back();

    vector<point>cw, ccw;   //cw -> clockwise and ccw -> counter-clockwise
    cw.push_back(start);    
    ccw.push_back(start);

    for(int i{1};i<(int)v.size();i++){       //using graham scan algorithm
        if(i == (int)v.size()-1 or orientation(start, v[i], end) < 0){  //for clockwise rotation 
            while(cw.size()>=2 and orientation(cw[cw.size()-2], cw.back(), v[i]) >= 0) //while counter-clockwise
                cw.pop_back();
            cw.push_back(v[i]);
        }
        if(i+1 == (int)v.size() or orientation(start, v[i], end) > 0){  //for counter-clockwise rotation 
            while(ccw.size()>=2 and orientation(ccw[ccw.size()-2], ccw.back() , v[i]) <= 0) //while clockwise
                ccw.pop_back();
            ccw.push_back(v[i]);
        }
    }

    v.clear();
    for(int i{0};i<ccw.size();i++)
        v.push_back(ccw[i]);
    for(int i{(int)cw.size()-2};i>0;i--)
        v.push_back(cw[i]);

}

int main( ){
    FIO;
    int num;
    cin>>num;

    vector<point>v(num);
    for(point& p : v)
        cin>>p.x>>p.y;

    auto beg = chrono::high_resolution_clock::now();

    convexHull(v);
    if(v.size()<3)
        cout<<"ConvexHull is not possible to build."<<endl;
    else
        for(auto& [x,y] : v)
            cout<<'('<<x<<','<<y<<')'<<endl;

    auto end = chrono::high_resolution_clock::now();
    auto total_duration = chrono::duration_cast<chrono::microseconds>(end - beg);
    cout<<"Elapsed time : " << total_duration.count()<< " [µs]"<<endl;

    return (( 0 - 0 ));
}
/*
input 1 :
6
0 0
-1 -1
1 1
2 2
3 3
4 4
input 2 :
8
1 1
2 2
0 0
3 3
4 4
3 1
0 3
1 2
*/
//(>.<) (^_^) (*_*) \_(^_^)_/
