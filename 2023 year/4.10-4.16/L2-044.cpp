#include <iostream>
#include <string.h>
using namespace std;

const int N = 510;
int sex[N];
int d[N][N];
int dis[N];
int n;

void folyd(){
    for(int k = 1;k <= n;k ++){
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    cin >> n;
    char op;
    int cnt;
    memset(d,0x3f,sizeof d);
    for(int i = 1;i <= n;i ++){
        d[i][i] = 0;
        cin >> op >> cnt;
        if(op == 'F')sex[i] = 0;
        else sex[i] = 1;
        while(cnt --){
            int a,b;
            scanf("%d:%d",&a,&b);
            d[i][a] = b;
        }
    }
    folyd();
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            if(sex[i] != sex[j]){
                dis[i] = max(dis[i],d[j][i]);
            }
        }
    }
    for(int i = 0;i <= 1;i ++){
        int x = 2e9;
        for(int j = 1;j <= n;j ++){
            if(sex[j] == i)x = min(x,dis[j]);
        }
        int t = 0;
        for(int j = 1;j <= n;j ++){
            if(dis[j] == x && sex[j] == i){
                if(t)cout << ' ';
                t ++;
                cout << j;
            }
        }
        cout << endl;
    }
    return 0;
}