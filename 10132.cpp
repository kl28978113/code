#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A[300];
int n;

bool cmp(string a, string b) {
	return a.size() < b.size();
}

bool judge(string word) {
	int vis[300] = {0};
	for (int i = 0; i < n / 2; i++) {
		for (int j = n - 1; j >= n / 2; j--)
			if (!vis[j] && (A[i] + A[j] == word || A[j] + A[i] == word)) {
				vis[j] = vis[i] = 1;
				break;
			}
		if (!vis[i]) return false;
	}
	cout << word << endl;
	return true;
}

void solve() {
	for (int i = 0; A[i].size() == A[0].size(); i++)
		for (int j = n - 1; A[j].size() == A[n-1].size(); j--)
			if (judge(A[i] + A[j]) || judge(A[j] + A[i])) return;
}

int main() {
	int  T;
	scanf("%d\n", &T);
	char str[300];
	while (T--) {
		n = 0;
		while (gets(str) != NULL && str[0]) A[n++] = str;
		sort(A, A + n, cmp);

		solve();
		if (T) puts("");
	}
	return 0;
}
