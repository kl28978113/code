#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
const int N = 10005;
int n;
map<int,int> mp;
int sum;
int Num[N];
int main() {
    while (scanf("%d", &n) != EOF) {
        mp.clear();
        int a;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            if (!mp.count(a)) {
                mp[a] = 1;    
            } else mp[a]++;
        }
        int flag = 0;
        for (int i = 0; i <= 10000; i++) {
            if (n - mp[i] < mp[i])    {
                if (flag == 0) printf("%d", i);
                else printf(" %d", i);
                flag = 1;    
            }
        }
        if (!flag) printf("-1");
        puts("");
    }
    return 0;
}
