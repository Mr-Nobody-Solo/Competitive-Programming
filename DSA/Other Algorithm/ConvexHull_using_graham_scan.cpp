//Starting with the name of ALLAH
/*
 ____                  _ 
/ ___|  __ _  __ _  __| |
\___ \ / _` |/ _` |/ _` |
 ___) | (_| | (_| | (_| |
|____/ \__,_|\__,_|\__,_|
                        
 Topic -> ConvexHull -> using gram-scan 
 Source 1 -> https://www.geeksforgeeks.org/convex-hull-using-graham-scan/
 Time complexity -> Overall complexity is O(n) + O(nLogn) + O(n) + O(n) which is O(nLogn).
 Caution -> It is not give accurate output for large input( such as 1e5 points)
             and also little bit slow because of atan2() function.
 */
#include<algorithm>
#include<iostream>
#include<chrono>
#include<vector>
#include<stack>
#include<cmath>
#define FIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

#define point pair<int,int>
#define x first
#define y second

vector<point>points;
point start;

inline int distance(point a , point b){
    return ((a.x-b.x)*1LL*(a.x-b.x) + (a.y-b.y)*1LL*(a.y-b.y))%(int)1e7+10;
}

inline int orientation(point a, point b, point c){
    // https://www.geeksforgeeks.org/orientation-3-ordered-points/
    int rotation = (c.y-b.y)*(b.x-a.x)  // just simple subtract slop of ab and ac 
                  -(b.y-a.y)*(c.x-b.x);
    return rotation;
    //rotation > 0  counter-clockwise, rotation == 0 collinear and rotation < 0 clockwise
}

void convexHull(int num){
    // finding the left & bottom most point
    int min_y = points[0].y ,
    min_idx = 0;
    for(int i{1};i<num;i++)
        if(points[i].y < min_y or (points[i].y == min_y and points[i].x < points[min_idx].x) )
            min_idx = i , min_y = points[i].y;
    swap(points[0],points[min_idx]);

    start.x = points[0].x;
    start.y = points[0].y;
    sort(points.begin()+1, points.end(), 
        [&](point a , point b){     //custom compare-tor
            if (orientation(start,a,b) == 0)
                return distance(a,start) < distance(b,start);
            float slop_a = atan2( (a.y - start.y),(a.x - start.x) );      //polar angle  atan2(y,x)
            float slop_b = atan2( (b.y - start.y),(b.x - start.x) );
            return slop_a < slop_b;
        }
    );

    //Checking special case if all points are in one-line
    int not_collinear{1};
    for(int i{1};i<num;i++){
        while(i<num-1 and orientation(points[0],points[i],points[i+1]) == 0)
            i++;
        points[ not_collinear ++ ] = points[i];
    }
    if(not_collinear<3){
        cout<<"Convex-Hull is not possible"<<endl;
        return;
    }

    stack<point> st;
    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);

    for(int i{3};i<not_collinear;i++){
        point first_top = st.top();
        st.pop();
        while(st.size() >= 1 and orientation(st.top(),first_top,points[i]) <= 0){
            // cerr<<first_top.x<<' '<<first_top.y<<endl;     //see removed points from the stack
            first_top = st.top();
            st.pop();
        }
        st.push(first_top);
        st.push(points[i]);
    }

    while(not st.empty()){
        cout<<'{'<<st.top().x<<','<<st.top().y<<'}'<<endl;
        st.pop();
    }
}

int main( ){
    FIO;
    int num;
    cin>>num;

    points = vector<point>(num);
    for(point& p : points)
        cin>>p.x>>p.y;


    auto beg = chrono::high_resolution_clock::now();
    
    convexHull(num);

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
