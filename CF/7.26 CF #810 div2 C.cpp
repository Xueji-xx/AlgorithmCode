#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N = 1e5+10;
int n,m,k;
int a[N];

bool check(){
    if((n & 1) && a[k] < m*3)return false;
    int sum = 0;
    for(int i = 1;i <= k;i ++){
        int t = a[i]/m;
        if(t >= 2)sum += t;
    }
    return sum >= n;
}


void solve(){
    cin>>n>>m>>k;
    for(int i = 1;i <= k;i ++)cin>>a[i];
    sort(a+1,a+k+1);
    if(check()){
        cout<<"Yes"<<endl;
        return;
    }
    swap(n,m);
    if(check()){
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}