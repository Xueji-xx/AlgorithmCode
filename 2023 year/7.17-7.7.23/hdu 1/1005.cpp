#include <iostream>
using namespace std;

const int N = 1e6+100;
#define int long long
#define endl "\n"
int n,m;
string g[N];

int get_min(string s)
{
    int i = 0,j = 1;
    while(i < m && j < m){
        int k = 0;
        while(k < m && s[i + k] == s[j + k])k ++;
        if(k == m)break;
        if(s[i + k] > s[j + k])i += k + 1;
        else j += k + 1;
        if(i == j)j ++;
    }
    return min(i,j);
}

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        string st;
        cin >> st;
        st += st;
        int pos = get_min(st);
        st = st.substr(pos,m);
        g[i] = st;
    }
    int q;
    cin >> q;
    while(q --){
        int x,y;
        cin >> x >> y;
        if(g[x] == g[y]){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}