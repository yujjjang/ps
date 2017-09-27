/**
Alpha Code.
https://www.acmicpc.net/problem/2011

11111 로 이루어진 알파코드가 있다고 생각해보면 된다.
생각해야할 수는 사실 0,1,2 만 있고 0인경우 1인경우 2인경우 . 3가지 경우의 수로 나눠서 재귀로 표현한 식.
**/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> cache(5001, 0);
int Solving(vector<int>& v, int idx, vector<int>& chk){
  if (cache[idx] != 0 ) return cache[idx];
  if (idx == v.size() -1 || idx == v.size()) return 1; // Base case.
  int sum = 0;
  // v[idx+2]=0 : It has only one case -> e.g. 120 = AT
  if (chk[idx+1] == -1){  
    sum = Solving(v, idx + 3, chk);
    cache[idx] = sum;
    return sum;
  }
  // v[idx+1]=0 : Same as above case -> e.g. 10 = J
  if (chk[idx] == -1){ 
    sum = Solving(v, idx + 2, chk);
    
  }
  // v[idx] != 1 || v[idx] != 2 -> 3,4,5 ....
  else if (chk[idx] == 0) { 
    sum = Solving(v, idx + 1, chk);
  } 
  // v[idx] = 1 : It has two cases. e.g. 11 = AA or K
  else if (chk[idx] == 1){ 
    sum = Solving(v,idx+1,chk)+Solving(v,idx+2,chk);
  } 
  // 1. e.g. 21 = BA or U 2. e.g. 27 = BG.
  else {
    if (v[idx+1] <= 6) sum = Solving(v, idx+1, chk) + Solving(v, idx+2, chk);  
    else sum = Solving(v, idx+1, chk); 
  }
  cache[idx] = sum%1000000;
  return sum%1000000;
}
int main(){
  string num;
  cin >> num;
  if (num[0] == '0') return -1;
  int len = num.length();
  vector<int> v;
  vector<int> dp(5001,0);
  vector<int> chk(len + 1, 0);
  for(int i = 0; i < len; ++i){
    v.push_back(num[i]-48);

    if (v[i] == 1) chk[i] = 1;
    else if (v[i] ==2) chk[i] = 2;
    else if (v[i] == 0) chk[i-1] = -1;
  }
  cout << Solving(v,0,chk)<<endl;
  return 0;
}
