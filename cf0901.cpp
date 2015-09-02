#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue <int> hehe;

int main() {
	int n, m, cur, tmp;
	scanf("%d%d", &n, &m);
	cur = m;

	for (int i = 1; i < n; ++i) {
		scanf("%d", &tmp);
		hehe.push(tmp);
	}

	while (hehe.top() >= cur) {
		tmp = hehe.top();
		hehe.pop();
		cur++;
		hehe.push(tmp-1);
	}
	printf("%d\n", cur - m);

	return 0;
}
