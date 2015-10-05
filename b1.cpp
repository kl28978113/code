#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Person {
    int ID;
    char name[205];
    int v;
    bool operator < (Person a) const {
        if (v != a.v)
            return v < a.v;
        return ID > a.ID;
    }
} A[150010];

priority_queue<Person> que;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        if (!que.empty()) que.pop();
        int B[150010] = {0}, rec[150010];

        int k, m, q;
        scanf("%d%d%d", &k, &m, &q);
        for (int i = 1; i <= k; i++) {
            scanf("%s%d", A[i].name, &A[i].v);
            A[i].ID = i;
        }
        int t, p;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &t, &p);
            B[t] += p;
        }
        int C[110], MAX = 0;
        for (int i = 1; i <= q; i++) {
            scanf("%d", &C[i]);
            MAX = max(MAX, C[i]);
        }

        int cnt = 1;
        for (int i = 1; i <= k; i++) {
            que.push(A[i]);
            Person hehe = que.top();
            if (cnt > MAX)
                break;
            if (B[i]) {
                for (int j = 0; j < B[i]; j++)
                    if (!que.empty()) {
                        Person tmp = que.top();
                        rec[cnt++] = tmp.ID;
                        que.pop();
                    }
            }
        }
        while (cnt <= MAX && !que.empty()) {
            Person tmp = que.top();
            rec[cnt++] = tmp.ID;
            que.pop();
        }

		for (int i = 1; i < q; i++)
			printf("%s ", A[rec[C[i]]].name);

		printf("%s\n", A[rec[C[q]]].name);
	}
	return 0;
}
