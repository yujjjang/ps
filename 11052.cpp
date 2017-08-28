#include <iostream>
#include <vector>
using namespace std;
int main(){
  int a,b;
  cin >> a;
  vector<int> v;
  v.push_back(0);
  int end = a;
  while(a--){
    cin >> b;
    v.push_back(b);
  }
  vector<int> dp(2000,0);
  for(int i = 1; i<=end; ++i){
    for(int j=1; j<=i;++j){
      if(i-j>=0){
        dp[i]=max(dp[i], dp[i-j]+v[j]);
      }
    }
  }
  cout << dp[end] << endl;
  return 0;
}
/**
Dynamic Programming:
Using prior data to solve posterior one
**/
