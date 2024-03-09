

// Link -> https://practice.geeksforgeeks.org/problems/convex-hull2138/1

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

class Solution {
public:
    vector<vector<int>>FindConvexHull(vector<vector<int>>points_list){

        int num = points_list.size();
        vector<point>v(num);
        
        int idx{0};
        for(auto& row : points_list){
            v[idx].x=row[0];
            v[idx++].y=row[1];
        }
      
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
            
        vector<vector<int>>ans(v.size());
        for(int i{0};i<v.size();i++){
            ans[i].push_back(v[i].x);
            ans[i].push_back(v[i].y);
        }
 
        if(ans.size() < 3){
            ans.clear();
            ans.push_back({{-1}});
        }
        
        sort(ans.begin(),ans.end());
        
        return ans ;
    }
};
