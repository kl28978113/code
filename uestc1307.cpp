#include <iostream>
using namespace std;

long long DP[15][15] = {0};

long long cal(long long n) {
	int cnt = 1, num[15] = {0};
// cout << endl << n <<"   ";
//	if (n==0)
//		cnt++;
	while (n) {
		num[cnt++] = n % 10;
		n /= 10;
	}
	// cout << "cnt = " <<cnt<<endl;
	long long sum = 0;

	cnt--;
	for (int i = 0; i < num[cnt]; i++) {
		sum += DP[cnt][i];
	}

	// cout << sum << endl;
	while (--cnt) {
		for (int i = 0; i < num[cnt]; i++) {
			if (i - num[cnt+1] >= 2 || num[cnt+1] - i >= 2) {
				if (cnt > 1) {
				for (int j = 0; j < 10; j++)
					if (i-j >= 2 || j-i >= 2)
						sum += DP[cnt-1][j];
				}
					else
						sum += DP[cnt][i];
			}
		//		sum += DP[cnt][i];
		//	if (i == 0)
		//		sum -= DP[cnt-1]
			// cout <<  "cnt=" <<cnt <<" i=" << i << " sum=" <<sum << ", ";
		}
		if (!(num[cnt+1] - num[cnt] >= 2 || num[cnt] - num[cnt+1] >=2))
			break;
	}
	return sum;
}

int main() {
	//for (int i = 0; i < 10; i++)
	//	DP[1][i] = 1;
	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j < 10; j++)
			for (int k = 0; k < 10; k++)
				if (j - k >= 2 || k -j >= 2)
					DP[i][j] += DP[i-1][k];

		for (int k = 0; k < 10; k++)
			DP[i][0] += DP[i-1][k];
	}
	//DP[2][0] = 9;
		// cout << DP[2][0] << endl << DP[2][1] << endl;

	long long A, B;
	while (cin >> A >> B) {
		cout << A << " ~ "<< B << " = ";
		cout << cal(B+1) -  cal(A) << endl;
	}
	return 0;
}
