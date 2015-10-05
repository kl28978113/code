#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, int> vis;

int cal(string A) {
	return  ((A[0] - '0')*10 + (A[1] - '0')) * 3600 + ((A[3] - '0') * 10  + (A[4] - '0')) * 60 + (A[6] - '0') * 10 + (A[7] - '0');
}

void change(int t) {
	int hou = t / 3600;
	int min = (t % 3600) / 60;
	int sec = t % 60;
	cout << (hou / 10) << (hou % 10) << ":" << (min / 10) << (min % 10) << ":" << (sec / 10) << (sec % 10) << endl;
}

int main() {
	int n, A[20010];
	string S[20010], Name, Time, Action;
	cin >> n;
	int cnt = 0, hehe = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		cin >> Name >> Time >> Action;
		int t = cal(Time);
		if (Action == "START") {
			vis[Name] = cnt;
			S[cnt] = Name;
			A[cnt++] = t;
			hehe++;
		} else {
			int pos = vis[Name];
			A[pos] = t - A[pos];
			if (A[pos] < 0)
				flag = true;
			hehe--;
		}
	}
	if (flag || hehe) {
		cout << "Incorrect performance log" << endl;
		return 0;
	}

	for (int i = 0; i < cnt; i++) {
		cout << S[i] << " ";
		change(A[i]);
	}
}
