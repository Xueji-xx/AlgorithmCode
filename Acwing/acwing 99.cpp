#include<iostream>
using namespace std;
const int N = 5e3+10;
int map[N][N];

int main(){
    int n,r;
    cin>>n>>r;
    for(int i = 0;i < n;i ++){
        int x,y,z;
        cin>>x>>y>>z;
        map[++x][++y] += z;
    }
    for(int i = 1;i <= 5001;i ++){
        for(int j = 1;j <= 5001;j ++){
            map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + map[i][j];
        }
    }
    int ans = 0;
    for(int i = r;i <= 5001;i ++){
        for(int j = r;j <= 5001;j ++){
            ans = max(ans,map[i][j] - map[i-r][j]-map[i][j-r]+map[i-r][j-r]);
        }
    }
    if(r > 5001)cout<<map[5001][5001];
    else cout<<ans<<endl;
    return 0;
}