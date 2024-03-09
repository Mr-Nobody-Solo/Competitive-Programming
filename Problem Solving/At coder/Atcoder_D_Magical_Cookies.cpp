// Starting with the name of the one and only creator of the universe Allah.
// Problem link -> https://atcoder.jp/contests/abc315/tasks/abc315_d
#include<iostream>
#include <unordered_set>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);

unsigned short board[2002][2002];
bool rowVis[2002],colVis[2002];

int main( ){
    fastIO;
    int row,col;
    cin>>row>>col;
    for(int i{0};i<row;i++){
        string s;
        cin>>s;
        for(int j{0};j<col;j++)
            board[i][j]= s[j]-'a';
    }

    unordered_set<int> NotUsedRow,NotUsedCol;   //it (insest, add, erase an element) take time almost O(1)
    for(int i{0};i<row;i++)
        NotUsedRow.insert(i);
    for(int j{0};j<col;j++)
        NotUsedCol.insert(j);

    while(true){
        bool search_again{false};
        // cheacking remaining rows
        if(NotUsedCol.size()>1)
            for(const int& i : NotUsedRow){
                auto it = NotUsedCol.begin();
                int startJ = *it;  
                for(++it; it != NotUsedCol.end();it++){
                    if(board[i][startJ] != board[i][*it])
                        break;
                }
                if(it == NotUsedCol.end() and NotUsedCol.size()>1){
                    search_again = true;
                    rowVis[i] = true;
                }
            }
        // cheacking remaining colums
        if(NotUsedRow.size()>1)
            for(const int& j : NotUsedCol){
                auto it = NotUsedRow.begin();
                int startI = *it;
                for(it++; it != NotUsedRow.end(); it++){
                    if(board[startI][j] != board[*it][j])
                        break;
                }
                if(it == NotUsedRow.end() and NotUsedRow.size()>1){
                    search_again = true;
                    colVis[j] = true;                
                }
            }

        //when no operation done.
        if(not search_again)
            break;

        // cerr<<"row :";
        for(auto it = NotUsedRow.begin();it != NotUsedRow.end();)
            if(rowVis[*it]){
                auto it_tmp = it;
                it++;
                // cerr<<*it_tmp<<' ';
                NotUsedRow.erase(it_tmp);
            }
            else
                 it++;
        // cerr<<"\ncol :";
        for(auto it = NotUsedCol.begin();it != NotUsedCol.end();)
            if(colVis[*it] ){
                auto it_tmp = it;
                it++;
                // cerr<<*it_tmp<<' ';
                NotUsedCol.erase(it_tmp);
            }else
                it++;
        // cerr<<endl;
    }
    if(NotUsedRow.size()==0)
        NotUsedCol.clear();
    if(NotUsedCol.size()==0)
        NotUsedRow.clear();

    cout<<NotUsedRow.size() *1LL* NotUsedCol.size()<<endl;   
    return (( 0 - 0 ));
}
//(>.<) (^_^) (*_*) \_(^_^)_/
