//source -> https://youtu.be/hVFFWpSRY4o

class Solution {
public:

void dfs(vector<vector<int>> &image ,int i,int j,int m,int n,int newColor,int currentColor){
  if(i<0 || j <0 || i>=m || j>=n)return;
  if(image[i][j]!=currentColor)return;
  
  image[i][j]=newColor;
  
  dfs(image,i-1,j,m,n,newColor,currentColor);
  dfs(image,i+1,j,m,n,newColor,currentColor);
  dfs(image,i,j+1,m,n,newColor,currentColor);
  dfs(image,i,j-1,m,n,newColor,currentColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    int currentColor = image[sr][sc];
    if(color!=currentColor)
        dfs(image,sr,sc,m,n,color,currentColor);
    return image;
  //opps i see the answer (^-^) 
    }
};