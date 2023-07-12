#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e5+10;
int n;

bool judge(int x){
    int y = sqrt(x);
    return y*y == x;
}

void dfs(int r){
    if(r < 0)return;
    for(int i = 0;i <= r;i ++){
        if(judge(i+r)){
            dfs(i-1);
            for(int j = r;j >= i;j --)cout<<j<<' ';
            break;
        }
    }
}

void solve(){
    cin>>n;
    dfs(n-1);
    cout<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}