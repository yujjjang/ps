#include <iostream>
#include <vector>
using namespace std;
int main(){
  int a,b,c;
  cin >> a;
  vector<int> dp(101,0);
  vector<short> o(101,1);
  dp[0]=0;
  dp[1]=1;
  int idx=1;
  while(a--){
    cin>>b;
    for(int i=2; i<=b; ++i){
      while(1){
        c=idx*i;
        if(c>b) break;
        if(o[c] == 1) o[c]=0;
        else o[c]=1;

        idx++;
      }
      idx=1;
      dp[i]=dp[i-1]+o[i];
    }
    cout<<dp[b]<<endl;
    for(int i=0;i<101;++i) o[i]=1;
  }
  return 0;
}
