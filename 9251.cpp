#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  char a[1001];
  char b[1001];
  vector<vector<int> > dp(1001, vector<int>(1001,0));
  fgets(a, sizeof(a), stdin);
  int len_a=strlen(a);
  a[len_a-1] = '\0';
  fgets(b, sizeof(b), stdin);
  int len_b=strlen(b);
  b[len_b-1] = '\0';
  len_a--;
  len_b--;
  for(int i=0;i<len_a;++i){
    if(a[i]==b[0]) dp[i][0]=1;
    else {
      if(i!=0) dp[i][0] = dp[i-1][0];
    }
  }
  for(int j=0; j<len_b;++j){
    if(a[0]==b[j]) dp[0][j]=1;
    else {
      if(j!=0) dp[0][j] = dp[0][j-1];
    }
  }
  for(int i=1;i<len_a;++i){
    for(int j=1;j<len_b;++j){
      if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
      else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
  }
  cout << dp[len_a-1][len_b-1] << endl;
  return 0;
}
