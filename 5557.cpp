/**
1학년
https://www.acmicpc.net/problem/5557
이 문제는 앞서 푼 기타리스트(1495번) 문제와 똑같은 문제이다.
**/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<long> > dp(105, vector<long>(25,-1));
int MM;
int size;
long Solving(int idx, int cur, vector<int>& w){
  if(cur <0 || cur>20) return 0;
  if(dp[idx][cur] !=-1) return dp[idx][cur];
  if(idx==size){
    if(cur == MM) return 1;
    else return 0;
  }
  long sum=0;
  if(cur+w[idx+1] <=20) sum+=Solving(idx+1,cur+w[idx+1],w);
  if(cur-w[idx+1] >= 0) sum+=Solving(idx+1,cur-w[idx+1],w);
  dp[idx][cur] = sum;
  return sum;
}
int main(){
  int n,a;
  vector<int> w;
  w.push_back(0);
  cin>>n;
  while(n--){
    cin>>a;
    w.push_back(a);
  }
  MM=w.back();
  w.pop_back();
  size=w.size()-1;
  cout << Solving(0,0,w) << endl;
  return 0;
}
