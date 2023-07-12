#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n,m;
map<int,int> id;
int st[50050][20];

void build(){
    for(int j = 1;1 << j <= n;j ++){
        for(int i = 1;i  + (1 << j) - 1 <= n;i ++){
            st[i][j] = max(st[i][j-1],st[i + (1 << (j -1))][j-1]);
        }
    }
}

inline int RMQ(int l,int r){
    int k;
    for(k = 0;1 << (k + 1) <= r - l + 1;k ++);
    return max(st[l][k],st[r - (1 << k) + 1][k]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i ++){
        int y;
        cin >> y >> st[i][0];
        id[y] = i;
    }
    build();
    cin >> m;
    while(m --){
        int x,y;
        cin >> y >> x;
        if(y >= x){
            cout << "false" << endl;
            continue;
        }
        bool kx = id.count(x),ky = id.count(y),flag;
        if(!kx && !ky){
            cout << "maybe" << endl;
            continue;
        }
        int xx,yy;
        map<int,int> ::iterator itx,ity;
        ity = id.lower_bound(y);
        itx = id.lower_bound(x);
        if(ity == id.end()){
            cout << "maybe" << endl;
            continue;
        }
        yy = ity->second;
        xx = itx == id.end() ? id.size() + 1 : itx->second;
        if(!ky)yy --;
        int rmq = yy + 1 <= xx - 1 ? RMQ(yy + 1,xx - 1) : 0;
        if(!ky) flag = rmq < st[xx][0];//情况3-1
		else if(!kx) flag = st[yy][0] > rmq;//情况3-2
		else flag = st[yy][0] >= st[xx][0] && st[xx][0] > rmq;
        if(ky && kx && yy - xx == y - x){
            if(flag)cout << "true" << endl;
            else cout << "false" << endl;
        }
        else{
            if(flag) cout << "maybe" << endl;
            else cout << "false" << endl;
        }
    }
    return 0;
}