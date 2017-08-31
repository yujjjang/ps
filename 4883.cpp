#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
  std::ios::sync_with_stdio(false);
  int a,b,cnt;
  cnt=1;
  vector<vector<long long> > dp;
  vector<int> aa(3,0);
  while(1){
    cin >> a;
    if(a==0) break;
    dp.resize(a+1,vector<long long>(4,0));
    dp[0][1]=0;
    dp[0][2]=INT_MAX;
    dp[0][3]=INT_MAX;
    for(int i=1;i<=a;++i){
      for(int j=1; j<=3; ++j){
        cin >> b;
        aa[j-1]=b;
        if(j==1){
          dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+b;
          dp[1][1]=INT_MAX;
        } else if (j==2){
          dp[i][j]=min(min(dp[i][j-1],dp[i-1][j-1]), min(dp[i-1][j],dp[i-1][j+1]))+b;
        } else {
          dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]), dp[i][j-1])+b;
        }
      }
    }
    cout << cnt << ". "<<dp[a][2]<<endl;
    cnt++;
    dp.clear();
  }
  return 0;
}
