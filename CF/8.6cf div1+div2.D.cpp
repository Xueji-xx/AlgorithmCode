#include<iostream>
using namespace std;
#include<algorithm>
const int N = 1e6+50;
#define int long long
int num[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i ++){
        int sum = 0;
        for(int j = 1;j <= m;j ++){
            int x;
            cin>>x;
            sum += j * x;
        }
        num[i] = sum;
    }
    int cnt = max_element(num+1,num+n+1) - num;
    if(cnt == 1){
        cout<<cnt<<' '<<num[cnt] - num[cnt+1]<<endl;
    }
    else{
        cout<<cnt<<' '<<num[cnt] - num[cnt-1]<<endl;
    }

}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}