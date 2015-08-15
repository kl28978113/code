#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	int N;
	string s[60];
	while (cin >> N) {
		if (!N) break;
		for (int i = 0; i < N; i++)
			cin >> s[i];

		sort(s, s + N, cmp);
		for (int i = 0; i < N; i++)
			cout << s[i];
		cout << endl;
	}
	return 0;
}
