#include <iostream>
#include <vector>
using namespace std;
int Solving(int a){
  if(a <= 1) return 0;
  int asum = 0;
  int bsum = 0;
  asum = a%3 + Solving(a/3) +1;
  bsum = a%2 + Solving(a/2) +1;
  asum = min(asum,bsum);
  return asum;
}
/*
asum, bsum . awesome idea.
*/
int main(){
  int a;
  cin >> a;
  cout << Solving(a) << endl;
  return 0;
}
