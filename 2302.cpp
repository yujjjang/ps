#include <iostream>
#include <vector>
using namespace std;
vector<int> cache(40,0);
int fibo(int n){
  if(cache[n] !=0) return cache[n];
  if(n==0 || n==1) return 1;
  int sum = fibo(n-1)+fibo(n-2);
  cache[n] = sum;
  return sum;
}
int main(){
  int a,b;
  cin >> a;
  cin >> b;
  int m,n,k,l;
  int pr=0;
  int ans = 1;
  while(b--){
    cin >> m;
    ans*= fibo(m-pr-1);
    pr = m;
  }
  if(pr!=a) ans *= fibo(a-pr);
  cout << ans << endl;
  return 0;
}
