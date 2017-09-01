#include<iostream>
#include<algorithm>

int a[1111][1111];
int l[1111][1111];
int r[1111][1111];

int main()
{
  int i,j,n,m;
  scanf("%d%d",&n,&m);
  for(j=2;j<=m;j++)a[0][j]=-1e9;
  for(i=1;i<=n;i++) {
    for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
    l[i][0]=r[i][m+1]=-1e9;
    for(j=1;j<=m;j++) l[i][j]=std::max(l[i][j-1],a[i-1][j])+a[i][j];
    for(j=m;j>=1;j--) r[i][j]=std::max(r[i][j+1], a[i-1][j])+a[i][j];
    for(j=1;j<=m;j++) a[i][j]=std::max(l[i][j],r[i][j]);
  }
  printf("%d",a[n][m]);
}
