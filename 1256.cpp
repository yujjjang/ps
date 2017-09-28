/**
사전
https://www.acmicpc.net/problem/1256
'a', 'z' 로 이루어진 사전에서 K번째 문자열이 무엇인지를 구하는 문제이다.
제일 앞자리와 나머지로 나누는 알고리즘을 통해서 재귀적으로 해결함.
'a' 인 경우와 'z'인 경우로 나누어서 해결할수 있음.
Binomial 을 사용해서 경우의수를 계산함(factorial은 범위를 벗어남)
bino에 대한 memoization 배열과 해답 dp에 관한 memoization 배열 생성.
**/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string A;
bool chk=false;
vector<vector<long double> > dp(202,vector<long double>(101,-1));
long double bino(int a, int b){
  if(dp[a][b] !=-1) return dp[a][b];
  if(a==b || b==0) return 1;
  if(b==1) return a;
  long double sum=0;
  sum=bino(a-1,b-1) + bino(a-1,b);
  dp[a][b]=sum;
  return sum;
}
void Solving(int a, int b, int k){
  if(a==0){
    while(b--){
      A.append("z");
    }
    return;
  } else if (b==0){
    while(a--){
      A.append("a");
    }
    return;
  }
  if(k <= bino(a+b-1,b)){
    A.append("a");
    Solving(a-1,b,k);
  } else {
    A.append("z");
    Solving(a,b-1,k-bino(a+b-1,b));
  }
}
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(c> bino(a+b,b)){
    cout << "-1" << endl;
    return 0;
  }
  Solving(a,b,c);
  cout << A << endl;
  return 0;
}
