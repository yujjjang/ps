#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main(){
  std::ios::sync_with_stdio(false); // 40ms -> 12ms.
  int a,b;
  cin >> a >> b;
  char c[1001];
  vector<vector<int> > w(a+1, vector<int>(b+1,0));
  vector<vector<int> > dp(a+1, vector<int>(b+1,0));
  int Min=INT_MAX;
  int Max=INT_MIN;
  for(int i=1; i<=a;++i){
    cin>>c;
    for(int j = 1; j <= b;++j){
        w[i][j]=c[j-1]-48;
        if(w[i][j]==1){
          dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]))+1;
        }
      Max=max(dp[i][j]*dp[i][j],Max);
      Min=INT_MAX;
    }
  }
  cout << Max << endl;
  return 0;
}
