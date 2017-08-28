#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
vector<vector<int> > cache(301, vector<int>(3,0));

int Solving(vector<int>& v, int idx, int size, int cnt){
  if (cache[idx][cnt] != 0) return cache[idx][cnt];
  if (idx > size) return INT_MIN;
  if (idx == size) return v[idx];
  int a = 0;
  if(cnt == 2) {
    a = Solving(v, idx + 2, size, 1) + v[idx];
  } else {
    a = max(Solving(v,idx + 1, size , cnt + 1) , Solving (v, idx + 2, size, 1)) + v[idx];
  }
  cache[idx][cnt] = a;
  return a;
}

int main(){
  int num,cc;
  cin >> num;
  vector<int> v;
  v.push_back(0);
  while(num--){
    cin >> cc;
    v.push_back(cc);
  }
  cache[v.size()-2][1] = v[v.size()-1] + v[v.size()-2];
  cache[v.size()-2][2] = INT_MIN;
  int a = Solving(v,0,v.size()-1,0);
  cout << a << endl;
  return 0;
}
