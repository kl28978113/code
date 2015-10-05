#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

int main() {
	queue <string> que;
	map <string, int> vis;
	string S;
	int N, M, cnt = 0;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		cin >> S;
		que.push(S);

		if (vis[S]++) {
			cout << "Cache" <<endl;
		} else {
			cnt++;
			cout << "Internet" <<endl;
			if (cnt > M) {
				while (--vis[que.front()]) que.pop();
				que.pop();
			}
		}
	}
	return 0;
}
