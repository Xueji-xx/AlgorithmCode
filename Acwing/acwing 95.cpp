#include<iostream>
using namespace std;
const int N = 10;

char g[N][N],bg[N][N];
int mov[] = {0,1,0,-1,0};

void turn(int x,int y){
    for(int i = 0;i < 5;i ++){
        int a = x + mov[i],b = y + mov[i+1];
        if(a < 0 || a >= 5 || b < 0 || b >= 5)continue;
        g[a][b] ^= 1;
    }
}


void solve(){
    for(int i = 0;i < 5;i ++)cin>>g[i];
    int res = 10;
    for(int k = 0;k < 1<<5;k ++){
        int cnt = 0;
        memcpy(g,bg,sizeof g);
        for(int i = 0;i < 5;i ++){
            if(k >> 1 & 1){
                turn(0,i);
                cnt++;
            }
        }
        bool flag = true;
        for(int i = 0;i < 5;i ++){
            if(g[4][i] == '0')flag = false;
        }
        if(flag && res > cnt)res = cnt;    
    }
    if(res > 6)res = -1;
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}