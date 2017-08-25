#include <iostream>
#include <vector>

using namespace std;
int main(){
  int n,m,k,l;
  vector<int> v;
  vector<int> a(10001,0);
  cin >> n;
  while(n--){
    cin >> m;
    while(m--){
      cin >> k;
      v.push_back(k);
    }
    cin >> l;
    a[0] = 1;
    for(int i = 0; i<v.size();++i){
      for(int j = v[i]; j <= l; ++j){
        a[j] += a[j-v[i]];
      }
    }
    cout << a[l] << endl;
    v.clear();
    a.clear();
    a.resize(10001,0);
  }
  return 0;
}

/*
Basic Dynamic Programming
*/
