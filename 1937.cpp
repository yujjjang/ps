#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > cache(502,vector<int>(502,-1));
vector<vector<int> > path(502, vector<int>(502,-1));
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
int dfs(int y, int x, vector<vector<int> >&v){
  if(cache[y][x] != -1) return cache[y][x];
  if(x==v.size()-1 || y==v.size()-1 || x==0 || y==0) return 0;
  int sum = 1;
  path[y][x] = 1;
  for(int i=0; i<4;++i)
    if(y+dir[i][1]>=0 && x+dir[i][0] >=0 && path[y+dir[i][1]][x+dir[i][0]]==-1 && v[y+dir[i][1]][x+dir[i][0]] > v[y][x]){
      sum = max(dfs(y+dir[i][1],x+dir[i][0],v)+1,sum);
    }
  path[y][x] = -1;
  cache[y][x] = sum;
  return sum;
}
int main(){
  std::ios::sync_with_stdio(false);
  int a,b;
  int sum=0;
  cin >> a;
  vector<vector<int> > v(a+2,vector<int>(a+2,0));
  for(int i=1;i<=a;++i)
    for(int j=1;j<=a;++j){
      cin >> b;
      v[i][j]=b;
    }
  for(int i=1;i<=a;++i)
    for(int j=1;j<=a;++j)
      sum=max(dfs(i,j,v),sum);
  cout << sum << endl;
  return 0;
}


/**
DFS + DP . Memoization.
**/
