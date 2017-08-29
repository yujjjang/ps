#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int a,b;
  cin >> a;
  int end=a;
  int y_idx = 1;
  int x_idx = 0;
  vector<vector<int> > dp(3, vector<int>(3,0));
  vector<vector<int> > mdp(3, vector<int>(3,0));
  while(a--){
    for(int x = 0; x<=2; ++x){
      cin >> b;
      if (x_idx==0){
        dp[y_idx][x_idx]=max(dp[y_idx-1][x_idx],dp[y_idx-1][x_idx+1])+b;
        mdp[y_idx][x_idx]=min(mdp[y_idx-1][x_idx],mdp[y_idx-1][x_idx+1])+b;
      } else if (x_idx ==2){
        dp[y_idx][x_idx]=max(dp[y_idx-1][x_idx],dp[y_idx-1][x_idx-1])+b;
        mdp[y_idx][x_idx]=min(mdp[y_idx-1][x_idx],mdp[y_idx-1][x_idx-1])+b;
      } else {
        dp[y_idx][x_idx]=max(dp[y_idx-1][x_idx],dp[y_idx-1][x_idx-1])+b;
        dp[y_idx][x_idx]=max(dp[y_idx][x_idx], dp[y_idx-1][x_idx+1]+b);
        mdp[y_idx][x_idx]=min(mdp[y_idx-1][x_idx],mdp[y_idx-1][x_idx-1])+b;
        mdp[y_idx][x_idx]=min(mdp[y_idx][x_idx], mdp[y_idx-1][x_idx+1]+b);
      }
      x_idx++;
    }
    for(int i = 0; i < 3; ++i){
      dp[0][i]=dp[1][i];
      mdp[0][i]=mdp[1][i];
    }
    x_idx=0;
   }
  for(int i = 0; i<3; ++i){
    dp[1][0] = max(dp[1][0], dp[1][i]);
    mdp[1][0] = min(mdp[1][0], mdp[1][i]);
  }
  cout << dp[1][0] << ' ' << mdp[1][0] << endl;
  return 0;
}
