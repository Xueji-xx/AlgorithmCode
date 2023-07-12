#include<iostream>
#include<string.h>
using namespace std;
int f[1100][1100];

int judge(string a,string b){
    a = '1' + a;
    b = '1' + b;
    int n = a.size()-1;
    int m = b.size()-1;
    memset(f,0,sizeof f);
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            f[i][j] = min(f[i-1][j] + 1,f[i][j-1] + 1);
            if(a[i] == b[j])f[i][j] = min(f[i][j],f[i-1][j-1]);
            else f[i][j] = min(f[i][j],f[i-1][j-1]+1);
        }
    }
    return f[n][m];
}



int main(){
    int n,m;
    cin>>n>>m;
    string a[n+5];
    for(int i = 0;i < n;i ++)cin>>a[i];
    for(int i = 0;i < m;i ++){
        string s;
        cin>>s;
        int k;
        cin>>k;
        int ans = 0;
        for(int j = 0;j < n;j ++)if(judge(a[i],s) <= k)ans++;
        cout<<ans<<endl;
    }
    return 0;
}