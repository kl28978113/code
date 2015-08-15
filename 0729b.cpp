//BZOJ1225; 求正整数 (HNOI2001); DP
//SGU475; Droid Fromation;
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define N 50000
#define LOGN 15
#define SIZE 10000
#define MOD 100000000LL
#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
const double INFI = 123456789012345.0;
const int p[LOGN + 1] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int n, logn, from[N + 1][LOGN + 1], pos;
double f[N + 1][LOGN + 1], Log[N + 1], min;
class bignum
{
public:
	ll num[SIZE];
	int tot;
	bignum() {}
	bignum(ll x)
	{
		clear();
		while (x) num[tot++] = x % MOD, x /= MOD;
	}
	void clear()
	{
		tot = 0;
		for (int i = 0; i < SIZE; ++i) num[i] = 0LL;
	}
	void operator *= (const int &x)
	{
		for (int i = 0; i < tot; ++i) num[i] *= x;
		for (int i = 0; i < tot; ++i)
			if (num[i] >= MOD)
			{
				num[i + 1] += num[i] / MOD;
				num[i] %= MOD;
			}
		while (num[tot])
		{
			if (num[tot] >= MOD)
			{
				num[tot + 1] += num[tot] / MOD;
				num[tot] %= MOD;
			}
			++tot;
		}
	}
	void print()
	{
		printf("%lld", num[tot - 1]);
		for (int i = tot - 2; i >= 0; --i)
			printf("%08lld", num[i]);
	}
}ans(1);
int t[LOGN + 1], ct[LOGN + 1], ts;

int main()
{
	while (scanf("%d", &n) != EOF) {
	for (int i = 1; i <= n; ++i) Log[i] = log((double)i) / log(2.0);
	for (int i = 1; i <= n; ++i)
	{
		f[i][1] = Log[2] * (double)(i - 1), from[i][1] = 1;
		for (int j = 2; j <= Log[i]; ++j)
		{
			min = INFI, pos = 0;
			for (int k = 1; k * k <= i; ++k)
				if (!(i % k) && Log[k] >= j - 1)
					if (min > f[k][j - 1] + Log[p[j]] * (double)(i / k - 1))
						min = f[k][j - 1] + Log[p[j]] * (double)(i / k - 1), pos = k;
			for (int k = 2; k * k <= i; ++k)
				if (!(i % k) && Log[i / k] >= j - 1)
					if (min > f[i / k][j - 1] + Log[p[j]] * (double)(k - 1))
						min = f[i / k][j - 1] + Log[p[j]] * (double)(k - 1), pos = i / k;
			f[i][j] = min, from[i][j] = pos;
		}
	}
	min = INFI, pos = 0;
	for (int j = 1; j <= Log[n]; ++j)
		if (min > f[n][j]) min = f[n][j], pos = j;
	for (int x = n; x != 1; x = from[x][pos--])
		for (int i = x / from[x][pos] - 1; i > 0; --i)
			ans *= p[pos];
	ans.print();
	}
	return 0;
}
