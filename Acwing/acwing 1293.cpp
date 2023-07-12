#include<iostream>
using namespace std;
const int N = 1e5+50;

int pri[N],cnt;
bool vis[N];

void get_prime(int n){
    vis[1] = true;
    for(int i = 2;i <= n;i ++){
        if(!vis[i])pri[cnt++] = i;
        for(int j = 0;pri[j] * i <= n;j ++){
            vis[pri[j] * i] = true;
            if(i % pri[j] == 0)break;
        }
    }
}


int main(){
    int n;
    cin>>n;
    get_prime(n);
    for(int i = 1;i <= n;i ++){
        if(vis[i+1])cout<<2<<' ';
        else cout<<1<<' ';
    }
    return 0;
}