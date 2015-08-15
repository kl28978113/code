#include <iostream>
#include <string>
using namespace std;

struct state {
	string s;
	int val;
	bool operator < (const state& a) {
		return val != a.val ? val < a.val : s > a.s;
	}
} DP[1010][1010];

int main() {
	string str;
	while (cin >> str) {
		int len = str.size();
		for (int i = 0; i < len; i++) {
			DP[i][i].val = 1;
			DP[i][i].s = str[i];
			for (int j = i-1; j >= 0; j--) {
				if (str[i] == str[j]) {
					DP[i][j].val = DP[i-1][j+1].val + 2;
					DP[i][j].s = str[i] + DP[i-1][j+1].s + str[j];
				}
				else 
					DP[i][j] = DP[i-1][j] < DP[i][j+1] ? DP[i][j+1] : DP[i][j] = DP[i-1][j];
			}
		}
		cout << DP[len-1][0].s << endl;
	}
	return 0;
}
