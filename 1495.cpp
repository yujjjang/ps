#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > dp(105,vector<int>(2001,-2));
int Solving(vector<int>& v, int idx, int size, int now, int MAX){
  if(dp[idx][now] != -2) return dp[idx][now];
  if(idx==size) return now;
  int sum=-1;
  if(now+v[idx] <= MAX) sum = max(sum, Solving(v,idx+1,size,now+v[idx],MAX));
  if(now-v[idx] >= 0) sum = max(sum, Solving(v, idx+1, size, now-v[idx],MAX));
  dp[idx][now] = sum;
  return sum;
}
int main(){
  std::ios::sync_with_stdio(false);
  int a,b,c,d;
  cin>>a>>b>>c;
  vector<int> v;
  while(a--){
    cin >> d;
    v.push_back(d);
  }
  int size=v.size();
  cout << Solving(v,0,size,b,c) << endl;
  return 0;
}

