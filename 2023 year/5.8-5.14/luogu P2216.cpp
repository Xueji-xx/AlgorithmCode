#include <iostream>
#include <algorithm>
using namespace std;

int g[1050][1050];
int maxm[1050][1050];
int minn[1050][1050];
const int INF = 1000000000;
int a,b,n,logn;

int query (int x, int y){
    int _max = 0, _min = 0;
    _max = max(maxm[x][y], max(maxm[x+n-(1<<logn)][y+n-(1<<logn)], max(maxm[x+n-(1<<logn)][y], maxm[x][y+n-(1<<logn)])));
    _min = min(minn[x][y], min(minn[x+n-(1<<logn)][y+n-(1<<logn)], min(minn[x+n-(1<<logn)][y], minn[x][y+n-(1<<logn)])));
    return _max - _min;
}


int main(){
    cin >> a >> b >> n;
    for(int i = 0;i < a;i ++){
        for(int j = 0;j < b;j ++){
            cin >> g[i][j];
            maxm[i][j] = minn[i][j] = g[i][j];
        }
    }
    for (logn = 0; ((1<<(logn+1)) <= n); logn++);
    for (int k = 0; k < logn; k++)
        for (int i = 0; i+(1<<k) < a; i++)
            for (int j = 0; j+(1<<k) < b; j++) {
                maxm[i][j] = max(maxm[i][j], max(maxm[i+(1<<k)][j+(1<<k)], max(maxm[i+(1<<k)][j], maxm[i][j+(1<<k)])));
                minn[i][j] = min(minn[i][j], min(minn[i+(1<<k)][j+(1<<k)], min(minn[i+(1<<k)][j], minn[i][j+(1<<k)])));
            }
    
    int ans = INF;
    for(int i = 0;i <= a - n;i ++){
        for(int j = 0;j <= b - n;j ++){
            ans = min(ans,query(i,j));
        }
    }
    cout << ans << endl;
    return 0;
}