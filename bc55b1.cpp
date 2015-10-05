#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 50;

int T;

int n, m;
char g[maxn + 5][maxn + 5];

double dis[maxn + 5][maxn + 5][maxn + 5];

int walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main()
{
//#ifndef ONLINE_JUDGE
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
//#endif
    scanf("%d", &T);
    while (T--)
    {
        int k;
        scanf("%d%d%d", &n, &m, &k);
        REP(i, 0, n) scanf("%s", g[i]);
        int x0, y0, x1, y1;
        scanf("%d%d%d%d", &x0, &y0, &x1, &y1), --x0, --y0, --x1, --y1;
        REP(i, 0, k + 1)
            REP(j, 0, n)
                REP(k, 0, m)
                    dis[i][j][k] = 1e100;
        dis[k][x0][y0] = 0;
        double ans = k ? dis[k][x1][y1] : 1e100;
        for (int a = k; a > 0; --a)
        {
            REP(b, 0, n)
                REP(c, 0, m)
                    if (dis[a][b][c] < 1e50)
                    {
                        REP(i, 0, 4)
                        {
                            int u = b + walk[i][0], v = c + walk[i][1];
                            if (u < 0 || v < 0 || u >= n || v >= m) continue;
                            if (g[u][v] == '#') continue;
                            chkmin(dis[a - 1][u][v], dis[a][b][c] + abs(g[u][v] - g[b][c]) / double(a));
                        }
                    }
            if (a > 1) chkmin(ans, dis[a - 1][x1][y1]);
        }
        if (ans > 1e50) printf("No Answer\n");
        else printf("%.2lf\n", ans);
    }
    return 0;
}
