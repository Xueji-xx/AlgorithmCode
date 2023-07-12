#include<iostream>
using namespace std;
const int N = 55;
int x[N],y[N];
#define endl '\n'
int n,k;
int ans = INT_MAX>>2;

struct mat {
    int lx,ly,rx,ry;//左上角坐标和右下角坐标
    bool cnt;//是否覆盖相关点
    void add(int x,int y){
        if(!cnt){
            lx = rx = x;
            ly = ry = y;
            cnt = true;
        }
        else{
            if(x < lx)lx = x;
            else if(x > rx)rx = x;
            if(y > ly)ly = y;
            else if(y < ry)ry = y;
        }
    }
    bool inmat(int x,int y) const{
        return x >= lx && x <= rx && y <= ly && y >= ry;
    }
    int operator() (){
        if(!cnt)return 0;
        return (rx - lx) * (ly - ry);
    }
    bool operator* (const mat &x){
        if(!cnt || !x.cnt)return false;
        return x.inmat(lx,ly) || x.inmat(lx,ry) || x.inmat(rx,ly) || x.inmat(rx,ry);
    }
} sq[5];

bool check(){
    for(int i = 1;i <= k;i ++){
        for(int j = i+1;j <= k;j ++){
            if(sq[i] * sq[j])return false;
        }
    }
    return true;
}

void dfs(int i,int area){
    if(area >= ans)return;
    if(i == n){
        if(check()){
            if(ans > area)ans = area;
        }
        return;
    }
    mat tmp;
    for(int j = 1;j <= k;j ++){
        tmp = sq[j];
        sq[j].add(x[i],y[i]);
        dfs(i+1,area - tmp() + sq[j]());
        sq[j] = tmp;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i = 0;i < n;i ++){
        cin>>x[i]>>y[i];
    }
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}