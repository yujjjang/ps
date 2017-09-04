#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1000],sz;
int main(){
  scanf("%d",&n);
  for(int i=0,x; i<n; i++){
    scanf("%d",&x);
    int pos=lower_bound(a,a+sz,x)-a;
    if(pos==sz) sz++;
    a[pos]=x;
  }
  printf("%d",sz);
  return 0;
}

