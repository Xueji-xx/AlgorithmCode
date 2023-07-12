#include <bits/stdc++.h>
    
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define debug(x)    cout << x << endl;
#define SZ(x)    (int)x.size()
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int inf = 0x3f3f3f3f;
void read(int &x) {int s = 0, f = 1; char ch = getchar(); while(!isdigit(ch)) {f = (ch == '-' ? -1 : f); ch = getchar();} while(isdigit(ch)) {s = s * 10 + ch - '0'; ch = getchar();} x = s * f;}

const int N = 1005;
int n, m;
LL a[N][N], s[N][N];

void init()
{
    memset(a, 0, sizeof a);
}

void solve()
{
    init();
    cin >> n >> m;
    rep(i, 0, n)
    {
        LL h, w; cin >> h >> w;
        a[h][w] += h * w;
    }

    rep(i, 1, N)
    rep(j, 1, N)
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

    while(m --)
    {
        LL h1, w1, h2, w2;
        cin >> h2 >> w2 >> h1 >> w1;
        cout << s[h2][w2] + s[h1 - 1][w1 - 1] - s[h2][w1 - 1] - s[h1 - 1][w2] << '\n';
    }
}

signed main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}