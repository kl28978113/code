#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
using namespace std;
typedef long long int LL;
const int MAXN =  0x3f3f3f3f;
const int  MIN =  -0x3f3f3f3f;
const double eps = 1e-9;
const int dir[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{-1,1},
  {1,1},{1,-1},{-1,-1}};
int dp[15][10], a[15];
// 这个函数求的是区间（0，n）内的个数
LL solve(int n){
  int len = 0; LL ans = 0;
  while (n){
    a[++len] = n % 10; n /= 10;
  }int i, j; a[len+1] = 0;
  // 长度为1~len-1
  for (i = 1; i <= len-1; ++i)
    for (j = 1; j <= 9; ++j) // 注意j从1开始，因为最高位不能是0！
      ans += dp[i][j];        //  debug了好久！！！
  // 长度为len，但是最高位是a[len] - 1
  for (i = 1; i <= a[len] - 1; ++i)
    ans += dp[len][i];
  // 长度为len，但是最高位是a[len]
  for (i = len - 1; i >= 1; --i){
    for (j = 0; j < a[i]; ++j)
      if (abs(a[i+1] - j) >= 2)
        ans += dp[i][j];
    if (abs(a[i] - a[i+1]) < 2)
      break;
  }
  return ans;
}
int main(void){
  memset(dp, 0, sizeof(dp));
  int i, j, k;
  for (i = 0; i <= 9; ++i)
    dp[1][i] = 1;
  for (i = 2; i <= 10; ++i)
    for (j = 0; j <= 9; ++j)
      for (k = 0; k <= 9; ++k)
        if (fabs(j - k) >= 2)
          dp[i][j] += dp[i-1][k];
  int a, b;
  while (~scanf("%d%d", &a, &b)){
	  cout << a <<" ~ " << b <<  " = ";
    cout << solve(b+1) - solve(a) << endl;
  }
  return 0;
}
