/**
1로만들기
https://www.acmicpc.net/problem/1463
1로 만들기. 연산의 종류는 3가지인데 실제로 1을 빼는 3번과정은 1번과 2번을 위한
과정이므로 %를 통해서 이를 계산한다.
2로 나누고 3으로 나눌 수 있는 환경에서 1을 빼지는 않을 것이기 때문에.
나머지는 간단하다.
**/

#include <iostream>
#include <vector>
using namespace std;
vector<int> dp(1000001,-1);
int Solving(int a){
  if(dp[a]!=-1) return dp[a];
  if(a <= 1) return 0;
  int asum = 0;
  int bsum = 0;
  asum = a%3 + Solving(a/3) +1;
  bsum = a%2 + Solving(a/2) +1;
  asum = min(asum,bsum);
  dp[a]=asum;
  return asum;
}
int main(){
  int a;
  cin >> a;
  cout << Solving(a) << endl;
  return 0;
}
