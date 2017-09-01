#include <iostream>
#include <vector>
using namespace std;
int n, k, i, j, dp[10001], arr[100];
int main(){
  std::ios::sync_with_stdio(false);
  cin >> n >> k;
  for (i = 0; i < n; i++){
    cin >> arr[i];
  }
  dp[0] = 1;
  for (i = 0; i < n; i++){
    for (j = arr[i]; j <= k; j++)
      dp[j] += dp[j - arr[i]];
  }
  cout << dp[k] << endl;
  return 0;
}
