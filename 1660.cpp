/**
캡틴이다솜
https://www.acmicpc.net/problem/1660
정말 간단한 dp 문제. 동전 교환하고 똑같음.
새로운 것이 추가되었을때 이전에 이루어진 것을 수정하면서 넘어감.
Botton-up방식.
**/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> dp1(300001,0);
vector<int> dp2(200,0);
int main(){
  int n;
  cin >> n;
  dp1[0]=0;
  for(int i=1; i<=n; ++i) dp1[i]=i+dp1[i-1];
  dp2[0]=0;
  dp2[1]=1;
  int k;
  for(int i=1; i<=125; ++i) {
    dp2[i]=dp2[i-1]+dp1[i];
    if(dp2[i] > n){
      k=i;
      break;
    }
  }
  for(int i=1;i<=n;++i) dp1[i]=INT_MAX;
  for(int i=1; i<k;++i){
    for(int j=dp2[i];j<=n;++j){
      dp1[j]=min(dp1[j],dp1[j-dp2[i]]+1);
    }
  }
  cout<<dp1[n]<<endl;
  return 0;
}
