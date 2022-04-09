#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[9]={0}, b[9] = {0}, c[20] = {0}, d[20] = {0};
int num=0;
int m[9][9]={0};
void dfs(int i, int k) {
  if (k == 0) {
    num++;
    return;
  }
  if (b[i] == 1) {
    dfs(i + 1, k);
    return;
  }
  if (i > 8) return;
  for (int j = 1; j <= 8; j++) {
    if (a[j] == 0 && b[i] == 0 && c[j + i - 1] == 0 && d[8 - i + j] == 0) {
      a[j] = 1;
      b[i] = 1;
      c[j + i - 1] = 1;
      d[8 - i + j] = 1;
      // cout << j << ' ' << i << endl;
      dfs(i + 1, k - 1);
      // cout << j << ' ' << i << endl;
      // cout << "dsadasdsad" << endl;
      a[j] = 0;
      b[i] = 0;
      c[j + i - 1] = 0;
      d[8 - i + j] = 0;
    }
  }
}
int main() {
  while (cin>>m[1][1]) 
  {
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(c,0,sizeof c);
    memset(d,0,sizeof d);
    int p, q, r = 0;
    
    for (q = 2; q <= 8; q++)
    {
       cin >> m[1][q];
    }
    for (p = 2; p <= 8; p++) 
    {
      for (q = 1; q <= 8; q++)
      {
        cin >> m[p][q];
      }
    }

    num = 0;
    for (p = 1; p <= 8; p++) {
      for (q = 1; q <= 8; q++) {
        if (m[p][q] == 1) {
          a[p] = 1;  //ÐÐ
          b[q] = 1;  //ÁÐ
          c[p + q - 1] = 1;
          d[8 - q + p] = 1;
          r = r + 1;
        }
      }
    }
    // cout << "k:" << 8-r << endl;
    dfs(1, 8 - r);
    cout << num << endl;
  }
  return 0;
  system("pause");
}