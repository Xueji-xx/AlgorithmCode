#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5+10;
 
int t;
 
void solve(){
    int n;
    cin>>n;
    int a[N];
    for(int i = 1; i <= n; i ++)cin>>a[i];
    sort(a + 1, a + n + 1);
    int res[N], cnt = 1;
    for(int i = 1, j = n/2 + 1; i <= n/2 || j <= n; i ++ , j ++ ){
        if(i <= n/2) res[cnt ++] = a[i];
        if(j <= n) res[cnt++] = a[j];
    }
    res[0] = res[n];
    res[n+1] = res[1];
    for(int i = 1; i <= n; i ++ ){
        if((res[i-1] >= res[i] && res[i+1] <= res[i]) || (res[i-1] <= res[i] && res[i+1] >= res[i])){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i ++ ){
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return;
}
 
int main(){
    cin>>t;
    while(t --)solve();
    return 0;
}
