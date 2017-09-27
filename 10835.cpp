/**
카드게임
1.언제든지 왼쪽 카드만 통에 버릴 수도 있고 왼쪽 카드와 오른쪽 카드를 둘 다 통에 버릴 수도 있다. 이때 얻는 점수는 없다.
2.오른쪽 카드에 적힌 수가 왼쪽 카드에 적힌 수보다 작은 경우에는 오른쪽 카드만 통에 버릴 수도 있다. 오른쪽 카드만 버리는 경우에는 오른쪽 카드에 적힌 수만큼 점수를 얻는다.
3.(1)과 (2)의 규칙에 따라 게임을 진행하다가 어느 쪽 더미든 남은 카드가 없다면 게임이 끝나며 그때까지 얻은 점수의 합이 최종 점수가 된다.

종료조건 : 왼쪽이나 오른쪽에 남은 카드가 없을때.

오른쪽 카드 < 왼쪽카드 :  오른쪽카드 버리고 오른쪽카드의 수만큼 점수 얻음.

1번 조건은 점수 획득이 없고 결국 점수를 획득하는 경우는 오른쪽이 왼쪽보다 작은경우 밖에없음.

**/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > cache(2002,vector<int>(2002,-1));
int Solving(int l, int r, vector<int>& A, vector<int>& B){
  if(cache[l][r] != -1) return cache[l][r];
  if(l>=A.size() || r>=B.size()) return 0; // End case! There is no card in right or left dummy.
  int sum=0;
  if(B[r] < A[l]){ // Case 2 : Right < Left.
    sum=Solving(l, r+1, A, B) + B[r];
  } else {
    sum = max(Solving(l+1,r,A,B), Solving(l+1,r+1,A,B)); // Case 1 : Drop Left card or both cards.
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
