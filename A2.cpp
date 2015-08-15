#include <cstdio>

int month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int num[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int m;

int E(int year, int month) {
	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2) 
		return 1;
	return 0;
}

int judge(int i, int j, int k) {
	if (num[i%10] + num[(i/10)%10] + num[(i/100)%10] + num[(i/1000)%10] + num[j%10] + num[(j/10)%10] + num[k%10] + num[(k/10)%10] == m)
		return 1;
	return 0;
}

int cal(int YYYY, int MM, int DD) {
	int cnt = 0;
	for (int i = YYYY; i < 3000; i++)
		for (int j = (i == YYYY ? MM : 1); j <= 12; j++)
			for (int k = ((i == YYYY && j == MM) ? DD : 1); k <= month[j] + E(i, j); k++) {
				if (judge(i, j, k))
					return cnt;
				cnt++;
			}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int tmp;
		scanf("%d%d", &tmp, &m);
		printf ("%d\n", cal(tmp/10000, (tmp/100) % 100, tmp % 100));
	}
	return 0;
}
