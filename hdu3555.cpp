#include <iostream>
using namespace std;

int main() {
	unsigned long long DP[25][25] = {0};
	for (int i = 2; i <= 20; i++) {
		unsigned long long tmp = 0;
		for (int j = 0; j < 10; j++)
			tmp += DP[i-1][j];
		for (int j = 0; j < 10; j++) {
			DP[i][j] = tmp;
		}

		tmp = 1;
		for (int j = i-2; j > 0; j--)
			tmp *= 10;

		DP[i][4] += tmp - DP[i-1][9];
	}

	int T;
	cin >> T;
	while (T--) {
		unsigned long long n;
		cin >> n;
		unsigned long long cnt = 1, num[25] = {0};
		n++;
		while (n) {
			num[cnt++] = n % 10;
			n /= 10;
		}
		unsigned long long sum = 0;
		while (--cnt) {
			for (int i = 0; i < num[cnt]; i++)
				sum += DP[cnt][i];
			if (num[cnt+1] == 4 && num[cnt] == 9) {
				unsigned long long last = 0;
				while (--cnt)
					last = last * 10 + num[cnt];
				sum += last;
				break;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
