#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<long double> cache(91, 0);

long double Solving(int n) { 
  if (cache[n] != 0 ) return cache[n];
  if (n == 1 || n == 2) return 1;

  long double sum = Solving(n-1) + Solving(n-2);
  cache[n] = sum;
  return sum;
}

int main(){
  int num;
  cin >> num;

  if (num == 1 || num ==2) {
    cout << "1" << endl;
    return 0;
  }

  printf("%.0Lf\n", Solving(num)); // print Long double param.
  return 0;
}
