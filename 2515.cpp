/**
전시장
https://www.acmicpc.net/problem/2515
자기보다 낮은 높이를 가진 그림은 아무런 의미가 없기때문에
언제나 자기보다 높은 인덱스를 가진 그림은 자신보다 높이가 높게 하도록
정렬을 먼저 해준다.
정렬 후에는 Botton-up 방식으로 간단한 dp 식을 잡아서 풀면 끝
**/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
using namespace std;
vector<int> dp(300005,0);
int main(){
  vector<pair<int, int> > v;
  pair<int, int> p;
  int n,s,h,pr;
  cin>>n>>s;
  p=make_pair(0,0);
  v.push_back(p);
  for(int i=0; i<n; ++i){
    scanf("%d %d", &h, &pr);
    p=make_pair(h,pr);
    v.push_back(p);
  }
  int j=0;
  sort(v.begin(), v.end());
  for(int i=1;i<=n;++i){
    while(v[j+1].first+s<=v[i].first) j++;
    dp[i]=max(dp[i-1],dp[j]+v[i].second);
    j=0;
    }
    cout << dp[n] << endl;
  return 0;
}
