#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > cache(2002,vector<int>(2002,-1));
int Solving(int l, int r, vector<int>& A, vector<int>& B){
  if(cache[l][r] != -1) return cache[l][r];
  if(l>=A.size() || r>=B.size()) return 0;
  int sum=0;
  if(B[r] < A[l]){
    sum=Solving(l, r+1, A, B) + B[r];
  } else {
    sum = max(Solving(l+1,r,A,B), Solving(l+1,r+1,A,B));
  }
  cache[l][r]=sum;
  return sum;
}
int main(){
  std::ios::sync_with_stdio(false);
  int N,a,b;
  cin >> N;
  vector<int> A;
  vector<int> B;
  for(int i=0;i<N;++i) {
    cin >> a;
    A.push_back(a);
  }
  for(int i=0;i<N;++i){
    cin >> a;
    B.push_back(a);
  }
  cout << Solving(0,0,A,B) << endl;
  return 0;
}
