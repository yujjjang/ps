/**
Dance Dacne Revolution
https://www.acmicpc.net/problem/2342
DP 식을 구하는 재귀함수가 굉장히 복잡한 형태로 되어있다.
각각의 조건을 따져서 식을 넣었는데 조건이 조금 복잡하게 되있어서
일단 생각안하고 크게크게 문제를 풀기만 한 상태이다.
현재 인덱스와 왼발,오른발의 위치를 기준으로 식을 세웠으며
각각 움직이는 경로에 따라 cost가 달라서 저렇게 표현해놨다.
최적화를 해야겠음.
**/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int dp[100001][5][5];
vector<int> w;
int Solving(int idx, int size, int left, int right){
  if(idx!=0 && left==right) return 1e9;
  if(dp[idx][left][right] != -1) return dp[idx][left][right];
  if(idx==size) return 0;
  int sum=1e9;
  if(left == w[idx+1]){
    sum=min(sum, Solving(idx+1,size,left,right)+1);
  } else if (right == w[idx+1]){
    sum=min(sum,Solving(idx+1,size,left,right)+1);
  } else {
    if(left==0){
      sum=min(sum, Solving(idx+1,size,w[idx+1],right)+2);
    } else if (left>0){
      if(abs(left-w[idx+1])==2) sum=min(sum, Solving(idx+1,size,w[idx+1],right)+4);
      else sum=min(sum, Solving(idx+1, size, w[idx+1], right) +3);
    }
    if(right==0){
      sum=min(sum,Solving(idx+1,size,left,w[idx+1])+2);
    } else if (right>0){
      if(abs(right-w[idx+1])==2) sum=min(sum, Solving(idx+1,size,left,w[idx+1])+4);
      else sum=min(sum, Solving(idx+1, size, left, w[idx+1]) +3);
    }
  }
  dp[idx][left][right] = sum;
  return sum;
}
int main(){
  for(int i=0; i<100001; ++i)
    for(int j=0; j<5; ++j)
      for(int k=0; k<5; ++k)
        dp[i][j][k]=-1;
  int a;
  w.push_back(0);
  while(1){
    cin>>a;
    if(a==0) break;
    w.push_back(a);
  }
  int size=w.size()-1;
  cout << Solving(0,size,0,0) << endl;
  return 0;
}
