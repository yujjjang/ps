#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> dp(1000001,-1);
long long solve(int n){
  if(dp[n]!=-1) return dp[n];
  long long sum =0;
  sum=((n-1)*(solve(n-1)%1000000000+solve(n-2)%1000000000))%1000000000;
  dp[n]=sum;
  return sum;
}
int main(){
  int n;
  cin >> n;
  dp[0]=0;
  dp[1]=0;
  dp[2]=1;
  dp[3]=2;
  printf("%lli\n",solve(n));
  return 0;
}
