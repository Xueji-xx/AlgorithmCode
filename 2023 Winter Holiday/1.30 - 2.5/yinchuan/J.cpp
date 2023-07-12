#include <iostream>
using namespace std;

const int N = 2020;
int u[N*N],d[N*N],l[N*N],r[N*N];
int a[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>>m;
    for(int i = 1;i <= m*m;i ++){
        cin>>u[i]>>d[i]>>l[i]>>r[i];
        if(u[i] == -1 && l[i] == -1)a[1][1] = i;
    }
    for(int i = 2;i <= m;i ++){
        a[1][i] = r[a[1][i-1]];
    }
    for(int i = 2;i <= m;i ++){
        for(int j = 1;j <= m;j ++){
            a[i][j] = d[a[i-1][j]];
        }
    }
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j <= m;j ++){
            cout<<a[i][j];
            if(j != m)cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}